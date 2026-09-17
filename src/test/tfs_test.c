
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tfs.h"

tfs_format_e test_input_formats[] = { TFS_EXCEL, TFS_POSIX, TFS_STATA, TFS_UTS35 };
tfs_format_e test_output_formats[] = { TFS_EXCEL, TFS_POSIX, TFS_STATA, TFS_UTS35 };

typedef struct tfs_test_s {
    char            name[50];

    char            excel[40];
    char            posix[40];
    char            stata[40];
    char            uts35[40];
    unsigned short  mask;
} tfs_test_t;

tfs_test_t all_tests[] = {
    {
        .name = "Era abbreviation",
        .uts35 = "GGG",
        .mask = TFS_ERA
    },
    {
        .name = "Era",
        .uts35 = "GGGG",
        .mask = TFS_ERA
    },
    {
        .name = "Era first letter",
        .uts35 = "GGGGG",
        .mask = TFS_ERA
    },

    {
        .name = "Century",
        .stata = "cc",
        .mask = TFS_CENTURY
    },
    {
        .name = "Century (zero-padded)",
        .stata = "CC",
        .posix = "%C",
        .mask = TFS_CENTURY
    },

    {
        .name = "Year",
        .excel = "yyyy",
        .stata = "ccYY",
        .uts35 = "y",
        .posix = "%Y",
        .mask = TFS_YEAR
    },
    {
        .name = "Year (zero-padded)",
        .stata = "CCYY",
        .uts35 = "yyyy",
        .mask = TFS_YEAR
    },
    {
        .name = "Two-digit year",
        .stata = "yy",
        .mask = TFS_YEAR
    },
    {
        .name = "Two-digit year (zero-padded)",
        .excel = "yy",
        .stata = "YY",
        .uts35 = "yy",
        .posix = "%y",
        .mask = TFS_YEAR
    },
    {
        .name = "Week-numbering year",
        .uts35 = "Y",
        .posix = "%G",
        .mask = TFS_YEAR
    },
    {
        .name = "Extended year",
        .uts35 = "u",
        .mask = TFS_YEAR
    },
    {
        .name = "Cyclic year name",
        .uts35 = "UUU",
        .mask = TFS_YEAR
    },

    {
        .name = "Half-year number",
        .stata = "h",
        .mask = TFS_HALF_YEAR
    },

    {
        .name = "Quarter number",
        .stata = "q",
        .uts35 = "Q",
        .mask = TFS_QUARTER
    },
    {
        .name = "Quarter abbreviation",
        .uts35 = "QQQ",
        .mask = TFS_QUARTER
    },
    {
        .name = "Quarter name",
        .uts35 = "QQQQ",
        .mask = TFS_QUARTER
    },

    { 
        .name = "Month as number", 
        .excel = "m", 
        .stata = "nn",
        .uts35 = "M",
        .mask = TFS_MONTH
    },
    {
        .name = "Month as number (zero-padded)",
        .excel = "mm",
        .stata = "NN",
        .uts35 = "MM",
        .posix = "%m",
        .mask = TFS_MONTH
    },
    {
        .name = "Month abbreviation",
        .excel = "mmm",
        .stata = "Mon",
        .uts35 = "MMM",
        .posix = "%b",
        .mask = TFS_MONTH
    },
    {
        .name = "Month name",
        .excel = "mmmm",
        .stata = "Month",
        .uts35 = "MMMM",
        .posix = "%B",
        .mask = TFS_MONTH
    },
    {
        .name = "Month first letter",
        .excel = "mmmmm",
        .uts35 = "MMMMM",
        .mask = TFS_MONTH
    },
    {
        .name = "Month abbreviation (lower case)",
        .stata = "Mon",
        .mask = TFS_MONTH
    },
    {   
        .name = "Month name (lower case)",
        .stata = "month",
        .mask = TFS_MONTH
    },

    {
        .name = "Week of year",
        .uts35 = "w",
        .mask = TFS_WEEK
    },
    {
        .name = "Week of year (zero-padded)",
        .uts35 = "ww",
        .mask = TFS_WEEK
    },
    {
        .name = "Week of month",
        .uts35 = "W",
        .mask = TFS_WEEK
    },

    {
        .name = "Day of month",
        .excel = "d",
        .stata = "dd",
        .uts35 = "d",
        .posix = "%e",
        .mask = TFS_DAY
    },
    {
        .name = "Day of month (zero-padded)",
        .excel = "dd",
        .stata = "DD",
        .uts35 = "dd",
        .posix = "%d",
        .mask = TFS_DAY
    },
    {
        .name = "Day of week abbreviation",
        .excel = "ddd",
        .stata = "Day",
        .uts35 = "EEE",
        .posix = "%a",
        .mask = TFS_DAY
    },
    {
        .name = "Day of week abbreviation (lower case)",
        .stata = "day",
        .mask = TFS_DAY
    },
    {
        .name = "Day of week two-letter abbreviation",
        .stata = "Da",
        .uts35 = "EEEEEE",
        .mask = TFS_DAY
    },
    {
        .name = "Day of week two-letter abbreviation (lower case)",
        .stata = "da",
        .mask = TFS_DAY
    },
    {
        .name = "Day of week first letter",
        .uts35 = "EEEEE",
        .mask = TFS_DAY
    },
    {
        .name = "Day of week number",
        .uts35 = "ee",
        .mask = TFS_DAY
    },
    {
        .name = "Day of week",
        .excel = "dddd",
        .stata = "Dayname",
        .uts35 = "EEEE",
        .posix = "%A",
        .mask = TFS_DAY
    },
    {
        .name = "Day of year",
        .stata = "jjj",
        .uts35 = "D",
        .mask = TFS_DAY
    },
    {
        .name = "Day of year (zero-padded)",
        .stata = "JJJ",
        .uts35 = "DDD",
        .posix = "%j",
        .mask = TFS_DAY
    },
    {
        .name = "Day of week in month",
        .uts35 = "F",
        .mask = TFS_DAY
    },
    {
        .name = "Modified Julian day",
        .uts35 = "g",
        .mask = TFS_DAY
    },
    {
        .name = "AM or PM",
        .uts35 = "a",
        .stata = "AM",
        .excel = "AM/PM",
        .posix = "%p",
        .mask = TFS_PERIOD
    },
    {
        .name = "A.M. or P.M.",
        .stata = "A.M.",
        .mask = TFS_PERIOD
    },
    {
        .name = "am or pm",
        .stata = "am",
        .excel = "am/pm",
        .mask = TFS_PERIOD
    },
    {
        .name = "a.m. or p.m.",
        .stata = "a.m.",
        .mask = TFS_PERIOD
    },
    {
        .name = "A or P",
        .excel = "A/P",
        .mask = TFS_PERIOD
    },
    {
        .name = "a or p",
        .excel = "a/p",
        .mask = TFS_PERIOD
    },

    {
        .name = "Hour [1-12]",
        .uts35 = "h",
        .stata = "hh",
        .posix = "%l",
        .mask = TFS_HOUR
    },

    {
        .name = "Hour [01-12]",
        .uts35 = "hh",
        .stata = "Hh",
        .posix = "%I",
        .mask = TFS_HOUR
    },
    {
        .name = "Hour [0-11]",
        .uts35 = "K",
        .mask = TFS_HOUR
    },
    {
        .name = "Hour [00-11]",
        .uts35 = "KK",
        .mask = TFS_HOUR
    },
    {
        .name = "Hour [0-23]",
        .uts35 = "H",
        .stata = "hH",
        .excel = "h",
        .posix = "%k",
        .mask = TFS_HOUR
    },
    {
        .name = "Hour [00-23]",
        .uts35 = "HH",
        .stata = "HH",
        .excel = "hh",
        .posix = "%H",
        .mask = TFS_HOUR
    },
    {
        .name = "Hour [1-24]",
        .uts35 = "k",
        .mask = TFS_HOUR
    },
    {
        .name = "Hour [01-24]",
        .uts35 = "kk",
        .mask = TFS_HOUR
    },

    {
        .name = "Minute",
        .stata = "mm",
        .uts35 = "m",
        .mask = TFS_MINUTE
    },
    {
        .name = "Minute (zero-padded)",
        .stata = "MM",
        .uts35 = "mm",
        .posix = "%M",
        .mask = TFS_MINUTE
    },
    {
        .name = "Second",
        .excel = "s",
        .stata = "ss",
        .uts35 = "s",
        .mask = TFS_SECOND
    },
    {
        .name = "Second (zero-padded)",
        .excel = "ss",
        .stata = "SS",
        .uts35 = "ss",
        .posix = "%S",
        .mask = TFS_SECOND
    },

    {
        .name = "Seconds to 1 decimal place",
        .excel = "s.0",
        .stata = "ss.s",
        .uts35 = "s.S",
        .mask = TFS_SECOND | TFS_FRACTIONAL_SECOND
    },

    {
        .name = "Seconds to 2 decimal places",
        .excel = "s.00",
        .stata = "ss.ss",
        .uts35 = "s.SS",
        .mask = TFS_SECOND | TFS_FRACTIONAL_SECOND
    },

    {
        .name = "Seconds to 3 decimal places",
        .excel = "s.000",
        .stata = "ss.sss",
        .uts35 = "s.SSS",
        .mask = TFS_SECOND | TFS_FRACTIONAL_SECOND
    },

    {
        .name = "MM/DD/YY",
        .excel = "mm/dd/yy",
        .stata = "NN/DD/YY",
        .uts35 = "MM/dd/yy",
        .posix = "%m/%d/%y",
        .mask = TFS_MONTH | TFS_DAY | TFS_YEAR
    },

    {
        .name = "MM/DD/YYYY",
        .excel = "mm/dd/yyyy",
        .stata = "NN/DD/ccYY",
        .uts35 = "MM/dd/y",
        .posix = "%m/%d/%Y",
        .mask = TFS_MONTH | TFS_DAY | TFS_YEAR
    },

    {
        .name = "Hour, minute, second, period",
        .excel = "h:mm:ss AM/PM",
        .stata = "hh:MM:SS_AM",
        .uts35 = "h:mm:ss a",
        .posix = "%l:%M:%S %p",
        .mask = TFS_HOUR | TFS_MINUTE | TFS_SECOND | TFS_PERIOD
    },

    {
        .name = "Date at 24-hour time",
        .excel = "mm/dd/yyyy \"at\" h:mm:ss",
        .stata = "NN/DD/ccYY_!a!t_hH:MM:SS",
        .uts35 = "MM/dd/y 'at' H:mm:ss",
        .posix = "%m/%d/%Y at %k:%M:%S",
        .mask = TFS_MONTH | TFS_DAY | TFS_YEAR | TFS_HOUR | TFS_MINUTE | TFS_SECOND
    },

    {
        .name = "String literal",
        .excel = "\"hello\"",
        .stata = "!h!e!l!l!o",
        .uts35 = "'hello'",
        .posix = "hello",
        .mask = 0
    },

    {
        .name = "String literal with percent sign",
        .excel = "\"100%\"!",
        .stata = "!1!0!0!%!!",
        .uts35 = "100%!",
        .posix = "100%%!",
        .mask = 0
    },

    {
        .name = "String literal with single-quote",
        .excel = "\"Hello,\" \"O\"'\"Malley\"",
        .stata = "!H!e!l!l!o,_!O!'!M!a!l!l!e!y",
        .uts35 = "'Hello', 'O''Malley'",
        .posix = "Hello, O'Malley",
        .mask = 0
    },

    {
        .name = "String literal with double-quote",
        .excel = "\"\\\"Yikes\"!\"\\\"\"",
        .stata = "!\"!Y!i!k!e!s!!!\"",
        .uts35 = "\"'Yikes'!\"",
        .posix = "\"Yikes!\"",
        .mask = 0
    }
};

