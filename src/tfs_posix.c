
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

#include "tfs.h"
#include "tfs_internal.h"

tfs_token_lookup_t posix_tokens[] = {
    { .text = "%A", .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_FULL } },
    { .text = "%a", .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_ABBREV } },
    { .text = "%B", .token = { .time_unit = TFS_MONTH, .relative_to = TFS_YEAR, .style = TFS_FULL } },
    { .text = "%b", .token = { .time_unit = TFS_MONTH, .relative_to = TFS_YEAR, .style = TFS_ABBREV } },
    { .text = "%C", .token = { .time_unit = TFS_CENTURY, .relative_to = TFS_ERA, .style = TFS_2DIGIT } },
    { .text = "%d", .token = { .time_unit = TFS_DAY, .relative_to = TFS_MONTH, .style = TFS_2DIGIT } },
    { .text = "%e", .token = { .time_unit = TFS_DAY, .relative_to = TFS_MONTH, .style = TFS_NUMBER } },
    { .text = "%G", .token = { .time_unit = TFS_YEAR, .relative_to = TFS_ERA, .style = TFS_NUMBER, .modifier = TFS_ISO_WEEK_NUMBERING_YEAR } },
    { .text = "%g", .token = { .time_unit = TFS_YEAR, .relative_to = TFS_CENTURY, .style = TFS_2DIGIT, .modifier = TFS_ISO_WEEK_NUMBERING_YEAR } },
    { .text = "%H", .token = { .time_unit = TFS_HOUR, .relative_to = TFS_DAY, .style = TFS_2DIGIT } },
    { .text = "%I", .token = { .time_unit = TFS_HOUR, .relative_to = TFS_PERIOD, .style = TFS_2DIGIT, .start_at_one = 1 } },
    { .text = "%j", .token = { .time_unit = TFS_DAY, .relative_to = TFS_YEAR, .style = TFS_NUMBER, .pad_len = 3, .pad_char = '0' } },
    { .text = "%k", .token = { .time_unit = TFS_HOUR, .relative_to = TFS_DAY, .style = TFS_NUMBER } },
    { .text = "%l", .token = { .time_unit = TFS_HOUR, .relative_to = TFS_PERIOD, .style = TFS_NUMBER, .start_at_one = 1 } },
    { .text = "%M", .token = { .time_unit = TFS_MINUTE, .relative_to = TFS_HOUR, .style = TFS_2DIGIT } },
    { .text = "%m", .token = { .time_unit = TFS_MONTH, .relative_to = TFS_YEAR, .style = TFS_2DIGIT } },
    { .text = "%p", .token = { .time_unit = TFS_PERIOD, .relative_to = TFS_DAY, .style = TFS_ABBREV, .uppercase = 1 } },
    { .text = "%S", .token = { .time_unit = TFS_SECOND, .relative_to = TFS_MINUTE, .style = TFS_2DIGIT } },
    { .text = "%U", .token = { .time_unit = TFS_WEEK, .relative_to = TFS_YEAR, .style = TFS_2DIGIT } },
    { .text = "%u", .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_NUMBER, .start_at_one = 1 } },
    { .text = "%V", .token = { .time_unit = TFS_WEEK, .relative_to = TFS_YEAR, .style = TFS_2DIGIT, .modifier = TFS_ISO_WEEK_NUMBERING_YEAR } },
    { .text = "%w", .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK, .style = TFS_NUMBER } },
    { .text = "%Y", .token = { .time_unit = TFS_YEAR, .relative_to = TFS_ERA, .style = TFS_NUMBER } },
    { .text = "%y", .token = { .time_unit = TFS_YEAR, .relative_to = TFS_CENTURY, .style = TFS_2DIGIT } },
};

static char *format_token(char *outbuf, tfs_token_t *token) {
    char *p = outbuf;
    char *match = tfs_match_token(posix_tokens, sizeof(posix_tokens)/sizeof(posix_tokens[0]), token);
    if (match) {
        p = stpcpy(p, match);
    } else {
        p = NULL;
    }
    return p;
}

