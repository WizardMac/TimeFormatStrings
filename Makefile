
CC=cc
PREFIX=/usr/local
RAGEL=/usr/local/bin/ragel
DYLIB=obj/libtfs.dylib

all:
	@mkdir -p obj
	[ -x $(RAGEL) ] && $(RAGEL) src/tfs_excel_parse.rl -G2
	[ -x $(RAGEL) ] && $(RAGEL) src/tfs_stata_parse.rl -G2
	$(CC) -Os src/*.c -dynamiclib -o $(DYLIB) -Wall -Werror

install: all
	@mkdir -p $(PREFIX)/lib
	@cp $(DYLIB) $(PREFIX)/lib/
	@mkdir -p $(PREFIX)/include
	@cp src/tfs.h $(PREFIX)/include/

clean:
	rm -rf obj
