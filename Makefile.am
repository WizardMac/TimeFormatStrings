lib_LTLIBRARIES = libtfs.la

libtfs_la_SOURCES = \
	src/tfs.c \
	src/tfs_excel.c \
	src/tfs_excel_parser.c \
	src/tfs_internal.c \
	src/tfs_posix.c \
	src/tfs_sas.c \
	src/tfs_spss.c \
	src/tfs_stata.c \
	src/tfs_stata_parser.c \
	src/tfs_token.c \
	src/tfs_uts35.c \
	src/tfs_uts35_parser.c

libtfs_la_CFLAGS = -D_GNU_SOURCE -Wall @EXTRA_WARNINGS@ -Werror -pedantic-errors -std=c99 @SANITIZERS@

if HAVE_RAGEL
.rl.c:
	$(AM_V_GEN)$(RAGEL) $(RAGELFLAGS) -C $< -o $@
endif

include_HEADERS = src/tfs.h

noinst_HEADERS = \
	src/tfs_excel.h
	src/tfs_excel_parser.h
	src/tfs_internal.h
	src/tfs_posix.h
	src/tfs_sas.h
	src/tfs_spss.h
	src/tfs_stata.h
	src/tfs_stata_parser.h
	src/tfs_token.h
	src/tfs_uts35.h
	src/tfs_uts35_parser.h

check_PROGRAMS = \
	tfs_test

tfs_test_SOURCES = test/tfs_test.c

tfs_test_LDADD = libtfs.la
tfs_test_CFLAGS = -Wall -Werror -pedantic-errors -std=c99 -Isrc

TESTS = tfs_test
