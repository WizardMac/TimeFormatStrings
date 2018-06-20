
#line 1 "src/tfs_uts35_parser.rl"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include "tfs.h"
#include "tfs_internal.h"
#include "tfs_uts35_parser.h"

/* See http://www.unicode.org/reports/tr35/tr35-dates.html#Date_Format_Patterns */


#line 16 "src/tfs_uts35_parser.c"
static const int uts35_format_start = 7;

static const int uts35_format_en_main = 7;


#line 15 "src/tfs_uts35_parser.rl"


int tfs_parse_uts35_format_string_internal(const u_char *bytes, size_t len,
        tfs_handle_string_callback handle_literal_cb,
        tfs_handle_string_callback handle_code_cb, void *user_ctx) {
    u_char *p = (u_char *)bytes;
    u_char *pe = (u_char *)bytes + len;
    u_char *str_start = NULL;

    u_char *eof = pe;

    int cs;

   
#line 37 "src/tfs_uts35_parser.c"
	{
	cs = uts35_format_start;
	}

#line 42 "src/tfs_uts35_parser.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr51:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st7;
tr82:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st7;
tr169:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
#line 76 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr8;
		case 65: goto tr9;
		case 68: goto tr10;
		case 69: goto tr11;
		case 70: goto tr12;
		case 71: goto tr13;
		case 72: goto tr14;
		case 75: goto tr15;
		case 76: goto tr16;
		case 77: goto tr17;
		case 79: goto st39;
		case 81: goto tr19;
		case 83: goto tr20;
		case 85: goto tr21;
		case 87: goto tr12;
		case 89: goto tr22;
		case 97: goto tr12;
		case 99: goto tr23;
		case 100: goto tr24;
		case 101: goto tr25;
		case 103: goto tr26;
		case 104: goto tr27;
		case 107: goto tr28;
		case 109: goto tr29;
		case 113: goto tr30;
		case 115: goto tr31;
		case 117: goto tr32;
		case 118: goto st86;
		case 119: goto tr34;
		case 121: goto tr35;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto st7;
		} else if ( (*p) >= 0 )
			goto tr7;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr7;
		} else if ( (*p) >= 120 )
			goto st7;
	} else
		goto tr7;
	goto st0;
st0:
cs = 0;
	goto _out;
tr7:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st8;
tr66:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st8;
tr67:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st8;
tr155:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
#line 173 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr37;
		case 65: goto tr38;
		case 68: goto tr39;
		case 69: goto tr40;
		case 70: goto tr41;
		case 71: goto tr42;
		case 72: goto tr43;
		case 75: goto tr44;
		case 76: goto tr45;
		case 77: goto tr46;
		case 79: goto tr47;
		case 81: goto tr48;
		case 83: goto tr49;
		case 85: goto tr50;
		case 87: goto tr41;
		case 89: goto tr52;
		case 97: goto tr41;
		case 99: goto tr53;
		case 100: goto tr54;
		case 101: goto tr55;
		case 103: goto tr56;
		case 104: goto tr57;
		case 107: goto tr58;
		case 109: goto tr59;
		case 113: goto tr60;
		case 115: goto tr61;
		case 117: goto tr62;
		case 118: goto tr63;
		case 119: goto tr64;
		case 121: goto tr65;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr51;
		} else if ( (*p) >= 0 )
			goto st8;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st8;
		} else if ( (*p) >= 120 )
			goto tr51;
	} else
		goto st8;
	goto st0;
