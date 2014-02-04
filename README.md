TimeFormatStrings
--

This C library can read and write time format strings in three formats: Excel
(`TFS_EXCEL`), Stata (`TFS_STATA`), and Unicode (`TFS_UTS35`).

Example usage:

    char result[100];
    int error = tfs_convert("HH:mm", TFS_EXCEL, result, TFS_UTS35);
    if (error == 0) {
        printf("%s\n", result);
    }

It is up to the developer to ensure the output buffer is large enough to hold
the result.

Type "make" to build the library and "make test" to run the test suite.
