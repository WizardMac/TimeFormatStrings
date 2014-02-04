
#line 1 "src/tfs_excel_parser.rl"

#include <sys/types.h>
#include <stdio.h>
#include "tfs.h"
#include "tfs_internal.h"
#include "tfs_excel_parser.h"

/* See http://office.microsoft.com/en-us/excel-help/text-function-HP010062580.aspx */


#line 14 "src/tfs_excel_parser.c"
static const int excel_format_start = 89;
static const int excel_format_first_final = 89;
static const int excel_format_error = 0;

static const int excel_format_en_main = 89;


#line 13 "src/tfs_excel_parser.rl"


int tfs_parse_excel_format_string_internal(const u_char *bytes, size_t len,
        tfs_handle_string_callback handle_literal_cb,
        tfs_handle_string_callback handle_code_cb, void *user_ctx) {
    u_char *p = (u_char *)bytes;
    u_char *pe = (u_char *)bytes + len;
    u_char *str_start = NULL;

    u_char *eof = pe;

    int cs;

   
#line 37 "src/tfs_excel_parser.c"
	{
	cs = excel_format_start;
	}

#line 42 "src/tfs_excel_parser.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 89:
	switch( (*p) ) {
		case 34: goto tr69;
		case 35: goto st91;
		case 37: goto st91;
		case 42: goto st3;
		case 44: goto st91;
		case 46: goto st91;
		case 48: goto st91;
		case 59: goto st92;
		case 65: goto tr72;
		case 68: goto tr73;
		case 69: goto st71;
		case 72: goto tr75;
		case 77: goto tr76;
		case 80: goto tr77;
		case 91: goto st87;
		case 92: goto st80;
		case 94: goto tr64;
		case 95: goto st3;
		case 97: goto tr80;
		case 100: goto tr81;
		case 101: goto st71;
		case 104: goto tr82;
		case 109: goto tr83;
		case 112: goto tr84;
		case 115: goto tr85;
		case 121: goto tr86;
		case 123: goto tr64;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr64;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr64;
		} else if ( (*p) >= 63 )
			goto st91;
	} else
		goto tr64;
	goto st0;
st0:
cs = 0;
	goto _out;
tr64:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st90;
tr87:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st90;
tr327:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st90;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
#line 127 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr88;
		case 35: goto tr89;
		case 37: goto tr89;
		case 42: goto tr90;
		case 44: goto tr89;
		case 46: goto tr89;
		case 48: goto tr89;
		case 59: goto tr91;
		case 65: goto tr92;
		case 68: goto tr93;
		case 69: goto tr94;
		case 72: goto tr95;
		case 77: goto tr96;
		case 80: goto tr97;
		case 91: goto tr98;
		case 92: goto tr99;
		case 94: goto tr87;
		case 95: goto tr90;
		case 97: goto tr100;
		case 100: goto tr101;
		case 101: goto tr94;
		case 104: goto tr102;
		case 109: goto tr103;
		case 112: goto tr104;
		case 115: goto tr105;
		case 121: goto tr106;
		case 123: goto tr87;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr87;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr87;
		} else if ( (*p) >= 63 )
			goto tr89;
	} else
		goto tr87;
	goto st0;
tr69:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st1;
tr88:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st1;
tr328:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st1;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
#line 203 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto st90;
		case 92: goto st2;
	}
	goto st1;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 34 )
		goto st1;
	goto st0;
tr89:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st91;
tr329:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st91;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
#line 236 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr69;
		case 35: goto st91;
		case 37: goto st91;
		case 42: goto st3;
		case 44: goto st91;
		case 46: goto st91;
		case 48: goto st91;
		case 59: goto st92;
		case 65: goto tr72;
		case 68: goto tr73;
		case 69: goto st71;
		case 72: goto tr75;
		case 77: goto tr76;
		case 80: goto tr77;
		case 91: goto st72;
		case 92: goto st80;
		case 94: goto tr64;
		case 95: goto st3;
		case 97: goto tr80;
		case 100: goto tr81;
		case 101: goto st71;
		case 104: goto tr82;
		case 109: goto tr83;
		case 112: goto tr84;
		case 115: goto tr85;
		case 121: goto tr86;
		case 123: goto tr64;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr64;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr64;
		} else if ( (*p) >= 63 )
			goto st91;
	} else
		goto tr64;
	goto st0;
tr90:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st3;
tr330:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 298 "src/tfs_excel_parser.c"
	goto st91;
tr91:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st92;
tr332:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st92;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
#line 320 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr108;
		case 35: goto st94;
		case 37: goto st94;
		case 42: goto st6;
		case 44: goto st94;
		case 46: goto st94;
		case 48: goto st94;
		case 59: goto st95;
		case 65: goto tr111;
		case 68: goto tr112;
		case 69: goto st52;
		case 72: goto tr114;
		case 77: goto tr115;
		case 80: goto tr116;
		case 91: goto st68;
		case 92: goto st61;
		case 94: goto tr51;
		case 95: goto st6;
		case 97: goto tr119;
		case 100: goto tr120;
		case 101: goto st52;
		case 104: goto tr121;
		case 109: goto tr122;
		case 112: goto tr123;
		case 115: goto tr124;
		case 121: goto tr125;
		case 123: goto tr51;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr51;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr51;
		} else if ( (*p) >= 63 )
			goto st94;
	} else
		goto tr51;
	goto st0;
tr51:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st93;
tr126:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st93;
tr292:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st93;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
#line 396 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr127;
		case 35: goto tr128;
		case 37: goto tr128;
		case 42: goto tr129;
		case 44: goto tr128;
		case 46: goto tr128;
		case 48: goto tr128;
		case 59: goto tr130;
		case 65: goto tr131;
		case 68: goto tr132;
		case 69: goto tr133;
		case 72: goto tr134;
		case 77: goto tr135;
		case 80: goto tr136;
		case 91: goto tr137;
		case 92: goto tr138;
		case 94: goto tr126;
		case 95: goto tr129;
		case 97: goto tr139;
		case 100: goto tr140;
		case 101: goto tr133;
		case 104: goto tr141;
		case 109: goto tr142;
		case 112: goto tr143;
		case 115: goto tr144;
		case 121: goto tr145;
		case 123: goto tr126;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr126;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr126;
		} else if ( (*p) >= 63 )
			goto tr128;
	} else
		goto tr126;
	goto st0;
tr108:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st4;
tr127:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st4;
tr293:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 472 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto st93;
		case 92: goto st5;
	}
	goto st4;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	if ( (*p) == 34 )
		goto st4;
	goto st0;
tr128:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st94;
tr294:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st94;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
#line 505 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr108;
		case 35: goto st94;
		case 37: goto st94;
		case 42: goto st6;
		case 44: goto st94;
		case 46: goto st94;
		case 48: goto st94;
		case 59: goto st95;
		case 65: goto tr111;
		case 68: goto tr112;
		case 69: goto st52;
		case 72: goto tr114;
		case 77: goto tr115;
		case 80: goto tr116;
		case 91: goto st53;
		case 92: goto st61;
		case 94: goto tr51;
		case 95: goto st6;
		case 97: goto tr119;
		case 100: goto tr120;
		case 101: goto st52;
		case 104: goto tr121;
		case 109: goto tr122;
		case 112: goto tr123;
		case 115: goto tr124;
		case 121: goto tr125;
		case 123: goto tr51;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr51;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr51;
		} else if ( (*p) >= 63 )
			goto st94;
	} else
		goto tr51;
	goto st0;
tr129:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st6;
tr295:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
#line 567 "src/tfs_excel_parser.c"
	goto st94;
tr130:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st95;
tr297:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st95;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
#line 589 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr147;
		case 35: goto st97;
		case 37: goto st97;
		case 42: goto st9;
		case 44: goto st97;
		case 46: goto st97;
		case 48: goto st97;
		case 59: goto st98;
		case 65: goto tr150;
		case 68: goto tr151;
		case 69: goto st33;
		case 72: goto tr153;
		case 77: goto tr154;
		case 80: goto tr155;
		case 91: goto st49;
		case 92: goto st42;
		case 94: goto tr38;
		case 95: goto st9;
		case 97: goto tr158;
		case 100: goto tr159;
		case 101: goto st33;
		case 104: goto tr160;
		case 109: goto tr161;
		case 112: goto tr162;
		case 115: goto tr163;
		case 121: goto tr164;
		case 123: goto tr38;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr38;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr38;
		} else if ( (*p) >= 63 )
			goto st97;
	} else
		goto tr38;
	goto st0;
tr38:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st96;
tr165:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st96;
tr257:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st96;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
#line 665 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr166;
		case 35: goto tr167;
		case 37: goto tr167;
		case 42: goto tr168;
		case 44: goto tr167;
		case 46: goto tr167;
		case 48: goto tr167;
		case 59: goto tr169;
		case 65: goto tr170;
		case 68: goto tr171;
		case 69: goto tr172;
		case 72: goto tr173;
		case 77: goto tr174;
		case 80: goto tr175;
		case 91: goto tr176;
		case 92: goto tr177;
		case 94: goto tr165;
		case 95: goto tr168;
		case 97: goto tr178;
		case 100: goto tr179;
		case 101: goto tr172;
		case 104: goto tr180;
		case 109: goto tr181;
		case 112: goto tr182;
		case 115: goto tr183;
		case 121: goto tr184;
		case 123: goto tr165;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr165;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr165;
		} else if ( (*p) >= 63 )
			goto tr167;
	} else
		goto tr165;
	goto st0;
tr147:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st7;
tr166:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st7;
tr258:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
#line 741 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto st96;
		case 92: goto st8;
	}
	goto st7;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	if ( (*p) == 34 )
		goto st7;
	goto st0;
tr167:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st97;
tr259:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st97;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
#line 774 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr147;
		case 35: goto st97;
		case 37: goto st97;
		case 42: goto st9;
		case 44: goto st97;
		case 46: goto st97;
		case 48: goto st97;
		case 59: goto st98;
		case 65: goto tr150;
		case 68: goto tr151;
		case 69: goto st33;
		case 72: goto tr153;
		case 77: goto tr154;
		case 80: goto tr155;
		case 91: goto st34;
		case 92: goto st42;
		case 94: goto tr38;
		case 95: goto st9;
		case 97: goto tr158;
		case 100: goto tr159;
		case 101: goto st33;
		case 104: goto tr160;
		case 109: goto tr161;
		case 112: goto tr162;
		case 115: goto tr163;
		case 121: goto tr164;
		case 123: goto tr38;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr38;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr38;
		} else if ( (*p) >= 63 )
			goto st97;
	} else
		goto tr38;
	goto st0;
tr168:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st9;
tr260:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st9;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
#line 836 "src/tfs_excel_parser.c"
	goto st97;
tr169:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st98;
tr262:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st98;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
#line 858 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr186;
		case 35: goto st100;
		case 37: goto st100;
		case 42: goto st12;
		case 44: goto st100;
		case 46: goto st100;
		case 48: goto st100;
		case 58: goto tr25;
		case 65: goto tr188;
		case 68: goto tr189;
		case 69: goto st14;
		case 72: goto tr191;
		case 77: goto tr192;
		case 80: goto tr193;
		case 91: goto st30;
		case 92: goto st23;
		case 94: goto tr25;
		case 95: goto st12;
		case 97: goto tr196;
		case 100: goto tr197;
		case 101: goto st14;
		case 104: goto tr198;
		case 109: goto tr199;
		case 112: goto tr200;
		case 115: goto tr201;
		case 121: goto tr202;
		case 123: goto tr25;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr25;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr25;
		} else if ( (*p) >= 63 )
			goto st100;
	} else
		goto tr25;
	goto st0;