tfs_error_e tfs_posix_generate(char *format, tfs_token_array_t *token_array) {
    int i;
    tfs_error_e error = TFS_OK;
    char *out = format;
    for (i=0; i<token_array->count; i++) {
        tfs_token_t *token = &token_array->tokens[i];
        if (token->is_literal) {
            char *in = token->text;
            while (*in) {
                if (*in == '%') {
                    *out++ = '%';
                    *out++ = *in;
                } else if (*in == '\n') {
                    *out++ = '%';
                    *out++ = 'n';
                } else if (*in == '\t') {
                    *out++ = '%';
                    *out++ = 't';
                } else {
                    *out++ = *in;
                }
                in++;
            }
        } else if (token->time_unit) {
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

tfs_token_array_t *tfs_posix_parse(const char *bytes, int *outError) {
    tfs_token_array_t *tokens = tfs_init_token_array(10);
    tfs_token_t *new_token = NULL;
    int literal_len = 0;
    const char *p = bytes;
    while (*p) {
        if (*p == '%') {
            if (literal_len) {
                new_token = tfs_append_token(tokens);
                new_token->is_literal = 1;
                memcpy(new_token->text, p-literal_len, literal_len);
                literal_len = 0;
            }
            p++;
            if (*p == '\0') {
                *outError = TFS_PARSE_ERROR;
                tfs_free_token_array(tokens);
                return NULL;
            }

            if (*p == 'n' || *p == 't' || *p == '%') {
                new_token = tfs_append_token(tokens);
                new_token->is_literal = 1;
                if (*p == 'n') {
                    new_token->text[0] = '\n';
                } else if (*p == 't') {
                    new_token->text[0] = '\t';
                } else {
                    new_token->text[0] = *p;
                }
            } else if (*p == 'D') {
                new_token = append_month(tokens, TFS_2DIGIT);
                new_token = append_literal_char(tokens, '/');
                new_token = append_day(tokens, TFS_MONTH, TFS_2DIGIT);
                new_token = append_literal_char(tokens, '/');
                new_token = append_year(tokens, TFS_CENTURY, TFS_2DIGIT);
            } else if (*p == 'F') {
                new_token = append_year(tokens, TFS_ERA, TFS_NUMBER);
                new_token = append_literal_char(tokens, '-');
                new_token = append_month(tokens, TFS_2DIGIT);
                new_token = append_literal_char(tokens, '-');
                new_token = append_day(tokens, TFS_MONTH, TFS_2DIGIT);
            } else if (*p == 'R') {
                new_token = append_hour(tokens, TFS_DAY, TFS_2DIGIT);
                new_token = append_literal_char(tokens, ':');
                new_token = append_minute(tokens, TFS_HOUR, TFS_2DIGIT);
            } else if (*p == 'r') {
                new_token = append_hour(tokens, TFS_PERIOD, TFS_2DIGIT);
                new_token = append_literal_char(tokens, ':');
                new_token = append_minute(tokens, TFS_HOUR, TFS_2DIGIT);
                new_token = append_literal_char(tokens, ':');
                new_token = append_second(tokens, TFS_MINUTE, TFS_2DIGIT);
                new_token = append_literal_char(tokens, ' ');
                new_token = append_ampm(tokens, TFS_ABBREV);
            } else if (*p == 'T') {
                new_token = append_hour(tokens, TFS_DAY, TFS_2DIGIT);
                new_token = append_literal_char(tokens, ':');
                new_token = append_minute(tokens, TFS_HOUR, TFS_2DIGIT);
                new_token = append_literal_char(tokens, ':');
                new_token = append_second(tokens, TFS_MINUTE, TFS_2DIGIT);
            } else if (*p == 'v') {
                new_token = append_day(tokens, TFS_MONTH, TFS_NUMBER);
                new_token = append_literal_char(tokens, '-');
                new_token = append_month(tokens, TFS_ABBREV);
                new_token = append_literal_char(tokens, '-');
                new_token = append_year(tokens, TFS_ERA, TFS_NUMBER);
            } else {
                int i;
                for (i=0; i<sizeof(posix_tokens)/sizeof(posix_tokens[0]); i++) {
                    if (posix_tokens[i].text[1] == *p) {
                        new_token = tfs_append_token(tokens);
                        memcpy(new_token, &posix_tokens[i].token, sizeof(tfs_token_t));
                        break;
                    }
                }
                if (i == sizeof(posix_tokens)/sizeof(posix_tokens[0])) {
                    *outError = TFS_PARSE_ERROR;
                    tfs_free_token_array(tokens);
                    return NULL;
                }
            }
        } else {
            literal_len++;
        }
        p++;
    }
    if (literal_len) {
        new_token = tfs_append_token(tokens);
        new_token->is_literal = 1;
        memcpy(new_token->text, p-literal_len, literal_len);
    }
    return tokens;
}
