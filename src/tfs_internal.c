
#include <sys/types.h>
#include <string.h>

#include "tfs.h"
#include "tfs_internal.h"

tfs_token_t *append_ampm(tfs_token_array_t *token_array, tfs_style_e style) {
    tfs_token_t *token = tfs_append_token(token_array);
    token->time_unit = TFS_PERIOD;
    token->style = style;

    return token;
}

tfs_token_t *append_second(tfs_token_array_t *token_array, tfs_time_unit_e relative_to, tfs_style_e style) {
    tfs_token_t *token = tfs_append_token(token_array);
    token->time_unit = TFS_SECOND;
    token->relative_to = relative_to;
    token->style = style;

    return token;
}

tfs_token_t *append_minute(tfs_token_array_t *token_array, tfs_time_unit_e relative_to, tfs_style_e style) {
    tfs_token_t *token = tfs_append_token(token_array);
    token->time_unit = TFS_MINUTE;
    token->relative_to = relative_to;
    token->style = style;

    return token;
}

tfs_token_t *append_hour(tfs_token_array_t *token_array, tfs_time_unit_e relative_to, tfs_style_e style) {
    tfs_token_t *token = tfs_append_token(token_array);
    token->time_unit = TFS_HOUR;
    token->relative_to = relative_to;
    token->style = style;

    return token;
}

tfs_token_t *append_day(tfs_token_array_t *token_array, tfs_time_unit_e relative_to, tfs_style_e style) {
    tfs_token_t *token = tfs_append_token(token_array);
    token->time_unit = TFS_DAY;
    token->relative_to = relative_to;
    token->style = style;

    return token;
}

tfs_token_t *append_week(tfs_token_array_t *token_array, tfs_time_unit_e relative_to, tfs_style_e style) {
    tfs_token_t *token = tfs_append_token(token_array);
    token->time_unit = TFS_WEEK;
    token->relative_to = relative_to;
    token->style = style;

    return token;
}

tfs_token_t *append_month(tfs_token_array_t *token_array, tfs_style_e style) {
    tfs_token_t *token = tfs_append_token(token_array);
    token->time_unit = TFS_MONTH;
    token->style = style;

    return token;
}

tfs_token_t *append_quarter(tfs_token_array_t *token_array, tfs_style_e style) {
    tfs_token_t *token = tfs_append_token(token_array);
    token->time_unit = TFS_QUARTER;
    token->style = style;

    return token;
}

tfs_token_t *append_year(tfs_token_array_t *token_array, tfs_time_unit_e relative_to, tfs_style_e style) {
    tfs_token_t *token = tfs_append_token(token_array);
    token->time_unit = TFS_YEAR;
    token->relative_to = relative_to;
    token->style = style;
    return token;
}

tfs_token_t *append_literal_char(tfs_token_array_t *token_array, char text) {
    tfs_token_t *token = tfs_append_token(token_array);
    token->is_literal = 1;
    token->text[0] = text;
    return token;
}

tfs_token_t *append_literal_string(tfs_token_array_t *token_array, char *text) {
    tfs_token_t *token = tfs_append_token(token_array);
    token->is_literal = 1;
    strncpy(&token->text[0], text, sizeof(token->text));
    return token;
}

