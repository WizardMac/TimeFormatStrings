
#line 1 "src/tfs_stata_parser.rl"

#include <sys/types.h>
#include <stdio.h>

#include "tfs.h"
#include "tfs_internal.h"
#include "tfs_token.h"
#include "tfs_stata_parser.h"

/* See http://www.stata.com/help.cgi?datetime_display_formats */


#line 16 "src/tfs_stata_parser.c"
static const int stata_format_start = 36;
static const int stata_format_first_final = 36;
static const int stata_format_error = 0;

static const int stata_format_en_main = 36;


#line 15 "src/tfs_stata_parser.rl"


int tfs_parse_stata_format_string_internal(const u_char *bytes, size_t len,
        tfs_handle_string_callback handle_literal_cb,
        tfs_handle_string_callback handle_code_cb, void *user_ctx) {
    u_char *p = (u_char *)bytes;
    u_char *pe = (u_char *)bytes + len;
    u_char *str_start = NULL;

    u_char *eof = pe;

    int cs;

   
#line 39 "src/tfs_stata_parser.c"
	{
	cs = stata_format_start;
	}

#line 44 "src/tfs_stata_parser.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr45:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st36;
tr72:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st36;
tr100:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
#line 78 "src/tfs_stata_parser.c"
	switch( (*p) ) {
		case 33: goto st1;
		case 43: goto st36;
		case 46: goto tr21;
		case 58: goto tr0;
		case 65: goto tr22;
		case 67: goto tr23;
		case 68: goto tr24;
		case 72: goto tr25;
		case 74: goto tr26;
		case 77: goto tr27;
		case 78: goto tr28;
		case 83: goto tr29;
		case 87: goto tr30;
		case 89: goto tr31;
		case 92: goto tr0;
		case 95: goto st42;
		case 97: goto tr33;
		case 99: goto tr34;
		case 100: goto tr35;
		case 104: goto tr36;
		case 106: goto tr37;
		case 109: goto tr38;
		case 110: goto tr39;
		case 113: goto tr40;
		case 115: goto tr41;
		case 119: goto tr42;
		case 121: goto tr43;
	}
	if ( 44 <= (*p) && (*p) <= 47 )
		goto tr0;
	goto st0;
st0:
cs = 0;
	goto _out;
tr44:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st1;
tr71:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st1;
tr99:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
	goto st1;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
#line 142 "src/tfs_stata_parser.c"
	if ( (*p) <= -1 )
		goto st0;
	goto tr0;
tr0:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st37;
tr46:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st37;
tr73:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st37;
tr101:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 192 "src/tfs_stata_parser.c"
	switch( (*p) ) {
		case 33: goto tr44;
		case 43: goto tr45;
		case 46: goto tr47;
		case 58: goto tr46;
		case 65: goto tr48;
		case 67: goto tr49;
		case 68: goto tr50;
		case 72: goto tr51;
		case 74: goto tr52;
		case 77: goto tr53;
		case 78: goto tr54;
		case 83: goto tr55;
		case 87: goto tr56;
		case 89: goto tr57;
		case 92: goto tr46;
		case 95: goto tr58;
		case 97: goto tr59;
		case 99: goto tr60;
		case 100: goto tr61;
		case 104: goto tr62;
		case 106: goto tr63;
		case 109: goto tr64;
		case 110: goto tr65;
		case 113: goto tr66;
		case 115: goto tr67;
		case 119: goto tr68;
		case 121: goto tr69;
	}
	if ( 44 <= (*p) && (*p) <= 47 )
		goto tr46;
	goto st0;
tr21:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st38;
tr47:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st38;
tr74:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st38;
tr102:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
#line 271 "src/tfs_stata_parser.c"
	switch( (*p) ) {
		case 33: goto tr44;
		case 43: goto tr45;
		case 46: goto tr47;
		case 58: goto tr46;
		case 65: goto tr48;
		case 67: goto tr49;
		case 68: goto tr50;
		case 72: goto tr51;
		case 74: goto tr52;
		case 77: goto tr53;
		case 78: goto tr54;
		case 83: goto tr55;
		case 87: goto tr56;
		case 89: goto tr57;
		case 92: goto tr46;
		case 95: goto tr58;
		case 97: goto tr59;
		case 99: goto tr60;
		case 100: goto tr61;
		case 104: goto tr62;
		case 106: goto tr63;
		case 109: goto tr64;
		case 110: goto tr65;
		case 113: goto tr66;
		case 115: goto st46;
		case 119: goto tr68;
		case 121: goto tr69;
	}
	if ( 44 <= (*p) && (*p) <= 47 )
		goto tr46;
	goto st0;
tr22:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st2;
tr48:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st2;
tr75:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st2;
tr103:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 350 "src/tfs_stata_parser.c"
	switch( (*p) ) {
		case 46: goto st3;
		case 77: goto st39;
	}
	goto st0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	if ( (*p) == 77 )
		goto st4;
	goto st0;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	if ( (*p) == 46 )
		goto st39;
	goto st0;
tr40:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st39;
tr66:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st39;
tr93:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st39;
tr121:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
#line 416 "src/tfs_stata_parser.c"
	switch( (*p) ) {
		case 33: goto tr71;
		case 43: goto tr72;
		case 46: goto tr74;
		case 58: goto tr73;
		case 65: goto tr75;
		case 67: goto tr76;
		case 68: goto tr77;
		case 72: goto tr78;
		case 74: goto tr79;
		case 77: goto tr80;
		case 78: goto tr81;
		case 83: goto tr82;
		case 87: goto tr83;
		case 89: goto tr84;
		case 92: goto tr73;
		case 95: goto tr85;
		case 97: goto tr86;
		case 99: goto tr87;
		case 100: goto tr88;
		case 104: goto tr89;
		case 106: goto tr90;
		case 109: goto tr91;
		case 110: goto tr92;
		case 113: goto tr93;
		case 115: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( 44 <= (*p) && (*p) <= 47 )
		goto tr73;
	goto st0;
tr23:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st5;
tr49:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st5;
tr76:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st5;
tr104:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 495 "src/tfs_stata_parser.c"
	if ( (*p) == 67 )
		goto st39;
	goto st0;
tr24:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st6;
tr50:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st6;
tr77:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st6;
tr105:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
#line 545 "src/tfs_stata_parser.c"
	switch( (*p) ) {
		case 65: goto st7;
		case 68: goto st39;
		case 97: goto st40;
	}
	goto st0;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	if ( (*p) == 89 )
		goto st8;
	goto st0;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	if ( (*p) == 78 )
		goto st9;
	goto st0;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	if ( (*p) == 65 )
		goto st10;
	goto st0;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	if ( (*p) == 77 )
		goto st11;
	goto st0;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	if ( (*p) == 69 )
		goto st39;
	goto st0;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	switch( (*p) ) {
		case 33: goto tr71;
		case 43: goto tr72;
		case 46: goto tr74;
		case 58: goto tr73;
		case 65: goto tr75;
		case 67: goto tr76;
		case 68: goto tr77;
		case 72: goto tr78;
		case 74: goto tr79;
		case 77: goto tr80;
		case 78: goto tr81;
		case 83: goto tr82;
		case 87: goto tr83;
		case 89: goto tr84;
		case 92: goto tr73;
		case 95: goto tr85;
		case 97: goto tr86;
		case 99: goto tr87;
		case 100: goto tr88;
		case 104: goto tr89;
		case 106: goto tr90;
		case 109: goto tr91;
		case 110: goto tr92;
		case 113: goto tr93;
		case 115: goto tr94;
		case 119: goto tr95;
		case 121: goto st45;
	}
	if ( 44 <= (*p) && (*p) <= 47 )
		goto tr73;
	goto st0;
tr25:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st12;
tr51:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st12;
tr78:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st12;
tr106:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 669 "src/tfs_stata_parser.c"
	switch( (*p) ) {
		case 72: goto st39;
		case 104: goto st39;
	}
	goto st0;
tr26:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st13;
tr52:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st13;
tr79:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st13;
tr107:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st13;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
#line 721 "src/tfs_stata_parser.c"
	if ( (*p) == 74 )
		goto st14;
	goto st0;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	if ( (*p) == 74 )
		goto st39;
	goto st0;
tr27:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st15;
tr53:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st15;
tr80:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st15;
tr108:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
#line 778 "src/tfs_stata_parser.c"
	switch( (*p) ) {
		case 77: goto st39;
		case 111: goto st16;
	}
	goto st0;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	if ( (*p) == 110 )
		goto st41;
	goto st0;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	switch( (*p) ) {
		case 33: goto tr71;
		case 43: goto tr72;
		case 46: goto tr74;
		case 58: goto tr73;
		case 65: goto tr75;
		case 67: goto tr76;
		case 68: goto tr77;
		case 72: goto tr78;
		case 74: goto tr79;
		case 77: goto tr80;
		case 78: goto tr81;
		case 83: goto tr82;
		case 87: goto tr83;
		case 89: goto tr84;
		case 92: goto tr73;
		case 95: goto tr85;
		case 97: goto tr86;
		case 99: goto tr87;
		case 100: goto tr88;
		case 104: goto tr89;
		case 106: goto tr90;
		case 109: goto tr91;
		case 110: goto tr92;
		case 113: goto tr93;
		case 115: goto tr94;
		case 116: goto st32;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( 44 <= (*p) && (*p) <= 47 )
		goto tr73;
	goto st0;
tr28:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st17;
tr54:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st17;
tr81:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st17;
tr109:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
#line 874 "src/tfs_stata_parser.c"
	if ( (*p) == 78 )
		goto st39;
	goto st0;
tr29:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st18;
tr55:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st18;
tr82:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st18;
tr110:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st18;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
#line 924 "src/tfs_stata_parser.c"
	if ( (*p) == 83 )
		goto st39;
	goto st0;
tr30:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st19;
tr56:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st19;
tr83:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st19;
tr111:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 974 "src/tfs_stata_parser.c"
	if ( (*p) == 87 )
		goto st39;
	goto st0;
tr31:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st20;
tr57:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st20;
tr84:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st20;
tr112:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 1024 "src/tfs_stata_parser.c"
	if ( (*p) == 89 )
		goto st39;
	goto st0;
tr58:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st42;
tr85:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st42;
tr113:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 1056 "src/tfs_stata_parser.c"
	switch( (*p) ) {
		case 33: goto tr99;
		case 43: goto tr100;
		case 46: goto tr102;
		case 58: goto tr101;
		case 65: goto tr103;
		case 67: goto tr104;
		case 68: goto tr105;
		case 72: goto tr106;
		case 74: goto tr107;
		case 77: goto tr108;
		case 78: goto tr109;
		case 83: goto tr110;
		case 87: goto tr111;
		case 89: goto tr112;
		case 92: goto tr101;
		case 95: goto tr113;
		case 97: goto tr114;
		case 99: goto tr115;
		case 100: goto tr116;
		case 104: goto tr117;
		case 106: goto tr118;
		case 109: goto tr119;
		case 110: goto tr120;
		case 113: goto tr121;
		case 115: goto tr122;
		case 119: goto tr123;
		case 121: goto tr124;
	}
	if ( 44 <= (*p) && (*p) <= 47 )
		goto tr101;
	goto st0;
tr33:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st21;
tr59:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st21;
tr86:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st21;
tr114:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 1135 "src/tfs_stata_parser.c"
	switch( (*p) ) {
		case 46: goto st22;
		case 109: goto st39;
	}
	goto st0;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	if ( (*p) == 109 )
		goto st4;
	goto st0;
tr34:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st23;
tr60:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st23;
tr87:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st23;
tr115:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
#line 1194 "src/tfs_stata_parser.c"
	if ( (*p) == 99 )
		goto st39;
	goto st0;
tr35:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st24;
tr61:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st24;
tr88:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st24;
tr116:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st24;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
#line 1244 "src/tfs_stata_parser.c"
	switch( (*p) ) {
		case 97: goto st43;
		case 100: goto st39;
	}
	goto st0;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	switch( (*p) ) {
		case 33: goto tr71;
		case 43: goto tr72;
		case 46: goto tr74;
		case 58: goto tr73;
		case 65: goto tr75;
		case 67: goto tr76;
		case 68: goto tr77;
		case 72: goto tr78;
		case 74: goto tr79;
		case 77: goto tr80;
		case 78: goto tr81;
		case 83: goto tr82;
		case 87: goto tr83;
		case 89: goto tr84;
		case 92: goto tr73;
		case 95: goto tr85;
		case 97: goto tr86;
		case 99: goto tr87;
		case 100: goto tr88;
		case 104: goto tr89;
		case 106: goto tr90;
		case 109: goto tr91;
		case 110: goto tr92;
		case 113: goto tr93;
		case 115: goto tr94;
		case 119: goto tr95;
		case 121: goto st39;
	}
	if ( 44 <= (*p) && (*p) <= 47 )
		goto tr73;
	goto st0;
tr36:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st44;
tr62:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st44;
tr89:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st44;
tr117:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
#line 1332 "src/tfs_stata_parser.c"
	switch( (*p) ) {
		case 33: goto tr71;
		case 43: goto tr72;
		case 46: goto tr74;
		case 58: goto tr73;
		case 65: goto tr75;
		case 67: goto tr76;
		case 68: goto tr77;
		case 72: goto st39;
		case 74: goto tr79;
		case 77: goto tr80;
		case 78: goto tr81;
		case 83: goto tr82;
		case 87: goto tr83;
		case 89: goto tr84;
		case 92: goto tr73;
		case 95: goto tr85;
		case 97: goto tr86;
		case 99: goto tr87;
		case 100: goto tr88;
		case 104: goto st39;
		case 106: goto tr90;
		case 109: goto tr91;
		case 110: goto tr92;
		case 113: goto tr93;
		case 115: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( 44 <= (*p) && (*p) <= 47 )
		goto tr73;
	goto st0;
tr37:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st25;
tr63:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st25;
tr90:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st25;
tr118:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
#line 1411 "src/tfs_stata_parser.c"
	if ( (*p) == 106 )
		goto st26;
	goto st0;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	if ( (*p) == 106 )
		goto st39;
	goto st0;
tr38:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st27;
tr64:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st27;
tr91:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st27;
tr119:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 1468 "src/tfs_stata_parser.c"
	switch( (*p) ) {
		case 109: goto st39;
		case 111: goto st16;
	}
	goto st0;
tr39:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st28;
tr65:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st28;
tr92:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st28;
tr120:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st28;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
#line 1520 "src/tfs_stata_parser.c"
	if ( (*p) == 110 )
		goto st39;
	goto st0;
tr41:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st29;
tr67:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st29;
tr94:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st29;
tr122:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
#line 1570 "src/tfs_stata_parser.c"
	if ( (*p) == 115 )
		goto st39;
	goto st0;
tr42:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st30;
tr68:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st30;
tr95:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st30;
tr123:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 1620 "src/tfs_stata_parser.c"
	if ( (*p) == 119 )
		goto st39;
	goto st0;
tr43:
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st31;
tr69:
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st31;
tr96:
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st31;
tr124:
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
#line 29 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
#line 1670 "src/tfs_stata_parser.c"
	if ( (*p) == 121 )
		goto st39;
	goto st0;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	if ( (*p) == 104 )
		goto st39;
	goto st0;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	switch( (*p) ) {
		case 33: goto tr71;
		case 43: goto tr72;
		case 46: goto tr74;
		case 58: goto tr73;
		case 65: goto tr75;
		case 67: goto tr76;
		case 68: goto tr77;
		case 72: goto tr78;
		case 74: goto tr79;
		case 77: goto tr80;
		case 78: goto tr81;
		case 83: goto tr82;
		case 87: goto tr83;
		case 89: goto tr84;
		case 92: goto tr73;
		case 95: goto tr85;
		case 97: goto tr86;
		case 99: goto tr87;
		case 100: goto tr88;
		case 104: goto tr89;
		case 106: goto tr90;
		case 109: goto tr91;
		case 110: goto st33;
		case 113: goto tr93;
		case 115: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( 44 <= (*p) && (*p) <= 47 )
		goto tr73;
	goto st0;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	if ( (*p) == 97 )
		goto st34;
	goto st0;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	if ( (*p) == 109 )
		goto st35;
	goto st0;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	if ( (*p) == 101 )
		goto st39;
	goto st0;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	switch( (*p) ) {
		case 33: goto tr71;
		case 43: goto tr72;
		case 46: goto tr74;
		case 58: goto tr73;
		case 65: goto tr75;
		case 67: goto tr76;
		case 68: goto tr77;
		case 72: goto tr78;
		case 74: goto tr79;
		case 77: goto tr80;
		case 78: goto tr81;
		case 83: goto tr82;
		case 87: goto tr83;
		case 89: goto tr84;
		case 92: goto tr73;
		case 95: goto tr85;
		case 97: goto tr86;
		case 99: goto tr87;
		case 100: goto tr88;
		case 104: goto tr89;
		case 106: goto tr90;
		case 109: goto tr91;
		case 110: goto tr92;
		case 113: goto tr93;
		case 115: goto st47;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( 44 <= (*p) && (*p) <= 47 )
		goto tr73;
	goto st0;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	switch( (*p) ) {
		case 33: goto tr71;
		case 43: goto tr72;
		case 46: goto tr74;
		case 58: goto tr73;
		case 65: goto tr75;
		case 67: goto tr76;
		case 68: goto tr77;
		case 72: goto tr78;
		case 74: goto tr79;
		case 77: goto tr80;
		case 78: goto tr81;
		case 83: goto tr82;
		case 87: goto tr83;
		case 89: goto tr84;
		case 92: goto tr73;
		case 95: goto tr85;
		case 97: goto tr86;
		case 99: goto tr87;
		case 100: goto tr88;
		case 104: goto tr89;
		case 106: goto tr90;
		case 109: goto tr91;
		case 110: goto tr92;
		case 113: goto tr93;
		case 115: goto st39;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( 44 <= (*p) && (*p) <= 47 )
		goto tr73;
	goto st0;
	}
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 39: 
	case 40: 
	case 41: 
	case 43: 
	case 44: 
	case 45: 
	case 46: 
	case 47: 
#line 32 "src/tfs_stata_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	break;
	case 37: 
	case 38: 
#line 38 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	break;
	case 42: 
#line 44 "src/tfs_stata_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
           }
       }
	break;
#line 1895 "src/tfs_stata_parser.c"
	}
	}

	_out: {}
	}

#line 82 "src/tfs_stata_parser.rl"


    if (cs < 36) {
        printf("Error parsing Stata format string '%s' around col #%ld (%c)", 
                p, (long)(p - bytes + 1), *p);
        return 1;
    }

    return 0;
}
