
typedef enum {
    TFS_EXCEL,
    TFS_STATA,
    TFS_UTS35
} tfs_format_e;

#define  TFS_NARROW          0x000001
#define  TFS_ABBREVIATED     0x000002
#define  TFS_LONG            0x000003
#define  TFS_FULL            0x000004

#define  TFS_LOWERCASE       0x000100
#define  TFS_UPPERCASE       0x000200
#define  TFS_ADD_DOTS        0x000400

#define  TFS_PAD             0x000800
#define  TFS_PAD_1           0x010800
#define  TFS_PAD_2           0x020800
#define  TFS_PAD_3           0x030800
#define  TFS_PAD_4           0x040800
#define  TFS_PAD_5           0x050800

#define  TFS_TRUNCATE        0x001000
#define  TFS_TRUNCATE_1      0x011000
#define  TFS_TRUNCATE_2      0x021000
#define  TFS_TRUNCATE_3      0x031000
#define  TFS_TRUNCATE_4      0x041000
#define  TFS_TRUNCATE_5      0x051000
#define  TFS_TRUNCATE_6      0x061000
#define  TFS_TRUNCATE_7      0x071000
#define  TFS_TRUNCATE_8      0x081000



#define  TFS_ERA                         0x000001

#define  TFS_YEAR                        0x000002
#define  TFS_ISO_WEEK_NUMBERING_YEAR     0x010002
#define  TFS_EXTENDED_YEAR               0x020002
#define  TFS_CYCLIC_YEAR                 0x030002

#define  TFS_HALF_YEAR                   0x000004

#define  TFS_QUARTER                     0x000008
#define  TFS_STANDALONE_QUARTER          0x010008

#define  TFS_MONTH                       0x000010
#define  TFS_STANDALONE_MONTH            0x010010

#define  TFS_WEEK                        0x000020
#define  TFS_WEEK_OF_YEAR                0x010020
#define  TFS_WEEK_OF_MONTH               0x020020

#define  TFS_DAY                         0x000040
#define  TFS_DAY_OF_MONTH                0x010040
#define  TFS_DAY_OF_YEAR                 0x020040
#define  TFS_MODIFIED_JULIAN_DAY         0x040040

#define  TFS_WEEK_DAY                    0x000080
#define  TFS_LOCAL_WEEK_DAY              0x010080
#define  TFS_STANDALONE_LOCAL_WEEK_DAY   0x020080

#define  TFS_PERIOD                      0x000100

#define  TFS_HOUR                        0x000100
#define  TFS_HOUR_1_12                   0x010100
#define  TFS_HOUR_0_23                   0x020100
#define  TFS_HOUR_0_11                   0x030100
#define  TFS_HOUR_1_24                   0x040100

#define  TFS_MINUTE                      0x000200
#define  TFS_SECOND                      0x000400
#define  TFS_FRACTIONAL_SECOND           0x000800

typedef int (*tfs_handle_string_callback)(const char *str, size_t len, void *ctx);
typedef int (*tfs_handle_field_symbol_callback)(unsigned int field_symbol, 
        unsigned int display_options, void *ctx);

int tfs_parse(const char *inbuf, tsf_format_e infmt, 
        tfs_handle_string_callback literal_cb, 
        tfs_handle_field_symbol_callback code_cb);

int tfs_field_mask(const char *inbuf, tfs_format_e infmt, unsigned int *mask);
int tfs_convert(const char *inbuf, tfs_format_e infmt, char *outbuf, tfs_format_e outfmt);