/* One-directional conversions: lossy conversions, error codes, and formats
 * that can be read but not written. */
typedef struct tfs_oneway_test_s {
    char            name[60];
    char            input[120];
    tfs_format_e    input_format;
    tfs_format_e    output_format;
    tfs_error_e     error;
    char            output[120];
} tfs_oneway_test_t;

tfs_oneway_test_t oneway_tests[] = {
    /* Unrepresentable tokens must fail cleanly instead of crashing */
    { "Unrepresentable token (POSIX)", "F", TFS_UTS35, TFS_POSIX, TFS_CANT_REPRESENT, "" },
    { "Unrepresentable token (Stata)", "F", TFS_UTS35, TFS_STATA, TFS_CANT_REPRESENT, "" },
    { "Unrepresentable token (UTS35)", "[h]:mm", TFS_EXCEL, TFS_UTS35, TFS_CANT_REPRESENT, "" },
    { "Unrepresentable token (Excel)", "F", TFS_UTS35, TFS_EXCEL, TFS_CANT_REPRESENT, "" },

    /* Zero-padded years convert to plain full years */
    { "Padded year to Excel", "yyyy-MM-dd", TFS_UTS35, TFS_EXCEL, TFS_OK, "yyyy-mm-dd" },
    { "Padded year to POSIX", "yyyy-MM-dd", TFS_UTS35, TFS_POSIX, TFS_OK, "%Y-%m-%d" },

    /* Excel codes are case-insensitive, and over-long runs collapse */
    { "Excel upper-case codes", "MM/DD/YYYY HH:MM:SS", TFS_EXCEL, TFS_UTS35, TFS_OK, "MM/dd/y HH:mm:ss" },
    { "Excel three-letter year", "yyy", TFS_EXCEL, TFS_EXCEL, TFS_OK, "yyyy" },
    { "Excel long day run", "ddddd", TFS_EXCEL, TFS_EXCEL, TFS_OK, "dddd" },
    { "Excel elapsed hours", "[h]:mm:ss", TFS_EXCEL, TFS_EXCEL, TFS_OK, "[h]:mm:ss" },
    { "Excel elapsed minutes", "[mm]:ss", TFS_EXCEL, TFS_EXCEL, TFS_OK, "[mm]:ss" },
    { "Excel colour code", "[Red]yyyy", TFS_EXCEL, TFS_UTS35, TFS_OK, "y" },
    { "Excel first section only", "yyyy-mm-dd;@", TFS_EXCEL, TFS_UTS35, TFS_OK, "y-MM-dd" },
    { "Excel unquoted non-ASCII", "yyyy\xe5\xb9\xb4m\xe6\x9c\x88", TFS_EXCEL, TFS_UTS35, TFS_OK, "y\xe5\xb9\xb4M\xe6\x9c\x88" },
    { "Excel non-ASCII output", "y\xe5\xb9\xb4M\xe6\x9c\x88", TFS_UTS35, TFS_EXCEL, TFS_OK, "yyyy\xe5\xb9\xb4m\xe6\x9c\x88" },
    { "Excel 12-hour clock needs AM/PM", "hh:mm", TFS_UTS35, TFS_EXCEL, TFS_CANT_REPRESENT, "" },
    { "Excel fraction needs decimal point", "SS", TFS_UTS35, TFS_EXCEL, TFS_CANT_REPRESENT, "" },

    /* UTS35 */
    { "UTS35 unquoted non-ASCII", "d MMM yyyy \xc3\xa0 HH:mm", TFS_UTS35, TFS_POSIX, TFS_OK, "%e %b %Y \xc3\xa0 %H:%M" },
    { "UTS35 lone apostrophe", "%H '%M", TFS_POSIX, TFS_UTS35, TFS_OK, "HH ''mm" },
    { "UTS35 apostrophe before letters", "%H 'x", TFS_POSIX, TFS_UTS35, TFS_OK, "HH '''x'" },
    { "UTS35 seven-digit fraction", "ss.SSSSSSS", TFS_UTS35, TFS_UTS35, TFS_OK, "ss.SSSSSSS" },
    { "UTS35 zone name", "HH:mm z", TFS_UTS35, TFS_POSIX, TFS_OK, "%H:%M %Z" },
    { "UTS35 zone offset", "HH:mm Z", TFS_UTS35, TFS_POSIX, TFS_OK, "%H:%M %z" },
    { "UTS35 zone ID", "HH:mm VV", TFS_UTS35, TFS_UTS35, TFS_OK, "HH:mm VV" },
    { "UTS35 zone to Excel", "HH:mm z", TFS_UTS35, TFS_EXCEL, TFS_CANT_REPRESENT, "" },

    /* POSIX */
    { "POSIX %h", "%h", TFS_POSIX, TFS_UTS35, TFS_OK, "MMM" },
    { "POSIX zone name", "%Z", TFS_POSIX, TFS_UTS35, TFS_OK, "zzz" },
    { "POSIX week-numbering year to Stata", "%G", TFS_POSIX, TFS_STATA, TFS_CANT_REPRESENT, "" },

    /* SAS */
    { "SAS DATE", "DATE", TFS_SAS, TFS_UTS35, TFS_OK, "ddMMMyy" },
    { "SAS DATE9", "DATE9", TFS_SAS, TFS_UTS35, TFS_OK, "ddMMMy" },
    { "SAS DATE9 with period", "date9.", TFS_SAS, TFS_UTS35, TFS_OK, "ddMMMy" },
    { "SAS DATE11", "DATE11", TFS_SAS, TFS_UTS35, TFS_OK, "dd-MMM-y" },
    { "SAS DATETIME", "DATETIME", TFS_SAS, TFS_UTS35, TFS_OK, "ddMMMy:HH:mm:ss" },
    { "SAS DATETIME16", "DATETIME16", TFS_SAS, TFS_UTS35, TFS_OK, "ddMMMyy:HH:mm:ss" },
    { "SAS DATETIME with decimals", "DATETIME22.2", TFS_SAS, TFS_UTS35, TFS_OK, "ddMMMy:HH:mm:ss.SS" },
    { "SAS TIME is 24-hour", "TIME", TFS_SAS, TFS_UTS35, TFS_OK, "H:mm:ss" },
    { "SAS TIME with decimals", "TIME12.3", TFS_SAS, TFS_UTS35, TFS_OK, "H:mm:ss.SSS" },
    { "SAS TOD is 24-hour", "TOD", TFS_SAS, TFS_UTS35, TFS_OK, "HH:mm:ss" },
    { "SAS TIMEAMPM", "TIMEAMPM", TFS_SAS, TFS_UTS35, TFS_OK, "h:mm:ss a" },
    { "SAS MMYY has no day", "MMYY", TFS_SAS, TFS_UTS35, TFS_OK, "MM'M'y" },
    { "SAS MMYY5", "MMYY5", TFS_SAS, TFS_UTS35, TFS_OK, "MM'M'yy" },
    { "SAS MMYYS", "MMYYS", TFS_SAS, TFS_UTS35, TFS_OK, "MM/y" },
    { "SAS MONYY", "MONYY", TFS_SAS, TFS_UTS35, TFS_OK, "MMMyy" },
    { "SAS MONYY7", "MONYY7", TFS_SAS, TFS_UTS35, TFS_OK, "MMMy" },
    { "SAS MMDDYY", "MMDDYY", TFS_SAS, TFS_UTS35, TFS_OK, "MM/dd/yy" },
    { "SAS MMDDYY6", "MMDDYY6", TFS_SAS, TFS_UTS35, TFS_OK, "MMddyy" },
    { "SAS MMDDYY8", "MMDDYY8", TFS_SAS, TFS_UTS35, TFS_OK, "MM/dd/yy" },
    { "SAS MMDDYY10", "MMDDYY10", TFS_SAS, TFS_UTS35, TFS_OK, "MM/dd/y" },
    { "SAS MMDDYYN8", "MMDDYYN8", TFS_SAS, TFS_UTS35, TFS_OK, "MMddy" },
    { "SAS MMDDYYS10", "MMDDYYS10", TFS_SAS, TFS_UTS35, TFS_OK, "MM/dd/y" },
    { "SAS DDMMYY8", "DDMMYY8", TFS_SAS, TFS_UTS35, TFS_OK, "dd/MM/yy" },
    { "SAS DDMMYYD10", "DDMMYYD10", TFS_SAS, TFS_UTS35, TFS_OK, "dd-MM-y" },
    { "SAS YYMMDD", "YYMMDD", TFS_SAS, TFS_UTS35, TFS_OK, "yy-MM-dd" },
    { "SAS YYMMDD10", "YYMMDD10", TFS_SAS, TFS_UTS35, TFS_OK, "y-MM-dd" },
    { "SAS YYMMDDS10", "YYMMDDS10", TFS_SAS, TFS_UTS35, TFS_OK, "y/MM/dd" },
    { "SAS YYMM", "YYMM", TFS_SAS, TFS_UTS35, TFS_OK, "y'M'MM" },
    { "SAS YYQ", "YYQ", TFS_SAS, TFS_UTS35, TFS_OK, "y'Q'Q" },
    { "SAS YYQR", "YYQR", TFS_SAS, TFS_UTS35, TFS_CANT_REPRESENT, "" },
    { "SAS JULIAN", "JULIAN", TFS_SAS, TFS_POSIX, TFS_OK, "%y%j" },
    { "SAS JULIAN7", "JULIAN7", TFS_SAS, TFS_POSIX, TFS_OK, "%Y%j" },
    { "SAS YEAR2", "YEAR2", TFS_SAS, TFS_POSIX, TFS_OK, "%y" },
    { "SAS MONNAME3", "MONNAME3", TFS_SAS, TFS_POSIX, TFS_OK, "%b" },
    { "SAS DOWNAME", "DOWNAME", TFS_SAS, TFS_POSIX, TFS_OK, "%A" },
    { "SAS unknown", "NOTAFORMAT", TFS_SAS, TFS_POSIX, TFS_PARSE_ERROR, "" },

    /* SPSS */
    { "SPSS MOYR", "MOYR", TFS_SPSS, TFS_EXCEL, TFS_OK, "mmm yyyy" },
    { "SPSS DATETIME17", "DATETIME17", TFS_SPSS, TFS_UTS35, TFS_OK, "dd-MMM-y H:mm" },
    { "SPSS DATETIME20", "DATETIME20", TFS_SPSS, TFS_UTS35, TFS_OK, "dd-MMM-y H:mm:ss" },
    { "SPSS TIME5", "TIME5", TFS_SPSS, TFS_UTS35, TFS_OK, "H:mm" },
    { "SPSS TIME11.2", "TIME11.2", TFS_SPSS, TFS_UTS35, TFS_OK, "H:mm:ss.SS" },

    /* Stata */
    { "Stata UTF-8 escape", "!\xe5\xb9\xb4", TFS_STATA, TFS_UTS35, TFS_OK, "\xe5\xb9\xb4" },
    { "Stata UTF-8 escape output", "'\xe5\xb9\xb4'", TFS_UTS35, TFS_STATA, TFS_OK, "!\xe5\xb9\xb4" },
    { "Stata lower-case month", "mon", TFS_STATA, TFS_STATA, TFS_OK, "mon" },
};

