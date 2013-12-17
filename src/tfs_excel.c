
/* This is more complicated than it should be because the Excel format string is
 * not context-free. The existence of "AM/PM" affects the display of the "HH" code,
 * and "MM" is interpreted as a month or a minute based on whether the previous code
 * was an hour.
 */

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

static unsigned int code2field_symbol(const char *code, size_t len, 
        unsigned int *display_options, excel_ctx_t *excel_ctx) {
    unsigned int fsym = 0;
    unsigned int disp = 0;

    if (code[0] == 'y' || code[0] == 'Y') {
        fsym = TFS_YEAR;
        if (len == 2) {
            disp = TFS_ABBREVIATED;
        }
    } else if (code[0] == 'D' || code[0] == 'd') {
        if (len == 1) {
            fsym = TFS_DAY_OF_MONTH;
        } else if (len == 2) {
            fsym = TFS_DAY_OF_MONTH;
            disp = TFS_PAD_2;
        } else if (len == 3) {
            fsym = TFS_WEEK_DAY;
            disp = TFS_ABBREVIATED;
        } else if (len == 4) {
            fsym = TFS_WEEK_DAY;
            disp = TFS_FULL;
        }
    } else if (code[0] == 'H' || code[0] == 'h') {
        if (excel_ctx->has_ampm) {
            fsym = TFS_HOUR_1_12;
        } else {
            fsym = TFS_HOUR_0_23;
        }
        if (len == 2) {
            disp = TFS_PAD_2;
        }
    } else if (code[0] == 'M' || code[0] == 'm') {
        if ((excel_ctx->previous_field_symbol & TFS_HOUR)) {
            fsym = TFS_MINUTE;
            if (len == 2) {
                disp = TFS_PAD_2;
            }
        } else {
            fsym = TFS_MONTH;
            if (len == 2) {
                disp = TFS_PAD_2;
            }
        }
    } else if (code[0] == 's') {
        /* TODO fractional seconds */
        fsym = TFS_SECOND;
        if (len > 1 && code[1] == 's') {
            disp = TFS_PAD_2;
        }
    } else if (code[0] == 'A' || code[0] == 'a' || code[0] == 'P' || code[0] == 'p') {
        fsym = TFS_PERIOD;
        if (code[0] == 'A' || code[0] == 'P') {
            disp |= TFS_UPPERCASE;
        } else {
            disp |= TFS_LOWERCASE;
        }
        if (code[1] == '/') {
            disp |= TFS_NARROW;
        }
    }
}

