
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tfs.h"
#include "tfs_token.h"

tfs_token_array_t *tfs_init_token_array(int count) {
    size_t len = sizeof(tfs_token_array_t) + count * sizeof(tfs_token_t);
    tfs_token_array_t *new_array = malloc(len);
    memset(new_array, 0, len);
    new_array->capacity = count;
    return new_array;
}

tfs_token_t *tfs_append_token(tfs_token_array_t *token_array) {
    tfs_token_t *new_token = NULL;
    if (token_array->count == token_array->capacity) {
        token_array->capacity *= 2;
        token_array = realloc(token_array, sizeof(tfs_token_array_t) + token_array->capacity * sizeof(tfs_token_t));
    }
    new_token = &token_array->tokens[token_array->count];

    token_array->count++;

    return new_token;
}

void tfs_free_token_array(tfs_token_array_t *token_array) {
    free(token_array);
}

char *tfs_match_token(tfs_token_lookup_t *token_table, size_t count, tfs_token_t *key) {
    int i;
    for (i=0; i<count; i++) {
        tfs_token_t *candidate = &token_table[i].token;
        if (candidate->time_unit != key->time_unit)
            continue;

        if (candidate->relative_to && candidate->relative_to != key->relative_to)
            continue;

        if (candidate->style == key->style ||
           ((candidate->style == TFS_FULL || candidate->style == TFS_LONG) &&
            (key->style == TFS_FULL || key->style == TFS_LONG))) {
            if (candidate->lowercase && !key->lowercase)
                continue;

            if (candidate->start_at_one && !key->start_at_one)
                continue;

            if (candidate->uppercase && !key->uppercase)
                continue;

            if (candidate->add_dots && !key->add_dots)
                continue;

            if (candidate->pad_len && candidate->pad_len != key->pad_len)
                continue;

            return token_table[i].text;
        }
    }

    return NULL;
}
