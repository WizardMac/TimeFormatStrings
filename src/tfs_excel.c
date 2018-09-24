
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#include "tfs.h"
#include "tfs_internal.h"
#include "tfs_excel.h"
#include "tfs_excel_parser.h"

/* This is more complicated than it should be because the Excel format string is
 * not context-free. The existence of "AM/PM" affects the display of the "HH" code,
 * and "MM" is interpreted as a month or a minute based on whether the previous code
 * was an hour.
 */

static tfs_token_lookup_t excel_tokens[] = {
    { .text = "yy",    .token = { .time_unit = TFS_YEAR, .relative_to = TFS_CENTURY, .style = TFS_2DIGIT } },
    { .text = "yyyy",  .token = { .time_unit = TFS_YEAR, .relative_to = TFS_ERA, .style = TFS_NUMBER } },

    { .text = "m",     .token = { .time_unit = TFS_MONTH, .relative_to = TFS_YEAR, .style = TFS_NUMBER } },
    { .text = "mm",    .token = { .time_unit = TFS_MONTH, .relative_to = TFS_YEAR, .style = TFS_2DIGIT } },
    { .text = "mmm",   .token = { .time_unit = TFS_MONTH, .relative_to = TFS_YEAR, .style = TFS_ABBREV } },
    { .text = "mmmm",  .token = { .time_unit = TFS_MONTH, .relative_to = TFS_YEAR, .style = TFS_FULL } },
    { .text = "mmmmm", .token = { .time_unit = TFS_MONTH, .relative_to = TFS_YEAR, .style = TFS_NARROW } },

    { .text = "d",     .token = { .time_unit = TFS_DAY, .relative_to = TFS_MONTH, .style = TFS_NUMBER } },
    { .text = "dd",    .token = { .time_unit = TFS_DAY, .relative_to = TFS_MONTH, .style = TFS_2DIGIT } },
    { .text = "ddd",   .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK,  .style = TFS_ABBREV } },
    { .text = "dddd",  .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK,  .style = TFS_FULL } },

    { .text = "AM/PM", .token = { .time_unit = TFS_PERIOD, .relative_to = TFS_DAY, .style = TFS_ABBREV, .uppercase = 1 } },
    { .text = "am/pm", .token = { .time_unit = TFS_PERIOD, .relative_to = TFS_DAY, .style = TFS_ABBREV, .lowercase = 1 } },
    { .text = "A/P",   .token = { .time_unit = TFS_PERIOD, .relative_to = TFS_DAY, .style = TFS_NARROW, .uppercase = 1 } },
    { .text = "a/p",   .token = { .time_unit = TFS_PERIOD, .relative_to = TFS_DAY, .style = TFS_NARROW, .lowercase = 1 } },

    { .text = "h",     .token = { .time_unit = TFS_HOUR, .relative_to = TFS_DAY, .style = TFS_NUMBER } },
    { .text = "hh",    .token = { .time_unit = TFS_HOUR, .relative_to = TFS_DAY, .style = TFS_2DIGIT } },

    { .text = "s",     .token = { .time_unit = TFS_SECOND, .relative_to = TFS_MINUTE, .style = TFS_NUMBER } },
    { .text = "ss",    .token = { .time_unit = TFS_SECOND, .relative_to = TFS_MINUTE, .style = TFS_2DIGIT } }
};

static int handle_code(const char *code, size_t len, void *ctx) {
    tfs_token_array_t *tokens = (void *)ctx;

    int i;
    tfs_token_t *new_token = NULL;
    if (code[0] == 's') {
        size_t fractional_len = 0;
        new_token = tfs_append_token(tokens);
        new_token->time_unit = TFS_SECOND;
        new_token->relative_to = TFS_MINUTE;
        if (len > 1 && code[1] == 's') {
            new_token->style = TFS_2DIGIT;
            if (len > 3 && code[2] == '.') {
                fractional_len = len - 3;
            }
        } else {
            new_token->style = TFS_NUMBER;
            if (len > 2 && code[1] == '.') {
                fractional_len = len - 2;
            }
        }
        if (fractional_len) {
            new_token = tfs_append_token(tokens);
            new_token->time_unit = TFS_FRACTIONAL_SECOND;
            new_token->style = TFS_NUMBER;
            new_token->truncate_len = fractional_len;
            new_token->add_dots = 1;
        }
    } else if ((code[0] == 'A' || code[0] == 'P' || code[0] == 'a' || code[0] == 'p') && len < 3) {
        new_token = tfs_append_token(tokens);
        new_token->time_unit = TFS_PERIOD;
        new_token->relative_to = TFS_DAY;
        new_token->style = len == 2 ? TFS_ABBREV : TFS_NARROW;
        new_token->uppercase = (code[0] == 'A' || code[0] == 'P');
        new_token->lowercase = (code[0] == 'a' || code[0] == 'p');
    } else {
        for (i=0; i<sizeof(excel_tokens)/sizeof(excel_tokens[0]); i++) {
            if (len == strlen(excel_tokens[i].text) && strncmp(excel_tokens[i].text, code, len) == 0) {
                new_token = tfs_append_token(tokens);
                memcpy(new_token, &excel_tokens[i].token, sizeof(tfs_token_t));
                break;
            }
        }
    }

    return 0;
}

