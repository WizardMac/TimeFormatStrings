
typedef enum {
    TFS_EXCEL,
    TFS_STATA,
    TFS_UTS35,
    TFS_DJANGO,
    TFS_STRFTIME
} tfs_format_e;

typedef enum {
    TFS_FRACTIONAL_SECOND = 0x0001,
    TFS_MILLISECOND       = 0x0002,
    TFS_SECOND            = 0x0004,
    TFS_MINUTE            = 0x0008,
    TFS_HOUR              = 0x0010,
    TFS_PERIOD            = 0x0020,
    TFS_DAY               = 0x0040,
    TFS_WEEK              = 0x0080,
    TFS_MONTH             = 0x0100,
    TFS_QUARTER           = 0x0200,
    TFS_HALF_YEAR         = 0x0400,
    TFS_YEAR              = 0x0800,
    TFS_CENTURY           = 0x1000,
    TFS_ERA               = 0x2000
} tfs_time_unit_e;


typedef int (*tfs_handle_string_callback)(const char *str, size_t len, void *ctx);
typedef int (*tfs_handle_field_symbol_callback)(unsigned int field_symbol, 
        unsigned int display_options, void *ctx);

int tfs_parse(const char *inbuf, tsf_format_e infmt, 
        tfs_handle_string_callback literal_cb, 
        tfs_handle_field_symbol_callback code_cb);

int tfs_field_mask(const char *inbuf, tfs_format_e infmt, unsigned short *mask);
int tfs_convert(const char *inbuf, tfs_format_e infmt, char *outbuf, tfs_format_e outfmt);