tr25:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st99;
tr203:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st99;
tr223:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st99;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
#line 934 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr204;
		case 35: goto tr205;
		case 37: goto tr205;
		case 42: goto tr206;
		case 44: goto tr205;
		case 46: goto tr205;
		case 48: goto tr205;
		case 58: goto tr203;
		case 65: goto tr207;
		case 68: goto tr208;
		case 69: goto tr209;
		case 72: goto tr210;
		case 77: goto tr211;
		case 80: goto tr212;
		case 91: goto tr213;
		case 92: goto tr214;
		case 94: goto tr203;
		case 95: goto tr206;
		case 97: goto tr215;
		case 100: goto tr216;
		case 101: goto tr209;
		case 104: goto tr217;
		case 109: goto tr218;
		case 112: goto tr219;
		case 115: goto tr220;
		case 121: goto tr221;
		case 123: goto tr203;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr203;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr203;
		} else if ( (*p) >= 63 )
			goto tr205;
	} else
		goto tr203;
	goto st0;
tr186:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st10;
tr204:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st10;
tr224:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
#line 1010 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto st99;
		case 92: goto st11;
	}
	goto st10;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	if ( (*p) == 34 )
		goto st10;
	goto st0;
tr205:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st100;
tr225:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st100;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
#line 1043 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr186;
		case 35: goto st100;
		case 37: goto st100;
		case 42: goto st12;
		case 44: goto st100;
		case 46: goto st100;
		case 48: goto st100;
		case 58: goto tr25;
		case 65: goto tr188;
		case 68: goto tr189;
		case 69: goto st14;
		case 72: goto tr191;
		case 77: goto tr192;
		case 80: goto tr193;
		case 91: goto st15;
		case 92: goto st23;
		case 94: goto tr25;
		case 95: goto st12;
		case 97: goto tr196;
		case 100: goto tr197;
		case 101: goto st14;
		case 104: goto tr198;
		case 109: goto tr199;
		case 112: goto tr200;
		case 115: goto tr201;
		case 121: goto tr202;
		case 123: goto tr25;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr25;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr25;
		} else if ( (*p) >= 63 )
			goto st100;
	} else
		goto tr25;
	goto st0;
tr206:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st12;
tr226:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 1105 "src/tfs_excel_parser.c"
	goto st100;
tr188:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st101;
tr207:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st101;
tr228:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st101;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
#line 1141 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr224;
		case 35: goto tr225;
		case 37: goto tr225;
		case 42: goto tr226;
		case 44: goto tr225;
		case 47: goto st13;
		case 58: goto tr223;
		case 65: goto tr228;
		case 68: goto tr229;
		case 69: goto tr230;
		case 72: goto tr231;
		case 77: goto st117;
		case 80: goto tr233;
		case 91: goto tr234;
		case 92: goto tr235;
		case 94: goto tr223;
		case 95: goto tr226;
		case 97: goto tr236;
		case 100: goto tr237;
		case 101: goto tr230;
		case 104: goto tr238;
		case 109: goto tr239;
		case 112: goto tr240;
		case 115: goto tr241;
		case 121: goto tr242;
		case 123: goto tr223;
	}
	if ( (*p) < 60 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr225;
		} else if ( (*p) >= 32 )
			goto tr223;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr223;
		} else if ( (*p) >= 63 )
			goto tr225;
	} else
		goto tr223;
	goto st0;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	if ( (*p) == 80 )
		goto st102;
	goto st0;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	switch( (*p) ) {
		case 34: goto tr224;
		case 35: goto tr225;
		case 37: goto tr225;
		case 42: goto tr226;
		case 44: goto tr225;
		case 46: goto tr225;
		case 48: goto tr225;
		case 58: goto tr223;
		case 65: goto tr228;
		case 68: goto tr229;
		case 69: goto tr230;
		case 72: goto tr231;
		case 77: goto tr243;
		case 80: goto tr233;
		case 91: goto tr234;
		case 92: goto tr235;
		case 94: goto tr223;
		case 95: goto tr226;
		case 97: goto tr236;
		case 100: goto tr237;
		case 101: goto tr230;
		case 104: goto tr238;
		case 109: goto tr239;
		case 112: goto tr240;
		case 115: goto tr241;
		case 121: goto tr242;
		case 123: goto tr223;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr223;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr223;
		} else if ( (*p) >= 63 )
			goto tr225;
	} else
		goto tr223;
	goto st0;
tr189:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st103;
tr208:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st103;
tr229:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st103;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
#line 1271 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr224;
		case 35: goto tr225;
		case 37: goto tr225;
		case 42: goto tr226;
		case 44: goto tr225;
		case 46: goto tr225;
		case 48: goto tr225;
		case 58: goto tr223;
		case 65: goto tr228;
		case 68: goto st103;
		case 69: goto tr230;
		case 72: goto tr231;
		case 77: goto tr243;
		case 80: goto tr233;
		case 91: goto tr234;
		case 92: goto tr235;
		case 94: goto tr223;
		case 95: goto tr226;
		case 97: goto tr236;
		case 100: goto tr237;
		case 101: goto tr230;
		case 104: goto tr238;
		case 109: goto tr239;
		case 112: goto tr240;
		case 115: goto tr241;
		case 121: goto tr242;
		case 123: goto tr223;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr223;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr223;
		} else if ( (*p) >= 63 )
			goto tr225;
	} else
		goto tr223;
	goto st0;
tr209:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st14;
tr230:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st14;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
#line 1333 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 43: goto st100;
		case 45: goto st100;
	}
	goto st0;
tr191:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st104;
tr210:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st104;
tr231:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st104;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
#line 1373 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr224;
		case 35: goto tr225;
		case 37: goto tr225;
		case 42: goto tr226;
		case 44: goto tr225;
		case 46: goto tr225;
		case 48: goto tr225;
		case 58: goto tr223;
		case 65: goto tr228;
		case 68: goto tr229;
		case 69: goto tr230;
		case 72: goto st104;
		case 77: goto tr243;
		case 80: goto tr233;
		case 91: goto tr234;
		case 92: goto tr235;
		case 94: goto tr223;
		case 95: goto tr226;
		case 97: goto tr236;
		case 100: goto tr237;
		case 101: goto tr230;
		case 104: goto tr238;
		case 109: goto tr239;
		case 112: goto tr240;
		case 115: goto tr241;
		case 121: goto tr242;
		case 123: goto tr223;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr223;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr223;
		} else if ( (*p) >= 63 )
			goto tr225;
	} else
		goto tr223;
	goto st0;
tr192:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st105;
tr211:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st105;
tr243:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st105;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
#line 1449 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr224;
		case 35: goto tr225;
		case 37: goto tr225;
		case 42: goto tr226;
		case 44: goto tr225;
		case 46: goto tr225;
		case 48: goto tr225;
		case 58: goto tr223;
		case 65: goto tr228;
		case 68: goto tr229;
		case 69: goto tr230;
		case 72: goto tr231;
		case 77: goto st105;
		case 80: goto tr233;
		case 91: goto tr234;
		case 92: goto tr235;
		case 94: goto tr223;
		case 95: goto tr226;
		case 97: goto tr236;
		case 100: goto tr237;
		case 101: goto tr230;
		case 104: goto tr238;
		case 109: goto tr239;
		case 112: goto tr240;
		case 115: goto tr241;
		case 121: goto tr242;
		case 123: goto tr223;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr223;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr223;
		} else if ( (*p) >= 63 )
			goto tr225;
	} else
		goto tr223;
	goto st0;
tr193:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st106;
tr212:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st106;
tr233:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st106;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
#line 1525 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr224;
		case 35: goto tr225;
		case 37: goto tr225;
		case 42: goto tr226;
		case 44: goto tr225;
		case 46: goto tr225;
		case 48: goto tr225;
		case 58: goto tr223;
		case 65: goto tr228;
		case 68: goto tr229;
		case 69: goto tr230;
		case 72: goto tr231;
		case 77: goto st102;
		case 80: goto tr233;
		case 91: goto tr234;
		case 92: goto tr235;
		case 94: goto tr223;
		case 95: goto tr226;
		case 97: goto tr236;
		case 100: goto tr237;
		case 101: goto tr230;
		case 104: goto tr238;
		case 109: goto tr239;
		case 112: goto tr240;
		case 115: goto tr241;
		case 121: goto tr242;
		case 123: goto tr223;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr223;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr223;
		} else if ( (*p) >= 63 )
			goto tr225;
	} else
		goto tr223;
	goto st0;
tr213:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st15;
tr234:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
#line 1587 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 60: goto st16;
		case 61: goto st21;
		case 62: goto st22;
	}
	goto st0;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	switch( (*p) ) {
		case 45: goto st17;
		case 46: goto st18;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 62 )
			goto st21;
	} else if ( (*p) >= 48 )
		goto st20;
	goto st0;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	if ( (*p) == 46 )
		goto st18;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st20;
	goto st0;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st19;
	goto st0;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	if ( (*p) == 93 )
		goto st100;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st19;
	goto st0;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	switch( (*p) ) {
		case 46: goto st18;
		case 93: goto st100;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st20;
	goto st0;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	switch( (*p) ) {
		case 45: goto st17;
		case 46: goto st18;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st20;
	goto st0;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	switch( (*p) ) {
		case 45: goto st17;
		case 46: goto st18;
		case 61: goto st21;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st20;
	goto st0;
tr214:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st23;
tr235:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
#line 1687 "src/tfs_excel_parser.c"
	goto tr25;
tr196:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st107;
tr215:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st107;
tr236:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st107;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
#line 1723 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr224;
		case 35: goto tr225;
		case 37: goto tr225;
		case 42: goto tr226;
		case 44: goto tr225;
		case 47: goto st24;
		case 58: goto tr223;
		case 65: goto tr228;
		case 68: goto tr229;
		case 69: goto tr230;
		case 72: goto tr231;
		case 77: goto tr243;
		case 80: goto tr233;
		case 91: goto tr234;
		case 92: goto tr235;
		case 94: goto tr223;
		case 95: goto tr226;
		case 97: goto tr236;
		case 100: goto tr237;
		case 101: goto tr230;
		case 104: goto tr238;
		case 109: goto st116;
		case 112: goto tr240;
		case 115: goto tr241;
		case 121: goto tr242;
		case 123: goto tr223;
	}
	if ( (*p) < 60 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr225;
		} else if ( (*p) >= 32 )
			goto tr223;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr223;
		} else if ( (*p) >= 63 )
			goto tr225;
	} else
		goto tr223;
	goto st0;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	if ( (*p) == 112 )
		goto st102;
	goto st0;
tr197:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st108;
tr216:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st108;
tr237:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st108;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
#line 1808 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr224;
		case 35: goto tr225;
		case 37: goto tr225;
		case 42: goto tr226;
		case 44: goto tr225;
		case 46: goto tr225;
		case 48: goto tr225;
		case 58: goto tr223;
		case 65: goto tr228;
		case 68: goto tr229;
		case 69: goto tr230;
		case 72: goto tr231;
		case 77: goto tr243;
		case 80: goto tr233;
		case 91: goto tr234;
		case 92: goto tr235;
		case 94: goto tr223;
		case 95: goto tr226;
		case 97: goto tr236;
		case 100: goto st108;
		case 101: goto tr230;
		case 104: goto tr238;
		case 109: goto tr239;
		case 112: goto tr240;
		case 115: goto tr241;
		case 121: goto tr242;
		case 123: goto tr223;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr223;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr223;
		} else if ( (*p) >= 63 )
			goto tr225;
	} else
		goto tr223;
	goto st0;
tr198:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st109;
tr217:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st109;
tr238:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st109;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
#line 1884 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr224;
		case 35: goto tr225;
		case 37: goto tr225;
		case 42: goto tr226;
		case 44: goto tr225;
		case 46: goto tr225;
		case 48: goto tr225;
		case 58: goto tr223;
		case 65: goto tr228;
		case 68: goto tr229;
		case 69: goto tr230;
		case 72: goto tr231;
		case 77: goto tr243;
		case 80: goto tr233;
		case 91: goto tr234;
		case 92: goto tr235;
		case 94: goto tr223;
		case 95: goto tr226;
		case 97: goto tr236;
		case 100: goto tr237;
		case 101: goto tr230;
		case 104: goto st109;
		case 109: goto tr239;
		case 112: goto tr240;
		case 115: goto tr241;
		case 121: goto tr242;
		case 123: goto tr223;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr223;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr223;
		} else if ( (*p) >= 63 )
			goto tr225;
	} else
		goto tr223;
	goto st0;
