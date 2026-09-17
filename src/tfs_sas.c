#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "tfs.h"
#include "tfs_internal.h"
#include "tfs_sas.h"

/* See https://documentation.sas.com/doc/en/pgmsascdc/9.4_3.5/leforinforref/ */

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

/* A SAS format name is NAME[x][w][.[d]] where x is an optional separator
 * letter (only for the formats that take one), w is the width, and d is the
 * number of decimal places. Returns 1 if `bytes` is `name` with a valid suffix,
 * and reports the separator letter (or 0), the width (or 0) and decimals (or 0). */
static int match_format(const char *bytes, const char *name, int takes_separator,
        char *out_sep_code, int *out_width, int *out_decimals) {
    size_t name_len = strlen(name);
    const char *p = bytes;
    char sep_code = 0;
    int width = 0, decimals = 0;

    if (strncasecmp(bytes, name, name_len) != 0)
        return 0;

    p += name_len;

    if (takes_separator && *p && strchr("BCDNPSbcdnps", *p)) {
        sep_code = toupper((unsigned char)*p);
        p++;
    }
    while (*p >= '0' && *p <= '9') {
        width = width * 10 + (*p - '0');
        p++;
    }
    if (*p == '.') {
        p++;
        while (*p >= '0' && *p <= '9') {
            decimals = decimals * 10 + (*p - '0');
            p++;
        }
    }
    if (*p != '\0')
        return 0;

    if (out_sep_code)
        *out_sep_code = sep_code;
    if (out_width)
        *out_width = width;
    if (out_decimals)
        *out_decimals = decimals;

    return 1;
}

/* Separator to display for a separator letter, or the default when none was given */
static char separator_or_default(char sep_code, char default_separator) {
    if (sep_code)
        return separator_for_code(sep_code);
    return default_separator;
}

static tfs_token_t *append_year_digits(tfs_token_array_t *token_array, int is_2digit) {
    if (is_2digit)
        return append_year(token_array, TFS_CENTURY, TFS_2DIGIT);
    return append_year(token_array, TFS_ERA, TFS_NUMBER);
}

/* MMDDYY, DDMMYY and YYMMDD share width rules: with no separator letter, a width
 * of 6 or less drops the separators, 7 to 9 shows a 2-digit year, and 10 or more
 * shows a 4-digit year. With a separator letter, N (no separator) switches to
 * a 4-digit year at width 8; the others at width 10. */
static void parse_numeric_date_width(char sep_code, int width, char default_separator,
        char *out_separator, int *out_is_2digit) {
    if (sep_code) {
        *out_separator = separator_for_code(sep_code);
        if (sep_code == 'N') {
            *out_is_2digit = (width < 8);
        } else {
            *out_is_2digit = (width < 10);
        }
    } else if (width == 0) {
        *out_separator = default_separator;
        *out_is_2digit = 1;
    } else if (width <= 6) {
        *out_separator = '\0';
        *out_is_2digit = 1;
    } else {
        *out_separator = default_separator;
        *out_is_2digit = (width < 10);
    }
}

static void append_hms(tfs_token_array_t *token_array, tfs_time_unit_e hour_relative_to,
        tfs_style_e hour_style, int decimals) {
    tfs_token_t *token = append_hour(token_array, hour_relative_to, hour_style);
    if (hour_relative_to == TFS_PERIOD)
        token->start_at_one = 1;
    append_literal_char(token_array, ':');
    append_minute(token_array, TFS_HOUR, TFS_2DIGIT);
    append_literal_char(token_array, ':');
    append_second(token_array, TFS_MINUTE, TFS_2DIGIT);
    if (decimals > 0) {
        token = tfs_append_token(token_array);
        token->time_unit = TFS_FRACTIONAL_SECOND;
        token->style = TFS_NUMBER;
        token->truncate_len = decimals;
        token->add_dots = 1;
    }
}

