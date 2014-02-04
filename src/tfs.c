
#include <stdio.h>
#include <string.h>

#include "tfs.h"
#include "tfs_token.h"
#include "tfs_excel.h"
#include "tfs_uts35.h"
#include "tfs_stata.h"

static tfs_token_array_t *parse_string(const char *inbuf, tfs_format_e infmt, int *outError) {
    if (infmt == TFS_EXCEL) {
        return tfs_excel_parse(inbuf, outError);
    }
    if (infmt == TFS_UTS35) {
        return tfs_uts35_parse(inbuf, outError);
    }
    if (infmt == TFS_STATA) {
        return tfs_stata_parse(inbuf, outError);
    }

    if (outError)
        *outError = TFS_UNKNOWN_FORMAT;

    return NULL;
}

static int generate_string(char *outbuf, tfs_format_e outfmt, tfs_token_array_t *tokens) {
    if (outfmt == TFS_EXCEL) {
        return tfs_excel_generate(outbuf, tokens);
    }
    if (outfmt == TFS_UTS35) {
        return tfs_uts35_generate(outbuf, tokens);
    }
    if (outfmt == TFS_STATA) {
        return tfs_stata_generate(outbuf, tokens);
    }

    return TFS_UNKNOWN_FORMAT;
}

tfs_error_e tfs_field_mask(const char *inbuf, tfs_format_e infmt, unsigned short *outMask) {
    unsigned short mask = 0;
    int i;
    int error = 0;
    tfs_token_array_t *token_array = parse_string(inbuf, infmt, &error);
    if (token_array == NULL)
        return error;

    for (i=0; i<token_array->count; i++) {
        mask |= token_array->tokens[i].time_unit;
    }

    tfs_free_token_array(token_array);

    *outMask = mask;

    return error;
}

tfs_error_e tfs_convert(const char *inbuf, tfs_format_e infmt, char *outbuf, tfs_format_e outfmt) {
    int error = 0;
    tfs_token_array_t *tokens = parse_string(inbuf, infmt, &error);
    if (tokens == NULL) {
        return error;
    }

    error = generate_string(outbuf, outfmt, tokens);

    tfs_free_token_array(tokens);

    return error;
}