tr199:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st110;
tr218:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st110;
tr239:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st110;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
#line 1960 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr224;
		case 35: goto tr225;
		case 37: goto tr225;
		case 42: goto tr226;
		case 44: goto tr225;
		case 46: goto tr225;
		case 48: goto tr225;
		case 58: goto tr223;
		case 65: goto tr228;
		case 68: goto tr229;
		case 69: goto tr230;
		case 72: goto tr231;
		case 77: goto tr243;
		case 80: goto tr233;
		case 91: goto tr234;
		case 92: goto tr235;
		case 94: goto tr223;
		case 95: goto tr226;
		case 97: goto tr236;
		case 100: goto tr237;
		case 101: goto tr230;
		case 104: goto tr238;
		case 109: goto st110;
		case 112: goto tr240;
		case 115: goto tr241;
		case 121: goto tr242;
		case 123: goto tr223;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr223;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr223;
		} else if ( (*p) >= 63 )
			goto tr225;
	} else
		goto tr223;
	goto st0;
tr200:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st111;
tr219:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st111;
tr240:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st111;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
#line 2036 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr224;
		case 35: goto tr225;
		case 37: goto tr225;
		case 42: goto tr226;
		case 44: goto tr225;
		case 46: goto tr225;
		case 48: goto tr225;
		case 58: goto tr223;
		case 65: goto tr228;
		case 68: goto tr229;
		case 69: goto tr230;
		case 72: goto tr231;
		case 77: goto tr243;
		case 80: goto tr233;
		case 91: goto tr234;
		case 92: goto tr235;
		case 94: goto tr223;
		case 95: goto tr226;
		case 97: goto tr236;
		case 100: goto tr237;
		case 101: goto tr230;
		case 104: goto tr238;
		case 109: goto st102;
		case 112: goto tr240;
		case 115: goto tr241;
		case 121: goto tr242;
		case 123: goto tr223;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr223;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr223;
		} else if ( (*p) >= 63 )
			goto tr225;
	} else
		goto tr223;
	goto st0;
tr201:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st112;
tr220:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st112;
tr241:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st112;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
#line 2112 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr224;
		case 35: goto tr225;
		case 37: goto tr225;
		case 42: goto tr226;
		case 44: goto tr225;
		case 46: goto st25;
		case 48: goto tr225;
		case 58: goto tr223;
		case 65: goto tr228;
		case 68: goto tr229;
		case 69: goto tr230;
		case 72: goto tr231;
		case 77: goto tr243;
		case 80: goto tr233;
		case 91: goto tr234;
		case 92: goto tr235;
		case 94: goto tr223;
		case 95: goto tr226;
		case 97: goto tr236;
		case 100: goto tr237;
		case 101: goto tr230;
		case 104: goto tr238;
		case 109: goto tr239;
		case 112: goto tr240;
		case 115: goto st115;
		case 121: goto tr242;
		case 123: goto tr223;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr223;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr223;
		} else if ( (*p) >= 63 )
			goto tr225;
	} else
		goto tr223;
	goto st0;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	switch( (*p) ) {
		case 35: goto st113;
		case 44: goto st113;
		case 48: goto st113;
		case 63: goto st113;
	}
	goto st0;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	switch( (*p) ) {
		case 34: goto tr224;
		case 35: goto st113;
		case 37: goto tr225;
		case 42: goto tr226;
		case 44: goto st113;
		case 46: goto tr225;
		case 48: goto st113;
		case 58: goto tr223;
		case 63: goto st113;
		case 64: goto tr225;
		case 65: goto tr228;
		case 68: goto tr229;
		case 69: goto tr230;
		case 72: goto tr231;
		case 77: goto tr243;
		case 80: goto tr233;
		case 91: goto tr234;
		case 92: goto tr235;
		case 94: goto tr223;
		case 95: goto tr226;
		case 97: goto tr236;
		case 100: goto tr237;
		case 101: goto tr230;
		case 104: goto tr238;
		case 109: goto tr239;
		case 112: goto tr240;
		case 115: goto tr241;
		case 121: goto tr242;
		case 123: goto tr223;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr223;
	} else if ( (*p) > 62 ) {
		if ( 125 <= (*p) && (*p) <= 126 )
			goto tr223;
	} else
		goto tr223;
	goto st0;
tr202:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st114;
tr221:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st114;
tr242:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st114;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
#line 2243 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr224;
		case 35: goto tr225;
		case 37: goto tr225;
		case 42: goto tr226;
		case 44: goto tr225;
		case 46: goto tr225;
		case 48: goto tr225;
		case 58: goto tr223;
		case 65: goto tr228;
		case 68: goto tr229;
		case 69: goto tr230;
		case 72: goto tr231;
		case 77: goto tr243;
		case 80: goto tr233;
		case 91: goto tr234;
		case 92: goto tr235;
		case 94: goto tr223;
		case 95: goto tr226;
		case 97: goto tr236;
		case 100: goto tr237;
		case 101: goto tr230;
		case 104: goto tr238;
		case 109: goto tr239;
		case 112: goto tr240;
		case 115: goto tr241;
		case 121: goto st114;
		case 123: goto tr223;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr223;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr223;
		} else if ( (*p) >= 63 )
			goto tr225;
	} else
		goto tr223;
	goto st0;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	switch( (*p) ) {
		case 34: goto tr224;
		case 35: goto tr225;
		case 37: goto tr225;
		case 42: goto tr226;
		case 44: goto tr225;
		case 46: goto st25;
		case 48: goto tr225;
		case 58: goto tr223;
		case 65: goto tr228;
		case 68: goto tr229;
		case 69: goto tr230;
		case 72: goto tr231;
		case 77: goto tr243;
		case 80: goto tr233;
		case 91: goto tr234;
		case 92: goto tr235;
		case 94: goto tr223;
		case 95: goto tr226;
		case 97: goto tr236;
		case 100: goto tr237;
		case 101: goto tr230;
		case 104: goto tr238;
		case 109: goto tr239;
		case 112: goto tr240;
		case 115: goto tr241;
		case 121: goto tr242;
		case 123: goto tr223;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr223;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr223;
		} else if ( (*p) >= 63 )
			goto tr225;
	} else
		goto tr223;
	goto st0;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
	switch( (*p) ) {
		case 34: goto tr224;
		case 35: goto tr225;
		case 37: goto tr225;
		case 42: goto tr226;
		case 44: goto tr225;
		case 47: goto st26;
		case 58: goto tr223;
		case 65: goto tr228;
		case 68: goto tr229;
		case 69: goto tr230;
		case 72: goto tr231;
		case 77: goto tr243;
		case 80: goto tr233;
		case 91: goto tr234;
		case 92: goto tr235;
		case 94: goto tr223;
		case 95: goto tr226;
		case 97: goto tr236;
		case 100: goto tr237;
		case 101: goto tr230;
		case 104: goto tr238;
		case 109: goto tr239;
		case 112: goto tr240;
		case 115: goto tr241;
		case 121: goto tr242;
		case 123: goto tr223;
	}
	if ( (*p) < 60 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr225;
		} else if ( (*p) >= 32 )
			goto tr223;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr223;
		} else if ( (*p) >= 63 )
			goto tr225;
	} else
		goto tr223;
	goto st0;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	if ( (*p) == 112 )
		goto st27;
	goto st0;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
	if ( (*p) == 109 )
		goto st102;
	goto st0;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	switch( (*p) ) {
		case 34: goto tr224;
		case 35: goto tr225;
		case 37: goto tr225;
		case 42: goto tr226;
		case 44: goto tr225;
		case 47: goto st28;
		case 58: goto tr223;
		case 65: goto tr228;
		case 68: goto tr229;
		case 69: goto tr230;
		case 72: goto tr231;
		case 77: goto tr243;
		case 80: goto tr233;
		case 91: goto tr234;
		case 92: goto tr235;
		case 94: goto tr223;
		case 95: goto tr226;
		case 97: goto tr236;
		case 100: goto tr237;
		case 101: goto tr230;
		case 104: goto tr238;
		case 109: goto tr239;
		case 112: goto tr240;
		case 115: goto tr241;
		case 121: goto tr242;
		case 123: goto tr223;
	}
	if ( (*p) < 60 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr225;
		} else if ( (*p) >= 32 )
			goto tr223;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr223;
		} else if ( (*p) >= 63 )
			goto tr225;
	} else
		goto tr223;
	goto st0;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	if ( (*p) == 80 )
		goto st29;
	goto st0;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	if ( (*p) == 77 )
		goto st102;
	goto st0;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	switch( (*p) ) {
		case 60: goto st16;
		case 61: goto st21;
		case 62: goto st22;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st31;
	} else if ( (*p) >= 65 )
		goto st31;
	goto st0;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	if ( (*p) == 93 )
		goto st100;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st31;
	} else if ( (*p) >= 65 )
		goto st31;
	goto st0;
tr150:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st118;
tr170:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st118;
tr263:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st118;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
#line 2513 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr258;
		case 35: goto tr259;
		case 37: goto tr259;
		case 42: goto tr260;
		case 44: goto tr259;
		case 47: goto st32;
		case 59: goto tr262;
		case 65: goto tr263;
		case 68: goto tr264;
		case 69: goto tr265;
		case 72: goto tr266;
		case 77: goto st134;
		case 80: goto tr268;
		case 91: goto tr269;
		case 92: goto tr270;
		case 94: goto tr257;
		case 95: goto tr260;
		case 97: goto tr271;
		case 100: goto tr272;
		case 101: goto tr265;
		case 104: goto tr273;
		case 109: goto tr274;
		case 112: goto tr275;
		case 115: goto tr276;
		case 121: goto tr277;
		case 123: goto tr257;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr259;
		} else if ( (*p) >= 32 )
			goto tr257;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr257;
		} else if ( (*p) >= 63 )
			goto tr259;
	} else
		goto tr257;
	goto st0;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	if ( (*p) == 80 )
		goto st119;
	goto st0;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	switch( (*p) ) {
		case 34: goto tr258;
		case 35: goto tr259;
		case 37: goto tr259;
		case 42: goto tr260;
		case 44: goto tr259;
		case 46: goto tr259;
		case 48: goto tr259;
		case 59: goto tr262;
		case 65: goto tr263;
		case 68: goto tr264;
		case 69: goto tr265;
		case 72: goto tr266;
		case 77: goto tr278;
		case 80: goto tr268;
		case 91: goto tr269;
		case 92: goto tr270;
		case 94: goto tr257;
		case 95: goto tr260;
		case 97: goto tr271;
		case 100: goto tr272;
		case 101: goto tr265;
		case 104: goto tr273;
		case 109: goto tr274;
		case 112: goto tr275;
		case 115: goto tr276;
		case 121: goto tr277;
		case 123: goto tr257;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr257;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr257;
		} else if ( (*p) >= 63 )
			goto tr259;
	} else
		goto tr257;
	goto st0;
tr151:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st120;
tr171:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st120;
tr264:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st120;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
#line 2643 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr258;
		case 35: goto tr259;
		case 37: goto tr259;
		case 42: goto tr260;
		case 44: goto tr259;
		case 46: goto tr259;
		case 48: goto tr259;
		case 59: goto tr262;
		case 65: goto tr263;
		case 68: goto st120;
		case 69: goto tr265;
		case 72: goto tr266;
		case 77: goto tr278;
		case 80: goto tr268;
		case 91: goto tr269;
		case 92: goto tr270;
		case 94: goto tr257;
		case 95: goto tr260;
		case 97: goto tr271;
		case 100: goto tr272;
		case 101: goto tr265;
		case 104: goto tr273;
		case 109: goto tr274;
		case 112: goto tr275;
		case 115: goto tr276;
		case 121: goto tr277;
		case 123: goto tr257;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr257;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr257;
		} else if ( (*p) >= 63 )
			goto tr259;
	} else
		goto tr257;
	goto st0;
