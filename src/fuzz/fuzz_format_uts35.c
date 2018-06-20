#include <stdlib.h>

#include "../tfs.h"
#include "fuzz_format.h"

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    return tfs_fuzz(Data, Size, TFS_UTS35);
}