tr8:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st1;
tr37:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st1;
tr68:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st1;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
#line 255 "src/tfs_uts35_parser.c"
	if ( (*p) == 39 )
		goto st92;
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 39 )
		goto st9;
	goto st2;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	switch( (*p) ) {
		case 39: goto st2;
		case 65: goto tr38;
		case 68: goto tr39;
		case 69: goto tr40;
		case 70: goto tr41;
		case 71: goto tr42;
		case 72: goto tr43;
		case 75: goto tr44;
		case 76: goto tr45;
		case 77: goto tr46;
		case 79: goto tr47;
		case 81: goto tr48;
		case 83: goto tr49;
		case 85: goto tr50;
		case 87: goto tr41;
		case 89: goto tr52;
		case 97: goto tr41;
		case 99: goto tr53;
		case 100: goto tr54;
		case 101: goto tr55;
		case 103: goto tr56;
		case 104: goto tr57;
		case 107: goto tr58;
		case 109: goto tr59;
		case 113: goto tr60;
		case 115: goto tr61;
		case 117: goto tr62;
		case 118: goto tr63;
		case 119: goto tr64;
		case 121: goto tr65;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr51;
		} else if ( (*p) >= 0 )
			goto tr66;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr66;
		} else if ( (*p) >= 120 )
			goto tr51;
	} else
		goto tr66;
	goto st0;
tr9:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st10;
tr38:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st10;
tr103:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st10;
tr156:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
#line 363 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto st11;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto st12;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto st13;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto st14;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto st15;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto st16;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto st17;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr12:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st17;
tr41:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st17;
tr72:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st17;
tr159:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
#line 763 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr10:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st18;
tr39:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st18;
tr70:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st18;
tr157:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st18;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
#line 857 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto st19;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto st17;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr11:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st20;
tr40:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st20;
tr71:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st20;
tr158:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 1002 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto st21;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto st22;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto st23;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto st24;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto st17;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr13:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st25;
tr42:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st25;
tr73:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st25;
tr160:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
#line 1300 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto st26;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto st27;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto st28;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto st17;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr14:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st29;
tr43:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st29;
tr74:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st29;
tr161:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
#line 1547 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto st17;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr15:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st30;
tr44:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st30;
tr75:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st30;
tr162:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 1641 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto st17;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr16:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st31;
tr45:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st31;
tr76:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st31;
tr163:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
#line 1735 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto st32;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto st33;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto st34;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto st17;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr17:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st35;
tr46:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st35;
tr77:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st35;
tr164:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st35;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
#line 1982 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto st36;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto st37;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto st38;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto st17;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr47:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st39;
tr78:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st39;
tr165:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
#line 2211 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr8;
		case 65: goto tr9;
		case 68: goto tr10;
		case 69: goto tr11;
		case 70: goto tr12;
		case 71: goto tr13;
		case 72: goto tr14;
		case 75: goto tr15;
		case 76: goto tr16;
		case 77: goto tr17;
		case 79: goto st3;
		case 81: goto tr19;
		case 83: goto tr20;
		case 85: goto tr21;
		case 87: goto tr12;
		case 89: goto tr22;
		case 97: goto tr12;
		case 99: goto tr23;
		case 100: goto tr24;
		case 101: goto tr25;
		case 103: goto tr26;
		case 104: goto tr27;
		case 107: goto tr28;
		case 109: goto tr29;
		case 113: goto tr30;
		case 115: goto tr31;
		case 117: goto tr32;
		case 118: goto st86;
		case 119: goto tr34;
		case 121: goto tr35;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto st7;
		} else if ( (*p) >= 0 )
			goto tr7;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr7;
		} else if ( (*p) >= 120 )
			goto st7;
	} else
		goto tr7;
	goto st0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	if ( (*p) == 79 )
		goto st4;
	goto st0;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	if ( (*p) == 79 )
		goto st7;
	goto st0;