tr172:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st33;
tr265:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 2705 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 43: goto st97;
		case 45: goto st97;
	}
	goto st0;
tr153:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st121;
tr173:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st121;
tr266:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st121;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
#line 2745 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr258;
		case 35: goto tr259;
		case 37: goto tr259;
		case 42: goto tr260;
		case 44: goto tr259;
		case 46: goto tr259;
		case 48: goto tr259;
		case 59: goto tr262;
		case 65: goto tr263;
		case 68: goto tr264;
		case 69: goto tr265;
		case 72: goto st121;
		case 77: goto tr278;
		case 80: goto tr268;
		case 91: goto tr269;
		case 92: goto tr270;
		case 94: goto tr257;
		case 95: goto tr260;
		case 97: goto tr271;
		case 100: goto tr272;
		case 101: goto tr265;
		case 104: goto tr273;
		case 109: goto tr274;
		case 112: goto tr275;
		case 115: goto tr276;
		case 121: goto tr277;
		case 123: goto tr257;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr257;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr257;
		} else if ( (*p) >= 63 )
			goto tr259;
	} else
		goto tr257;
	goto st0;
tr154:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st122;
tr174:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st122;
tr278:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st122;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
#line 2821 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr258;
		case 35: goto tr259;
		case 37: goto tr259;
		case 42: goto tr260;
		case 44: goto tr259;
		case 46: goto tr259;
		case 48: goto tr259;
		case 59: goto tr262;
		case 65: goto tr263;
		case 68: goto tr264;
		case 69: goto tr265;
		case 72: goto tr266;
		case 77: goto st122;
		case 80: goto tr268;
		case 91: goto tr269;
		case 92: goto tr270;
		case 94: goto tr257;
		case 95: goto tr260;
		case 97: goto tr271;
		case 100: goto tr272;
		case 101: goto tr265;
		case 104: goto tr273;
		case 109: goto tr274;
		case 112: goto tr275;
		case 115: goto tr276;
		case 121: goto tr277;
		case 123: goto tr257;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr257;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr257;
		} else if ( (*p) >= 63 )
			goto tr259;
	} else
		goto tr257;
	goto st0;
tr155:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st123;
tr175:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st123;
tr268:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st123;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
#line 2897 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr258;
		case 35: goto tr259;
		case 37: goto tr259;
		case 42: goto tr260;
		case 44: goto tr259;
		case 46: goto tr259;
		case 48: goto tr259;
		case 59: goto tr262;
		case 65: goto tr263;
		case 68: goto tr264;
		case 69: goto tr265;
		case 72: goto tr266;
		case 77: goto st119;
		case 80: goto tr268;
		case 91: goto tr269;
		case 92: goto tr270;
		case 94: goto tr257;
		case 95: goto tr260;
		case 97: goto tr271;
		case 100: goto tr272;
		case 101: goto tr265;
		case 104: goto tr273;
		case 109: goto tr274;
		case 112: goto tr275;
		case 115: goto tr276;
		case 121: goto tr277;
		case 123: goto tr257;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr257;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr257;
		} else if ( (*p) >= 63 )
			goto tr259;
	} else
		goto tr257;
	goto st0;
tr176:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st34;
tr269:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st34;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
#line 2959 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 60: goto st35;
		case 61: goto st40;
		case 62: goto st41;
	}
	goto st0;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	switch( (*p) ) {
		case 45: goto st36;
		case 46: goto st37;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 62 )
			goto st40;
	} else if ( (*p) >= 48 )
		goto st39;
	goto st0;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	if ( (*p) == 46 )
		goto st37;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st39;
	goto st0;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st38;
	goto st0;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	if ( (*p) == 93 )
		goto st97;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st38;
	goto st0;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	switch( (*p) ) {
		case 46: goto st37;
		case 93: goto st97;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st39;
	goto st0;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	switch( (*p) ) {
		case 45: goto st36;
		case 46: goto st37;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st39;
	goto st0;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	switch( (*p) ) {
		case 45: goto st36;
		case 46: goto st37;
		case 61: goto st40;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st39;
	goto st0;
tr177:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st42;
tr270:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 3059 "src/tfs_excel_parser.c"
	goto tr38;
tr158:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st124;
tr178:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st124;
tr271:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st124;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
#line 3095 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr258;
		case 35: goto tr259;
		case 37: goto tr259;
		case 42: goto tr260;
		case 44: goto tr259;
		case 47: goto st43;
		case 59: goto tr262;
		case 65: goto tr263;
		case 68: goto tr264;
		case 69: goto tr265;
		case 72: goto tr266;
		case 77: goto tr278;
		case 80: goto tr268;
		case 91: goto tr269;
		case 92: goto tr270;
		case 94: goto tr257;
		case 95: goto tr260;
		case 97: goto tr271;
		case 100: goto tr272;
		case 101: goto tr265;
		case 104: goto tr273;
		case 109: goto st133;
		case 112: goto tr275;
		case 115: goto tr276;
		case 121: goto tr277;
		case 123: goto tr257;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr259;
		} else if ( (*p) >= 32 )
			goto tr257;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr257;
		} else if ( (*p) >= 63 )
			goto tr259;
	} else
		goto tr257;
	goto st0;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	if ( (*p) == 112 )
		goto st119;
	goto st0;
tr159:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st125;
tr179:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st125;
tr272:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st125;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
#line 3180 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr258;
		case 35: goto tr259;
		case 37: goto tr259;
		case 42: goto tr260;
		case 44: goto tr259;
		case 46: goto tr259;
		case 48: goto tr259;
		case 59: goto tr262;
		case 65: goto tr263;
		case 68: goto tr264;
		case 69: goto tr265;
		case 72: goto tr266;
		case 77: goto tr278;
		case 80: goto tr268;
		case 91: goto tr269;
		case 92: goto tr270;
		case 94: goto tr257;
		case 95: goto tr260;
		case 97: goto tr271;
		case 100: goto st125;
		case 101: goto tr265;
		case 104: goto tr273;
		case 109: goto tr274;
		case 112: goto tr275;
		case 115: goto tr276;
		case 121: goto tr277;
		case 123: goto tr257;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr257;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr257;
		} else if ( (*p) >= 63 )
			goto tr259;
	} else
		goto tr257;
	goto st0;
tr160:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st126;
tr180:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st126;
tr273:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st126;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
#line 3256 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr258;
		case 35: goto tr259;
		case 37: goto tr259;
		case 42: goto tr260;
		case 44: goto tr259;
		case 46: goto tr259;
		case 48: goto tr259;
		case 59: goto tr262;
		case 65: goto tr263;
		case 68: goto tr264;
		case 69: goto tr265;
		case 72: goto tr266;
		case 77: goto tr278;
		case 80: goto tr268;
		case 91: goto tr269;
		case 92: goto tr270;
		case 94: goto tr257;
		case 95: goto tr260;
		case 97: goto tr271;
		case 100: goto tr272;
		case 101: goto tr265;
		case 104: goto st126;
		case 109: goto tr274;
		case 112: goto tr275;
		case 115: goto tr276;
		case 121: goto tr277;
		case 123: goto tr257;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr257;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr257;
		} else if ( (*p) >= 63 )
			goto tr259;
	} else
		goto tr257;
	goto st0;
tr161:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st127;
tr181:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st127;
tr274:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st127;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
#line 3332 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr258;
		case 35: goto tr259;
		case 37: goto tr259;
		case 42: goto tr260;
		case 44: goto tr259;
		case 46: goto tr259;
		case 48: goto tr259;
		case 59: goto tr262;
		case 65: goto tr263;
		case 68: goto tr264;
		case 69: goto tr265;
		case 72: goto tr266;
		case 77: goto tr278;
		case 80: goto tr268;
		case 91: goto tr269;
		case 92: goto tr270;
		case 94: goto tr257;
		case 95: goto tr260;
		case 97: goto tr271;
		case 100: goto tr272;
		case 101: goto tr265;
		case 104: goto tr273;
		case 109: goto st127;
		case 112: goto tr275;
		case 115: goto tr276;
		case 121: goto tr277;
		case 123: goto tr257;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr257;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr257;
		} else if ( (*p) >= 63 )
			goto tr259;
	} else
		goto tr257;
	goto st0;
tr162:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st128;
tr182:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st128;
tr275:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st128;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
#line 3408 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr258;
		case 35: goto tr259;
		case 37: goto tr259;
		case 42: goto tr260;
		case 44: goto tr259;
		case 46: goto tr259;
		case 48: goto tr259;
		case 59: goto tr262;
		case 65: goto tr263;
		case 68: goto tr264;
		case 69: goto tr265;
		case 72: goto tr266;
		case 77: goto tr278;
		case 80: goto tr268;
		case 91: goto tr269;
		case 92: goto tr270;
		case 94: goto tr257;
		case 95: goto tr260;
		case 97: goto tr271;
		case 100: goto tr272;
		case 101: goto tr265;
		case 104: goto tr273;
		case 109: goto st119;
		case 112: goto tr275;
		case 115: goto tr276;
		case 121: goto tr277;
		case 123: goto tr257;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr257;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr257;
		} else if ( (*p) >= 63 )
			goto tr259;
	} else
		goto tr257;
	goto st0;
tr163:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st129;
tr183:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st129;
tr276:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st129;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
#line 3484 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr258;
		case 35: goto tr259;
		case 37: goto tr259;
		case 42: goto tr260;
		case 44: goto tr259;
		case 46: goto st44;
		case 48: goto tr259;
		case 59: goto tr262;
		case 65: goto tr263;
		case 68: goto tr264;
		case 69: goto tr265;
		case 72: goto tr266;
		case 77: goto tr278;
		case 80: goto tr268;
		case 91: goto tr269;
		case 92: goto tr270;
		case 94: goto tr257;
		case 95: goto tr260;
		case 97: goto tr271;
		case 100: goto tr272;
		case 101: goto tr265;
		case 104: goto tr273;
		case 109: goto tr274;
		case 112: goto tr275;
		case 115: goto st132;
		case 121: goto tr277;
		case 123: goto tr257;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr257;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr257;
		} else if ( (*p) >= 63 )
			goto tr259;
	} else
		goto tr257;
	goto st0;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	switch( (*p) ) {
		case 35: goto st130;
		case 44: goto st130;
		case 48: goto st130;
		case 63: goto st130;
	}
	goto st0;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	switch( (*p) ) {
		case 34: goto tr258;
		case 35: goto st130;
		case 37: goto tr259;
		case 42: goto tr260;
		case 44: goto st130;
		case 46: goto tr259;
		case 48: goto st130;
		case 59: goto tr262;
		case 63: goto st130;
		case 64: goto tr259;
		case 65: goto tr263;
		case 68: goto tr264;
		case 69: goto tr265;
		case 72: goto tr266;
		case 77: goto tr278;
		case 80: goto tr268;
		case 91: goto tr269;
		case 92: goto tr270;
		case 94: goto tr257;
		case 95: goto tr260;
		case 97: goto tr271;
		case 100: goto tr272;
		case 101: goto tr265;
		case 104: goto tr273;
		case 109: goto tr274;
		case 112: goto tr275;
		case 115: goto tr276;
		case 121: goto tr277;
		case 123: goto tr257;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr257;
	} else if ( (*p) > 62 ) {
		if ( 125 <= (*p) && (*p) <= 126 )
			goto tr257;
	} else
		goto tr257;
	goto st0;
