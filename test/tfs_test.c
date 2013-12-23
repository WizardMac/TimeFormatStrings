
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tfs.h"

tfs_format_e test_input_formats[] = { TFS_EXCEL, TFS_STATA, TFS_UTS35 };
tfs_format_e test_output_formats[] = { TFS_EXCEL, TFS_STATA, TFS_UTS35 };

typedef struct tfs_test_s {
    char            name[50];

    char            excel[40];
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
        .mask = TFS_CENTURY
    },

    {
        .name = "Year",
        .excel = "yyyy",
        .stata = "ccYY",
        .uts35 = "y",
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
        .mask = TFS_YEAR
    },
    {
        .name = "Week-numbering year",
        .uts35 = "Y",
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
        .mask = TFS_MONTH
    },
    {
        .name = "Month abbreviation",
        .excel = "mmm",
        .stata = "Mon",
        .uts35 = "MMM",
        .mask = TFS_MONTH
    },
    {
        .name = "Month name",
        .excel = "mmmm",
        .stata = "Month",
        .uts35 = "MMMM",
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
        .stata = "mon",
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
        .mask = TFS_DAY
    },
    {
        .name = "Day of month (zero-padded)",
        .excel = "dd",
        .stata = "DD",
        .uts35 = "dd",
        .mask = TFS_DAY
    },
    {
        .name = "Day of week abbreviation",
        .excel = "ddd",
        .stata = "Day",
        .uts35 = "EEE",
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
        .mask = TFS_HOUR
    },

    {
        .name = "Hour [01-12]",
        .uts35 = "hh",
        .stata = "Hh",
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
        .mask = TFS_HOUR
    },
    {
        .name = "Hour [00-23]",
        .uts35 = "HH",
        .stata = "HH",
        .excel = "hh",
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
        .mask = TFS_SECOND
    },

    {
        .name = "MM/DD/YY",
        .excel = "mm/dd/yy",
        .stata = "NN/DD/YY",
        .uts35 = "MM/dd/yy",
        .mask = TFS_MONTH | TFS_DAY | TFS_YEAR
    },

    {
        .name = "MM/DD/YYYY",
        .excel = "mm/dd/yyyy",
        .stata = "NN/DD/ccYY",
        .uts35 = "MM/dd/y",
        .mask = TFS_MONTH | TFS_DAY | TFS_YEAR
    },

    {
        .name = "Hour, minute, second",
        .excel = "h:mm:ss AM/PM",
        .stata = "hh:MM:SS_AM",
        .uts35 = "h:mm:ss a",
        .mask = TFS_HOUR | TFS_MINUTE | TFS_SECOND | TFS_PERIOD
    },

    {
        .name = "Date at 24-hour time",
        .excel = "mm/dd/yyyy \"at\" h:mm:ss",
        .stata = "NN/DD/ccYY_!a!t_hH:MM:SS",
        .uts35 = "MM/dd/y 'at' H:mm:ss",
        .mask = TFS_MONTH | TFS_DAY | TFS_YEAR | TFS_HOUR | TFS_MINUTE | TFS_SECOND
    },

    {
        .name = "String literal",
        .excel = "\"hello\"",
        .stata = "!h!e!l!l!o",
        .uts35 = "'hello'",
        .mask = 0
    },

    {
        .name = "String literal with single-quote",
        .excel = "\"Hello,\" \"O\"'\"Malley\"",
        .stata = "!H!e!l!l!o,_!O!'!M!a!l!l!e!y",
        .uts35 = "'Hello', 'O''Malley'",
        .mask = 0
    },

    {
        .name = "String literal with double-quote",
        .excel = "\"\\\"Yikes\"!\"\\\"\"",
        .stata = "!\"!Y!i!k!e!s!!!\"",
        .uts35 = "\"'Yikes'!\"",
        .mask = 0
    }
};

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
                } else if (output_format == TFS_STATA) {
                    buf2 = test->stata;
                } else {
                    buf2 = test->uts35;
                }
                if (!buf2[0])
                    continue;

                memset(tmp, 0, sizeof(tmp));

                error = tfs_convert(buf1, input_format, tmp, output_format);

                if (error) {
                    printf("Error converting %s: %d\n", buf1, error);
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
    printf("\n\nTotal failures: %d (out of %d tests)\n", total_failures, total_tests);
    if (total_failures)
        return 1;

    return 0;
}
