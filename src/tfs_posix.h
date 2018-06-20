
tfs_error_e tfs_posix_generate(char *format, size_t format_len, tfs_token_array_t *token_array);
tfs_token_array_t *tfs_posix_parse(const char *bytes,
        tfs_handle_string_callback handle_error, tfs_error_e *outError);
