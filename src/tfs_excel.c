
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

static int handle_code(const char *raw_code, size_t len, void *ctx) {
    tfs_token_array_t *tokens = (void *)ctx;

    int i;
    tfs_token_t *new_token = NULL;
    char code[32];
    int is_ampm = (raw_code[0] == 'A' || raw_code[0] == 'a' || raw_code[0] == 'P' || raw_code[0] == 'p');

    /* Excel date codes are case-insensitive, except for the AM/PM variants,
     * whose case selects the case of the output. */
    if (len >= sizeof(code))
        len = sizeof(code) - 1;
    for (i=0; i<len; i++) {
        char c = raw_code[i];
        if (!is_ampm && c >= 'A' && c <= 'Z')
            c += 'a' - 'A';
        code[i] = c;
    }
    code[len] = '\0';

    if (code[0] == '[') {
        /* Elapsed time: [h], [hh], [mm], [ss] */
        size_t digits = len - 2;
        new_token = tfs_append_token(tokens);
        new_token->time_unit = code[1] == 'h' ? TFS_HOUR : code[1] == 'm' ? TFS_MINUTE : TFS_SECOND;
        new_token->relative_to = 0; /* elapsed: not relative to anything */
        new_token->style = digits > 1 ? TFS_2DIGIT : TFS_NUMBER;
        return 0;
    }

    /* Excel treats a run longer than the longest code as the longest code */
    if (code[0] == 'y' && len == 3) {
        len = 4;
        code[3] = 'y';
    } else if (code[0] == 'y' && len > 4) {
        len = 4;
    } else if (code[0] == 'd' && len > 4) {
        len = 4;
    } else if (code[0] == 'm' && len > 5) {
        len = 5;
    } else if (code[0] == 'h' && len > 2) {
        len = 2;
    }
    code[len] = '\0';

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
    int out_len = sizeof(new_token->text) - 1;
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
    out_text[out_i] = '\0';

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

static char *format_token(char *outbuf, size_t outbuf_len, tfs_token_t *token, int has_ampm) {
    char *p = outbuf;
    char *last = outbuf + outbuf_len;
    if (token->time_unit == TFS_MINUTE || token->time_unit == TFS_HOUR ||
            (token->time_unit == TFS_SECOND && token->relative_to == 0)) {
        const char *code = NULL;
        if (token->time_unit == TFS_HOUR) {
            /* Excel shows a 12-hour clock only if AM/PM appears somewhere in the
             * format, and has no way to show 0-11 or 1-24 clocks. */
            if (token->relative_to == TFS_PERIOD && (!token->start_at_one || !has_ampm))
                return NULL;
            if (token->relative_to == TFS_DAY && token->start_at_one)
                return NULL;
            code = token->style == TFS_2DIGIT ? "hh" : token->style == TFS_NUMBER ? "h" : NULL;
        } else if (token->time_unit == TFS_MINUTE) {
            code = token->style == TFS_2DIGIT ? "mm" : token->style == TFS_NUMBER ? "m" : NULL;
        } else {
            code = token->style == TFS_2DIGIT ? "ss" : token->style == TFS_NUMBER ? "s" : NULL;
        }
        if (code == NULL)
            return NULL;
        if (token->relative_to == 0) {
            /* Elapsed time */
            p = stpncpy(p, "[", last - p);
            p = stpncpy(p, code, last - p);
            p = stpncpy(p, "]", last - p);
        } else {
            p = stpncpy(p, code, last - p);
        }
    } else if (token->time_unit == TFS_FRACTIONAL_SECOND) {
        /* Excel only shows fractional seconds as decimals following the seconds */
        if (!token->add_dots || token->truncate_len == 0)
            return NULL;
        p = stpncpy(p, ".", last - p);
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
    int has_ampm = 0;
    for (i=0; i<token_array->count; i++) {
        tfs_token_t *token = &token_array->tokens[i];
        if (!token->is_literal && token->time_unit == TFS_PERIOD)
            has_ampm = 1;
    }
    for (i=0; i<token_array->count; i++) {
        tfs_token_t *token = &token_array->tokens[i];
        if (token->is_literal) {
            char *in = token->text;
            while (*in && out < last) {
                int is_display = (unsigned char)*in >= 0x80 || strchr(display_chars, *in) != NULL;
                if (is_quoting) {
                    if (*in == '"') {
                        *out++ = '\\';
                    } else if (is_display) {
                        *out++ = '"';
                        is_quoting = 0;
                    }
                    if (out < last)
                        *out++ = *in;
                } else {
                    if (!is_display) {
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
            out = format_token(out, last - out, token, has_ampm);
            if (out == NULL) {
                error = TFS_CANT_REPRESENT;
                break;
            }
        }
        if (out == last)
            break;
    }
    if (out && is_quoting) {
        if (out < last) {
            *out++ = '"';
        } else {
            error = TFS_MORE_BUFFER_PLEASE;
        }
    }
    return tfs_finish_output(format, format_len, out, error);
}
