
typedef enum {
    TFS_NUMBER,
    TFS_2DIGIT,
    TFS_NARROW,
    TFS_SHORT,
    TFS_ABBREV,
    TFS_LONG,
    TFS_FULL
} tfs_style_e;

typedef enum {
    TFS_ISO_WEEK_NUMBERING_YEAR = 1,
    TFS_DAY_OF_WEEK_IN_MONTH,
    TFS_CYCLIC_YEAR,
    TFS_MODIFIED_JULIAN
} tfs_modifier_e;

typedef struct tfs_token_s {
    int              is_literal;
    tfs_style_e      style;
    tfs_time_unit_e  time_unit;
    tfs_time_unit_e  relative_to; /* What 'time_unit' is relative to; e.g. "day of month" will be represented
                                   * with time_unit = TFS_DAY and relative_to = TFS_MONTH
                                   *
                                   * Similarly, a 12 hour clock will be represented as time_unit = TFS_HOUR
                                   * and relative_to = TFS_PERIOD.
                                   */

    tfs_modifier_e   modifier;

    int              pad_len;
    char             pad_char; /* usually ' ' or '0' */

    int              truncate_len;

    int              truncate_direction;
    int              pad_direction;

    int              lowercase:1;
    int              uppercase:1;
    int              add_dots:1;

    int              start_at_one:1;
    int              is_standalone:1;
    int              is_local:1;

    int              is_aligned:1;

    char             text[100];
} tfs_token_t;

typedef struct tfs_token_array_s {
    int         count;
    int         capacity;

    tfs_token_t tokens[0];
} tfs_token_array_t;

typedef struct tfs_token_lookup_s {
    char        text[16];
    tfs_token_t token;
} tfs_token_lookup_t;

tfs_token_array_t *tfs_init_token_array(int count);
tfs_token_t *tfs_append_token(tfs_token_array_t *token_array);
void tfs_free_token_array(tfs_token_array_t *token_array);
char *tfs_match_token(tfs_token_lookup_t *token_table, size_t count, tfs_token_t *key);
