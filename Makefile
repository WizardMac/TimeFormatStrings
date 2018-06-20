
CC=cc
PREFIX=/usr/local
RAGEL=/usr/local/bin/ragel
DYLIB=obj/libtfs.dylib
MIN_OSX=10.10

.PHONY: test

all:
	@mkdir -p obj
	[ -x $(RAGEL) ] && $(RAGEL) src/tfs_excel_parser.rl -G2
	[ -x $(RAGEL) ] && $(RAGEL) src/tfs_stata_parser.rl -G2
	[ -x $(RAGEL) ] && $(RAGEL) src/tfs_uts35_parser.rl -G2
	$(CC) -Os src/*.c -dynamiclib -o $(DYLIB) -pedantic -Wall -Werror -Wno-unused-variable -Wno-tautological-constant-out-of-range-compare -mmacosx-version-min=$(MIN_OSX)

install: all
	@mkdir -p $(PREFIX)/lib
	@cp $(DYLIB) $(PREFIX)/lib/
	@mkdir -p $(PREFIX)/include
	@cp src/tfs.h $(PREFIX)/include/

test:
	$(CC) test/tfs_test.c -o obj/tfs_test -Isrc -Lobj -ltfs -Wall -Werror
	./obj/tfs_test

clean:
	rm -rf obj
