
#include <stdio.h>
#include <string.h>

#include "tfs.h"
#include "tfs_internal.h"
#include "tfs_excel.h"
#include "tfs_uts35.h"
#include "tfs_stata.h"
#include "tfs_spss.h"
#include "tfs_sas.h"
#include "tfs_posix.h"

static tfs_token_array_t *parse_string(const char *inbuf, tfs_format_e infmt, int *outError) {
    if (infmt == TFS_EXCEL) {
        return tfs_excel_parse(inbuf, outError);
    }
    if (infmt == TFS_POSIX) {
        return tfs_posix_parse(inbuf, outError);
    }
    if (infmt == TFS_SAS) {
        return tfs_sas_parse(inbuf, outError);
    }
    if (infmt == TFS_SPSS) {
        return tfs_spss_parse(inbuf, outError);
    }
    if (infmt == TFS_STATA) {
        return tfs_stata_parse(inbuf, outError);
    }
    if (infmt == TFS_UTS35) {
        return tfs_uts35_parse(inbuf, outError);
    }

    if (outError)
        *outError = TFS_UNKNOWN_FORMAT;

    return NULL;
}

static int generate_string(char *outbuf, size_t outbuf_len, tfs_format_e outfmt, tfs_token_array_t *tokens) {
    if (outfmt == TFS_EXCEL) {
        return tfs_excel_generate(outbuf, outbuf_len, tokens);
    }
    if (outfmt == TFS_POSIX) {
        return tfs_posix_generate(outbuf, outbuf_len, tokens);
    }
    if (outfmt == TFS_STATA) {
        return tfs_stata_generate(outbuf, outbuf_len, tokens);
    }
    if (outfmt == TFS_UTS35) {
        return tfs_uts35_generate(outbuf, outbuf_len, tokens);
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

tfs_error_e tfs_field_style(const char *inbuf, tfs_format_e infmt, tfs_time_unit_e time_unit, tfs_style_e *outStyle) {
    tfs_style_e style = TFS_NONE;
    int i;
    int error = 0;
    tfs_token_array_t *token_array = parse_string(inbuf, infmt, &error);
    if (token_array == NULL)
        return error;

    for (i=0; i<token_array->count; i++) {
        if (token_array->tokens[i].time_unit == time_unit) {
            style = token_array->tokens[i].style;
            break;
        }
    }

    tfs_free_token_array(token_array);

    *outStyle = style;

    return error;
}

tfs_error_e tfs_convert(const char *inbuf, tfs_format_e infmt, char *outbuf, tfs_format_e outfmt, size_t outbuf_len) {
    int error = 0;
    tfs_token_array_t *tokens = parse_string(inbuf, infmt, &error);
    if (tokens == NULL) {
        return error;
    }

    error = generate_string(outbuf, outbuf_len, outfmt, tokens);

    tfs_free_token_array(tokens);

    return error;
}