tfs_token_array_t *tfs_sas_parse(const char *bytes, tfs_handle_string_callback handle_error, tfs_error_e *outError) {
    tfs_token_array_t *token_array = tfs_init_token_array(10);
    tfs_token_t *token = NULL;
    char sep_code = 0;
    char separator = '\0';
    int width = 0, decimals = 0, is_2digit = 0;

    /* Longer names must be tested before their prefixes (DATETIME before DATE,
     * YYMMDD before YYMM, YYQR before YYQ) */
    if (match_format(bytes, "DATETIME", 0, NULL, &width, &decimals)) {
        /* ddMMMyy:HH:mm:ss, four-digit year from width 18 */
        token = append_day(token_array, TFS_MONTH, TFS_2DIGIT);
        token = append_month(token_array, TFS_ABBREV);
        token->uppercase = 1;
        token = append_year_digits(token_array, width > 0 && width < 18);
        token = append_literal_char(token_array, ':');
        append_hms(token_array, TFS_DAY, TFS_2DIGIT, decimals);
    } else if (match_format(bytes, "DATE", 0, NULL, &width, NULL)) {
        /* ddMMMyy (width 7), ddMMMyyyy (width 9), dd-MMM-yyyy (width 11) */
        separator = width >= 11 ? '-' : '\0';
        token = append_day(token_array, TFS_MONTH, TFS_2DIGIT);
        if (separator)
            token = append_literal_char(token_array, separator);
        token = append_month(token_array, TFS_ABBREV);
        token->uppercase = 1;
        if (separator)
            token = append_literal_char(token_array, separator);
        token = append_year_digits(token_array, width < 9);
    } else if (match_format(bytes, "DAY", 0, NULL, NULL, NULL)) {
        token = append_day(token_array, TFS_MONTH, TFS_NUMBER);
    } else if (match_format(bytes, "DDMMYY", 1, &sep_code, &width, NULL)) {
        parse_numeric_date_width(sep_code, width, '/', &separator, &is_2digit);

        token = append_day(token_array, TFS_MONTH, TFS_2DIGIT);
        if (separator)
            token = append_literal_char(token_array, separator);
        token = append_month(token_array, TFS_2DIGIT);
        if (separator)
            token = append_literal_char(token_array, separator);
        token = append_year_digits(token_array, is_2digit);
    } else if (match_format(bytes, "DOWNAME", 0, NULL, &width, NULL)) {
        token = append_day(token_array, TFS_WEEK, (width > 0 && width <= 3) ? TFS_ABBREV : TFS_FULL);
    } else if (match_format(bytes, "JULDAY", 0, NULL, NULL, NULL)) {
        token = append_day(token_array, TFS_YEAR, TFS_NUMBER);
    } else if (match_format(bytes, "JULIAN", 0, NULL, &width, NULL)) {
        /* yyddd (width 5) or yyyyddd (width 7) */
        token = append_year_digits(token_array, width < 7);
        token = append_day(token_array, TFS_YEAR, TFS_NUMBER);
        token->pad_len = 3;
        token->pad_char = '0';
    } else if (match_format(bytes, "MMDDYY", 1, &sep_code, &width, NULL)) {
        parse_numeric_date_width(sep_code, width, '/', &separator, &is_2digit);

        token = append_month(token_array, TFS_2DIGIT);
        if (separator)
            token = append_literal_char(token_array, separator);
        token = append_day(token_array, TFS_MONTH, TFS_2DIGIT);
        if (separator)
            token = append_literal_char(token_array, separator);
        token = append_year_digits(token_array, is_2digit);
    } else if (match_format(bytes, "MMYY", 1, &sep_code, &width, NULL)) {
        /* mmMyyyy (width 7, the default) or mmMyy (width 5) */
        separator = separator_or_default(sep_code, 'M');

        token = append_month(token_array, TFS_2DIGIT);
        if (separator)
            token = append_literal_char(token_array, separator);
        token = append_year_digits(token_array, width > 0 && width < 7);
    } else if (match_format(bytes, "MONNAME", 0, NULL, &width, NULL)) {
        token = append_month(token_array, (width > 0 && width <= 3) ? TFS_ABBREV : TFS_FULL);
    } else if (match_format(bytes, "MONTH", 0, NULL, NULL, NULL)) {
        token = append_month(token_array, TFS_NUMBER);
    } else if (match_format(bytes, "MONYY", 0, NULL, &width, NULL)) {
        /* MMMyy (width 5, the default) or MMMyyyy (width 7) */
        token = append_month(token_array, TFS_ABBREV);
        token->uppercase = 1;

        token = append_year_digits(token_array, width < 7);
    } else if (match_format(bytes, "PDFJULG", 0, NULL, NULL, NULL)) {
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);
        token = append_day(token_array, TFS_YEAR, TFS_NUMBER);
        token->pad_len = 3;
        token->pad_char = '0';
        token = append_literal_char(token_array, 'F');
    } else if (match_format(bytes, "WEEKDATE", 0, NULL, NULL, NULL)) {
        token = append_day(token_array, TFS_WEEK, TFS_FULL);
        token = append_literal_string(token_array, ", ");
        token = append_month(token_array, TFS_FULL);
        token = append_literal_string(token_array, " ");
        token = append_day(token_array, TFS_MONTH, TFS_NUMBER);
        token = append_literal_string(token_array, ", ");
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);
    } else if (match_format(bytes, "WEEKDAY", 0, NULL, NULL, NULL)) {
        token = append_day(token_array, TFS_WEEK, TFS_NUMBER);
    } else if (match_format(bytes, "WORDDATE", 0, NULL, NULL, NULL)) {
        token = append_month(token_array, TFS_FULL);
        token = append_literal_string(token_array, " ");
        token = append_day(token_array, TFS_MONTH, TFS_NUMBER);
        token = append_literal_string(token_array, ", ");
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);
    } else if (match_format(bytes, "WORDDATX", 0, NULL, NULL, NULL)) {
        token = append_day(token_array, TFS_MONTH, TFS_NUMBER);
        token = append_literal_string(token_array, " ");
        token = append_month(token_array, TFS_FULL);
        token = append_literal_string(token_array, " ");
        token = append_year(token_array, TFS_ERA, TFS_NUMBER);
    } else if (match_format(bytes, "QTRR", 0, NULL, NULL, NULL)) {
        token = append_quarter(token_array, TFS_ROMAN);
    } else if (match_format(bytes, "QTR", 0, NULL, NULL, NULL)) {
        token = append_quarter(token_array, TFS_NUMBER);
    } else if (match_format(bytes, "TIMEAMPM", 0, NULL, NULL, &decimals)) {
        /* h:mm:ss AM */
        append_hms(token_array, TFS_PERIOD, TFS_NUMBER, decimals);
        token = append_literal_char(token_array, ' ');
        token = append_ampm(token_array, TFS_ABBREV);
        token->uppercase = 1;
    } else if (match_format(bytes, "TIME", 0, NULL, NULL, &decimals)) {
        /* H:mm:ss on a 24-hour clock */
        append_hms(token_array, TFS_DAY, TFS_NUMBER, decimals);
        token = &token_array->tokens[token_array->count-1];
    } else if (match_format(bytes, "TOD", 0, NULL, NULL, &decimals)) {
        /* HH:mm:ss on a 24-hour clock */
        append_hms(token_array, TFS_DAY, TFS_2DIGIT, decimals);
        token = &token_array->tokens[token_array->count-1];
    } else if (match_format(bytes, "YEAR", 0, NULL, &width, NULL)) {
        token = append_year_digits(token_array, width > 0 && width < 4);
    } else if (match_format(bytes, "YYMMDD", 1, &sep_code, &width, NULL)) {
        parse_numeric_date_width(sep_code, width, '-', &separator, &is_2digit);

        token = append_year_digits(token_array, is_2digit);
        if (separator)
            token = append_literal_char(token_array, separator);
        token = append_month(token_array, TFS_2DIGIT);
        if (separator)
            token = append_literal_char(token_array, separator);
        token = append_day(token_array, TFS_MONTH, TFS_2DIGIT);
    } else if (match_format(bytes, "YYMM", 1, &sep_code, &width, NULL)) {
        /* yyyyMmm (width 7, the default) or yyMmm (width 5) */
        separator = separator_or_default(sep_code, 'M');

        token = append_year_digits(token_array, width > 0 && width < 7);
        if (separator)
            token = append_literal_char(token_array, separator);
        token = append_month(token_array, TFS_2DIGIT);
    } else if (match_format(bytes, "YYQR", 1, &sep_code, &width, NULL)) {
        /* yyyyQrr with a Roman-numeral quarter (width 8, the default) */
        separator = separator_or_default(sep_code, 'Q');

        token = append_year_digits(token_array, width > 0 && width < 7);
        if (separator)
            token = append_literal_char(token_array, separator);
        token = append_quarter(token_array, TFS_ROMAN);
    } else if (match_format(bytes, "YYQ", 1, &sep_code, &width, NULL)) {
        /* yyyyQq (width 6, the default) or yyQq (width 4) */
        separator = separator_or_default(sep_code, 'Q');

        token = append_year_digits(token_array, width > 0 && width < 6);
        if (separator)
            token = append_literal_char(token_array, separator);
        token = append_quarter(token_array, TFS_NUMBER);
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
