
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tfs.h"
#include "tfs_internal.h"
#include "tfs_uts35_parser.h"

static tfs_token_lookup_t uts35_tokens[] = {
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

    { .text = "Q",     .token = { .time_unit = TFS_QUARTER, .relative_to = TFS_YEAR, .style = TFS_NUMBER } },
    { .text = "QQ",    .token = { .time_unit = TFS_QUARTER, .relative_to = TFS_YEAR, .style = TFS_2DIGIT } },
    { .text = "QQQ",   .token = { .time_unit = TFS_QUARTER, .relative_to = TFS_YEAR, .style = TFS_ABBREV } },
    { .text = "QQQQ",  .token = { .time_unit = TFS_QUARTER, .relative_to = TFS_YEAR, .style = TFS_FULL } },

    { .text = "q",     .token = { .time_unit = TFS_QUARTER, .style = TFS_NUMBER, .is_standalone = 1 } },
    { .text = "qq",    .token = { .time_unit = TFS_QUARTER, .style = TFS_2DIGIT, .is_standalone = 1 } },
    { .text = "qqq",   .token = { .time_unit = TFS_QUARTER, .style = TFS_ABBREV, .is_standalone = 1 } },
    { .text = "qqqq",  .token = { .time_unit = TFS_QUARTER, .style = TFS_FULL,   .is_standalone = 1 } },

    { .text = "M",     .token = { .time_unit = TFS_MONTH, .relative_to = TFS_YEAR, .style = TFS_NUMBER } },
    { .text = "MM",    .token = { .time_unit = TFS_MONTH, .relative_to = TFS_YEAR, .style = TFS_2DIGIT } },
    { .text = "MMM",   .token = { .time_unit = TFS_MONTH, .relative_to = TFS_YEAR, .style = TFS_ABBREV } },
    { .text = "MMMM",  .token = { .time_unit = TFS_MONTH, .relative_to = TFS_YEAR, .style = TFS_FULL   } },
    { .text = "MMMMM", .token = { .time_unit = TFS_MONTH, .relative_to = TFS_YEAR, .style = TFS_NARROW } },

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

    { .text = "D",     .token = { .time_unit = TFS_DAY, .relative_to = TFS_YEAR, .style = TFS_NUMBER } },
    { .text = "DD",    .token = { .time_unit = TFS_DAY, .relative_to = TFS_YEAR, .style = TFS_NUMBER, .pad_len = 2, .pad_char = '0' } },
    { .text = "DDD",   .token = { .time_unit = TFS_DAY, .relative_to = TFS_YEAR, .style = TFS_NUMBER, .pad_len = 3, .pad_char = '0' } },

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
    { .text = "EE",    .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_ABBREV } },
    { .text = "EEE",   .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_ABBREV } },
    { .text = "EEEE",  .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_FULL } },
    { .text = "EEEEE", .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_NARROW } },
    { .text = "EEEEEE",.token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_SHORT } },

    { .text = "e",     .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_NUMBER, .is_local = 1 } },
    { .text = "ee",    .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_NUMBER, .is_local = 1 } },
    { .text = "eee",   .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_ABBREV, .is_local = 1 } },
    { .text = "eeee",  .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_FULL, .is_local = 1 } },
    { .text = "eeeee", .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_NARROW, .is_local = 1 } },
    { .text = "eeeeee",.token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_SHORT, .is_local = 1 } },

    { .text = "c",     .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_NUMBER, .is_standalone = 1 } },
    { .text = "cc",    .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_NUMBER, .is_standalone = 1 } },
    { .text = "ccc",   .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_ABBREV, .is_standalone = 1 } },
    { .text = "cccc",  .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_FULL, .is_standalone = 1 } },
    { .text = "ccccc", .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_NARROW, .is_standalone = 1 } },
    { .text = "cccccc",.token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_SHORT, .is_standalone = 1 } },

    { .text = "a",     .token = { .time_unit = TFS_PERIOD, .relative_to = TFS_DAY, .style = TFS_ABBREV, .uppercase = 1 } },

    { .text = "h",     .token = { .time_unit = TFS_HOUR, .relative_to = TFS_PERIOD, .style = TFS_NUMBER, .start_at_one = 1 } },
    { .text = "hh",    .token = { .time_unit = TFS_HOUR, .relative_to = TFS_PERIOD, .style = TFS_2DIGIT, .start_at_one = 1 } },
    { .text = "H",     .token = { .time_unit = TFS_HOUR, .relative_to = TFS_DAY, .style = TFS_NUMBER, .start_at_one = 0 } },
    { .text = "HH",    .token = { .time_unit = TFS_HOUR, .relative_to = TFS_DAY, .style = TFS_2DIGIT, .start_at_one = 0 } },
    { .text = "K",     .token = { .time_unit = TFS_HOUR, .relative_to = TFS_PERIOD, .style = TFS_NUMBER, .start_at_one = 0 } },
    { .text = "KK",    .token = { .time_unit = TFS_HOUR, .relative_to = TFS_PERIOD, .style = TFS_2DIGIT, .start_at_one = 0 } },
    { .text = "k",     .token = { .time_unit = TFS_HOUR, .relative_to = TFS_DAY, .style = TFS_NUMBER, .start_at_one = 1 } },
    { .text = "kk",    .token = { .time_unit = TFS_HOUR, .relative_to = TFS_DAY, .style = TFS_2DIGIT, .start_at_one = 1 } },

    { .text = "m",     .token = { .time_unit = TFS_MINUTE, .relative_to = TFS_HOUR, .style = TFS_NUMBER } },
    { .text = "mm",    .token = { .time_unit = TFS_MINUTE, .relative_to = TFS_HOUR, .style = TFS_2DIGIT } },

    { .text = "s",     .token = { .time_unit = TFS_SECOND, .relative_to = TFS_MINUTE, .style = TFS_NUMBER } },
    { .text = "ss",    .token = { .time_unit = TFS_SECOND, .relative_to = TFS_MINUTE, .style = TFS_2DIGIT } },

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

