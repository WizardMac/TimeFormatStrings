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

libtfs_la_CFLAGS = -D_GNU_SOURCE -Wall @EXTRA_WARNINGS@ -Werror -pedantic-errors -std=c99
libtfs_la_LDFLAGS =

if FUZZER_ENABLED
libtfs_la_CFLAGS += -fsanitize=fuzzer-no-link
libtfs_la_LDFLAGS += -fsanitize=fuzzer
endif

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

tfs_test_SOURCES = src/test/tfs_test.c

tfs_test_LDADD = libtfs.la
tfs_test_CFLAGS = -Wall -Werror -pedantic-errors -std=c99 -Isrc

TESTS = tfs_test

if FUZZER_ENABLED
noinst_PROGRAMS = \
	fuzz_format_excel \
	fuzz_format_posix \
	fuzz_format_sas \
	fuzz_format_spss \
	fuzz_format_stata \
	fuzz_format_uts35

noinst_HEADERS += src/fuzz/fuzz_format.h

fuzz_format_excel_SOURCES = \
	src/fuzz/fuzz_format.c \
	src/fuzz/fuzz_format_excel.c
fuzz_format_excel_LDADD = libtfs.la
fuzz_format_excel_CFLAGS = -g -Wall @EXTRA_WARNINGS@ -Werror -pedantic-errors -std=c99 @SANITIZERS@

fuzz_format_posix_SOURCES = \
	src/fuzz/fuzz_format.c \
	src/fuzz/fuzz_format_posix.c
fuzz_format_posix_LDADD = libtfs.la
fuzz_format_posix_CFLAGS = -g -Wall @EXTRA_WARNINGS@ -Werror -pedantic-errors -std=c99 @SANITIZERS@

fuzz_format_sas_SOURCES = \
	src/fuzz/fuzz_format.c \
	src/fuzz/fuzz_format_sas.c
fuzz_format_sas_LDADD = libtfs.la
fuzz_format_sas_CFLAGS = -g -Wall @EXTRA_WARNINGS@ -Werror -pedantic-errors -std=c99 @SANITIZERS@

fuzz_format_spss_SOURCES = \
	src/fuzz/fuzz_format.c \
	src/fuzz/fuzz_format_spss.c
fuzz_format_spss_LDADD = libtfs.la
fuzz_format_spss_CFLAGS = -g -Wall @EXTRA_WARNINGS@ -Werror -pedantic-errors -std=c99 @SANITIZERS@

fuzz_format_stata_SOURCES = \
	src/fuzz/fuzz_format.c \
	src/fuzz/fuzz_format_stata.c
fuzz_format_stata_LDADD = libtfs.la
fuzz_format_stata_CFLAGS = -g -Wall @EXTRA_WARNINGS@ -Werror -pedantic-errors -std=c99 @SANITIZERS@

fuzz_format_uts35_SOURCES = \
	src/fuzz/fuzz_format.c \
	src/fuzz/fuzz_format_uts35.c
fuzz_format_uts35_LDADD = libtfs.la
fuzz_format_uts35_CFLAGS = -g -Wall @EXTRA_WARNINGS@ -Werror -pedantic-errors -std=c99 @SANITIZERS@
endif
