
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
