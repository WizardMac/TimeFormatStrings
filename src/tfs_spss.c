
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

#include "tfs.h"
#include "tfs_internal.h"
#include "tfs_spss.h"

tfs_token_array_t *tfs_spss_parse(const char *bytes, tfs_handle_string_callback handle_error, tfs_error_e *outError) {
    tfs_token_array_t *token_array = tfs_init_token_array(10);
    tfs_token_t *token = NULL;
    if (strncasecmp(bytes, "DATETIME", sizeof("DATETIME")-1) == 0) {
        token = append_day(token_array, TFS_MONTH, TFS_2DIGIT);
        token = append_literal_char(token_array, '-');
        token = append_month(token_array, TFS_ABBREV);
        token = append_literal_char(token_array, '-');
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);
        token = append_literal_char(token_array, ' ');
        token = append_hour(token_array, TFS_DAY, TFS_NUMBER);
        token = append_literal_char(token_array, ':');
        token = append_minute(token_array, TFS_HOUR, TFS_2DIGIT);
    } else if (strncasecmp(bytes, "DATE", sizeof("DATE")-1) == 0) {
        token = append_day(token_array, TFS_MONTH, TFS_2DIGIT);
        token = append_literal_char(token_array, '-');
        token = append_month(token_array, TFS_ABBREV);
        token = append_literal_char(token_array, '-');
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);
    } else if (strncasecmp(bytes, "TIME", sizeof("TIME")-1) == 0) {
        token = append_hour(token_array, TFS_DAY, TFS_NUMBER);
        token = append_literal_char(token_array, ':');
        token = append_minute(token_array, TFS_HOUR, TFS_2DIGIT);
    } else if (strncasecmp(bytes, "ADATE", sizeof("ADATE")-1) == 0) {
        token = append_month(token_array, TFS_2DIGIT);
        token = append_literal_char(token_array, '/');
        token = append_day(token_array, TFS_MONTH, TFS_2DIGIT);
        token = append_literal_char(token_array, '/');
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);
    } else if (strncasecmp(bytes, "EDATE", sizeof("EDATE")-1) == 0) {
        token = append_day(token_array, TFS_MONTH, TFS_2DIGIT);
        token = append_literal_char(token_array, '.');
        token = append_month(token_array, TFS_2DIGIT);
        token = append_literal_char(token_array, '.');
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);
    } else if (strncasecmp(bytes, "JDATE", sizeof("JDATE")-1) == 0) {
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);
        token = append_day(token_array, TFS_YEAR, TFS_NUMBER);
        token->pad_len = 3;
        token->pad_char = '0';
    } else if (strncasecmp(bytes, "SDATE", sizeof("SDATE")-1) == 0) {
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);
        token = append_literal_char(token_array, '/');
        token = append_month(token_array, TFS_2DIGIT);
        token = append_literal_char(token_array, '/');
        token = append_day(token_array, TFS_MONTH, TFS_2DIGIT);
    } else if (strncasecmp(bytes, "QYR", sizeof("QYR")-1) == 0) {
        token = append_quarter(token_array, TFS_NUMBER);
        token = append_literal_string(token_array, " Q ");
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);
    } else if (strncasecmp(bytes, "MOYR", sizeof("MOYR")-1) == 0) {
        token = append_month(token_array, TFS_ABBREV);
        token = append_literal_char(token_array, '0');
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);
    } else if (strncasecmp(bytes, "WKYR", sizeof("WKYR")-1) == 0) {
        token = append_week(token_array, TFS_YEAR, TFS_NUMBER);
        token = append_literal_string(token_array, " WK ");
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);
        token->modifier = TFS_ISO_WEEK_NUMBERING_YEAR;
    }

    if (token == NULL) {
        if (handle_error) {
            char error_buf[1024];
            snprintf(error_buf, sizeof(error_buf), "Unrecognized SPSS format: %s", bytes);
            handle_error(error_buf, sizeof(error_buf), token_array);
        }
        *outError = TFS_PARSE_ERROR;
        tfs_free_token_array(token_array);
        return NULL;
    }

    return token_array;
}
