
tfs_token_array_t *tfs_stata_parse(const char *bytes, tfs_handle_string_callback handle_error, tfs_error_e *outError);
tfs_error_e tfs_stata_generate(char *format, size_t format_len, tfs_token_array_t *tokens);
