AC_INIT([tfs], [0.1.0-prerelease])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AM_SILENT_RULES([yes])

LT_INIT([disable-static])

AC_PROG_CC

AC_ARG_ENABLE([sanitizers], AS_HELP_STRING([--enable-sanitizers], [Enable address sanitizing]),
    [SANITIZERS="-fsanitize=address,bool,float-cast-overflow,integer-divide-by-zero,return,returns-nonnull-attribute,shift-exponent,signed-integer-overflow,unreachable,vla-bound -fsanitize-coverage=trace-pc-guard,indirect-calls,trace-cmp"], [SANITIZERS=""])
AC_SUBST([SANITIZERS])

EXTRA_WARNINGS="-Wno-tautological-constant-out-of-range-compare"
AC_SUBST([EXTRA_WARNINGS])

AC_ARG_VAR([RAGEL], [Ragel generator command])
AC_ARG_VAR([RAGELFLAGS], [Ragel generator flags])
AC_PATH_PROG([RAGEL], [ragel], [true])
AM_CONDITIONAL([HAVE_RAGEL], test "$RAGEL" != "true")

AC_CHECK_LIB([Fuzzer], [__libfuzzer_is_present], [true], [false], [-lstdc++])
AM_CONDITIONAL([HAVE_FUZZER], test "$ac_cv_lib_Fuzzer___libfuzzer_is_present" = yes)

AC_OUTPUT([Makefile])

AC_MSG_RESULT([
Configuration:

C compiler: $CC
CFLAGS: $CFLAGS

Host: $host
Extra warnings: $EXTRA_WARNINGS
Extra libs: $EXTRA_LIBS
Extra ld flags: $EXTRA_LDFLAGS

Ragel: $RAGEL
Ragel flags: $RAGELFLAGS])
