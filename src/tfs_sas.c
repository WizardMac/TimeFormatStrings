#include <sys/types.h>
#include <stdio.h>
#include <string.h>

#include "tfs.h"
#include "tfs_internal.h"
#include "tfs_sas.h"

static char sas_separator_codes[][2] = {
    { 'B', ' ' },
    { 'C', ':' },
    { 'D', '-' },
    { 'N', '\0' },
    { 'P', '.' },
    { 'S', '/' }
};

static char separator_for_code(char code) {
    char separator = '\0';
    int i;
    for (i=0; i<sizeof(sas_separator_codes)/sizeof(sas_separator_codes[0]); i++) {
        if (code == sas_separator_codes[i][0]) {
            separator = sas_separator_codes[i][1];
            break;
        }
    }
    return separator;
}

tfs_token_array_t *tfs_sas_parse(const char *bytes, tfs_handle_string_callback handle_error, tfs_error_e *outError) {
    tfs_token_array_t *token_array = tfs_init_token_array(10);
    tfs_token_t *token = NULL;
    if (strcasecmp(bytes, "DATE") == 0 ||
            strcasecmp(bytes, "DATE9") == 0) {
        token = append_day(token_array, TFS_MONTH, TFS_2DIGIT);
        token = append_month(token_array, TFS_ABBREV);
        token->uppercase = 1;

        if (strcasecmp(bytes, "DATE9") == 0) {
            token = append_year(token_array, TFS_ERA, TFS_NUMBER);
        } else {
            token = append_year(token_array, TFS_CENTURY, TFS_2DIGIT);
        }
    } else if (strcasecmp(bytes, "DATETIME") == 0) {
        token = append_day(token_array, TFS_MONTH, TFS_2DIGIT);
        token = append_month(token_array, TFS_ABBREV);
        token->uppercase = 1;
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);

        token = append_literal_char(token_array, ' ');

        token = append_hour(token_array, TFS_PERIOD, TFS_2DIGIT);
        token = append_literal_char(token_array, ':');
        token = append_minute(token_array, TFS_HOUR, TFS_2DIGIT);
        token = append_literal_char(token_array, ':');
        token = append_second(token_array, TFS_MINUTE, TFS_2DIGIT);
    } else if (strcasecmp(bytes, "DAY") == 0) {
        token = append_day(token_array, TFS_MONTH, TFS_NUMBER);
    } else if (strncasecmp(bytes, "DDMMYY", sizeof("DDMMYY")-1) == 0) {
        char separator = '/';
        int is_2digit = 1;

        if (strcasecmp(bytes, "DDMMYY10") == 0) {
            is_2digit = 0;
        } else if (strlen(bytes) > sizeof("DDMMYY")-1) {
            separator = separator_for_code(bytes[6]);
            if (separator) {
                if (strlen(bytes) == sizeof("DDMMYYS10")-1 && bytes[7] == '1' && bytes[8] == '0') {
                    is_2digit = 0;
                }
            } else {
                is_2digit = (strcasecmp(bytes, "DDMMYYN6") == 0);
            }
        }

        token = append_day(token_array, TFS_MONTH, TFS_2DIGIT);
        if (separator) {
            token = append_literal_char(token_array, separator);
        }
        token = append_month(token_array, TFS_2DIGIT);
        if (separator) {
            token = append_literal_char(token_array, separator);
        }
        if (is_2digit) {
            token = append_year(token_array, TFS_CENTURY, TFS_2DIGIT);
        } else {
            token = append_year(token_array, TFS_ERA, TFS_NUMBER);
        }
    } else if (strcasecmp(bytes, "DOWNAME") == 0) {
        token = append_day(token_array, TFS_WEEK, TFS_FULL);
    } else if (strcasecmp(bytes, "JULDAY") == 0) {
        token = append_day(token_array, TFS_YEAR, TFS_NUMBER);
    } else if (strcasecmp(bytes, "JULIAN") == 0) {
        token = append_year(token_array, TFS_CENTURY, TFS_2DIGIT);
        token = append_day(token_array, TFS_YEAR, TFS_NUMBER);
        token->pad_len = 3;
        token->pad_char = '0';
    } else if (strncasecmp(bytes, "MMDDYY", sizeof("MMDDYY")-1) == 0) {
        char separator = '/';
        int is_2digit = 1;

        if (strcasecmp(bytes, "MMDDYY10") == 0) {
            is_2digit = 0;
        } else if (strlen(bytes) > sizeof("MMDDYY")-1) {
            separator = separator_for_code(bytes[6]);
            if (separator) {
                if (strlen(bytes) == sizeof("MMDDYYS10")-1 && bytes[7] == '1' && bytes[8] == '0') {
                    is_2digit = 0;
                }
            } else {
                is_2digit = (strcasecmp(bytes, "MMDDYYN8") != 0);
            }
        }

        token = append_month(token_array, TFS_2DIGIT);
        if (separator) {
            token = append_literal_char(token_array, separator);
        }
        token = append_day(token_array, TFS_MONTH, TFS_2DIGIT);
        if (separator) {
            token = append_literal_char(token_array, separator);
        }
        if (is_2digit) {
            token = append_year(token_array, TFS_CENTURY, TFS_2DIGIT);
        } else {
            token = append_year(token_array, TFS_ERA, TFS_NUMBER);
        }
    } else if (strncasecmp(bytes, "MMYY", sizeof("MMYY")-1) == 0) {
        char separator = 'M';

        if (strlen(bytes) > sizeof("MMYY")-1) {
            separator = separator_for_code(bytes[4]);
        }

        token = append_month(token_array, TFS_2DIGIT);
        if (separator) {
            token = append_literal_char(token_array, separator);
        }
        token = append_day(token_array, TFS_MONTH, TFS_2DIGIT);
        if (separator) {
            token = append_literal_char(token_array, separator);
        }
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);
    } else if (strcasecmp(bytes, "MONNAME") == 0) {
        token = append_month(token_array, TFS_FULL);
    } else if (strcasecmp(bytes, "MONTH") == 0) {
        token = append_month(token_array, TFS_NUMBER);
    } else if (strcasecmp(bytes, "MONYY") == 0) {
        token = append_month(token_array, TFS_ABBREV);
        token->uppercase = 1;

        token = append_year(token_array, TFS_ERA, TFS_2DIGIT);
    } else if (strcasecmp(bytes, "PDFJULG") == 0) {
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);
        token = append_day(token_array, TFS_YEAR, TFS_NUMBER);
        token->pad_len = 3;
        token->pad_char = '0';
        token = append_literal_char(token_array, 'F');
    } else if (strcasecmp(bytes, "WEEKDATE") == 0) {
        token = append_day(token_array, TFS_WEEK, TFS_FULL);
        token = append_literal_string(token_array, ", ");
        token = append_month(token_array, TFS_FULL);
        token = append_literal_string(token_array, " ");
        token = append_day(token_array, TFS_MONTH, TFS_NUMBER);
        token = append_literal_string(token_array, ", ");
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);
    } else if (strcasecmp(bytes, "WEEKDAY") == 0) {
        token = append_day(token_array, TFS_WEEK, TFS_NUMBER);
    } else if (strcasecmp(bytes, "WORDDATE") == 0) {
        token = append_month(token_array, TFS_FULL);
        token = append_literal_string(token_array, " ");
        token = append_day(token_array, TFS_MONTH, TFS_NUMBER);
        token = append_literal_string(token_array, ", ");
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);
    } else if (strcasecmp(bytes, "WORDDATX") == 0) {
        token = append_day(token_array, TFS_MONTH, TFS_NUMBER);
        token = append_literal_string(token_array, " ");
        token = append_month(token_array, TFS_FULL);
        token = append_literal_string(token_array, " ");
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);
    } else if (strcasecmp(bytes, "QTR") == 0) {
        token = append_quarter(token_array, TFS_NUMBER);
    } else if (strcasecmp(bytes, "QTRR") == 0) {
        token = append_quarter(token_array, TFS_ROMAN);
    } else if (strcasecmp(bytes, "TIME") == 0) {
        token = append_hour(token_array, TFS_PERIOD, TFS_NUMBER);
        token = append_literal_char(token_array, ':');
        token = append_minute(token_array, TFS_HOUR, TFS_2DIGIT);
        token = append_literal_char(token_array, ':');
        token = append_second(token_array, TFS_MINUTE, TFS_2DIGIT);
    } else if (strcasecmp(bytes, "TIMEAMPM") == 0) {
        token = append_hour(token_array, TFS_PERIOD, TFS_NUMBER);
        token = append_literal_char(token_array, ':');
        token = append_minute(token_array, TFS_HOUR, TFS_2DIGIT);
        token = append_literal_char(token_array, ':');
        token = append_second(token_array, TFS_MINUTE, TFS_2DIGIT);
        token = append_literal_char(token_array, ' ');
        token = append_ampm(token_array, TFS_ABBREV);
        token->uppercase = 1;
    } else if (strcasecmp(bytes, "TOD") == 0) {
        token = append_hour(token_array, TFS_PERIOD, TFS_2DIGIT);
        token = append_literal_char(token_array, ':');
        token = append_minute(token_array, TFS_HOUR, TFS_2DIGIT);
        token = append_literal_char(token_array, ':');
        token = append_second(token_array, TFS_MINUTE, TFS_2DIGIT);
    } else if (strcasecmp(bytes, "YEAR") == 0) {
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);
    } else if (strcasecmp(bytes, "YYMMDD") == 0) {
        char separator = '-';
        token = append_year(token_array, TFS_CENTURY, TFS_2DIGIT);
        token = append_literal_char(token_array, separator);
        token = append_month(token_array, TFS_2DIGIT);
        token = append_literal_char(token_array, separator);
        token = append_day(token_array, TFS_MONTH, TFS_2DIGIT);
    } else if (strncasecmp(bytes, "YYMM", sizeof("YYMM")-1) == 0) {
        char separator = 'M';
        if (strlen(bytes) == sizeof("YYMMS")-1) {
            separator = separator_for_code(bytes[4]);
        }
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);
        if (separator) {
            token = append_literal_char(token_array, separator);
        }
        token = append_month(token_array, TFS_2DIGIT);
    } else if (strncasecmp(bytes, "YYQ", sizeof("YYQ")-1) == 0) {
        char separator = 'Q';
        if (strlen(bytes) == sizeof("YYQS")-1) {
            separator = separator_for_code(bytes[3]);
        }
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);
        if (separator) {
            token = append_literal_char(token_array, separator);
        }
        token = append_quarter(token_array, TFS_NUMBER);
    } else if (strncasecmp(bytes, "YYQR", sizeof("YYQR")-1) == 0) {
        char separator = 'Q';
        if (strlen(bytes) == sizeof("YYQRS")-1) {
            separator = separator_for_code(bytes[4]);
        }
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);
        if (separator) {
            token = append_literal_char(token_array, separator);
        }
        token = append_quarter(token_array, TFS_ROMAN);
    }

    if (token == NULL) {
        if (handle_error) {
            char error_buf[1024];
            snprintf(error_buf, sizeof(error_buf), "Unrecognized SAS format: %s", bytes);
            handle_error(error_buf, sizeof(error_buf), token_array);
        }
        *outError = TFS_PARSE_ERROR;
        tfs_free_token_array(token_array);
        return NULL;
    }

    return token_array;
}