static int run_oneway_tests(void) {
    int i, failures = 0;
    char tmp[200];
    for (i=0; i<sizeof(oneway_tests)/sizeof(oneway_tests[0]); i++) {
        tfs_oneway_test_t *test = &oneway_tests[i];
        tfs_error_e error;
        printf("Testing %s... ", test->name);
        memset(tmp, 'X', sizeof(tmp));
        error = tfs_convert(test->input, test->input_format, tmp, test->output_format, sizeof(tmp));
        if (error != test->error) {
            printf("Expected error %d, got %d\n", test->error, error);
            failures++;
        } else if (memchr(tmp, '\0', sizeof(tmp)) == NULL) {
            printf("Output not terminated\n");
            failures++;
        } else if (strcmp(tmp, test->output) != 0) {
            printf("Expected '%s', got '%s'\n", test->output, tmp);
            failures++;
        } else {
            printf("ok\n");
        }
    }
    return failures;
}

/* Buffers that are too small must report it and still leave a terminated string */
static int run_buffer_tests(void) {
    int failures = 0;
    size_t n;
    const char *input = "%Y-%m-%d %H:%M:%S";
    tfs_format_e output_formats[] = { TFS_EXCEL, TFS_POSIX, TFS_STATA, TFS_UTS35 };
    int i;
    printf("Testing small output buffers... ");
    for (i=0; i<sizeof(output_formats)/sizeof(output_formats[0]); i++) {
        char full[100];
        tfs_error_e error = tfs_convert(input, TFS_POSIX, full, output_formats[i], sizeof(full));
        if (error != TFS_OK) {
            printf("Error %d converting to format %d\n", error, output_formats[i]);
            failures++;
            continue;
        }
        for (n=0; n<=strlen(full)+1; n++) {
            char tmp[100];
            memset(tmp, 'X', sizeof(tmp));
            error = tfs_convert(input, TFS_POSIX, tmp, output_formats[i], n);
            if (n == strlen(full)+1) {
                if (error != TFS_OK || strcmp(tmp, full) != 0) {
                    printf("Exact-size buffer failed for format %d: error %d\n", output_formats[i], error);
                    failures++;
                }
            } else if (error != TFS_MORE_BUFFER_PLEASE) {
                printf("Buffer of %zu bytes for format %d: expected TFS_MORE_BUFFER_PLEASE, got %d\n",
                        n, output_formats[i], error);
                failures++;
            } else if (n > 0 && (memchr(tmp, '\0', n) == NULL || tmp[n] != 'X')) {
                printf("Buffer of %zu bytes for format %d: not terminated or overrun\n", n, output_formats[i]);
                failures++;
            }
        }
    }
    if (failures == 0)
        printf("ok\n");
    return failures;
}

