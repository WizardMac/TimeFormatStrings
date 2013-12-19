
tfs_token_lookup_t stata_lookup[] = {
    { .text = "CC",    .token = { .time_unit = TFS_CENTURY, .style = TFS_2DIGIT } },
    { .text = "cc",    .token = { .time_unit = TFS_CENTURY, .style = TFS_NUMBER } },

    { .text = "YY",    .token = { .time_unit = TFS_YEAR, .relative_to = TFS_CENTURY, .style = TFS_2DIGIT } },
    { .text = "yy",    .token = { .time_unit = TFS_YEAR, .relative_to = TFS_CENTURY, .style = TFS_NUMBER } },

    { .text = "JJJ",   .token = { .time_unit = TFS_DAY, .relative_to = TFS_YEAR, .style = TFS_NUMBER, .pad_len = 3, .pad_char = '0' } },
    { .text = "jjj",   .token = { .time_unit = TFS_DAY, .relative_to = TFS_YEAR, .style = TFS_NUMBER } },

    { .text = "Mon",   .token = { .time_unit = TFS_MONTH, .style = TFS_ABBREV } },
    { .text = "Month", .token = { .time_unit = TFS_MONTH, .style = TFS_FULL } },
    { .text = "mon",   .token = { .time_unit = TFS_MONTH, .style = TFS_ABBREV, .lowercase = 1 } },
    { .text = "month", .token = { .time_unit = TFS_MONTH, .style = TFS_FULL, .lowercase = 1 } },
    { .text = "NN",    .token = { .time_unit = TFS_MONTH, .style = TFS_2DIGIT } },
    { .text = "nn",    .token = { .time_unit = TFS_MONTH, .style = TFS_NUMBER } },

    { .text = "DD",    .token = { .time_unit = TFS_DAY, .relative_to = TFS_MONTH, .style = TFS_2DIGIT } },
    { .text = "dd",    .token = { .time_unit = TFS_DAY, .relative_to = TFS_MONTH, .style = TFS_NUMBER } },

    { .text = "DAYNAME",.token= { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_FULL } },
    { .text = "Dayname",.token= { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_FULL } },

    { .text = "Day",   .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_ABBREV } },
    { .text = "Da",    .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_SHORT } },

    { .text = "day",   .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_ABBREV, .lowercase = 1 } },
    { .text = "da",    .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_SHORT, .lowercase = 1 } },

    { .text = "h",     .token = { .time_unit = TFS_HALF_YEAR, .style = TFS_NUMBER } },
    { .text = "q",     .token = { .time_unit = TFS_QUARTER,   .style = TFS_NUMBER } },
    { .text = "WW",    .token = { .time_unit = TFS_WEEK, .relative_to = TFS_YEAR, .style = TFS_2DIGIT } },
    { .text = "ww",    .token = { .time_unit = TFS_WEEK, .relative_to = TFS_YEAR, .style = TFS_NUMBER } },

    { .text = "HH",    .token = { .time_unit = TFS_HOUR, .relative_to = TFS_DAY, .style = TFS_2DIGIT } },
    { .text = "Hh",    .token = { .time_unit = TFS_HOUR, .relative_to = TFS_PERIOD, .style = TFS_2DIGIT, .start_at_one = 1 } },

    { .text = "hH",    .token = { .time_unit = TFS_HOUR, .relative_to = TFS_DAY, .style = TFS_NUMBER } },
    { .text = "hh",    .token = { .time_unit = TFS_HOUR, .relative_to = TFS_PERIOD, .style = TFS_NUMBER, .start_at_one = 1 } },

    { .text = "MM",    .token = { .time_unit = TFS_MINUTE, .style = TFS_2DIGIT } },
    { .text = "mm",    .token = { .time_unit = TFS_MINUTE, .style = TFS_NUMBER } },

    { .text = "SS",    .token = { .time_unit = TFS_SECOND, .style = TFS_2DIGIT } },
    { .text = "ss",    .token = { .time_unit = TFS_SECOND, .style = TFS_NUMBER } },

    { .text = "am",    .token = { .time_unit = TFS_PERIOD, .style = TFS_ABBREV, .lowercase = 1 } },
    { .text = "a.m.",  .token = { .time_unit = TFS_PERIOD, .style = TFS_ABBREV, .lowercase = 1, .add_dots = 1 } },
    { .text = "AM",    .token = { .time_unit = TFS_PERIOD, .style = TFS_ABBREV, .uppercase = 1 } },
    { .text = "A.M.",  .token = { .time_unit = TFS_PERIOD, .style = TFS_ABBREV, .uppercase = 1, .add_dots = 1 } }
};