tr19:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st40;
tr48:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st40;
tr79:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st40;
tr166:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
#line 2319 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto st41;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto st42;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto st17;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr20:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st43;
tr49:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st43;
tr80:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st43;
tr167:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
#line 2515 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto st44;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto st45;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto st46;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto st47;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto st48;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto st49;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto st17;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr21:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st50;
tr50:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st50;
tr81:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st50;
tr168:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st50;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
#line 2915 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto st51;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto st52;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto st53;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto st17;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr22:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st54;
tr52:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st54;
tr83:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st54;
tr170:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
#line 3162 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto st55;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto st56;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto st57;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto st17;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr23:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st58;
tr53:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st58;
tr84:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st58;
tr171:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st58;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
#line 3409 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto st59;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto st60;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto st61;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto st62;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto st17;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr24:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st63;
tr54:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st63;
tr85:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st63;
tr172:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
#line 3707 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto st17;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr25:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st64;
tr55:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st64;
tr86:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st64;
tr173:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
#line 3801 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto st65;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto st66;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto st67;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto st68;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto st17;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr26:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st69;
tr56:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st69;
tr87:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st69;
tr174:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st69;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
#line 4099 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto st70;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto st71;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto st72;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto st73;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto st74;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto st17;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr27:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st75;
tr57:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st75;
tr88:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st75;
tr175:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st75;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
#line 4448 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto st17;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr28:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st76;
tr58:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st76;
tr89:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st76;
tr176:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st76;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
#line 4542 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto st17;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr29:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st77;
tr59:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st77;
tr90:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st77;
tr177:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st77;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
#line 4636 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto st17;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr30:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st78;
tr60:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st78;
tr91:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st78;
tr178:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st78;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
#line 4730 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto st79;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto st80;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto st17;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr31:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st81;
tr61:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st81;
tr92:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st81;
tr179:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st81;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
#line 4926 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto st17;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr32:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st82;
tr62:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st82;
tr93:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st82;
tr180:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st82;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
#line 5020 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto st83;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto st84;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto st85;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto st17;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr63:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st86;
tr94:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st86;
tr181:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
	goto st86;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
#line 5249 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr8;
		case 65: goto tr9;
		case 68: goto tr10;
		case 69: goto tr11;
		case 70: goto tr12;
		case 71: goto tr13;
		case 72: goto tr14;
		case 75: goto tr15;
		case 76: goto tr16;
		case 77: goto tr17;
		case 79: goto st39;
		case 81: goto tr19;
		case 83: goto tr20;
		case 85: goto tr21;
		case 87: goto tr12;
		case 89: goto tr22;
		case 97: goto tr12;
		case 99: goto tr23;
		case 100: goto tr24;
		case 101: goto tr25;
		case 103: goto tr26;
		case 104: goto tr27;
		case 107: goto tr28;
		case 109: goto tr29;
		case 113: goto tr30;
		case 115: goto tr31;
		case 117: goto tr32;
		case 118: goto st5;
		case 119: goto tr34;
		case 121: goto tr35;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto st7;
		} else if ( (*p) >= 0 )
			goto tr7;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr7;
		} else if ( (*p) >= 120 )
			goto st7;
	} else
		goto tr7;
	goto st0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	if ( (*p) == 118 )
		goto st6;
	goto st0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	if ( (*p) == 118 )
		goto st7;
	goto st0;
tr34:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st87;
tr64:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st87;
tr95:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st87;
tr182:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st87;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
#line 5357 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto st17;
		case 121: goto tr96;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
tr35:
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st88;
tr65:
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st88;
tr96:
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st88;
tr183:
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
#line 29 "src/tfs_uts35_parser.rl"
	{
           str_start = p;
       }
	goto st88;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
