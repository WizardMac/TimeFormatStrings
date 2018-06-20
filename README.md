[![Travis CI build status](https://travis-ci.org/WizardMac/TimeFormatStrings.svg?branch=master)](https://travis-ci.org/WizardMac/TimeFormatStrings)
TimeFormatStrings
--

This handy C library can read and write time format strings in four formats:
Excel (`TFS_EXCEL`), POSIX (`TFS_POSIX`), Stata (`TFS_STATA`), and Unicode
(`TFS_UTS35`).

It can also read, but not write, format strings in SAS format (`TFS_SAS`) and
SPSS format (`TFS_SPSS`).

Example usage:

    #include "tfs.h"
    
    char result[100];
    int error = tfs_convert("mm/dd/yyyy", TFS_EXCEL, result, TFS_UTS35);
    if (error == 0) {
        printf("%s\n", result); /* prints "MM/dd/y" */
    }

It is up to the developer to ensure the output buffer is large enough to hold
the result.

Type "make" to build the library and "make test" to run the test suite.