tr164:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st131;
tr184:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st131;
tr277:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st131;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
#line 3615 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr258;
		case 35: goto tr259;
		case 37: goto tr259;
		case 42: goto tr260;
		case 44: goto tr259;
		case 46: goto tr259;
		case 48: goto tr259;
		case 59: goto tr262;
		case 65: goto tr263;
		case 68: goto tr264;
		case 69: goto tr265;
		case 72: goto tr266;
		case 77: goto tr278;
		case 80: goto tr268;
		case 91: goto tr269;
		case 92: goto tr270;
		case 94: goto tr257;
		case 95: goto tr260;
		case 97: goto tr271;
		case 100: goto tr272;
		case 101: goto tr265;
		case 104: goto tr273;
		case 109: goto tr274;
		case 112: goto tr275;
		case 115: goto tr276;
		case 121: goto st131;
		case 123: goto tr257;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr257;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr257;
		} else if ( (*p) >= 63 )
			goto tr259;
	} else
		goto tr257;
	goto st0;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	switch( (*p) ) {
		case 34: goto tr258;
		case 35: goto tr259;
		case 37: goto tr259;
		case 42: goto tr260;
		case 44: goto tr259;
		case 46: goto st44;
		case 48: goto tr259;
		case 59: goto tr262;
		case 65: goto tr263;
		case 68: goto tr264;
		case 69: goto tr265;
		case 72: goto tr266;
		case 77: goto tr278;
		case 80: goto tr268;
		case 91: goto tr269;
		case 92: goto tr270;
		case 94: goto tr257;
		case 95: goto tr260;
		case 97: goto tr271;
		case 100: goto tr272;
		case 101: goto tr265;
		case 104: goto tr273;
		case 109: goto tr274;
		case 112: goto tr275;
		case 115: goto tr276;
		case 121: goto tr277;
		case 123: goto tr257;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr257;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr257;
		} else if ( (*p) >= 63 )
			goto tr259;
	} else
		goto tr257;
	goto st0;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	switch( (*p) ) {
		case 34: goto tr258;
		case 35: goto tr259;
		case 37: goto tr259;
		case 42: goto tr260;
		case 44: goto tr259;
		case 47: goto st45;
		case 59: goto tr262;
		case 65: goto tr263;
		case 68: goto tr264;
		case 69: goto tr265;
		case 72: goto tr266;
		case 77: goto tr278;
		case 80: goto tr268;
		case 91: goto tr269;
		case 92: goto tr270;
		case 94: goto tr257;
		case 95: goto tr260;
		case 97: goto tr271;
		case 100: goto tr272;
		case 101: goto tr265;
		case 104: goto tr273;
		case 109: goto tr274;
		case 112: goto tr275;
		case 115: goto tr276;
		case 121: goto tr277;
		case 123: goto tr257;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr259;
		} else if ( (*p) >= 32 )
			goto tr257;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr257;
		} else if ( (*p) >= 63 )
			goto tr259;
	} else
		goto tr257;
	goto st0;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	if ( (*p) == 112 )
		goto st46;
	goto st0;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	if ( (*p) == 109 )
		goto st119;
	goto st0;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	switch( (*p) ) {
		case 34: goto tr258;
		case 35: goto tr259;
		case 37: goto tr259;
		case 42: goto tr260;
		case 44: goto tr259;
		case 47: goto st47;
		case 59: goto tr262;
		case 65: goto tr263;
		case 68: goto tr264;
		case 69: goto tr265;
		case 72: goto tr266;
		case 77: goto tr278;
		case 80: goto tr268;
		case 91: goto tr269;
		case 92: goto tr270;
		case 94: goto tr257;
		case 95: goto tr260;
		case 97: goto tr271;
		case 100: goto tr272;
		case 101: goto tr265;
		case 104: goto tr273;
		case 109: goto tr274;
		case 112: goto tr275;
		case 115: goto tr276;
		case 121: goto tr277;
		case 123: goto tr257;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr259;
		} else if ( (*p) >= 32 )
			goto tr257;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr257;
		} else if ( (*p) >= 63 )
			goto tr259;
	} else
		goto tr257;
	goto st0;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	if ( (*p) == 80 )
		goto st48;
	goto st0;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	if ( (*p) == 77 )
		goto st119;
	goto st0;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	switch( (*p) ) {
		case 60: goto st35;
		case 61: goto st40;
		case 62: goto st41;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st50;
	} else if ( (*p) >= 65 )
		goto st50;
	goto st0;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	if ( (*p) == 93 )
		goto st97;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st50;
	} else if ( (*p) >= 65 )
		goto st50;
	goto st0;
tr111:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st135;
tr131:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st135;
tr298:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st135;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
#line 3885 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr293;
		case 35: goto tr294;
		case 37: goto tr294;
		case 42: goto tr295;
		case 44: goto tr294;
		case 47: goto st51;
		case 59: goto tr297;
		case 65: goto tr298;
		case 68: goto tr299;
		case 69: goto tr300;
		case 72: goto tr301;
		case 77: goto st151;
		case 80: goto tr303;
		case 91: goto tr304;
		case 92: goto tr305;
		case 94: goto tr292;
		case 95: goto tr295;
		case 97: goto tr306;
		case 100: goto tr307;
		case 101: goto tr300;
		case 104: goto tr308;
		case 109: goto tr309;
		case 112: goto tr310;
		case 115: goto tr311;
		case 121: goto tr312;
		case 123: goto tr292;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr294;
		} else if ( (*p) >= 32 )
			goto tr292;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr292;
		} else if ( (*p) >= 63 )
			goto tr294;
	} else
		goto tr292;
	goto st0;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	if ( (*p) == 80 )
		goto st136;
	goto st0;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	switch( (*p) ) {
		case 34: goto tr293;
		case 35: goto tr294;
		case 37: goto tr294;
		case 42: goto tr295;
		case 44: goto tr294;
		case 46: goto tr294;
		case 48: goto tr294;
		case 59: goto tr297;
		case 65: goto tr298;
		case 68: goto tr299;
		case 69: goto tr300;
		case 72: goto tr301;
		case 77: goto tr313;
		case 80: goto tr303;
		case 91: goto tr304;
		case 92: goto tr305;
		case 94: goto tr292;
		case 95: goto tr295;
		case 97: goto tr306;
		case 100: goto tr307;
		case 101: goto tr300;
		case 104: goto tr308;
		case 109: goto tr309;
		case 112: goto tr310;
		case 115: goto tr311;
		case 121: goto tr312;
		case 123: goto tr292;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr292;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr292;
		} else if ( (*p) >= 63 )
			goto tr294;
	} else
		goto tr292;
	goto st0;
tr112:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st137;
tr132:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st137;
tr299:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st137;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
#line 4015 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr293;
		case 35: goto tr294;
		case 37: goto tr294;
		case 42: goto tr295;
		case 44: goto tr294;
		case 46: goto tr294;
		case 48: goto tr294;
		case 59: goto tr297;
		case 65: goto tr298;
		case 68: goto st137;
		case 69: goto tr300;
		case 72: goto tr301;
		case 77: goto tr313;
		case 80: goto tr303;
		case 91: goto tr304;
		case 92: goto tr305;
		case 94: goto tr292;
		case 95: goto tr295;
		case 97: goto tr306;
		case 100: goto tr307;
		case 101: goto tr300;
		case 104: goto tr308;
		case 109: goto tr309;
		case 112: goto tr310;
		case 115: goto tr311;
		case 121: goto tr312;
		case 123: goto tr292;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr292;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr292;
		} else if ( (*p) >= 63 )
			goto tr294;
	} else
		goto tr292;
	goto st0;
tr133:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st52;
tr300:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
#line 4077 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 43: goto st94;
		case 45: goto st94;
	}
	goto st0;
tr114:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st138;
tr134:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st138;
tr301:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st138;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
#line 4117 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr293;
		case 35: goto tr294;
		case 37: goto tr294;
		case 42: goto tr295;
		case 44: goto tr294;
		case 46: goto tr294;
		case 48: goto tr294;
		case 59: goto tr297;
		case 65: goto tr298;
		case 68: goto tr299;
		case 69: goto tr300;
		case 72: goto st138;
		case 77: goto tr313;
		case 80: goto tr303;
		case 91: goto tr304;
		case 92: goto tr305;
		case 94: goto tr292;
		case 95: goto tr295;
		case 97: goto tr306;
		case 100: goto tr307;
		case 101: goto tr300;
		case 104: goto tr308;
		case 109: goto tr309;
		case 112: goto tr310;
		case 115: goto tr311;
		case 121: goto tr312;
		case 123: goto tr292;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr292;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr292;
		} else if ( (*p) >= 63 )
			goto tr294;
	} else
		goto tr292;
	goto st0;
tr115:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st139;
tr135:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st139;
tr313:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st139;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
#line 4193 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr293;
		case 35: goto tr294;
		case 37: goto tr294;
		case 42: goto tr295;
		case 44: goto tr294;
		case 46: goto tr294;
		case 48: goto tr294;
		case 59: goto tr297;
		case 65: goto tr298;
		case 68: goto tr299;
		case 69: goto tr300;
		case 72: goto tr301;
		case 77: goto st139;
		case 80: goto tr303;
		case 91: goto tr304;
		case 92: goto tr305;
		case 94: goto tr292;
		case 95: goto tr295;
		case 97: goto tr306;
		case 100: goto tr307;
		case 101: goto tr300;
		case 104: goto tr308;
		case 109: goto tr309;
		case 112: goto tr310;
		case 115: goto tr311;
		case 121: goto tr312;
		case 123: goto tr292;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr292;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr292;
		} else if ( (*p) >= 63 )
			goto tr294;
	} else
		goto tr292;
	goto st0;
tr116:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st140;
tr136:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st140;
tr303:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st140;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
#line 4269 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr293;
		case 35: goto tr294;
		case 37: goto tr294;
		case 42: goto tr295;
		case 44: goto tr294;
		case 46: goto tr294;
		case 48: goto tr294;
		case 59: goto tr297;
		case 65: goto tr298;
		case 68: goto tr299;
		case 69: goto tr300;
		case 72: goto tr301;
		case 77: goto st136;
		case 80: goto tr303;
		case 91: goto tr304;
		case 92: goto tr305;
		case 94: goto tr292;
		case 95: goto tr295;
		case 97: goto tr306;
		case 100: goto tr307;
		case 101: goto tr300;
		case 104: goto tr308;
		case 109: goto tr309;
		case 112: goto tr310;
		case 115: goto tr311;
		case 121: goto tr312;
		case 123: goto tr292;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr292;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr292;
		} else if ( (*p) >= 63 )
			goto tr294;
	} else
		goto tr292;
	goto st0;
tr137:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st53;
tr304:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st53;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
#line 4331 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 60: goto st54;
		case 61: goto st59;
		case 62: goto st60;
	}
	goto st0;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	switch( (*p) ) {
		case 45: goto st55;
		case 46: goto st56;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 62 )
			goto st59;
	} else if ( (*p) >= 48 )
		goto st58;
	goto st0;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	if ( (*p) == 46 )
		goto st56;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st58;
	goto st0;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st57;
	goto st0;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	if ( (*p) == 93 )
		goto st94;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st57;
	goto st0;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	switch( (*p) ) {
		case 46: goto st56;
		case 93: goto st94;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st58;
	goto st0;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	switch( (*p) ) {
		case 45: goto st55;
		case 46: goto st56;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st58;
	goto st0;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	switch( (*p) ) {
		case 45: goto st55;
		case 46: goto st56;
		case 61: goto st59;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st58;
	goto st0;
tr138:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st61;
tr305:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st61;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
#line 4431 "src/tfs_excel_parser.c"
	goto tr51;
tr119:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st141;
tr139:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st141;
tr306:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st141;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
#line 4467 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr293;
		case 35: goto tr294;
		case 37: goto tr294;
		case 42: goto tr295;
		case 44: goto tr294;
		case 47: goto st62;
		case 59: goto tr297;
		case 65: goto tr298;
		case 68: goto tr299;
		case 69: goto tr300;
		case 72: goto tr301;
		case 77: goto tr313;
		case 80: goto tr303;
		case 91: goto tr304;
		case 92: goto tr305;
		case 94: goto tr292;
		case 95: goto tr295;
		case 97: goto tr306;
		case 100: goto tr307;
		case 101: goto tr300;
		case 104: goto tr308;
		case 109: goto st150;
		case 112: goto tr310;
		case 115: goto tr311;
		case 121: goto tr312;
		case 123: goto tr292;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr294;
		} else if ( (*p) >= 32 )
			goto tr292;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr292;
		} else if ( (*p) >= 63 )
			goto tr294;
	} else
		goto tr292;
	goto st0;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	if ( (*p) == 112 )
		goto st136;
	goto st0;
