
#include "tfs_token.h"

typedef int (*tfs_handle_string_callback)(const char *str, size_t len, void *ctx);

typedef struct tfs_parse_ctx_s {
    tfs_handle_string_callback  handle_code;
    tfs_handle_string_callback  handle_literal;
    tfs_handle_string_callback  handle_error;
    void    *user_ctx;
} tfs_parse_ctx_t;

tfs_token_t *append_ampm(tfs_token_array_t *token_array, tfs_style_e style);
tfs_token_t *append_second(tfs_token_array_t *token_array, tfs_time_unit_e relative_to, tfs_style_e style);
tfs_token_t *append_minute(tfs_token_array_t *token_array, tfs_time_unit_e relative_to, tfs_style_e style);
tfs_token_t *append_hour(tfs_token_array_t *token_array, tfs_time_unit_e relative_to, tfs_style_e style);
tfs_token_t *append_day(tfs_token_array_t *token_array, tfs_time_unit_e relative_to, tfs_style_e style);
tfs_token_t *append_week(tfs_token_array_t *token_array, tfs_time_unit_e relative_to, tfs_style_e style);
tfs_token_t *append_month(tfs_token_array_t *token_array, tfs_style_e style);
tfs_token_t *append_quarter(tfs_token_array_t *token_array, tfs_style_e style);
tfs_token_t *append_year(tfs_token_array_t *token_array, tfs_time_unit_e relative_to, tfs_style_e style);
tfs_token_t *append_literal_char(tfs_token_array_t *token_array, char text);
tfs_token_t *append_literal_string(tfs_token_array_t *token_array, char *text);

/* Copy up to sizeof(token->text)-1 bytes of a literal into the token, always NUL-terminated */
void tfs_copy_literal(tfs_token_t *token, const char *text, size_t len);

/* Common tail for the generators: NUL-terminate the output and translate a
 * NULL / exhausted cursor into the right error code. */
tfs_error_e tfs_finish_output(char *outbuf, size_t outbuf_len, char *cursor, tfs_error_e error);
