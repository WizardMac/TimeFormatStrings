[![Build status](https://github.com/WizardMac/TimeFormatStrings/workflows/build/badge.svg)](https://github.com/WizardMac/TimeFormatStrings/actions)
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
    tfs_error_e error = tfs_convert("mm/dd/yyyy", TFS_EXCEL,
                                    result, TFS_UTS35, sizeof(result));
    if (error == TFS_OK) {
        printf("%s\n", result); /* prints "MM/dd/y" */
    }

The POSIX format can be fed to `strftime` and `strptime` in order to present
and parse specific time values.

Type "make" to build the library and "make test" to run the test suite.
