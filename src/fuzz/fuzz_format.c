#include <stdlib.h>
#include <string.h>

#include "../tfs.h"

int tfs_fuzz(const uint8_t *Data, size_t Size, tfs_format_e format) {
    char *string = malloc(Size+1);
    memcpy(string, Data, Size);
    string[Size] = '\0';
    tfs_validate(string, format);
    free(string);
    return 0;
}