static int handle_literal(const char *literal, size_t len, void *ctx) {
    tfs_token_array_t *tokens = (void *)ctx;

    int in_i = 0, out_i = 0;
    int was_slash = 0;
    tfs_token_t *new_token = tfs_append_token(tokens);
    new_token->is_literal = 1;
    int out_len = sizeof(new_token->text);
    char *out_text = new_token->text;

    if (literal[0] == '"') {
        in_i = 1;
        len--;
    }

    while (in_i < len && out_i < out_len) {
        if (was_slash) {
            out_text[out_i++] = literal[in_i];
        } else if (literal[in_i] == '\\') {
            was_slash = 1;
        } else {
            out_text[out_i++] = literal[in_i];
        }
        in_i++;
    }
    if (out_i < out_len)
        out_text[out_i++] = '\0';

    return 0;
}

tfs_token_array_t *tfs_excel_parse(const char *bytes, tfs_handle_string_callback handle_error, tfs_error_e *outError) {
    tfs_token_array_t *token_array = tfs_init_token_array(10);
    int error = 0;
    int i;
    size_t len = strlen(bytes);
    tfs_parse_ctx_t ctx = {
        .handle_literal = &handle_literal,
        .handle_code = &handle_code,
        .handle_error = handle_error,
        .user_ctx = token_array
    };

    error = tfs_parse_excel_format_string_internal((const unsigned char *)bytes, len, &ctx);

    if (error) {
        *outError = error;
        tfs_free_token_array(token_array);
        return NULL;
    }

    tfs_time_unit_e last_unit = 0;
    int has_ampm = 0;

    /* Various stupid fix-ups because the Excel format is retarded */
    for (i=0; i<token_array->count; i++) {
        tfs_token_t *token = &token_array->tokens[i];
        if (!token->is_literal && token->time_unit == TFS_PERIOD) {
            has_ampm = 1;
            break;
        }
    }

    for (i=0; i<token_array->count; i++) {
        tfs_token_t *token = &token_array->tokens[i];

        if (!token->is_literal) {
            if (token->time_unit == TFS_HOUR && has_ampm) {
                token->relative_to = TFS_PERIOD;
                token->start_at_one = 1;
            }
            if (token->time_unit == TFS_MONTH && last_unit == TFS_HOUR) {
                token->time_unit = TFS_MINUTE;
                token->relative_to = TFS_HOUR;
            }
            last_unit = token->time_unit;
        }
    }

    last_unit = 0;

    for (i=token_array->count-1; i>=0; i--) {
        tfs_token_t *token = &token_array->tokens[i];

        if (!token->is_literal) {
            if (token->time_unit == TFS_MONTH && last_unit == TFS_SECOND) {
                token->time_unit = TFS_MINUTE;
                token->relative_to = TFS_HOUR;
            }

            last_unit = token->time_unit;
        }
    }

    return token_array;
}

static char *format_token(char *outbuf, size_t outbuf_len, tfs_token_t *token) {
    char *p = outbuf;
    char *last = outbuf + outbuf_len;
    if (token->time_unit == TFS_MINUTE) {
        if (token->style == TFS_NUMBER) {
            p = stpncpy(p, "m", last - p);
        } else if (token->style == TFS_2DIGIT) {
            p = stpncpy(p, "mm", last - p);
        } else {
            p = NULL;
        }
    } else if (token->time_unit == TFS_HOUR) {
        if (token->style == TFS_NUMBER) {
            p = stpncpy(p, "h", last - p);
        } else if (token->style == TFS_2DIGIT) {
            p = stpncpy(p, "hh", last - p);
        } else {
            p = NULL;
        }
    } else if (token->time_unit == TFS_FRACTIONAL_SECOND) {
        if (token->add_dots) {
            p = stpncpy(p, ".", last - p);
        }
        size_t len = token->truncate_len;
        while (len--) {
            p = stpncpy(p, "0", last - p);
        }
    } else {
        char *match = tfs_match_token(excel_tokens, sizeof(excel_tokens)/sizeof(excel_tokens[0]), token);
        if (match) {
            p = stpncpy(p, match, last - p);
        } else {
            p = NULL;
        }
    }
    return p;
}

int tfs_excel_generate(char *format, size_t format_len, tfs_token_array_t *token_array) {
    int i;
    char *out = format;
    char *last = format + format_len;
    const char *display_chars = "$-+/():!^&'~{}<>= ";
    int is_quoting = 0;
    int error = 0;
    for (i=0; i<token_array->count; i++) {
        tfs_token_t *token = &token_array->tokens[i];
        if (token->is_literal) {
            char *in = token->text;
            while (*in && out < last) {
                if (is_quoting) {
                    if (*in == '"') {
                        *out++ = '\\';
                    } else if (strchr(display_chars, *in) != NULL) {
                        *out++ = '"';
                        is_quoting = 0;
                    }
                    if (out < last)
                        *out++ = *in;
                } else {
                    if (strchr(display_chars, *in) == NULL) {
                        *out++ = '"';
                        if (*in == '"' && out < last) {
                            *out++ = '\\';
                        }
                        is_quoting = 1;
                    }
                    if (out < last)
                        *out++ = *in;
                }
                in++;
            }
        } else if (token->time_unit) {
            if (is_quoting && out < last) {
                *out++ = '"';
                is_quoting = 0;
            }
            out = format_token(out, last - out, token);
            if (out == NULL) {
                error = TFS_CANT_REPRESENT;
                break;
            }
        }
        if (out == last)
            break;
    }
    if (out) {
        if (is_quoting && out < last) {
            *out++ = '"';
        }
        if (out < last)
            *out++ = '\0';
    }
    return error;
}