tr120:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st142;
tr140:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st142;
tr307:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st142;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
#line 4552 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr293;
		case 35: goto tr294;
		case 37: goto tr294;
		case 42: goto tr295;
		case 44: goto tr294;
		case 46: goto tr294;
		case 48: goto tr294;
		case 59: goto tr297;
		case 65: goto tr298;
		case 68: goto tr299;
		case 69: goto tr300;
		case 72: goto tr301;
		case 77: goto tr313;
		case 80: goto tr303;
		case 91: goto tr304;
		case 92: goto tr305;
		case 94: goto tr292;
		case 95: goto tr295;
		case 97: goto tr306;
		case 100: goto st142;
		case 101: goto tr300;
		case 104: goto tr308;
		case 109: goto tr309;
		case 112: goto tr310;
		case 115: goto tr311;
		case 121: goto tr312;
		case 123: goto tr292;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr292;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr292;
		} else if ( (*p) >= 63 )
			goto tr294;
	} else
		goto tr292;
	goto st0;
tr121:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st143;
tr141:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st143;
tr308:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st143;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
#line 4628 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr293;
		case 35: goto tr294;
		case 37: goto tr294;
		case 42: goto tr295;
		case 44: goto tr294;
		case 46: goto tr294;
		case 48: goto tr294;
		case 59: goto tr297;
		case 65: goto tr298;
		case 68: goto tr299;
		case 69: goto tr300;
		case 72: goto tr301;
		case 77: goto tr313;
		case 80: goto tr303;
		case 91: goto tr304;
		case 92: goto tr305;
		case 94: goto tr292;
		case 95: goto tr295;
		case 97: goto tr306;
		case 100: goto tr307;
		case 101: goto tr300;
		case 104: goto st143;
		case 109: goto tr309;
		case 112: goto tr310;
		case 115: goto tr311;
		case 121: goto tr312;
		case 123: goto tr292;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr292;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr292;
		} else if ( (*p) >= 63 )
			goto tr294;
	} else
		goto tr292;
	goto st0;
tr122:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st144;
tr142:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st144;
tr309:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st144;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
#line 4704 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr293;
		case 35: goto tr294;
		case 37: goto tr294;
		case 42: goto tr295;
		case 44: goto tr294;
		case 46: goto tr294;
		case 48: goto tr294;
		case 59: goto tr297;
		case 65: goto tr298;
		case 68: goto tr299;
		case 69: goto tr300;
		case 72: goto tr301;
		case 77: goto tr313;
		case 80: goto tr303;
		case 91: goto tr304;
		case 92: goto tr305;
		case 94: goto tr292;
		case 95: goto tr295;
		case 97: goto tr306;
		case 100: goto tr307;
		case 101: goto tr300;
		case 104: goto tr308;
		case 109: goto st144;
		case 112: goto tr310;
		case 115: goto tr311;
		case 121: goto tr312;
		case 123: goto tr292;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr292;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr292;
		} else if ( (*p) >= 63 )
			goto tr294;
	} else
		goto tr292;
	goto st0;
tr123:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st145;
tr143:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st145;
tr310:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st145;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
#line 4780 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr293;
		case 35: goto tr294;
		case 37: goto tr294;
		case 42: goto tr295;
		case 44: goto tr294;
		case 46: goto tr294;
		case 48: goto tr294;
		case 59: goto tr297;
		case 65: goto tr298;
		case 68: goto tr299;
		case 69: goto tr300;
		case 72: goto tr301;
		case 77: goto tr313;
		case 80: goto tr303;
		case 91: goto tr304;
		case 92: goto tr305;
		case 94: goto tr292;
		case 95: goto tr295;
		case 97: goto tr306;
		case 100: goto tr307;
		case 101: goto tr300;
		case 104: goto tr308;
		case 109: goto st136;
		case 112: goto tr310;
		case 115: goto tr311;
		case 121: goto tr312;
		case 123: goto tr292;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr292;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr292;
		} else if ( (*p) >= 63 )
			goto tr294;
	} else
		goto tr292;
	goto st0;
tr124:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st146;
tr144:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st146;
tr311:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st146;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
#line 4856 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr293;
		case 35: goto tr294;
		case 37: goto tr294;
		case 42: goto tr295;
		case 44: goto tr294;
		case 46: goto st63;
		case 48: goto tr294;
		case 59: goto tr297;
		case 65: goto tr298;
		case 68: goto tr299;
		case 69: goto tr300;
		case 72: goto tr301;
		case 77: goto tr313;
		case 80: goto tr303;
		case 91: goto tr304;
		case 92: goto tr305;
		case 94: goto tr292;
		case 95: goto tr295;
		case 97: goto tr306;
		case 100: goto tr307;
		case 101: goto tr300;
		case 104: goto tr308;
		case 109: goto tr309;
		case 112: goto tr310;
		case 115: goto st149;
		case 121: goto tr312;
		case 123: goto tr292;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr292;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr292;
		} else if ( (*p) >= 63 )
			goto tr294;
	} else
		goto tr292;
	goto st0;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	switch( (*p) ) {
		case 35: goto st147;
		case 44: goto st147;
		case 48: goto st147;
		case 63: goto st147;
	}
	goto st0;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	switch( (*p) ) {
		case 34: goto tr293;
		case 35: goto st147;
		case 37: goto tr294;
		case 42: goto tr295;
		case 44: goto st147;
		case 46: goto tr294;
		case 48: goto st147;
		case 59: goto tr297;
		case 63: goto st147;
		case 64: goto tr294;
		case 65: goto tr298;
		case 68: goto tr299;
		case 69: goto tr300;
		case 72: goto tr301;
		case 77: goto tr313;
		case 80: goto tr303;
		case 91: goto tr304;
		case 92: goto tr305;
		case 94: goto tr292;
		case 95: goto tr295;
		case 97: goto tr306;
		case 100: goto tr307;
		case 101: goto tr300;
		case 104: goto tr308;
		case 109: goto tr309;
		case 112: goto tr310;
		case 115: goto tr311;
		case 121: goto tr312;
		case 123: goto tr292;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr292;
	} else if ( (*p) > 62 ) {
		if ( 125 <= (*p) && (*p) <= 126 )
			goto tr292;
	} else
		goto tr292;
	goto st0;
tr125:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st148;
tr145:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st148;
tr312:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st148;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
#line 4987 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr293;
		case 35: goto tr294;
		case 37: goto tr294;
		case 42: goto tr295;
		case 44: goto tr294;
		case 46: goto tr294;
		case 48: goto tr294;
		case 59: goto tr297;
		case 65: goto tr298;
		case 68: goto tr299;
		case 69: goto tr300;
		case 72: goto tr301;
		case 77: goto tr313;
		case 80: goto tr303;
		case 91: goto tr304;
		case 92: goto tr305;
		case 94: goto tr292;
		case 95: goto tr295;
		case 97: goto tr306;
		case 100: goto tr307;
		case 101: goto tr300;
		case 104: goto tr308;
		case 109: goto tr309;
		case 112: goto tr310;
		case 115: goto tr311;
		case 121: goto st148;
		case 123: goto tr292;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr292;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr292;
		} else if ( (*p) >= 63 )
			goto tr294;
	} else
		goto tr292;
	goto st0;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
	switch( (*p) ) {
		case 34: goto tr293;
		case 35: goto tr294;
		case 37: goto tr294;
		case 42: goto tr295;
		case 44: goto tr294;
		case 46: goto st63;
		case 48: goto tr294;
		case 59: goto tr297;
		case 65: goto tr298;
		case 68: goto tr299;
		case 69: goto tr300;
		case 72: goto tr301;
		case 77: goto tr313;
		case 80: goto tr303;
		case 91: goto tr304;
		case 92: goto tr305;
		case 94: goto tr292;
		case 95: goto tr295;
		case 97: goto tr306;
		case 100: goto tr307;
		case 101: goto tr300;
		case 104: goto tr308;
		case 109: goto tr309;
		case 112: goto tr310;
		case 115: goto tr311;
		case 121: goto tr312;
		case 123: goto tr292;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr292;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr292;
		} else if ( (*p) >= 63 )
			goto tr294;
	} else
		goto tr292;
	goto st0;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	switch( (*p) ) {
		case 34: goto tr293;
		case 35: goto tr294;
		case 37: goto tr294;
		case 42: goto tr295;
		case 44: goto tr294;
		case 47: goto st64;
		case 59: goto tr297;
		case 65: goto tr298;
		case 68: goto tr299;
		case 69: goto tr300;
		case 72: goto tr301;
		case 77: goto tr313;
		case 80: goto tr303;
		case 91: goto tr304;
		case 92: goto tr305;
		case 94: goto tr292;
		case 95: goto tr295;
		case 97: goto tr306;
		case 100: goto tr307;
		case 101: goto tr300;
		case 104: goto tr308;
		case 109: goto tr309;
		case 112: goto tr310;
		case 115: goto tr311;
		case 121: goto tr312;
		case 123: goto tr292;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr294;
		} else if ( (*p) >= 32 )
			goto tr292;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr292;
		} else if ( (*p) >= 63 )
			goto tr294;
	} else
		goto tr292;
	goto st0;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	if ( (*p) == 112 )
		goto st65;
	goto st0;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	if ( (*p) == 109 )
		goto st136;
	goto st0;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	switch( (*p) ) {
		case 34: goto tr293;
		case 35: goto tr294;
		case 37: goto tr294;
		case 42: goto tr295;
		case 44: goto tr294;
		case 47: goto st66;
		case 59: goto tr297;
		case 65: goto tr298;
		case 68: goto tr299;
		case 69: goto tr300;
		case 72: goto tr301;
		case 77: goto tr313;
		case 80: goto tr303;
		case 91: goto tr304;
		case 92: goto tr305;
		case 94: goto tr292;
		case 95: goto tr295;
		case 97: goto tr306;
		case 100: goto tr307;
		case 101: goto tr300;
		case 104: goto tr308;
		case 109: goto tr309;
		case 112: goto tr310;
		case 115: goto tr311;
		case 121: goto tr312;
		case 123: goto tr292;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr294;
		} else if ( (*p) >= 32 )
			goto tr292;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr292;
		} else if ( (*p) >= 63 )
			goto tr294;
	} else
		goto tr292;
	goto st0;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	if ( (*p) == 80 )
		goto st67;
	goto st0;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
	if ( (*p) == 77 )
		goto st136;
	goto st0;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	switch( (*p) ) {
		case 60: goto st54;
		case 61: goto st59;
		case 62: goto st60;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st69;
	} else if ( (*p) >= 65 )
		goto st69;
	goto st0;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	if ( (*p) == 93 )
		goto st94;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st69;
	} else if ( (*p) >= 65 )
		goto st69;
	goto st0;
