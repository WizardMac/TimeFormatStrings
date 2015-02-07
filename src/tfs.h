
typedef enum {
    TFS_EXCEL,
    TFS_STATA,
    TFS_UTS35,
    TFS_SAS,
    TFS_SPSS
} tfs_format_e;

typedef enum {
    TFS_OK = 0,
    TFS_UNKNOWN_FORMAT = 1,
    TFS_PARSE_ERROR,
    TFS_MORE_BUFFER_PLEASE,
    TFS_CANT_REPRESENT
} tfs_error_e;

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

tfs_error_e tfs_field_mask(const char *inbuf, tfs_format_e infmt, unsigned short *mask);
tfs_error_e tfs_convert(const char *inbuf, tfs_format_e infmt, char *outbuf, tfs_format_e outfmt);