/* Literals longer than a token holds are truncated, but stay terminated */
static int run_long_literal_tests(void) {
    int failures = 0;
    char input[400], expected[400], tmp[400];
    tfs_error_e error;
    printf("Testing long literals... ");
    memset(input, 'a', 150);
    input[150] = '\0';
    memset(expected, 'a', 99);
    expected[99] = '\0';
    error = tfs_convert(input, TFS_POSIX, tmp, TFS_POSIX, sizeof(tmp));
    if (error != TFS_OK || strcmp(tmp, expected) != 0) {
        printf("POSIX literal: error %d\n", error);
        failures++;
    }
    input[0] = '"';
    memset(input+1, 'a', 150);
    input[151] = '"';
    input[152] = '\0';
    error = tfs_convert(input, TFS_EXCEL, tmp, TFS_POSIX, sizeof(tmp));
    if (error != TFS_OK || strcmp(tmp, expected) != 0) {
        printf("Excel literal: error %d\n", error);
        failures++;
    }
    input[0] = '\'';
    input[151] = '\'';
    error = tfs_convert(input, TFS_UTS35, tmp, TFS_POSIX, sizeof(tmp));
    if (error != TFS_OK || strcmp(tmp, expected) != 0) {
        printf("UTS35 literal: error %d\n", error);
        failures++;
    }
    if (failures == 0)
        printf("ok\n");
    return failures;
}