tr72:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st152;
tr92:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st152;
tr333:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st152;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
#line 5257 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr328;
		case 35: goto tr329;
		case 37: goto tr329;
		case 42: goto tr330;
		case 44: goto tr329;
		case 47: goto st70;
		case 59: goto tr332;
		case 65: goto tr333;
		case 68: goto tr334;
		case 69: goto tr335;
		case 72: goto tr336;
		case 77: goto st168;
		case 80: goto tr338;
		case 91: goto tr339;
		case 92: goto tr340;
		case 94: goto tr327;
		case 95: goto tr330;
		case 97: goto tr341;
		case 100: goto tr342;
		case 101: goto tr335;
		case 104: goto tr343;
		case 109: goto tr344;
		case 112: goto tr345;
		case 115: goto tr346;
		case 121: goto tr347;
		case 123: goto tr327;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr329;
		} else if ( (*p) >= 32 )
			goto tr327;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr327;
		} else if ( (*p) >= 63 )
			goto tr329;
	} else
		goto tr327;
	goto st0;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	if ( (*p) == 80 )
		goto st153;
	goto st0;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	switch( (*p) ) {
		case 34: goto tr328;
		case 35: goto tr329;
		case 37: goto tr329;
		case 42: goto tr330;
		case 44: goto tr329;
		case 46: goto tr329;
		case 48: goto tr329;
		case 59: goto tr332;
		case 65: goto tr333;
		case 68: goto tr334;
		case 69: goto tr335;
		case 72: goto tr336;
		case 77: goto tr348;
		case 80: goto tr338;
		case 91: goto tr339;
		case 92: goto tr340;
		case 94: goto tr327;
		case 95: goto tr330;
		case 97: goto tr341;
		case 100: goto tr342;
		case 101: goto tr335;
		case 104: goto tr343;
		case 109: goto tr344;
		case 112: goto tr345;
		case 115: goto tr346;
		case 121: goto tr347;
		case 123: goto tr327;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr327;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr327;
		} else if ( (*p) >= 63 )
			goto tr329;
	} else
		goto tr327;
	goto st0;
tr73:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st154;
tr93:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st154;
tr334:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st154;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
#line 5387 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr328;
		case 35: goto tr329;
		case 37: goto tr329;
		case 42: goto tr330;
		case 44: goto tr329;
		case 46: goto tr329;
		case 48: goto tr329;
		case 59: goto tr332;
		case 65: goto tr333;
		case 68: goto st154;
		case 69: goto tr335;
		case 72: goto tr336;
		case 77: goto tr348;
		case 80: goto tr338;
		case 91: goto tr339;
		case 92: goto tr340;
		case 94: goto tr327;
		case 95: goto tr330;
		case 97: goto tr341;
		case 100: goto tr342;
		case 101: goto tr335;
		case 104: goto tr343;
		case 109: goto tr344;
		case 112: goto tr345;
		case 115: goto tr346;
		case 121: goto tr347;
		case 123: goto tr327;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr327;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr327;
		} else if ( (*p) >= 63 )
			goto tr329;
	} else
		goto tr327;
	goto st0;
tr94:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st71;
tr335:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st71;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
#line 5449 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 43: goto st91;
		case 45: goto st91;
	}
	goto st0;
tr75:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st155;
tr95:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st155;
tr336:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st155;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
#line 5489 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr328;
		case 35: goto tr329;
		case 37: goto tr329;
		case 42: goto tr330;
		case 44: goto tr329;
		case 46: goto tr329;
		case 48: goto tr329;
		case 59: goto tr332;
		case 65: goto tr333;
		case 68: goto tr334;
		case 69: goto tr335;
		case 72: goto st155;
		case 77: goto tr348;
		case 80: goto tr338;
		case 91: goto tr339;
		case 92: goto tr340;
		case 94: goto tr327;
		case 95: goto tr330;
		case 97: goto tr341;
		case 100: goto tr342;
		case 101: goto tr335;
		case 104: goto tr343;
		case 109: goto tr344;
		case 112: goto tr345;
		case 115: goto tr346;
		case 121: goto tr347;
		case 123: goto tr327;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr327;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr327;
		} else if ( (*p) >= 63 )
			goto tr329;
	} else
		goto tr327;
	goto st0;
tr76:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st156;
tr96:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st156;
tr348:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st156;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
#line 5565 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr328;
		case 35: goto tr329;
		case 37: goto tr329;
		case 42: goto tr330;
		case 44: goto tr329;
		case 46: goto tr329;
		case 48: goto tr329;
		case 59: goto tr332;
		case 65: goto tr333;
		case 68: goto tr334;
		case 69: goto tr335;
		case 72: goto tr336;
		case 77: goto st156;
		case 80: goto tr338;
		case 91: goto tr339;
		case 92: goto tr340;
		case 94: goto tr327;
		case 95: goto tr330;
		case 97: goto tr341;
		case 100: goto tr342;
		case 101: goto tr335;
		case 104: goto tr343;
		case 109: goto tr344;
		case 112: goto tr345;
		case 115: goto tr346;
		case 121: goto tr347;
		case 123: goto tr327;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr327;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr327;
		} else if ( (*p) >= 63 )
			goto tr329;
	} else
		goto tr327;
	goto st0;
tr77:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st157;
tr97:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st157;
tr338:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st157;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
#line 5641 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr328;
		case 35: goto tr329;
		case 37: goto tr329;
		case 42: goto tr330;
		case 44: goto tr329;
		case 46: goto tr329;
		case 48: goto tr329;
		case 59: goto tr332;
		case 65: goto tr333;
		case 68: goto tr334;
		case 69: goto tr335;
		case 72: goto tr336;
		case 77: goto st153;
		case 80: goto tr338;
		case 91: goto tr339;
		case 92: goto tr340;
		case 94: goto tr327;
		case 95: goto tr330;
		case 97: goto tr341;
		case 100: goto tr342;
		case 101: goto tr335;
		case 104: goto tr343;
		case 109: goto tr344;
		case 112: goto tr345;
		case 115: goto tr346;
		case 121: goto tr347;
		case 123: goto tr327;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr327;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr327;
		} else if ( (*p) >= 63 )
			goto tr329;
	} else
		goto tr327;
	goto st0;
tr98:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st72;
tr339:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st72;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
#line 5703 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 60: goto st73;
		case 61: goto st78;
		case 62: goto st79;
	}
	goto st0;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	switch( (*p) ) {
		case 45: goto st74;
		case 46: goto st75;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 62 )
			goto st78;
	} else if ( (*p) >= 48 )
		goto st77;
	goto st0;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	if ( (*p) == 46 )
		goto st75;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st77;
	goto st0;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st76;
	goto st0;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	if ( (*p) == 93 )
		goto st91;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st76;
	goto st0;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	switch( (*p) ) {
		case 46: goto st75;
		case 93: goto st91;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st77;
	goto st0;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	switch( (*p) ) {
		case 45: goto st74;
		case 46: goto st75;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st77;
	goto st0;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	switch( (*p) ) {
		case 45: goto st74;
		case 46: goto st75;
		case 61: goto st78;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st77;
	goto st0;
tr99:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st80;
tr340:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st80;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
#line 5803 "src/tfs_excel_parser.c"
	goto tr64;
tr80:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st158;
tr100:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st158;
tr341:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st158;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
#line 5839 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr328;
		case 35: goto tr329;
		case 37: goto tr329;
		case 42: goto tr330;
		case 44: goto tr329;
		case 47: goto st81;
		case 59: goto tr332;
		case 65: goto tr333;
		case 68: goto tr334;
		case 69: goto tr335;
		case 72: goto tr336;
		case 77: goto tr348;
		case 80: goto tr338;
		case 91: goto tr339;
		case 92: goto tr340;
		case 94: goto tr327;
		case 95: goto tr330;
		case 97: goto tr341;
		case 100: goto tr342;
		case 101: goto tr335;
		case 104: goto tr343;
		case 109: goto st167;
		case 112: goto tr345;
		case 115: goto tr346;
		case 121: goto tr347;
		case 123: goto tr327;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr329;
		} else if ( (*p) >= 32 )
			goto tr327;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr327;
		} else if ( (*p) >= 63 )
			goto tr329;
	} else
		goto tr327;
	goto st0;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	if ( (*p) == 112 )
		goto st153;
	goto st0;
tr81:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st159;
tr101:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st159;
tr342:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st159;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
#line 5924 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr328;
		case 35: goto tr329;
		case 37: goto tr329;
		case 42: goto tr330;
		case 44: goto tr329;
		case 46: goto tr329;
		case 48: goto tr329;
		case 59: goto tr332;
		case 65: goto tr333;
		case 68: goto tr334;
		case 69: goto tr335;
		case 72: goto tr336;
		case 77: goto tr348;
		case 80: goto tr338;
		case 91: goto tr339;
		case 92: goto tr340;
		case 94: goto tr327;
		case 95: goto tr330;
		case 97: goto tr341;
		case 100: goto st159;
		case 101: goto tr335;
		case 104: goto tr343;
		case 109: goto tr344;
		case 112: goto tr345;
		case 115: goto tr346;
		case 121: goto tr347;
		case 123: goto tr327;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr327;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr327;
		} else if ( (*p) >= 63 )
			goto tr329;
	} else
		goto tr327;
	goto st0;
tr82:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st160;
tr102:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st160;
tr343:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st160;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
#line 6000 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr328;
		case 35: goto tr329;
		case 37: goto tr329;
		case 42: goto tr330;
		case 44: goto tr329;
		case 46: goto tr329;
		case 48: goto tr329;
		case 59: goto tr332;
		case 65: goto tr333;
		case 68: goto tr334;
		case 69: goto tr335;
		case 72: goto tr336;
		case 77: goto tr348;
		case 80: goto tr338;
		case 91: goto tr339;
		case 92: goto tr340;
		case 94: goto tr327;
		case 95: goto tr330;
		case 97: goto tr341;
		case 100: goto tr342;
		case 101: goto tr335;
		case 104: goto st160;
		case 109: goto tr344;
		case 112: goto tr345;
		case 115: goto tr346;
		case 121: goto tr347;
		case 123: goto tr327;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr327;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr327;
		} else if ( (*p) >= 63 )
			goto tr329;
	} else
		goto tr327;
	goto st0;
tr83:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st161;
tr103:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st161;
tr344:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st161;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
#line 6076 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr328;
		case 35: goto tr329;
		case 37: goto tr329;
		case 42: goto tr330;
		case 44: goto tr329;
		case 46: goto tr329;
		case 48: goto tr329;
		case 59: goto tr332;
		case 65: goto tr333;
		case 68: goto tr334;
		case 69: goto tr335;
		case 72: goto tr336;
		case 77: goto tr348;
		case 80: goto tr338;
		case 91: goto tr339;
		case 92: goto tr340;
		case 94: goto tr327;
		case 95: goto tr330;
		case 97: goto tr341;
		case 100: goto tr342;
		case 101: goto tr335;
		case 104: goto tr343;
		case 109: goto st161;
		case 112: goto tr345;
		case 115: goto tr346;
		case 121: goto tr347;
		case 123: goto tr327;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr327;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr327;
		} else if ( (*p) >= 63 )
			goto tr329;
	} else
		goto tr327;
	goto st0;
tr84:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st162;
tr104:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st162;
tr345:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st162;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
#line 6152 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr328;
		case 35: goto tr329;
		case 37: goto tr329;
		case 42: goto tr330;
		case 44: goto tr329;
		case 46: goto tr329;
		case 48: goto tr329;
		case 59: goto tr332;
		case 65: goto tr333;
		case 68: goto tr334;
		case 69: goto tr335;
		case 72: goto tr336;
		case 77: goto tr348;
		case 80: goto tr338;
		case 91: goto tr339;
		case 92: goto tr340;
		case 94: goto tr327;
		case 95: goto tr330;
		case 97: goto tr341;
		case 100: goto tr342;
		case 101: goto tr335;
		case 104: goto tr343;
		case 109: goto st153;
		case 112: goto tr345;
		case 115: goto tr346;
		case 121: goto tr347;
		case 123: goto tr327;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr327;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr327;
		} else if ( (*p) >= 63 )
			goto tr329;
	} else
		goto tr327;
	goto st0;