static int handle_code(const char *code, size_t len, void *ctx) {
    tfs_token_array_t *tokens = (void *)ctx;

    int i;
    tfs_token_t *new_token = NULL;
    for (i=0; i<sizeof(uts35_tokens)/sizeof(uts35_tokens[0]); i++) {
        if (len == strlen(uts35_tokens[i].text) && strncmp(uts35_tokens[i].text, code, len) == 0) {
            new_token = tfs_append_token(tokens);
            memcpy(new_token, &uts35_tokens[i].token, sizeof(tfs_token_t));
            break;
        }
    }

    return 0;
}

static int handle_literal(const char *literal, size_t len, void *ctx) {
    tfs_token_array_t *tokens = (void *)ctx;

    int in_i = 0, out_i = 0;
    int was_quote = 0;
    tfs_token_t *new_token = tfs_append_token(tokens);
    new_token->is_literal = 1;
    char *out_text = new_token->text;

    if (literal[0] == '\'') {
        in_i = 1;
        len--;
    }

    /* TODO bounds check */
    while (in_i < len) {
        if (literal[in_i] == '\'') {
            if (was_quote) {
                out_text[out_i++] = literal[in_i];
                was_quote = 0;
            } else {
                was_quote = 1;
            }
        } else {
            out_text[out_i++] = literal[in_i];
            was_quote = 0;
        }
        in_i++;
    }
    out_text[out_i] = '\0';

    return 0;
}

tfs_token_array_t *tfs_uts35_parse(const char *bytes, int *outError) {
    tfs_token_array_t *token_array = tfs_init_token_array(10);
    int error = 0;
    size_t len = strlen(bytes);

    error = tfs_parse_uts35_format_string_internal((const u_char *)bytes, len,
        &handle_literal, &handle_code, token_array);

    if (error) {
        *outError = error;
        tfs_free_token_array(token_array);
        return NULL;
    }

    int i;
    for (i=0; i<token_array->count-1; i++) {
        tfs_token_t *token1 = &token_array->tokens[i];
        tfs_token_t *token2 = &token_array->tokens[i+1];
        if (token1->is_literal && token1->text[0] == '.' && token1->text[1] == '\0' &&
                token2->time_unit == TFS_FRACTIONAL_SECOND) {
            token1->text[0] = '\0';
            token2->add_dots = 1;
        }
    }

    return token_array;
}

static char *format_token(char *outbuf, tfs_token_t *token) {
    char *p = outbuf;
    if (token->time_unit == TFS_FRACTIONAL_SECOND && token->add_dots) {
        p = stpcpy(p, ".");
        size_t len = token->truncate_len;
        while (len--) {
            p = stpcpy(p, "S");
        }
    } else {
        char *match = tfs_match_token(uts35_tokens, sizeof(uts35_tokens)/sizeof(uts35_tokens[0]), token);
        if (match) {
            p = stpcpy(p, match);
        } else {
            p = NULL;
        }
    }
    return p;
}

int tfs_uts35_generate(char *format, tfs_token_array_t *token_array) {
    int i;
    char *out = format;
    int is_quoting = 0;
    int error = 0;
    for (i=0; i<token_array->count; i++) {
        tfs_token_t *token = &token_array->tokens[i];
        if (token->is_literal) {
            char *in = token->text;
            while (*in) {
                if (is_quoting) {
                    if (*in == '\'') {
                        *out++ = '\'';
                    } else if ((*in < 'a' || *in > 'z') && (*in < 'A' || *in > 'Z')) {
                        *out++ = '\'';
                        is_quoting = 0;
                    }
                    *out++ = *in;
                } else {
                    if ((*in >= 'a' && *in <= 'z') || (*in >= 'A' && *in <= 'Z')) {
                        *out++ = '\'';
                        is_quoting = 1;
                    }
                    *out++ = *in;
                }
                in++;
            }
        } else if (token->time_unit) {
            if (is_quoting) {
                *out++ = '\'';
                is_quoting = 0;
            }
            out = format_token(out, token);
            if (out == NULL) {
                error = TFS_CANT_REPRESENT;
                break;
            }
        }
    }
    if (is_quoting) {
        *out++ = '\'';
    }
    return error;
}
