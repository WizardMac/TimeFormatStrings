
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tfs.h"
#include "tfs_token.h"

tfs_token_array_t *tfs_init_token_array(int count) {
    tfs_token_array_t *new_array = calloc(1, sizeof(tfs_token_array_t));
    new_array->capacity = count;
    new_array->tokens = calloc(count, sizeof(tfs_token_t));
    return new_array;
}

tfs_token_t *tfs_append_token(tfs_token_array_t *token_array) {
    tfs_token_t *new_token = NULL;
    if (token_array->count == token_array->capacity) {
        token_array->capacity *= 2;
        token_array->tokens = realloc(token_array->tokens, token_array->capacity * sizeof(tfs_token_t));
        memset(&token_array->tokens[token_array->count], 0,
                (token_array->capacity - token_array->count) * sizeof(tfs_token_t));
    }
    new_token = &token_array->tokens[token_array->count];

    token_array->count++;

    return new_token;
}

void tfs_free_token_array(tfs_token_array_t *token_array) {
    free(token_array->tokens);
    free(token_array);
}

char *tfs_match_token(tfs_token_lookup_t *token_table, size_t count, tfs_token_t *key) {
    int i;
    for (i=count-1; i>=0; i--) {
        tfs_token_t *candidate = &token_table[i].token;
        if (candidate->time_unit != key->time_unit)
            continue;

        if (candidate->relative_to != key->relative_to)
            continue;

        if (candidate->style == key->style ||
           ((candidate->style == TFS_FULL || candidate->style == TFS_LONG) &&
            (key->style == TFS_FULL || key->style == TFS_LONG))) {
            if (candidate->lowercase != key->lowercase)
                continue;

            if (candidate->start_at_one != key->start_at_one)
                continue;

            if (candidate->uppercase != key->uppercase)
                continue;

            if (candidate->add_dots != key->add_dots)
                continue;
            
            if (candidate->is_aligned != key->is_aligned)
                continue;

            if (candidate->is_standalone != key->is_standalone)
                continue;

            if (candidate->is_local != key->is_local)
                continue;

            if (candidate->pad_len != key->pad_len)
                continue;

            if (candidate->truncate_len != key->truncate_len)
                continue;

            if (candidate->modifier != key->modifier)
                continue;

            return token_table[i].text;
        }
    }

    return NULL;
}
