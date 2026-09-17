#include <stdlib.h>
#include <string.h>

#include "../tfs.h"

int tfs_fuzz(const uint8_t *Data, size_t Size, tfs_format_e format) {
    tfs_format_e output_formats[] = { TFS_EXCEL, TFS_POSIX, TFS_STATA, TFS_UTS35 };
    size_t buffer_sizes[] = { 0, 1, 7, 64, 4096 };
    char *string = malloc(Size+1);
    char *outbuf = malloc(4096);
    unsigned short mask = 0;
    int i, j;
    memcpy(string, Data, Size);
    string[Size] = '\0';
    tfs_validate(string, format);
    tfs_field_mask(string, format, &mask);
    for (i=0; i<sizeof(output_formats)/sizeof(output_formats[0]); i++) {
        for (j=0; j<sizeof(buffer_sizes)/sizeof(buffer_sizes[0]); j++) {
            tfs_convert(string, format, outbuf, output_formats[i], buffer_sizes[j]);
        }
    }
    free(outbuf);
    free(string);
    return 0;
}
