
tfs_token_array_t *tfs_excel_parse(const char *bytes,
        tfs_handle_string_callback handle_error, tfs_error_e *outError);
int tfs_excel_generate(char *format, size_t format_len, tfs_token_array_t *tokens);