int main(int argc, char *argv[]) {
    int i, j, k;
    int total_failures = 0, test_failures = 0;
    int total_tests = 0;
    int error = 0;
    unsigned short mask;
    char *buf1 = NULL, *buf2 = NULL;
    tfs_format_e input_format, output_format;
    char tmp[100];
    for (i=0; i<sizeof(all_tests)/sizeof(all_tests[0]); i++) {
        tfs_test_t *test = &all_tests[i];
        printf("Testing %s... ", test->name);
        test_failures = 0;
        for (j=0; j<sizeof(test_input_formats)/sizeof(test_input_formats[0]); j++) {
            mask = 0;
            input_format = test_input_formats[j];
            if (input_format == TFS_EXCEL) {
                buf1 = test->excel;
            } else if (input_format == TFS_POSIX) {
                buf1 = test->posix;
            } else if (input_format == TFS_STATA) {
                buf1 = test->stata;
            } else {
                buf1 = test->uts35;
            }
            if (!buf1[0])
                continue;

            error = tfs_field_mask(buf1, input_format, &mask);
            if (error) {
                printf("Error parsing %s: %d\n", buf1, error);
                test_failures++;
            } else if (mask != test->mask) {
                printf("Bad mask for '%s'. Expected: %xh Got: %xh\n", buf1, test->mask, mask);
                test_failures++;
            }
            total_tests++;

            for (k=0; k<sizeof(test_output_formats)/sizeof(test_output_formats[0]); k++) {
                output_format = test_output_formats[k];
                if (output_format == TFS_EXCEL) {
                    buf2 = test->excel;
                } else if (output_format == TFS_POSIX) {
                    buf2 = test->posix;
                } else if (output_format == TFS_STATA) {
                    buf2 = test->stata;
                } else {
                    buf2 = test->uts35;
                }
                if (!buf2[0])
                    continue;

                memset(tmp, 0, sizeof(tmp));

                error = tfs_convert(buf1, input_format, tmp, output_format, sizeof(tmp));

                if (error) {
                    printf("Error converting \"%s\" (%d->%d): %d\n", buf1, input_format, output_format, error);
                    test_failures++;
                } else if (strcmp(buf2, tmp) != 0) {
                    printf("Bad conversion for '%s'. Expected: '%s' Got: '%s'\n", buf1, buf2, tmp);
                    test_failures++;
                }
                total_tests++;
            }
        }
        if (test_failures) {
            printf("%d failed\n", test_failures);
        } else {
            printf("ok\n");
        }
        total_failures += test_failures;
    }

    test_failures = run_oneway_tests();
    total_tests += sizeof(oneway_tests)/sizeof(oneway_tests[0]);
    total_failures += test_failures;

    test_failures = run_buffer_tests();
    total_tests++;
    total_failures += test_failures;

    test_failures = run_long_literal_tests();
    total_tests++;
    total_failures += test_failures;

    printf("\n\nTotal failures: %d (out of %d tests)\n", total_failures, total_tests);
    if (total_failures)
        return 1;

    return 0;
}
