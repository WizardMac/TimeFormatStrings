
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