#line 5451 "src/tfs_uts35_parser.c"
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto st89;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto st90;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto st91;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	switch( (*p) ) {
		case 39: goto tr68;
		case 65: goto tr103;
		case 68: goto tr70;
		case 69: goto tr71;
		case 70: goto tr72;
		case 71: goto tr73;
		case 72: goto tr74;
		case 75: goto tr75;
		case 76: goto tr76;
		case 77: goto tr77;
		case 79: goto tr78;
		case 81: goto tr79;
		case 83: goto tr80;
		case 85: goto tr81;
		case 87: goto tr72;
		case 89: goto tr83;
		case 97: goto tr72;
		case 99: goto tr84;
		case 100: goto tr85;
		case 101: goto tr86;
		case 103: goto tr87;
		case 104: goto tr88;
		case 107: goto tr89;
		case 109: goto tr90;
		case 113: goto tr91;
		case 115: goto tr92;
		case 117: goto tr93;
		case 118: goto tr94;
		case 119: goto tr95;
		case 121: goto st17;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr82;
		} else if ( (*p) >= 0 )
			goto tr67;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr67;
		} else if ( (*p) >= 120 )
			goto tr82;
	} else
		goto tr67;
	goto st0;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	switch( (*p) ) {
		case 39: goto st2;
		case 65: goto tr156;
		case 68: goto tr157;
		case 69: goto tr158;
		case 70: goto tr159;
		case 71: goto tr160;
		case 72: goto tr161;
		case 75: goto tr162;
		case 76: goto tr163;
		case 77: goto tr164;
		case 79: goto tr165;
		case 81: goto tr166;
		case 83: goto tr167;
		case 85: goto tr168;
		case 87: goto tr159;
		case 89: goto tr170;
		case 97: goto tr159;
		case 99: goto tr171;
		case 100: goto tr172;
		case 101: goto tr173;
		case 103: goto tr174;
		case 104: goto tr175;
		case 107: goto tr176;
		case 109: goto tr177;
		case 113: goto tr178;
		case 115: goto tr179;
		case 117: goto tr180;
		case 118: goto tr181;
		case 119: goto tr182;
		case 121: goto tr183;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 64 ) {
			if ( 86 <= (*p) && (*p) <= 90 )
				goto tr169;
		} else if ( (*p) >= 0 )
			goto tr155;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto tr155;
		} else if ( (*p) >= 120 )
			goto tr169;
	} else
		goto tr155;
	goto st0;
	}
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof73: cs = 73; goto _test_eof; 
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof75: cs = 75; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof86: cs = 86; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof87: cs = 87; goto _test_eof; 
	_test_eof88: cs = 88; goto _test_eof; 
	_test_eof89: cs = 89; goto _test_eof; 
	_test_eof90: cs = 90; goto _test_eof; 
	_test_eof91: cs = 91; goto _test_eof; 
	_test_eof92: cs = 92; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 10: 
	case 11: 
	case 12: 
	case 13: 
	case 14: 
	case 15: 
	case 16: 
	case 17: 
	case 18: 
	case 19: 
	case 20: 
	case 21: 
	case 22: 
	case 23: 
	case 24: 
	case 25: 
	case 26: 
	case 27: 
	case 28: 
	case 29: 
	case 30: 
	case 31: 
	case 32: 
	case 33: 
	case 34: 
	case 35: 
	case 36: 
	case 37: 
	case 38: 
	case 40: 
	case 41: 
	case 42: 
	case 43: 
	case 44: 
	case 45: 
	case 46: 
	case 47: 
	case 48: 
	case 49: 
	case 50: 
	case 51: 
	case 52: 
	case 53: 
	case 54: 
	case 55: 
	case 56: 
	case 57: 
	case 58: 
	case 59: 
	case 60: 
	case 61: 
	case 62: 
	case 63: 
	case 64: 
	case 65: 
	case 66: 
	case 67: 
	case 68: 
	case 69: 
	case 70: 
	case 71: 
	case 72: 
	case 73: 
	case 74: 
	case 75: 
	case 76: 
	case 77: 
	case 78: 
	case 79: 
	case 80: 
	case 81: 
	case 82: 
	case 83: 
	case 84: 
	case 85: 
	case 87: 
	case 88: 
	case 89: 
	case 90: 
	case 91: 
#line 32 "src/tfs_uts35_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	break;
	case 8: 
	case 9: 
#line 38 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	break;
	case 92: 
#line 44 "src/tfs_uts35_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb("''''", 4, user_ctx);
           }
       }
	break;
#line 5905 "src/tfs_uts35_parser.c"
	}
	}

	_out: {}
	}

#line 90 "src/tfs_uts35_parser.rl"


    (void)uts35_format_en_main;

    if (cs < 7) {
        printf("Error parsing UTS35 format string around col #%ld (%c)\n", 
                (long)(p + 1 - bytes), *p);
        return 1;
    }

    return 0;
}
