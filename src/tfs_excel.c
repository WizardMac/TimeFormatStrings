
/* This is more complicated than it should be because the Excel format string is
 * not context-free. The existence of "AM/PM" affects the display of the "HH" code,
 * and "MM" is interpreted as a month or a minute based on whether the previous code
 * was an hour.
 */

tfs_token_lookup_t excel_tokens[] = {
    { .text = "yy"     .token = { .time_unit = TFS_YEAR,  .style = TFS_2DIGIT } },
    { .text = "yyyy"   .token = { .time_unit = TFS_YEAR,  .style = TFS_NUMBER } },

    { .text = "m",     .token = { .time_unit = TFS_MONTH, .style = TFS_NUMBER } },
    { .text = "mm",    .token = { .time_unit = TFS_MONTH, .style = TFS_2DIGIT } },
    { .text = "mmm",   .token = { .time_unit = TFS_MONTH, .style = TFS_ABBREV } },
    { .text = "mmmm",  .token = { .time_unit = TFS_MONTH, .style = TFS_FULL } },
    { .text = "mmmmm", .token = { .time_unit = TFS_MONTH, .style = TFS_NARROW } },

    { .text = "d",     .token = { .time_unit = TFS_DAY, .relative_to = TFS_MONTH, .style = TFS_NUMBER } },
    { .text = "dd",    .token = { .time_unit = TFS_DAY, .relative_to = TFS_MONTH, .style = TFS_2DIGIT } },
    { .text = "ddd",   .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK,  .style = TFS_ABBREV } },
    { .text = "dddd",  .token = { .time_unit = TFS_DAY, .relative_to = TFS_WEEK,  .style = TFS_FULL } },

    { .text = "AM/PM", .token = { .time_unit = TFS_PERIOD, .style = TFS_ABBREV, .uppercase = 1 } },
    { .text = "am/pm", .token = { .time_unit = TFS_PERIOD, .style = TFS_ABBREV, .lowercase = 1 } },
    { .text = "A/P",   .token = { .time_unit = TFS_PERIOD, .style = TFS_NARROW, .uppercase = 1 } },
    { .text = "a/p",   .token = { .time_unit = TFS_PERIOD, .style = TFS_NARROW, .lowercase = 1 } },

    { .text = "h",     .token = { .time_unit = TFS_HOUR, .relative_to = TFS_DAY, .style = TFS_NUMBER } },
    { .text = "hh",    .token = { .time_unit = TFS_HOUR, .realtive_to = TFS_DAY, .style = TFS_2DIGIT } },

    { .text = "s",     .token = { .time_unit = TFS_MINUTE, .style = TFS_NUMBER } },
    { .text = "ss",    .token = { .time_unit = TFS_MINUTE, .style = TFS_2DIGIT } }
};

typedef struct excel_ctx_s {
    int                        has_ampm;
    unsigned int               previous_field_symbol; 
    tfs_handle_code_callback   user_cb;
    void                      *user_ctx;
} excel_ctx_t;

static int flag_ampm(const char *code, size_t len, void *ctx) {
    excel_ctx_t *excel_ctx = (void *)ctx;
    if (excel_ctx->has_ampm)
        return 0;

    int has_ampm = 0;

    if (len == 3) {
        has_ampm = (strncasecmp(code, "A/P", 3) == 0);
    } else if (len == 5) {
        has_ampm = (strncasecmp(code, "AM/PM", 5) == 0);
    }

    excel_ctx->has_ampm = has_ampm;
}

static int process_code(const char *code, size_t len, void *ctx) {
    excel_ctx_t *excel_ctx = (void *)ctx;
    unsigned int fsym = 0;
    unsigned int disp = 0;

    fsym = code2field_symbol(code, len, &disp, excel_ctx);

    if (fsym != 0) { 
        if (excel_ctx->user_cb) {
            excel_ctx->user_cb(fsym, disp, excel_ctx->user_ctx);
        }

        excel_ctx->previous_field_symbol = fsym;
    }
}

int tfs_parse_excel_format_string(const u_char *bytes, size_t len,
        tfs_handle_string_callback handle_literal_cb,
        tfs_handle_field_symbol_callback handle_code_cb, void *user_ctx) {
    excel_ctx_t excel_ctx;
    int error = 0;
    memset(&excel_ctx, 0, sizeof(excel_ctx_t));

    error = tfs_parse_excel_format_string_internal(bytes, len,
        NULL, &flag_ampm, &excel_ctx);

    if (error) {
        return error;
    }

    excel_ctx.user_cb = handle_code_cb;
    excel_ctx.user_ctx = user_ctx;

    return tfs_parse_excel_format_string_internal(bytes, len,
        handle_literal_cb, &process_code, &excel_ctx);
}