tr85:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st163;
tr105:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st163;
tr346:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st163;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
#line 6228 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr328;
		case 35: goto tr329;
		case 37: goto tr329;
		case 42: goto tr330;
		case 44: goto tr329;
		case 46: goto st82;
		case 48: goto tr329;
		case 59: goto tr332;
		case 65: goto tr333;
		case 68: goto tr334;
		case 69: goto tr335;
		case 72: goto tr336;
		case 77: goto tr348;
		case 80: goto tr338;
		case 91: goto tr339;
		case 92: goto tr340;
		case 94: goto tr327;
		case 95: goto tr330;
		case 97: goto tr341;
		case 100: goto tr342;
		case 101: goto tr335;
		case 104: goto tr343;
		case 109: goto tr344;
		case 112: goto tr345;
		case 115: goto st166;
		case 121: goto tr347;
		case 123: goto tr327;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr327;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr327;
		} else if ( (*p) >= 63 )
			goto tr329;
	} else
		goto tr327;
	goto st0;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	switch( (*p) ) {
		case 35: goto st164;
		case 44: goto st164;
		case 48: goto st164;
		case 63: goto st164;
	}
	goto st0;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
	switch( (*p) ) {
		case 34: goto tr328;
		case 35: goto st164;
		case 37: goto tr329;
		case 42: goto tr330;
		case 44: goto st164;
		case 46: goto tr329;
		case 48: goto st164;
		case 59: goto tr332;
		case 63: goto st164;
		case 64: goto tr329;
		case 65: goto tr333;
		case 68: goto tr334;
		case 69: goto tr335;
		case 72: goto tr336;
		case 77: goto tr348;
		case 80: goto tr338;
		case 91: goto tr339;
		case 92: goto tr340;
		case 94: goto tr327;
		case 95: goto tr330;
		case 97: goto tr341;
		case 100: goto tr342;
		case 101: goto tr335;
		case 104: goto tr343;
		case 109: goto tr344;
		case 112: goto tr345;
		case 115: goto tr346;
		case 121: goto tr347;
		case 123: goto tr327;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr327;
	} else if ( (*p) > 62 ) {
		if ( 125 <= (*p) && (*p) <= 126 )
			goto tr327;
	} else
		goto tr327;
	goto st0;
tr86:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st165;
tr106:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st165;
tr347:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st165;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
#line 6359 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr328;
		case 35: goto tr329;
		case 37: goto tr329;
		case 42: goto tr330;
		case 44: goto tr329;
		case 46: goto tr329;
		case 48: goto tr329;
		case 59: goto tr332;
		case 65: goto tr333;
		case 68: goto tr334;
		case 69: goto tr335;
		case 72: goto tr336;
		case 77: goto tr348;
		case 80: goto tr338;
		case 91: goto tr339;
		case 92: goto tr340;
		case 94: goto tr327;
		case 95: goto tr330;
		case 97: goto tr341;
		case 100: goto tr342;
		case 101: goto tr335;
		case 104: goto tr343;
		case 109: goto tr344;
		case 112: goto tr345;
		case 115: goto tr346;
		case 121: goto st165;
		case 123: goto tr327;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr327;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr327;
		} else if ( (*p) >= 63 )
			goto tr329;
	} else
		goto tr327;
	goto st0;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
	switch( (*p) ) {
		case 34: goto tr328;
		case 35: goto tr329;
		case 37: goto tr329;
		case 42: goto tr330;
		case 44: goto tr329;
		case 46: goto st82;
		case 48: goto tr329;
		case 59: goto tr332;
		case 65: goto tr333;
		case 68: goto tr334;
		case 69: goto tr335;
		case 72: goto tr336;
		case 77: goto tr348;
		case 80: goto tr338;
		case 91: goto tr339;
		case 92: goto tr340;
		case 94: goto tr327;
		case 95: goto tr330;
		case 97: goto tr341;
		case 100: goto tr342;
		case 101: goto tr335;
		case 104: goto tr343;
		case 109: goto tr344;
		case 112: goto tr345;
		case 115: goto tr346;
		case 121: goto tr347;
		case 123: goto tr327;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr327;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr327;
		} else if ( (*p) >= 63 )
			goto tr329;
	} else
		goto tr327;
	goto st0;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
	switch( (*p) ) {
		case 34: goto tr328;
		case 35: goto tr329;
		case 37: goto tr329;
		case 42: goto tr330;
		case 44: goto tr329;
		case 47: goto st83;
		case 59: goto tr332;
		case 65: goto tr333;
		case 68: goto tr334;
		case 69: goto tr335;
		case 72: goto tr336;
		case 77: goto tr348;
		case 80: goto tr338;
		case 91: goto tr339;
		case 92: goto tr340;
		case 94: goto tr327;
		case 95: goto tr330;
		case 97: goto tr341;
		case 100: goto tr342;
		case 101: goto tr335;
		case 104: goto tr343;
		case 109: goto tr344;
		case 112: goto tr345;
		case 115: goto tr346;
		case 121: goto tr347;
		case 123: goto tr327;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr329;
		} else if ( (*p) >= 32 )
			goto tr327;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr327;
		} else if ( (*p) >= 63 )
			goto tr329;
	} else
		goto tr327;
	goto st0;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	if ( (*p) == 112 )
		goto st84;
	goto st0;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	if ( (*p) == 109 )
		goto st153;
	goto st0;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
	switch( (*p) ) {
		case 34: goto tr328;
		case 35: goto tr329;
		case 37: goto tr329;
		case 42: goto tr330;
		case 44: goto tr329;
		case 47: goto st85;
		case 59: goto tr332;
		case 65: goto tr333;
		case 68: goto tr334;
		case 69: goto tr335;
		case 72: goto tr336;
		case 77: goto tr348;
		case 80: goto tr338;
		case 91: goto tr339;
		case 92: goto tr340;
		case 94: goto tr327;
		case 95: goto tr330;
		case 97: goto tr341;
		case 100: goto tr342;
		case 101: goto tr335;
		case 104: goto tr343;
		case 109: goto tr344;
		case 112: goto tr345;
		case 115: goto tr346;
		case 121: goto tr347;
		case 123: goto tr327;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr329;
		} else if ( (*p) >= 32 )
			goto tr327;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr327;
		} else if ( (*p) >= 63 )
			goto tr329;
	} else
		goto tr327;
	goto st0;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	if ( (*p) == 80 )
		goto st86;
	goto st0;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	if ( (*p) == 77 )
		goto st153;
	goto st0;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	switch( (*p) ) {
		case 60: goto st73;
		case 61: goto st78;
		case 62: goto st79;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st88;
	} else if ( (*p) >= 65 )
		goto st88;
	goto st0;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	if ( (*p) == 93 )
		goto st91;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st88;
	} else if ( (*p) >= 65 )
		goto st88;
	goto st0;
	}
	_test_eof90: cs = 90; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof91: cs = 91; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof92: cs = 92; goto _test_eof; 
	_test_eof93: cs = 93; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof94: cs = 94; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof95: cs = 95; goto _test_eof; 
	_test_eof96: cs = 96; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof97: cs = 97; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof98: cs = 98; goto _test_eof; 
	_test_eof99: cs = 99; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof100: cs = 100; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof101: cs = 101; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof102: cs = 102; goto _test_eof; 
	_test_eof103: cs = 103; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof104: cs = 104; goto _test_eof; 
	_test_eof105: cs = 105; goto _test_eof; 
	_test_eof106: cs = 106; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof107: cs = 107; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof108: cs = 108; goto _test_eof; 
	_test_eof109: cs = 109; goto _test_eof; 
	_test_eof110: cs = 110; goto _test_eof; 
	_test_eof111: cs = 111; goto _test_eof; 
	_test_eof112: cs = 112; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof113: cs = 113; goto _test_eof; 
	_test_eof114: cs = 114; goto _test_eof; 
	_test_eof115: cs = 115; goto _test_eof; 
	_test_eof116: cs = 116; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof117: cs = 117; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof118: cs = 118; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof119: cs = 119; goto _test_eof; 
	_test_eof120: cs = 120; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof121: cs = 121; goto _test_eof; 
	_test_eof122: cs = 122; goto _test_eof; 
	_test_eof123: cs = 123; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof124: cs = 124; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof125: cs = 125; goto _test_eof; 
	_test_eof126: cs = 126; goto _test_eof; 
	_test_eof127: cs = 127; goto _test_eof; 
	_test_eof128: cs = 128; goto _test_eof; 
	_test_eof129: cs = 129; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof130: cs = 130; goto _test_eof; 
	_test_eof131: cs = 131; goto _test_eof; 
	_test_eof132: cs = 132; goto _test_eof; 
	_test_eof133: cs = 133; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof134: cs = 134; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof135: cs = 135; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof136: cs = 136; goto _test_eof; 
	_test_eof137: cs = 137; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof138: cs = 138; goto _test_eof; 
	_test_eof139: cs = 139; goto _test_eof; 
	_test_eof140: cs = 140; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof141: cs = 141; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof142: cs = 142; goto _test_eof; 
	_test_eof143: cs = 143; goto _test_eof; 
	_test_eof144: cs = 144; goto _test_eof; 
	_test_eof145: cs = 145; goto _test_eof; 
	_test_eof146: cs = 146; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof147: cs = 147; goto _test_eof; 
	_test_eof148: cs = 148; goto _test_eof; 
	_test_eof149: cs = 149; goto _test_eof; 
	_test_eof150: cs = 150; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof151: cs = 151; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof152: cs = 152; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof153: cs = 153; goto _test_eof; 
	_test_eof154: cs = 154; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof155: cs = 155; goto _test_eof; 
	_test_eof156: cs = 156; goto _test_eof; 
	_test_eof157: cs = 157; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof73: cs = 73; goto _test_eof; 
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof75: cs = 75; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof158: cs = 158; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof159: cs = 159; goto _test_eof; 
	_test_eof160: cs = 160; goto _test_eof; 
	_test_eof161: cs = 161; goto _test_eof; 
	_test_eof162: cs = 162; goto _test_eof; 
	_test_eof163: cs = 163; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof164: cs = 164; goto _test_eof; 
	_test_eof165: cs = 165; goto _test_eof; 
	_test_eof166: cs = 166; goto _test_eof; 
	_test_eof167: cs = 167; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof168: cs = 168; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof86: cs = 86; goto _test_eof; 
	_test_eof87: cs = 87; goto _test_eof; 
	_test_eof88: cs = 88; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 101: 
	case 102: 
	case 103: 
	case 104: 
	case 105: 
	case 106: 
	case 107: 
	case 108: 
	case 109: 
	case 110: 
	case 111: 
	case 112: 
	case 113: 
	case 114: 
	case 115: 
	case 116: 
	case 117: 
	case 118: 
	case 119: 
	case 120: 
	case 121: 
	case 122: 
	case 123: 
	case 124: 
	case 125: 
	case 126: 
	case 127: 
	case 128: 
	case 129: 
	case 130: 
	case 131: 
	case 132: 
	case 133: 
	case 134: 
	case 135: 
	case 136: 
	case 137: 
	case 138: 
	case 139: 
	case 140: 
	case 141: 
	case 142: 
	case 143: 
	case 144: 
	case 145: 
	case 146: 
	case 147: 
	case 148: 
	case 149: 
	case 150: 
	case 151: 
	case 152: 
	case 153: 
	case 154: 
	case 155: 
	case 156: 
	case 157: 
	case 158: 
	case 159: 
	case 160: 
	case 161: 
	case 162: 
	case 163: 
	case 164: 
	case 165: 
	case 166: 
	case 167: 
	case 168: 
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	break;
	case 90: 
	case 93: 
	case 96: 
	case 99: 
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	break;
#line 6854 "src/tfs_excel_parser.c"
	}
	}

	_out: {}
	}

#line 103 "src/tfs_excel_parser.rl"


    if (cs < 
#line 6865 "src/tfs_excel_parser.c"
89
#line 105 "src/tfs_excel_parser.rl"
) {
        printf("Error parsing Excel format string '%s' around col #%ld (%c)",
            bytes, (long)(p - bytes + 1), *p);
        return 1;
    }

    return 0;
}
