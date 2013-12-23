
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

#include "tfs.h"
#include "tfs_token.h"
#include "tfs_stata.h"
#include "tfs_stata_parser.h"

tfs_token_lookup_t stata_tokens[] = {
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

    { .text = "DAYNAME",.token= { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_FULL, .is_aligned = 1 } },
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

    { .text = ".s",    .token = { .time_unit = TFS_FRACTIONAL_SECOND, .style = TFS_NUMBER, .truncate_len = 1, .add_dots = 1 } },
    { .text = ".ss",   .token = { .time_unit = TFS_FRACTIONAL_SECOND, .style = TFS_NUMBER, .truncate_len = 2, .add_dots = 1 } },
    { .text = ".sss",  .token = { .time_unit = TFS_FRACTIONAL_SECOND, .style = TFS_NUMBER, .truncate_len = 3, .add_dots = 1 } },

    { .text = "am",    .token = { .time_unit = TFS_PERIOD, .style = TFS_ABBREV, .lowercase = 1 } },
    { .text = "a.m.",  .token = { .time_unit = TFS_PERIOD, .style = TFS_ABBREV, .lowercase = 1, .add_dots = 1 } },
    { .text = "AM",    .token = { .time_unit = TFS_PERIOD, .style = TFS_ABBREV, .uppercase = 1 } },
    { .text = "A.M.",  .token = { .time_unit = TFS_PERIOD, .style = TFS_ABBREV, .uppercase = 1, .add_dots = 1 } }
};

static int handle_code(const char *code, size_t len, void *ctx) {
    tfs_token_array_t *tokens = (void *)ctx;

    int i;
    tfs_token_t *new_token = NULL;
    for (i=0; i<sizeof(stata_tokens)/sizeof(stata_tokens[0]); i++) {
        if (len == strlen(stata_tokens[i].text) && strncmp(stata_tokens[i].text, code, len) == 0) {
            new_token = tfs_append_token(tokens);
            memcpy(new_token, &stata_tokens[i].token, sizeof(tfs_token_t));
            break;
        }
    }

    return 0;
}

static int handle_literal(const char *literal, size_t len, void *ctx) {
    tfs_token_array_t *tokens = (void *)ctx;
    int in_i = 0, out_i = 0;
    tfs_token_t *new_token = tfs_append_token(tokens);
    new_token->is_literal = 1;
    char *out_text = new_token->text;

    while (in_i < len) {
        out_text[out_i++] = literal[in_i++];
    }
    out_text[out_i] = '\0';

    return 0;
}

tfs_token_array_t *tfs_stata_parse(const char *bytes, int *outError) {
    tfs_token_array_t *token_array = tfs_init_token_array(10);
    int error = 0;
    size_t len = strlen(bytes);
    int i;

    error = tfs_parse_stata_format_string_internal((const u_char *)bytes, len,
        &handle_literal, &handle_code, token_array);

    if (error) {
        *outError = error;
        tfs_free_token_array(token_array);
        return NULL;
    }

    for (i=0; i<token_array->count-1; i++) {
        if (token_array->tokens[i].time_unit == TFS_CENTURY &&
                (token_array->tokens[i+1].time_unit == TFS_YEAR &&
                 token_array->tokens[i+1].relative_to == TFS_CENTURY &&
                 token_array->tokens[i+1].style == TFS_2DIGIT)) {
            token_array->tokens[i].time_unit = 0;
            token_array->tokens[i+1].relative_to = TFS_ERA;
            token_array->tokens[i+1].style = TFS_NUMBER;
            if (token_array->tokens[i].style == TFS_2DIGIT) {
                token_array->tokens[i+1].pad_len = 4;
                token_array->tokens[i+1].pad_char = '0';
            }
        }
    }

    return token_array;
}

static char *format_token(char *outbuf, tfs_token_t *token) {
    char *p = outbuf;
    if (token->time_unit == TFS_YEAR) {
        if (token->relative_to == TFS_CENTURY) {
            if (token->style == TFS_NUMBER) {
                p = stpcpy(p, "yy");
            } else if (token->style == TFS_2DIGIT) {
                p = stpcpy(p, "YY");
            } else {
                p = NULL;
            }
        } else if (token->style == TFS_NUMBER) {
            if (token->pad_len == 4 && token->pad_char == '0') {
                p = stpcpy(p, "CCYY");
            } else {
                p = stpcpy(p, "ccYY");
            }
        } else {
            p = NULL;
        }
    } else if (token->time_unit) {
        char *match = tfs_match_token(stata_tokens, sizeof(stata_tokens)/sizeof(stata_tokens[0]), token);
        if (match) {
            p = stpcpy(p, match);
        } else {
            p = NULL;
        }
    }

    return p;
}

int tfs_stata_generate(char *format, tfs_token_array_t *token_array) {
    int i;
    int error = 0;
    char *out = format;
    const char *display_chars = ".,:-/\\";
    for (i=0; i<token_array->count; i++) {
        tfs_token_t *token = &token_array->tokens[i];
        if (token->is_literal) {
            char *in = token->text;
            while (*in) {
                if (*in == ' ') {
                    *out++ = '_';
                } else if (strchr(display_chars, *in) != NULL) {
                    *out++ = *in;
                } else {
                    *out++ = '!';
                    *out++ = *in;
                }
                in++;
            }
        } else {
            out = format_token(out, token);
            if (out == NULL) {
                error = TFS_CANT_REPRESENT;
                break;
            }
        }
    }
    if (out)
        *out++ = '\0';

    return error;
}
