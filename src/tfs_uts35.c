
tfs_token_lookup_t uts35_tokens[] = {
    { .text = "G",     .token = { .time_unit = TFS_ERA, .style = TFS_ABBREV } },
    { .text = "GG",    .token = { .time_unit = TFS_ERA, .style = TFS_ABBREV } },
    { .text = "GGG",   .token = { .time_unit = TFS_ERA, .style = TFS_ABBREV } },
    { .text = "GGGG",  .token = { .time_unit = TFS_ERA, .style = TFS_LONG } },
    { .text = "GGGGG", .token = { .time_unit = TFS_ERA, .style = TFS_NARROW } },

    { .text = "y",     .token = { .time_unit = TFS_YEAR, .relative_to = TFS_ERA, .style = TFS_NUMBER } },
    { .text = "yy",    .token = { .time_unit = TFS_YEAR, .relative_to = TFS_CENTURY, .style = TFS_2DIGIT } },
    { .text = "yyy",   .token = { .time_unit = TFS_YEAR, .relative_to = TFS_ERA, .style = TFS_NUMBER, .pad_len = 3, .pad_char = '0' } },
    { .text = "yyyy",  .token = { .time_unit = TFS_YEAR, .relative_to = TFS_ERA, .style = TFS_NUMBER, .pad_len = 4, .pad_char = '0' } },
    { .text = "yyyyy", .token = { .time_unit = TFS_YEAR, .relative_to = TFS_ERA, .style = TFS_NUMBER, .pad_len = 5, .pad_char = '0' } },

    { .text = "Y",     .token = { .time_unit = TFS_YEAR, .relative_to = TFS_ERA, .style = TFS_NUMBER, .modifier = TFS_ISO_WEEK_NUMBERING_YEAR } },
    { .text = "YY",    .token = { .time_unit = TFS_YEAR, .relative_to = TFS_CENTURY, .style = TFS_2DIGIT, .modifier = TFS_ISO_WEEK_NUMBERING_YEAR } },
    { .text = "YYY",   .token = { .time_unit = TFS_YEAR, .relative_to = TFS_ERA, .style = TFS_NUMBER, .pad_len = 3, .pad_char = '0',
                           .modifier = TFS_ISO_WEEK_NUMBERING_YEAR } },
    { .text = "YYYY",  .token = { .time_unit = TFS_YEAR, .relative_to = TFS_ERA, .style = TFS_NUMBER, .pad_len = 4, .pad_char = '0',
                           .modifier = TFS_ISO_WEEK_NUMBERING_YEAR } },
    { .text = "YYYYY", .token = { .time_unit = TFS_YEAR, .relative_to = TFS_ERA, .style = TFS_NUMBER, .pad_len = 5, .pad_char = '0',
                           .modifier = TFS_ISO_WEEK_NUMBERING_YEAR } },

    { .text = "u",     .token = { .time_unit = TFS_YEAR, .style = TFS_NUMBER } },
    { .text = "uu",    .token = { .time_unit = TFS_YEAR, .style = TFS_NUMBER, .pad_len = 2, .pad_char = '0' } },
    { .text = "uuu",   .token = { .time_unit = TFS_YEAR, .style = TFS_NUMBER, .pad_len = 3, .pad_char = '0' } },
    { .text = "uuuu",  .token = { .time_unit = TFS_YEAR, .style = TFS_NUMBER, .pad_len = 4, .pad_char = '0' } },
    { .text = "uuuuu", .token = { .time_unit = TFS_YEAR, .style = TFS_NUMBER, .pad_len = 5, .pad_char = '0' } },

    { .text = "U",     .token = { .time_unit = TFS_YEAR, .style = TFS_ABBREV, .modifier = TFS_CYCLIC_YEAR } },
    { .text = "UU",    .token = { .time_unit = TFS_YEAR, .style = TFS_ABBREV, .modifier = TFS_CYCLIC_YEAR } },
    { .text = "UUU",   .token = { .time_unit = TFS_YEAR, .style = TFS_ABBREV, .modifier = TFS_CYCLIC_YEAR } },
    { .text = "UUUU",  .token = { .time_unit = TFS_YEAR, .style = TFS_FULL,   .modifier = TFS_CYCLIC_YEAR } },
    { .text = "UUUUU", .token = { .time_unit = TFS_YEAR, .style = TFS_NARROW, .modifier = TFS_CYCLIC_YEAR } },

    { .text = "Q",     .token = { .time_unit = TFS_QUARTER, .style = TFS_NUMBER } },
    { .text = "QQ",    .token = { .time_unit = TFS_QUARTER, .style = TFS_2DIGIT } },
    { .text = "QQQ",   .token = { .time_unit = TFS_QUARTER, .style = TFS_ABBREV } },
    { .text = "QQQQ",  .token = { .time_unit = TFS_QUARTER, .style = TFS_FULL } },

    { .text = "q",     .token = { .time_unit = TFS_QUARTER, .style = TFS_NUMBER, .is_standalone = 1 } },
    { .text = "qq",    .token = { .time_unit = TFS_QUARTER, .style = TFS_2DIGIT, .is_standalone = 1 } },
    { .text = "qqq",   .token = { .time_unit = TFS_QUARTER, .style = TFS_ABBREV, .is_standalone = 1 } },
    { .text = "qqqq",  .token = { .time_unit = TFS_QUARTER, .style = TFS_FULL,   .is_standalone = 1 } },

    { .text = "M",     .token = { .time_unit = TFS_MONTH, .style = TFS_NUMBER } },
    { .text = "MM",    .token = { .time_unit = TFS_MONTH, .style = TFS_2DIGIT } },
    { .text = "MMM",   .token = { .time_unit = TFS_MONTH, .style = TFS_ABBREV } },
    { .text = "MMMM",  .token = { .time_unit = TFS_MONTH, .style = TFS_FULL   } },
    { .text = "MMMMM", .token = { .time_unit = TFS_MONTH, .style = TFS_NARROW } },

    { .text = "L",     .token = { .time_unit = TFS_MONTH, .style = TFS_NUMBER, .is_standalone = 1 } },
    { .text = "LL",    .token = { .time_unit = TFS_MONTH, .style = TFS_2DIGIT, .is_standalone = 1 } },
    { .text = "LLL",   .token = { .time_unit = TFS_MONTH, .style = TFS_ABBREV, .is_standalone = 1 } },
    { .text = "LLLL",  .token = { .time_unit = TFS_MONTH, .style = TFS_FULL,   .is_standalone = 1 } },
    { .text = "LLLLL", .token = { .time_unit = TFS_MONTH, .style = TFS_NARROW, .is_standalone = 1 } },

    { .text = "w",     .token = { .time_unit = TFS_WEEK, .relative_to = TFS_YEAR, .style = TFS_NUMBER } },
    { .text = "ww",    .token = { .time_unit = TFS_WEEK, .relative_to = TFS_YEAR, .style = TFS_2DIGIT } },

    { .text = "W",     .token = { .time_unit = TFS_WEEK, .relative_to = TFS_MONTH, .style = TFS_NUMBER } },
    
    { .text = "d",     .token = { .time_unit = TFS_DAY, .relative_to = TFS_MONTH, .style = TFS_NUMBER } },
    { .text = "dd",    .token = { .time_unit = TFS_DAY, .relative_to = TFS_MONTH, .style = TFS_2DIGIT } },

    { .text = "D"      .token = { .time_unit = TFS_DAY, .relative_to = TFS_YEAR, .style = TFS_NUMBER } },
    { .text = "DD"     .token = { .time_unit = TFS_DAY, .relative_to = TFS_YEAR, .style = TFS_2DIGIT } },
    { .text = "DDD"    .token = { .time_unit = TFS_DAY, .relative_to = TFS_YEAR, .style = TFS_NUMBER, .pad_len = 3, .pad_char = '0' } },

    { .text = "F",     .token = { .time_unit = TFS_DAY, .relative_to = TFS_MONTH, .style = TFS_NUMBER, .modifier = TFS_DAY_OF_WEEK_IN_MONTH } },

    { .text = "g",     .token = { .time_unit = TFS_DAY, .relative_to = TFS_ERA, .style = TFS_NUMBER } },
    { .text = "gg",    .token = { .time_unit = TFS_DAY, .relative_to = TFS_ERA, .style = TFS_NUMBER,
                                .pad_len = 2, .pad_char = '0' } },
    { .text = "ggg",   .token = { .time_unit = TFS_DAY, .relative_to = TFS_ERA, .style = TFS_NUMBER,
                                .pad_len = 3, .pad_char = '0' } },
    { .text = "gggg",  .token = { .time_unit = TFS_DAY, .relative_to = TFS_ERA, .style = TFS_NUMBER,
                                .pad_len = 4, .pad_char = '0' } },
    { .text = "ggggg", .token = { .time_unit = TFS_DAY, .relative_to = TFS_ERA, .style = TFS_NUMBER,
                                .pad_len = 5, .pad_char = '0' } },
    { .text = "gggggg",.token = { .time_unit = TFS_DAY, .relative_to = TFS_ERA, .style = TFS_NUMBER,
                                .pad_len = 6, .pad_char = '0' } },
    { .text = "ggggggg",.token= { .time_unit = TFS_DAY, .relative_to = TFS_ERA, .style = TFS_NUMBER,
                                .pad_len = 7, .pad_char = '0' } },

    { .text = "E",     .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_ABBREV } },
    { .text = "EE"     .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_ABBREV } },
    { .text = "EEE"    .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_ABBREV } },
    { .text = "EEEE"   .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_FULL } },
    { .text = "EEEEE"  .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_NARROW } },
    { .text = "EEEEEE" .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_SHORT } },

    { .text = "e",     .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_NUMBER } },
    { .text = "ee"     .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_NUMBER } },
    { .text = "eee"    .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_ABBREV } },
    { .text = "eeee"   .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_FULL } },
    { .text = "eeeee"  .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_NARROW } },
    { .text = "eeeeee" .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_SHORT } },

    { .text = "c",     .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_NUMBER, .is_standalone = 1 } },
    { .text = "cc"     .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_NUMBER, .is_standalone = 1 } },
    { .text = "ccc"    .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_ABBREV, .is_standalone = 1 } },
    { .text = "cccc"   .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_FULL, .is_standalone = 1 } },
    { .text = "ccccc"  .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_NARROW, .is_standalone = 1 } },
    { .text = "cccccc" .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_SHORT, .is_standalone = 1 } },

    { .text = "a",     .token = { .time_unit = TFS_PERIOD, .style = TFS_ABBREV, .uppercase = 1 } },

    { .text = "h",     .token = { .time_unit = TFS_HOUR, .relative_to = TFS_PERIOD, .style = TFS_NUMBER, .start_at_one = 1 } },
    { .text = "hh",    .token = { .time_unit = TFS_HOUR, .relative_to = TFS_PERIOD, .style = TFS_2DIGIT, .start_at_one = 1 } },
    { .text = "H",     .token = { .time_unit = TFS_HOUR, .relative_to = TFS_DAY, .style = TFS_NUMBER, .start_at_one = 0 } },
    { .text = "HH",    .token = { .time_unit = TFS_HOUR, .relative_to = TFS_DAY, .style = TFS_2DIGIT, .start_at_one = 0 } },
    { .text = "K",     .token = { .time_unit = TFS_HOUR, .relative_to = TFS_PERIOD, .style = TFS_NUMBER, .start_at_one = 0 } },
    { .text = "KK",    .token = { .time_unit = TFS_HOUR, .relative_to = TFS_PERIOD, .style = TFS_2DIGIT, .start_at_one = 0 } },
    { .text = "k",     .token = { .time_unit = TFS_HOUR, .relative_to = TFS_DAY, .style = TFS_NUMBER, .start_at_one = 1 } },
    { .text = "kk",    .token = { .time_unit = TFS_HOUR, .relative_to = TFS_DAY, .style = TFS_2DIGIT, .start_at_one = 1 } },

    { .text = "m",     .token = { .time_unit = TFS_MINUTE, .style = TFS_NUMBER } },
    { .text = "mm",    .token = { .time_unit = TFS_MINUTE, .style = TFS_2DIGIT } },

    { .text = "s",     .token = { .time_unit = TFS_SECOND, .style = TFS_NUMBER } },
    { .text = "ss"     .token = { .time_unit = TFS_SECOND, .style = TFS_2DIGIT } },

    { .text = "S",     .token = { .time_unit = TFS_FRACTIONAL_SECOND, .style = TFS_NUMBER, .truncate_len = 1 } },
    { .text = "SS",    .token = { .time_unit = TFS_FRACTIONAL_SECOND, .style = TFS_NUMBER, .truncate_len = 2 } },
    { .text = "SSS",   .token = { .time_unit = TFS_FRACTIONAL_SECOND, .style = TFS_NUMBER, .truncate_len = 3 } },
    { .text = "SSSS",  .token = { .time_unit = TFS_FRACTIONAL_SECOND, .style = TFS_NUMBER, .truncate_len = 4 } },
    { .text = "SSSSS", .token = { .time_unit = TFS_FRACTIONAL_SECOND, .style = TFS_NUMBER, .truncate_len = 5 } },
    { .text = "SSSSSS",.token = { .time_unit = TFS_FRACTIONAL_SECOND, .style = TFS_NUMBER, .truncate_len = 6 } },

    { .text = "A",     .token = { .time_unit = TFS_MILLISECOND, .relative_to = TFS_DAY, .style = TFS_NUMBER } },
    { .text = "AA",    .token = { .time_unit = TFS_MILLISECOND, .relative_to = TFS_DAY, .style = TFS_NUMBER,
                                .pad_len = 2, .pad_char = '0' } },
    { .text = "AAA",   .token = { .time_unit = TFS_MILLISECOND, .relative_to = TFS_DAY, .style = TFS_NUMBER,
                                .pad_len = 3, .pad_char = '0' } },
    { .text = "AAAA",  .token = { .time_unit = TFS_MILLISECOND, .relative_to = TFS_DAY, .style = TFS_NUMBER,
                                .pad_len = 4, .pad_char = '0' } },
    { .text = "AAAAA", .token = { .time_unit = TFS_MILLISECOND, .relative_to = TFS_DAY, .style = TFS_NUMBER,
                                .pad_len = 5, .pad_char = '0' } },
    { .text = "AAAAAA",.token = { .time_unit = TFS_MILLISECOND, .relative_to = TFS_DAY, .style = TFS_NUMBER,
                                .pad_len = 6, .pad_char = '0' } },
    { .text = "AAAAAAA",.token = { .time_unit = TFS_MILLISECOND, .relative_to = TFS_DAY, .style = TFS_NUMBER,
                                .pad_len = 7, .pad_char = '0' } },
    { .text = "AAAAAAAA",.token = { .time_unit = TFS_MILLISECOND, .relative_to = TFS_DAY, .style = TFS_NUMBER,
                                .pad_len = 8, .pad_char = '0' } }

    /* TODO timezones */
};
