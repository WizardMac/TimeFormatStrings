AC_INIT([tfs], [0.1.0-prerelease])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AM_SILENT_RULES([yes])

LT_INIT([disable-static])

AC_PROG_CC

AC_ARG_VAR([RAGEL], [Ragel generator command])
AC_ARG_VAR([RAGELFLAGS], [Ragel generator flags])
AC_PATH_PROG([RAGEL], [ragel], [true])
AM_CONDITIONAL([HAVE_RAGEL], test "$RAGEL" != "true")

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
