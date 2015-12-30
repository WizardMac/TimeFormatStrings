
#line 1 "src/tfs_excel_parser.rl"

#include <sys/types.h>
#include <stdio.h>
#include "tfs.h"
#include "tfs_internal.h"
#include "tfs_excel_parser.h"

/* See http://office.microsoft.com/en-us/excel-help/text-function-HP010062580.aspx */


#line 14 "src/tfs_excel_parser.c"
static const int excel_format_start = 93;
static const int excel_format_first_final = 93;
static const int excel_format_error = 0;

static const int excel_format_en_main = 93;


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
case 93:
	switch( (*p) ) {
		case 34: goto tr73;
		case 35: goto st95;
		case 37: goto st95;
		case 42: goto st3;
		case 44: goto st95;
		case 46: goto st95;
		case 48: goto st95;
		case 59: goto st96;
		case 65: goto tr76;
		case 68: goto tr77;
		case 69: goto st74;
		case 72: goto tr79;
		case 77: goto tr80;
		case 80: goto tr81;
		case 91: goto st90;
		case 92: goto st83;
		case 94: goto tr67;
		case 95: goto st3;
		case 97: goto tr84;
		case 100: goto tr85;
		case 101: goto st74;
		case 104: goto tr86;
		case 109: goto tr87;
		case 112: goto tr88;
		case 115: goto tr89;
		case 121: goto tr90;
		case 123: goto tr67;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr67;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr67;
		} else if ( (*p) >= 63 )
			goto st95;
	} else
		goto tr67;
	goto st0;
st0:
cs = 0;
	goto _out;
tr67:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st94;
tr91:
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
	goto st94;
tr331:
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
	goto st94;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
#line 127 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr92;
		case 35: goto tr93;
		case 37: goto tr93;
		case 42: goto tr94;
		case 44: goto tr93;
		case 46: goto tr93;
		case 48: goto tr93;
		case 59: goto tr95;
		case 65: goto tr96;
		case 68: goto tr97;
		case 69: goto tr98;
		case 72: goto tr99;
		case 77: goto tr100;
		case 80: goto tr101;
		case 91: goto tr102;
		case 92: goto tr103;
		case 94: goto tr91;
		case 95: goto tr94;
		case 97: goto tr104;
		case 100: goto tr105;
		case 101: goto tr98;
		case 104: goto tr106;
		case 109: goto tr107;
		case 112: goto tr108;
		case 115: goto tr109;
		case 121: goto tr110;
		case 123: goto tr91;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr91;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr91;
		} else if ( (*p) >= 63 )
			goto tr93;
	} else
		goto tr91;
	goto st0;
tr73:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st1;
tr92:
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
tr332:
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
		case 34: goto st94;
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
tr93:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st95;
tr333:
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
#line 236 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr73;
		case 35: goto st95;
		case 37: goto st95;
		case 42: goto st3;
		case 44: goto st95;
		case 46: goto st95;
		case 48: goto st95;
		case 59: goto st96;
		case 65: goto tr76;
		case 68: goto tr77;
		case 69: goto st74;
		case 72: goto tr79;
		case 77: goto tr80;
		case 80: goto tr81;
		case 91: goto st75;
		case 92: goto st83;
		case 94: goto tr67;
		case 95: goto st3;
		case 97: goto tr84;
		case 100: goto tr85;
		case 101: goto st74;
		case 104: goto tr86;
		case 109: goto tr87;
		case 112: goto tr88;
		case 115: goto tr89;
		case 121: goto tr90;
		case 123: goto tr67;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr67;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr67;
		} else if ( (*p) >= 63 )
			goto st95;
	} else
		goto tr67;
	goto st0;
tr94:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st3;
tr334:
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
	goto st95;
tr95:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st96;
tr336:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st96;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
#line 320 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr112;
		case 35: goto st98;
		case 37: goto st98;
		case 42: goto st6;
		case 44: goto st98;
		case 46: goto st98;
		case 48: goto st98;
		case 59: goto st99;
		case 65: goto tr115;
		case 68: goto tr116;
		case 69: goto st54;
		case 72: goto tr118;
		case 77: goto tr119;
		case 80: goto tr120;
		case 91: goto st70;
		case 92: goto st63;
		case 94: goto tr53;
		case 95: goto st6;
		case 97: goto tr123;
		case 100: goto tr124;
		case 101: goto st54;
		case 104: goto tr125;
		case 109: goto tr126;
		case 112: goto tr127;
		case 115: goto tr128;
		case 121: goto tr129;
		case 123: goto tr53;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr53;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr53;
		} else if ( (*p) >= 63 )
			goto st98;
	} else
		goto tr53;
	goto st0;
tr53:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st97;
tr130:
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
	goto st97;
tr296:
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
	goto st97;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
#line 396 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr131;
		case 35: goto tr132;
		case 37: goto tr132;
		case 42: goto tr133;
		case 44: goto tr132;
		case 46: goto tr132;
		case 48: goto tr132;
		case 59: goto tr134;
		case 65: goto tr135;
		case 68: goto tr136;
		case 69: goto tr137;
		case 72: goto tr138;
		case 77: goto tr139;
		case 80: goto tr140;
		case 91: goto tr141;
		case 92: goto tr142;
		case 94: goto tr130;
		case 95: goto tr133;
		case 97: goto tr143;
		case 100: goto tr144;
		case 101: goto tr137;
		case 104: goto tr145;
		case 109: goto tr146;
		case 112: goto tr147;
		case 115: goto tr148;
		case 121: goto tr149;
		case 123: goto tr130;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr130;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr130;
		} else if ( (*p) >= 63 )
			goto tr132;
	} else
		goto tr130;
	goto st0;
tr112:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st4;
tr131:
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
tr297:
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
		case 34: goto st97;
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
tr132:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st98;
tr298:
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
#line 505 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr112;
		case 35: goto st98;
		case 37: goto st98;
		case 42: goto st6;
		case 44: goto st98;
		case 46: goto st98;
		case 48: goto st98;
		case 59: goto st99;
		case 65: goto tr115;
		case 68: goto tr116;
		case 69: goto st54;
		case 72: goto tr118;
		case 77: goto tr119;
		case 80: goto tr120;
		case 91: goto st55;
		case 92: goto st63;
		case 94: goto tr53;
		case 95: goto st6;
		case 97: goto tr123;
		case 100: goto tr124;
		case 101: goto st54;
		case 104: goto tr125;
		case 109: goto tr126;
		case 112: goto tr127;
		case 115: goto tr128;
		case 121: goto tr129;
		case 123: goto tr53;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr53;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr53;
		} else if ( (*p) >= 63 )
			goto st98;
	} else
		goto tr53;
	goto st0;
tr133:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st6;
tr299:
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
	goto st98;
tr134:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st99;
tr301:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st99;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
#line 589 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr151;
		case 35: goto st101;
		case 37: goto st101;
		case 42: goto st9;
		case 44: goto st101;
		case 46: goto st101;
		case 48: goto st101;
		case 59: goto st102;
		case 65: goto tr154;
		case 68: goto tr155;
		case 69: goto st34;
		case 72: goto tr157;
		case 77: goto tr158;
		case 80: goto tr159;
		case 91: goto st50;
		case 92: goto st43;
		case 94: goto tr39;
		case 95: goto st9;
		case 97: goto tr162;
		case 100: goto tr163;
		case 101: goto st34;
		case 104: goto tr164;
		case 109: goto tr165;
		case 112: goto tr166;
		case 115: goto tr167;
		case 121: goto tr168;
		case 123: goto tr39;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr39;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr39;
		} else if ( (*p) >= 63 )
			goto st101;
	} else
		goto tr39;
	goto st0;
tr39:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st100;
tr169:
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
	goto st100;
tr261:
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
	goto st100;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
#line 665 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr170;
		case 35: goto tr171;
		case 37: goto tr171;
		case 42: goto tr172;
		case 44: goto tr171;
		case 46: goto tr171;
		case 48: goto tr171;
		case 59: goto tr173;
		case 65: goto tr174;
		case 68: goto tr175;
		case 69: goto tr176;
		case 72: goto tr177;
		case 77: goto tr178;
		case 80: goto tr179;
		case 91: goto tr180;
		case 92: goto tr181;
		case 94: goto tr169;
		case 95: goto tr172;
		case 97: goto tr182;
		case 100: goto tr183;
		case 101: goto tr176;
		case 104: goto tr184;
		case 109: goto tr185;
		case 112: goto tr186;
		case 115: goto tr187;
		case 121: goto tr188;
		case 123: goto tr169;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr169;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr169;
		} else if ( (*p) >= 63 )
			goto tr171;
	} else
		goto tr169;
	goto st0;
tr151:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st7;
tr170:
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
tr262:
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
		case 34: goto st100;
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
tr171:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st101;
tr263:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st101;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
#line 774 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr151;
		case 35: goto st101;
		case 37: goto st101;
		case 42: goto st9;
		case 44: goto st101;
		case 46: goto st101;
		case 48: goto st101;
		case 59: goto st102;
		case 65: goto tr154;
		case 68: goto tr155;
		case 69: goto st34;
		case 72: goto tr157;
		case 77: goto tr158;
		case 80: goto tr159;
		case 91: goto st35;
		case 92: goto st43;
		case 94: goto tr39;
		case 95: goto st9;
		case 97: goto tr162;
		case 100: goto tr163;
		case 101: goto st34;
		case 104: goto tr164;
		case 109: goto tr165;
		case 112: goto tr166;
		case 115: goto tr167;
		case 121: goto tr168;
		case 123: goto tr39;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr39;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr39;
		} else if ( (*p) >= 63 )
			goto st101;
	} else
		goto tr39;
	goto st0;
tr172:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st9;
tr264:
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
	goto st101;
tr173:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st102;
tr266:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st102;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
#line 858 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr190;
		case 35: goto st104;
		case 37: goto st104;
		case 42: goto st12;
		case 44: goto st104;
		case 46: goto st104;
		case 48: goto st104;
		case 58: goto tr25;
		case 65: goto tr192;
		case 68: goto tr193;
		case 69: goto st14;
		case 72: goto tr195;
		case 77: goto tr196;
		case 80: goto tr197;
		case 91: goto st30;
		case 92: goto st23;
		case 94: goto tr25;
		case 95: goto st12;
		case 97: goto tr200;
		case 100: goto tr201;
		case 101: goto st14;
		case 104: goto tr202;
		case 109: goto tr203;
		case 112: goto tr204;
		case 115: goto tr205;
		case 121: goto tr206;
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
			goto st104;
	} else
		goto tr25;
	goto st0;
tr25:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st103;
tr207:
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
	goto st103;
tr227:
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
	goto st103;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
#line 934 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr208;
		case 35: goto tr209;
		case 37: goto tr209;
		case 42: goto tr210;
		case 44: goto tr209;
		case 46: goto tr209;
		case 48: goto tr209;
		case 58: goto tr207;
		case 65: goto tr211;
		case 68: goto tr212;
		case 69: goto tr213;
		case 72: goto tr214;
		case 77: goto tr215;
		case 80: goto tr216;
		case 91: goto tr217;
		case 92: goto tr218;
		case 94: goto tr207;
		case 95: goto tr210;
		case 97: goto tr219;
		case 100: goto tr220;
		case 101: goto tr213;
		case 104: goto tr221;
		case 109: goto tr222;
		case 112: goto tr223;
		case 115: goto tr224;
		case 121: goto tr225;
		case 123: goto tr207;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr207;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr207;
		} else if ( (*p) >= 63 )
			goto tr209;
	} else
		goto tr207;
	goto st0;
tr190:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st10;
tr208:
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
tr228:
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
		case 34: goto st103;
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
tr209:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st104;
tr229:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st104;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
#line 1043 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr190;
		case 35: goto st104;
		case 37: goto st104;
		case 42: goto st12;
		case 44: goto st104;
		case 46: goto st104;
		case 48: goto st104;
		case 58: goto tr25;
		case 65: goto tr192;
		case 68: goto tr193;
		case 69: goto st14;
		case 72: goto tr195;
		case 77: goto tr196;
		case 80: goto tr197;
		case 91: goto st15;
		case 92: goto st23;
		case 94: goto tr25;
		case 95: goto st12;
		case 97: goto tr200;
		case 100: goto tr201;
		case 101: goto st14;
		case 104: goto tr202;
		case 109: goto tr203;
		case 112: goto tr204;
		case 115: goto tr205;
		case 121: goto tr206;
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
			goto st104;
	} else
		goto tr25;
	goto st0;
tr210:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st12;
tr230:
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
	goto st104;
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
tr232:
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
#line 1141 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr228;
		case 35: goto tr229;
		case 37: goto tr229;
		case 42: goto tr230;
		case 44: goto tr229;
		case 47: goto st13;
		case 58: goto tr227;
		case 65: goto tr232;
		case 68: goto tr233;
		case 69: goto tr234;
		case 72: goto tr235;
		case 77: goto st121;
		case 80: goto tr237;
		case 91: goto tr238;
		case 92: goto tr239;
		case 94: goto tr227;
		case 95: goto tr230;
		case 97: goto tr240;
		case 100: goto tr241;
		case 101: goto tr234;
		case 104: goto tr242;
		case 109: goto tr243;
		case 112: goto tr244;
		case 115: goto tr245;
		case 121: goto tr246;
		case 123: goto tr227;
	}
	if ( (*p) < 60 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr229;
		} else if ( (*p) >= 32 )
			goto tr227;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr227;
		} else if ( (*p) >= 63 )
			goto tr229;
	} else
		goto tr227;
	goto st0;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	if ( (*p) == 80 )
		goto st106;
	goto st0;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	switch( (*p) ) {
		case 34: goto tr228;
		case 35: goto tr229;
		case 37: goto tr229;
		case 42: goto tr230;
		case 44: goto tr229;
		case 46: goto tr229;
		case 48: goto tr229;
		case 58: goto tr227;
		case 65: goto tr232;
		case 68: goto tr233;
		case 69: goto tr234;
		case 72: goto tr235;
		case 77: goto tr247;
		case 80: goto tr237;
		case 91: goto tr238;
		case 92: goto tr239;
		case 94: goto tr227;
		case 95: goto tr230;
		case 97: goto tr240;
		case 100: goto tr241;
		case 101: goto tr234;
		case 104: goto tr242;
		case 109: goto tr243;
		case 112: goto tr244;
		case 115: goto tr245;
		case 121: goto tr246;
		case 123: goto tr227;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr227;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr227;
		} else if ( (*p) >= 63 )
			goto tr229;
	} else
		goto tr227;
	goto st0;
tr193:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st107;
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
	goto st107;
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
	goto st107;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
#line 1271 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr228;
		case 35: goto tr229;
		case 37: goto tr229;
		case 42: goto tr230;
		case 44: goto tr229;
		case 46: goto tr229;
		case 48: goto tr229;
		case 58: goto tr227;
		case 65: goto tr232;
		case 68: goto st107;
		case 69: goto tr234;
		case 72: goto tr235;
		case 77: goto tr247;
		case 80: goto tr237;
		case 91: goto tr238;
		case 92: goto tr239;
		case 94: goto tr227;
		case 95: goto tr230;
		case 97: goto tr240;
		case 100: goto tr241;
		case 101: goto tr234;
		case 104: goto tr242;
		case 109: goto tr243;
		case 112: goto tr244;
		case 115: goto tr245;
		case 121: goto tr246;
		case 123: goto tr227;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr227;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr227;
		} else if ( (*p) >= 63 )
			goto tr229;
	} else
		goto tr227;
	goto st0;
tr213:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st14;
tr234:
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
		case 43: goto st104;
		case 45: goto st104;
	}
	goto st0;
tr195:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st108;
tr214:
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
tr235:
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
#line 1373 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr228;
		case 35: goto tr229;
		case 37: goto tr229;
		case 42: goto tr230;
		case 44: goto tr229;
		case 46: goto tr229;
		case 48: goto tr229;
		case 58: goto tr227;
		case 65: goto tr232;
		case 68: goto tr233;
		case 69: goto tr234;
		case 72: goto st108;
		case 77: goto tr247;
		case 80: goto tr237;
		case 91: goto tr238;
		case 92: goto tr239;
		case 94: goto tr227;
		case 95: goto tr230;
		case 97: goto tr240;
		case 100: goto tr241;
		case 101: goto tr234;
		case 104: goto tr242;
		case 109: goto tr243;
		case 112: goto tr244;
		case 115: goto tr245;
		case 121: goto tr246;
		case 123: goto tr227;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr227;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr227;
		} else if ( (*p) >= 63 )
			goto tr229;
	} else
		goto tr227;
	goto st0;
tr196:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st109;
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
	goto st109;
tr247:
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
#line 1449 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr228;
		case 35: goto tr229;
		case 37: goto tr229;
		case 42: goto tr230;
		case 44: goto tr229;
		case 46: goto tr229;
		case 48: goto tr229;
		case 58: goto tr227;
		case 65: goto tr232;
		case 68: goto tr233;
		case 69: goto tr234;
		case 72: goto tr235;
		case 77: goto st109;
		case 80: goto tr237;
		case 91: goto tr238;
		case 92: goto tr239;
		case 94: goto tr227;
		case 95: goto tr230;
		case 97: goto tr240;
		case 100: goto tr241;
		case 101: goto tr234;
		case 104: goto tr242;
		case 109: goto tr243;
		case 112: goto tr244;
		case 115: goto tr245;
		case 121: goto tr246;
		case 123: goto tr227;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr227;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr227;
		} else if ( (*p) >= 63 )
			goto tr229;
	} else
		goto tr227;
	goto st0;
tr197:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st110;
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
	goto st110;
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
	goto st110;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
#line 1525 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr228;
		case 35: goto tr229;
		case 37: goto tr229;
		case 42: goto tr230;
		case 44: goto tr229;
		case 46: goto tr229;
		case 48: goto tr229;
		case 58: goto tr227;
		case 65: goto tr232;
		case 68: goto tr233;
		case 69: goto tr234;
		case 72: goto tr235;
		case 77: goto st106;
		case 80: goto tr237;
		case 91: goto tr238;
		case 92: goto tr239;
		case 94: goto tr227;
		case 95: goto tr230;
		case 97: goto tr240;
		case 100: goto tr241;
		case 101: goto tr234;
		case 104: goto tr242;
		case 109: goto tr243;
		case 112: goto tr244;
		case 115: goto tr245;
		case 121: goto tr246;
		case 123: goto tr227;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr227;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr227;
		} else if ( (*p) >= 63 )
			goto tr229;
	} else
		goto tr227;
	goto st0;
tr217:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st15;
tr238:
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
		goto st104;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st19;
	goto st0;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	switch( (*p) ) {
		case 46: goto st18;
		case 93: goto st104;
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
tr218:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st23;
tr239:
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
#line 1723 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr228;
		case 35: goto tr229;
		case 37: goto tr229;
		case 42: goto tr230;
		case 44: goto tr229;
		case 47: goto st24;
		case 58: goto tr227;
		case 65: goto tr232;
		case 68: goto tr233;
		case 69: goto tr234;
		case 72: goto tr235;
		case 77: goto tr247;
		case 80: goto tr237;
		case 91: goto tr238;
		case 92: goto tr239;
		case 94: goto tr227;
		case 95: goto tr230;
		case 97: goto tr240;
		case 100: goto tr241;
		case 101: goto tr234;
		case 104: goto tr242;
		case 109: goto st120;
		case 112: goto tr244;
		case 115: goto tr245;
		case 121: goto tr246;
		case 123: goto tr227;
	}
	if ( (*p) < 60 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr229;
		} else if ( (*p) >= 32 )
			goto tr227;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr227;
		} else if ( (*p) >= 63 )
			goto tr229;
	} else
		goto tr227;
	goto st0;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	if ( (*p) == 112 )
		goto st106;
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
#line 1808 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr228;
		case 35: goto tr229;
		case 37: goto tr229;
		case 42: goto tr230;
		case 44: goto tr229;
		case 46: goto tr229;
		case 48: goto tr229;
		case 58: goto tr227;
		case 65: goto tr232;
		case 68: goto tr233;
		case 69: goto tr234;
		case 72: goto tr235;
		case 77: goto tr247;
		case 80: goto tr237;
		case 91: goto tr238;
		case 92: goto tr239;
		case 94: goto tr227;
		case 95: goto tr230;
		case 97: goto tr240;
		case 100: goto st112;
		case 101: goto tr234;
		case 104: goto tr242;
		case 109: goto tr243;
		case 112: goto tr244;
		case 115: goto tr245;
		case 121: goto tr246;
		case 123: goto tr227;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr227;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr227;
		} else if ( (*p) >= 63 )
			goto tr229;
	} else
		goto tr227;
	goto st0;
tr202:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st113;
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
	goto st113;
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
	goto st113;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
#line 1884 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr228;
		case 35: goto tr229;
		case 37: goto tr229;
		case 42: goto tr230;
		case 44: goto tr229;
		case 46: goto tr229;
		case 48: goto tr229;
		case 58: goto tr227;
		case 65: goto tr232;
		case 68: goto tr233;
		case 69: goto tr234;
		case 72: goto tr235;
		case 77: goto tr247;
		case 80: goto tr237;
		case 91: goto tr238;
		case 92: goto tr239;
		case 94: goto tr227;
		case 95: goto tr230;
		case 97: goto tr240;
		case 100: goto tr241;
		case 101: goto tr234;
		case 104: goto st113;
		case 109: goto tr243;
		case 112: goto tr244;
		case 115: goto tr245;
		case 121: goto tr246;
		case 123: goto tr227;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr227;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr227;
		} else if ( (*p) >= 63 )
			goto tr229;
	} else
		goto tr227;
	goto st0;
tr203:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st114;
tr222:
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
	goto st114;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
#line 1960 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr228;
		case 35: goto tr229;
		case 37: goto tr229;
		case 42: goto tr230;
		case 44: goto tr229;
		case 46: goto tr229;
		case 48: goto tr229;
		case 58: goto tr227;
		case 65: goto tr232;
		case 68: goto tr233;
		case 69: goto tr234;
		case 72: goto tr235;
		case 77: goto tr247;
		case 80: goto tr237;
		case 91: goto tr238;
		case 92: goto tr239;
		case 94: goto tr227;
		case 95: goto tr230;
		case 97: goto tr240;
		case 100: goto tr241;
		case 101: goto tr234;
		case 104: goto tr242;
		case 109: goto st114;
		case 112: goto tr244;
		case 115: goto tr245;
		case 121: goto tr246;
		case 123: goto tr227;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr227;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr227;
		} else if ( (*p) >= 63 )
			goto tr229;
	} else
		goto tr227;
	goto st0;
tr204:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st115;
tr223:
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
	goto st115;
tr244:
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
	goto st115;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
#line 2036 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr228;
		case 35: goto tr229;
		case 37: goto tr229;
		case 42: goto tr230;
		case 44: goto tr229;
		case 46: goto tr229;
		case 48: goto tr229;
		case 58: goto tr227;
		case 65: goto tr232;
		case 68: goto tr233;
		case 69: goto tr234;
		case 72: goto tr235;
		case 77: goto tr247;
		case 80: goto tr237;
		case 91: goto tr238;
		case 92: goto tr239;
		case 94: goto tr227;
		case 95: goto tr230;
		case 97: goto tr240;
		case 100: goto tr241;
		case 101: goto tr234;
		case 104: goto tr242;
		case 109: goto st106;
		case 112: goto tr244;
		case 115: goto tr245;
		case 121: goto tr246;
		case 123: goto tr227;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr227;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr227;
		} else if ( (*p) >= 63 )
			goto tr229;
	} else
		goto tr227;
	goto st0;
tr205:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st116;
tr224:
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
	goto st116;
tr245:
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
	goto st116;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
#line 2112 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr228;
		case 35: goto tr229;
		case 37: goto tr229;
		case 42: goto tr230;
		case 44: goto tr229;
		case 46: goto st25;
		case 48: goto tr229;
		case 58: goto tr227;
		case 65: goto tr232;
		case 68: goto tr233;
		case 69: goto tr234;
		case 72: goto tr235;
		case 77: goto tr247;
		case 80: goto tr237;
		case 91: goto tr238;
		case 92: goto tr239;
		case 94: goto tr227;
		case 95: goto tr230;
		case 97: goto tr240;
		case 100: goto tr241;
		case 101: goto tr234;
		case 104: goto tr242;
		case 109: goto tr243;
		case 112: goto tr244;
		case 115: goto st119;
		case 121: goto tr246;
		case 123: goto tr227;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr227;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr227;
		} else if ( (*p) >= 63 )
			goto tr229;
	} else
		goto tr227;
	goto st0;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	switch( (*p) ) {
		case 35: goto st117;
		case 44: goto st117;
		case 48: goto st117;
		case 63: goto st117;
	}
	goto st0;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	switch( (*p) ) {
		case 34: goto tr228;
		case 35: goto st117;
		case 37: goto tr229;
		case 42: goto tr230;
		case 44: goto st117;
		case 46: goto tr229;
		case 48: goto st117;
		case 58: goto tr227;
		case 63: goto st117;
		case 64: goto tr229;
		case 65: goto tr232;
		case 68: goto tr233;
		case 69: goto tr234;
		case 72: goto tr235;
		case 77: goto tr247;
		case 80: goto tr237;
		case 91: goto tr238;
		case 92: goto tr239;
		case 94: goto tr227;
		case 95: goto tr230;
		case 97: goto tr240;
		case 100: goto tr241;
		case 101: goto tr234;
		case 104: goto tr242;
		case 109: goto tr243;
		case 112: goto tr244;
		case 115: goto tr245;
		case 121: goto tr246;
		case 123: goto tr227;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr227;
	} else if ( (*p) > 62 ) {
		if ( 125 <= (*p) && (*p) <= 126 )
			goto tr227;
	} else
		goto tr227;
	goto st0;
tr206:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st118;
tr225:
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
tr246:
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
#line 2243 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr228;
		case 35: goto tr229;
		case 37: goto tr229;
		case 42: goto tr230;
		case 44: goto tr229;
		case 46: goto tr229;
		case 48: goto tr229;
		case 58: goto tr227;
		case 65: goto tr232;
		case 68: goto tr233;
		case 69: goto tr234;
		case 72: goto tr235;
		case 77: goto tr247;
		case 80: goto tr237;
		case 91: goto tr238;
		case 92: goto tr239;
		case 94: goto tr227;
		case 95: goto tr230;
		case 97: goto tr240;
		case 100: goto tr241;
		case 101: goto tr234;
		case 104: goto tr242;
		case 109: goto tr243;
		case 112: goto tr244;
		case 115: goto tr245;
		case 121: goto st118;
		case 123: goto tr227;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr227;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr227;
		} else if ( (*p) >= 63 )
			goto tr229;
	} else
		goto tr227;
	goto st0;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	switch( (*p) ) {
		case 34: goto tr228;
		case 35: goto tr229;
		case 37: goto tr229;
		case 42: goto tr230;
		case 44: goto tr229;
		case 46: goto st25;
		case 48: goto tr229;
		case 58: goto tr227;
		case 65: goto tr232;
		case 68: goto tr233;
		case 69: goto tr234;
		case 72: goto tr235;
		case 77: goto tr247;
		case 80: goto tr237;
		case 91: goto tr238;
		case 92: goto tr239;
		case 94: goto tr227;
		case 95: goto tr230;
		case 97: goto tr240;
		case 100: goto tr241;
		case 101: goto tr234;
		case 104: goto tr242;
		case 109: goto tr243;
		case 112: goto tr244;
		case 115: goto tr245;
		case 121: goto tr246;
		case 123: goto tr227;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr227;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr227;
		} else if ( (*p) >= 63 )
			goto tr229;
	} else
		goto tr227;
	goto st0;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	switch( (*p) ) {
		case 34: goto tr228;
		case 35: goto tr229;
		case 37: goto tr229;
		case 42: goto tr230;
		case 44: goto tr229;
		case 47: goto st26;
		case 58: goto tr227;
		case 65: goto tr232;
		case 68: goto tr233;
		case 69: goto tr234;
		case 72: goto tr235;
		case 77: goto tr247;
		case 80: goto tr237;
		case 91: goto tr238;
		case 92: goto tr239;
		case 94: goto tr227;
		case 95: goto tr230;
		case 97: goto tr240;
		case 100: goto tr241;
		case 101: goto tr234;
		case 104: goto tr242;
		case 109: goto tr243;
		case 112: goto tr244;
		case 115: goto tr245;
		case 121: goto tr246;
		case 123: goto tr227;
	}
	if ( (*p) < 60 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr229;
		} else if ( (*p) >= 32 )
			goto tr227;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr227;
		} else if ( (*p) >= 63 )
			goto tr229;
	} else
		goto tr227;
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
		goto st106;
	goto st0;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	switch( (*p) ) {
		case 34: goto tr228;
		case 35: goto tr229;
		case 37: goto tr229;
		case 42: goto tr230;
		case 44: goto tr229;
		case 47: goto st28;
		case 58: goto tr227;
		case 65: goto tr232;
		case 68: goto tr233;
		case 69: goto tr234;
		case 72: goto tr235;
		case 77: goto tr247;
		case 80: goto tr237;
		case 91: goto tr238;
		case 92: goto tr239;
		case 94: goto tr227;
		case 95: goto tr230;
		case 97: goto tr240;
		case 100: goto tr241;
		case 101: goto tr234;
		case 104: goto tr242;
		case 109: goto tr243;
		case 112: goto tr244;
		case 115: goto tr245;
		case 121: goto tr246;
		case 123: goto tr227;
	}
	if ( (*p) < 60 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr229;
		} else if ( (*p) >= 32 )
			goto tr227;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr227;
		} else if ( (*p) >= 63 )
			goto tr229;
	} else
		goto tr227;
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
		goto st106;
	goto st0;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	switch( (*p) ) {
		case 36: goto st31;
		case 60: goto st16;
		case 61: goto st21;
		case 62: goto st22;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st32;
	} else if ( (*p) >= 65 )
		goto st32;
	goto st0;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	if ( (*p) == 45 )
		goto st18;
	goto st0;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	if ( (*p) == 93 )
		goto st104;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st32;
	} else if ( (*p) >= 65 )
		goto st32;
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
tr267:
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
#line 2521 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr262;
		case 35: goto tr263;
		case 37: goto tr263;
		case 42: goto tr264;
		case 44: goto tr263;
		case 47: goto st33;
		case 59: goto tr266;
		case 65: goto tr267;
		case 68: goto tr268;
		case 69: goto tr269;
		case 72: goto tr270;
		case 77: goto st138;
		case 80: goto tr272;
		case 91: goto tr273;
		case 92: goto tr274;
		case 94: goto tr261;
		case 95: goto tr264;
		case 97: goto tr275;
		case 100: goto tr276;
		case 101: goto tr269;
		case 104: goto tr277;
		case 109: goto tr278;
		case 112: goto tr279;
		case 115: goto tr280;
		case 121: goto tr281;
		case 123: goto tr261;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr263;
		} else if ( (*p) >= 32 )
			goto tr261;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr261;
		} else if ( (*p) >= 63 )
			goto tr263;
	} else
		goto tr261;
	goto st0;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	if ( (*p) == 80 )
		goto st123;
	goto st0;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	switch( (*p) ) {
		case 34: goto tr262;
		case 35: goto tr263;
		case 37: goto tr263;
		case 42: goto tr264;
		case 44: goto tr263;
		case 46: goto tr263;
		case 48: goto tr263;
		case 59: goto tr266;
		case 65: goto tr267;
		case 68: goto tr268;
		case 69: goto tr269;
		case 72: goto tr270;
		case 77: goto tr282;
		case 80: goto tr272;
		case 91: goto tr273;
		case 92: goto tr274;
		case 94: goto tr261;
		case 95: goto tr264;
		case 97: goto tr275;
		case 100: goto tr276;
		case 101: goto tr269;
		case 104: goto tr277;
		case 109: goto tr278;
		case 112: goto tr279;
		case 115: goto tr280;
		case 121: goto tr281;
		case 123: goto tr261;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr261;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr261;
		} else if ( (*p) >= 63 )
			goto tr263;
	} else
		goto tr261;
	goto st0;
tr155:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st124;
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
	goto st124;
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
	goto st124;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
#line 2651 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr262;
		case 35: goto tr263;
		case 37: goto tr263;
		case 42: goto tr264;
		case 44: goto tr263;
		case 46: goto tr263;
		case 48: goto tr263;
		case 59: goto tr266;
		case 65: goto tr267;
		case 68: goto st124;
		case 69: goto tr269;
		case 72: goto tr270;
		case 77: goto tr282;
		case 80: goto tr272;
		case 91: goto tr273;
		case 92: goto tr274;
		case 94: goto tr261;
		case 95: goto tr264;
		case 97: goto tr275;
		case 100: goto tr276;
		case 101: goto tr269;
		case 104: goto tr277;
		case 109: goto tr278;
		case 112: goto tr279;
		case 115: goto tr280;
		case 121: goto tr281;
		case 123: goto tr261;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr261;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr261;
		} else if ( (*p) >= 63 )
			goto tr263;
	} else
		goto tr261;
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
#line 2713 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 43: goto st101;
		case 45: goto st101;
	}
	goto st0;
tr157:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st125;
tr177:
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
tr270:
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
#line 2753 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr262;
		case 35: goto tr263;
		case 37: goto tr263;
		case 42: goto tr264;
		case 44: goto tr263;
		case 46: goto tr263;
		case 48: goto tr263;
		case 59: goto tr266;
		case 65: goto tr267;
		case 68: goto tr268;
		case 69: goto tr269;
		case 72: goto st125;
		case 77: goto tr282;
		case 80: goto tr272;
		case 91: goto tr273;
		case 92: goto tr274;
		case 94: goto tr261;
		case 95: goto tr264;
		case 97: goto tr275;
		case 100: goto tr276;
		case 101: goto tr269;
		case 104: goto tr277;
		case 109: goto tr278;
		case 112: goto tr279;
		case 115: goto tr280;
		case 121: goto tr281;
		case 123: goto tr261;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr261;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr261;
		} else if ( (*p) >= 63 )
			goto tr263;
	} else
		goto tr261;
	goto st0;
tr158:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st126;
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
	goto st126;
tr282:
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
#line 2829 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr262;
		case 35: goto tr263;
		case 37: goto tr263;
		case 42: goto tr264;
		case 44: goto tr263;
		case 46: goto tr263;
		case 48: goto tr263;
		case 59: goto tr266;
		case 65: goto tr267;
		case 68: goto tr268;
		case 69: goto tr269;
		case 72: goto tr270;
		case 77: goto st126;
		case 80: goto tr272;
		case 91: goto tr273;
		case 92: goto tr274;
		case 94: goto tr261;
		case 95: goto tr264;
		case 97: goto tr275;
		case 100: goto tr276;
		case 101: goto tr269;
		case 104: goto tr277;
		case 109: goto tr278;
		case 112: goto tr279;
		case 115: goto tr280;
		case 121: goto tr281;
		case 123: goto tr261;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr261;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr261;
		} else if ( (*p) >= 63 )
			goto tr263;
	} else
		goto tr261;
	goto st0;
tr159:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st127;
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
	goto st127;
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
	goto st127;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
#line 2905 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr262;
		case 35: goto tr263;
		case 37: goto tr263;
		case 42: goto tr264;
		case 44: goto tr263;
		case 46: goto tr263;
		case 48: goto tr263;
		case 59: goto tr266;
		case 65: goto tr267;
		case 68: goto tr268;
		case 69: goto tr269;
		case 72: goto tr270;
		case 77: goto st123;
		case 80: goto tr272;
		case 91: goto tr273;
		case 92: goto tr274;
		case 94: goto tr261;
		case 95: goto tr264;
		case 97: goto tr275;
		case 100: goto tr276;
		case 101: goto tr269;
		case 104: goto tr277;
		case 109: goto tr278;
		case 112: goto tr279;
		case 115: goto tr280;
		case 121: goto tr281;
		case 123: goto tr261;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr261;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr261;
		} else if ( (*p) >= 63 )
			goto tr263;
	} else
		goto tr261;
	goto st0;
tr180:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st35;
tr273:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st35;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
#line 2967 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 60: goto st36;
		case 61: goto st41;
		case 62: goto st42;
	}
	goto st0;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	switch( (*p) ) {
		case 45: goto st37;
		case 46: goto st38;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 62 )
			goto st41;
	} else if ( (*p) >= 48 )
		goto st40;
	goto st0;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	if ( (*p) == 46 )
		goto st38;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st40;
	goto st0;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st39;
	goto st0;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	if ( (*p) == 93 )
		goto st101;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st39;
	goto st0;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	switch( (*p) ) {
		case 46: goto st38;
		case 93: goto st101;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st40;
	goto st0;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	switch( (*p) ) {
		case 45: goto st37;
		case 46: goto st38;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st40;
	goto st0;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	switch( (*p) ) {
		case 45: goto st37;
		case 46: goto st38;
		case 61: goto st41;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st40;
	goto st0;
tr181:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st43;
tr274:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
#line 3067 "src/tfs_excel_parser.c"
	goto tr39;
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
#line 3103 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr262;
		case 35: goto tr263;
		case 37: goto tr263;
		case 42: goto tr264;
		case 44: goto tr263;
		case 47: goto st44;
		case 59: goto tr266;
		case 65: goto tr267;
		case 68: goto tr268;
		case 69: goto tr269;
		case 72: goto tr270;
		case 77: goto tr282;
		case 80: goto tr272;
		case 91: goto tr273;
		case 92: goto tr274;
		case 94: goto tr261;
		case 95: goto tr264;
		case 97: goto tr275;
		case 100: goto tr276;
		case 101: goto tr269;
		case 104: goto tr277;
		case 109: goto st137;
		case 112: goto tr279;
		case 115: goto tr280;
		case 121: goto tr281;
		case 123: goto tr261;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr263;
		} else if ( (*p) >= 32 )
			goto tr261;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr261;
		} else if ( (*p) >= 63 )
			goto tr263;
	} else
		goto tr261;
	goto st0;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	if ( (*p) == 112 )
		goto st123;
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
#line 3188 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr262;
		case 35: goto tr263;
		case 37: goto tr263;
		case 42: goto tr264;
		case 44: goto tr263;
		case 46: goto tr263;
		case 48: goto tr263;
		case 59: goto tr266;
		case 65: goto tr267;
		case 68: goto tr268;
		case 69: goto tr269;
		case 72: goto tr270;
		case 77: goto tr282;
		case 80: goto tr272;
		case 91: goto tr273;
		case 92: goto tr274;
		case 94: goto tr261;
		case 95: goto tr264;
		case 97: goto tr275;
		case 100: goto st129;
		case 101: goto tr269;
		case 104: goto tr277;
		case 109: goto tr278;
		case 112: goto tr279;
		case 115: goto tr280;
		case 121: goto tr281;
		case 123: goto tr261;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr261;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr261;
		} else if ( (*p) >= 63 )
			goto tr263;
	} else
		goto tr261;
	goto st0;
tr164:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st130;
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
	goto st130;
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
	goto st130;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
#line 3264 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr262;
		case 35: goto tr263;
		case 37: goto tr263;
		case 42: goto tr264;
		case 44: goto tr263;
		case 46: goto tr263;
		case 48: goto tr263;
		case 59: goto tr266;
		case 65: goto tr267;
		case 68: goto tr268;
		case 69: goto tr269;
		case 72: goto tr270;
		case 77: goto tr282;
		case 80: goto tr272;
		case 91: goto tr273;
		case 92: goto tr274;
		case 94: goto tr261;
		case 95: goto tr264;
		case 97: goto tr275;
		case 100: goto tr276;
		case 101: goto tr269;
		case 104: goto st130;
		case 109: goto tr278;
		case 112: goto tr279;
		case 115: goto tr280;
		case 121: goto tr281;
		case 123: goto tr261;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr261;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr261;
		} else if ( (*p) >= 63 )
			goto tr263;
	} else
		goto tr261;
	goto st0;
tr165:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st131;
tr185:
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
	goto st131;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
#line 3340 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr262;
		case 35: goto tr263;
		case 37: goto tr263;
		case 42: goto tr264;
		case 44: goto tr263;
		case 46: goto tr263;
		case 48: goto tr263;
		case 59: goto tr266;
		case 65: goto tr267;
		case 68: goto tr268;
		case 69: goto tr269;
		case 72: goto tr270;
		case 77: goto tr282;
		case 80: goto tr272;
		case 91: goto tr273;
		case 92: goto tr274;
		case 94: goto tr261;
		case 95: goto tr264;
		case 97: goto tr275;
		case 100: goto tr276;
		case 101: goto tr269;
		case 104: goto tr277;
		case 109: goto st131;
		case 112: goto tr279;
		case 115: goto tr280;
		case 121: goto tr281;
		case 123: goto tr261;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr261;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr261;
		} else if ( (*p) >= 63 )
			goto tr263;
	} else
		goto tr261;
	goto st0;
tr166:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st132;
tr186:
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
	goto st132;
tr279:
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
	goto st132;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
#line 3416 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr262;
		case 35: goto tr263;
		case 37: goto tr263;
		case 42: goto tr264;
		case 44: goto tr263;
		case 46: goto tr263;
		case 48: goto tr263;
		case 59: goto tr266;
		case 65: goto tr267;
		case 68: goto tr268;
		case 69: goto tr269;
		case 72: goto tr270;
		case 77: goto tr282;
		case 80: goto tr272;
		case 91: goto tr273;
		case 92: goto tr274;
		case 94: goto tr261;
		case 95: goto tr264;
		case 97: goto tr275;
		case 100: goto tr276;
		case 101: goto tr269;
		case 104: goto tr277;
		case 109: goto st123;
		case 112: goto tr279;
		case 115: goto tr280;
		case 121: goto tr281;
		case 123: goto tr261;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr261;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr261;
		} else if ( (*p) >= 63 )
			goto tr263;
	} else
		goto tr261;
	goto st0;
tr167:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st133;
tr187:
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
	goto st133;
tr280:
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
	goto st133;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
#line 3492 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr262;
		case 35: goto tr263;
		case 37: goto tr263;
		case 42: goto tr264;
		case 44: goto tr263;
		case 46: goto st45;
		case 48: goto tr263;
		case 59: goto tr266;
		case 65: goto tr267;
		case 68: goto tr268;
		case 69: goto tr269;
		case 72: goto tr270;
		case 77: goto tr282;
		case 80: goto tr272;
		case 91: goto tr273;
		case 92: goto tr274;
		case 94: goto tr261;
		case 95: goto tr264;
		case 97: goto tr275;
		case 100: goto tr276;
		case 101: goto tr269;
		case 104: goto tr277;
		case 109: goto tr278;
		case 112: goto tr279;
		case 115: goto st136;
		case 121: goto tr281;
		case 123: goto tr261;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr261;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr261;
		} else if ( (*p) >= 63 )
			goto tr263;
	} else
		goto tr261;
	goto st0;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	switch( (*p) ) {
		case 35: goto st134;
		case 44: goto st134;
		case 48: goto st134;
		case 63: goto st134;
	}
	goto st0;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	switch( (*p) ) {
		case 34: goto tr262;
		case 35: goto st134;
		case 37: goto tr263;
		case 42: goto tr264;
		case 44: goto st134;
		case 46: goto tr263;
		case 48: goto st134;
		case 59: goto tr266;
		case 63: goto st134;
		case 64: goto tr263;
		case 65: goto tr267;
		case 68: goto tr268;
		case 69: goto tr269;
		case 72: goto tr270;
		case 77: goto tr282;
		case 80: goto tr272;
		case 91: goto tr273;
		case 92: goto tr274;
		case 94: goto tr261;
		case 95: goto tr264;
		case 97: goto tr275;
		case 100: goto tr276;
		case 101: goto tr269;
		case 104: goto tr277;
		case 109: goto tr278;
		case 112: goto tr279;
		case 115: goto tr280;
		case 121: goto tr281;
		case 123: goto tr261;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr261;
	} else if ( (*p) > 62 ) {
		if ( 125 <= (*p) && (*p) <= 126 )
			goto tr261;
	} else
		goto tr261;
	goto st0;
tr168:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st135;
tr188:
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
tr281:
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
#line 3623 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr262;
		case 35: goto tr263;
		case 37: goto tr263;
		case 42: goto tr264;
		case 44: goto tr263;
		case 46: goto tr263;
		case 48: goto tr263;
		case 59: goto tr266;
		case 65: goto tr267;
		case 68: goto tr268;
		case 69: goto tr269;
		case 72: goto tr270;
		case 77: goto tr282;
		case 80: goto tr272;
		case 91: goto tr273;
		case 92: goto tr274;
		case 94: goto tr261;
		case 95: goto tr264;
		case 97: goto tr275;
		case 100: goto tr276;
		case 101: goto tr269;
		case 104: goto tr277;
		case 109: goto tr278;
		case 112: goto tr279;
		case 115: goto tr280;
		case 121: goto st135;
		case 123: goto tr261;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr261;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr261;
		} else if ( (*p) >= 63 )
			goto tr263;
	} else
		goto tr261;
	goto st0;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	switch( (*p) ) {
		case 34: goto tr262;
		case 35: goto tr263;
		case 37: goto tr263;
		case 42: goto tr264;
		case 44: goto tr263;
		case 46: goto st45;
		case 48: goto tr263;
		case 59: goto tr266;
		case 65: goto tr267;
		case 68: goto tr268;
		case 69: goto tr269;
		case 72: goto tr270;
		case 77: goto tr282;
		case 80: goto tr272;
		case 91: goto tr273;
		case 92: goto tr274;
		case 94: goto tr261;
		case 95: goto tr264;
		case 97: goto tr275;
		case 100: goto tr276;
		case 101: goto tr269;
		case 104: goto tr277;
		case 109: goto tr278;
		case 112: goto tr279;
		case 115: goto tr280;
		case 121: goto tr281;
		case 123: goto tr261;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr261;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr261;
		} else if ( (*p) >= 63 )
			goto tr263;
	} else
		goto tr261;
	goto st0;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	switch( (*p) ) {
		case 34: goto tr262;
		case 35: goto tr263;
		case 37: goto tr263;
		case 42: goto tr264;
		case 44: goto tr263;
		case 47: goto st46;
		case 59: goto tr266;
		case 65: goto tr267;
		case 68: goto tr268;
		case 69: goto tr269;
		case 72: goto tr270;
		case 77: goto tr282;
		case 80: goto tr272;
		case 91: goto tr273;
		case 92: goto tr274;
		case 94: goto tr261;
		case 95: goto tr264;
		case 97: goto tr275;
		case 100: goto tr276;
		case 101: goto tr269;
		case 104: goto tr277;
		case 109: goto tr278;
		case 112: goto tr279;
		case 115: goto tr280;
		case 121: goto tr281;
		case 123: goto tr261;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr263;
		} else if ( (*p) >= 32 )
			goto tr261;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr261;
		} else if ( (*p) >= 63 )
			goto tr263;
	} else
		goto tr261;
	goto st0;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	if ( (*p) == 112 )
		goto st47;
	goto st0;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	if ( (*p) == 109 )
		goto st123;
	goto st0;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	switch( (*p) ) {
		case 34: goto tr262;
		case 35: goto tr263;
		case 37: goto tr263;
		case 42: goto tr264;
		case 44: goto tr263;
		case 47: goto st48;
		case 59: goto tr266;
		case 65: goto tr267;
		case 68: goto tr268;
		case 69: goto tr269;
		case 72: goto tr270;
		case 77: goto tr282;
		case 80: goto tr272;
		case 91: goto tr273;
		case 92: goto tr274;
		case 94: goto tr261;
		case 95: goto tr264;
		case 97: goto tr275;
		case 100: goto tr276;
		case 101: goto tr269;
		case 104: goto tr277;
		case 109: goto tr278;
		case 112: goto tr279;
		case 115: goto tr280;
		case 121: goto tr281;
		case 123: goto tr261;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr263;
		} else if ( (*p) >= 32 )
			goto tr261;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr261;
		} else if ( (*p) >= 63 )
			goto tr263;
	} else
		goto tr261;
	goto st0;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	if ( (*p) == 80 )
		goto st49;
	goto st0;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	if ( (*p) == 77 )
		goto st123;
	goto st0;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	switch( (*p) ) {
		case 36: goto st51;
		case 60: goto st36;
		case 61: goto st41;
		case 62: goto st42;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st52;
	} else if ( (*p) >= 65 )
		goto st52;
	goto st0;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	if ( (*p) == 45 )
		goto st38;
	goto st0;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	if ( (*p) == 93 )
		goto st101;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st52;
	} else if ( (*p) >= 65 )
		goto st52;
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
tr302:
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
#line 3901 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr297;
		case 35: goto tr298;
		case 37: goto tr298;
		case 42: goto tr299;
		case 44: goto tr298;
		case 47: goto st53;
		case 59: goto tr301;
		case 65: goto tr302;
		case 68: goto tr303;
		case 69: goto tr304;
		case 72: goto tr305;
		case 77: goto st155;
		case 80: goto tr307;
		case 91: goto tr308;
		case 92: goto tr309;
		case 94: goto tr296;
		case 95: goto tr299;
		case 97: goto tr310;
		case 100: goto tr311;
		case 101: goto tr304;
		case 104: goto tr312;
		case 109: goto tr313;
		case 112: goto tr314;
		case 115: goto tr315;
		case 121: goto tr316;
		case 123: goto tr296;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr298;
		} else if ( (*p) >= 32 )
			goto tr296;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr296;
		} else if ( (*p) >= 63 )
			goto tr298;
	} else
		goto tr296;
	goto st0;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	if ( (*p) == 80 )
		goto st140;
	goto st0;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	switch( (*p) ) {
		case 34: goto tr297;
		case 35: goto tr298;
		case 37: goto tr298;
		case 42: goto tr299;
		case 44: goto tr298;
		case 46: goto tr298;
		case 48: goto tr298;
		case 59: goto tr301;
		case 65: goto tr302;
		case 68: goto tr303;
		case 69: goto tr304;
		case 72: goto tr305;
		case 77: goto tr317;
		case 80: goto tr307;
		case 91: goto tr308;
		case 92: goto tr309;
		case 94: goto tr296;
		case 95: goto tr299;
		case 97: goto tr310;
		case 100: goto tr311;
		case 101: goto tr304;
		case 104: goto tr312;
		case 109: goto tr313;
		case 112: goto tr314;
		case 115: goto tr315;
		case 121: goto tr316;
		case 123: goto tr296;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr296;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr296;
		} else if ( (*p) >= 63 )
			goto tr298;
	} else
		goto tr296;
	goto st0;
tr116:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st141;
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
	goto st141;
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
	goto st141;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
#line 4031 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr297;
		case 35: goto tr298;
		case 37: goto tr298;
		case 42: goto tr299;
		case 44: goto tr298;
		case 46: goto tr298;
		case 48: goto tr298;
		case 59: goto tr301;
		case 65: goto tr302;
		case 68: goto st141;
		case 69: goto tr304;
		case 72: goto tr305;
		case 77: goto tr317;
		case 80: goto tr307;
		case 91: goto tr308;
		case 92: goto tr309;
		case 94: goto tr296;
		case 95: goto tr299;
		case 97: goto tr310;
		case 100: goto tr311;
		case 101: goto tr304;
		case 104: goto tr312;
		case 109: goto tr313;
		case 112: goto tr314;
		case 115: goto tr315;
		case 121: goto tr316;
		case 123: goto tr296;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr296;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr296;
		} else if ( (*p) >= 63 )
			goto tr298;
	} else
		goto tr296;
	goto st0;
tr137:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st54;
tr304:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
#line 4093 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 43: goto st98;
		case 45: goto st98;
	}
	goto st0;
tr118:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st142;
tr138:
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
tr305:
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
#line 4133 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr297;
		case 35: goto tr298;
		case 37: goto tr298;
		case 42: goto tr299;
		case 44: goto tr298;
		case 46: goto tr298;
		case 48: goto tr298;
		case 59: goto tr301;
		case 65: goto tr302;
		case 68: goto tr303;
		case 69: goto tr304;
		case 72: goto st142;
		case 77: goto tr317;
		case 80: goto tr307;
		case 91: goto tr308;
		case 92: goto tr309;
		case 94: goto tr296;
		case 95: goto tr299;
		case 97: goto tr310;
		case 100: goto tr311;
		case 101: goto tr304;
		case 104: goto tr312;
		case 109: goto tr313;
		case 112: goto tr314;
		case 115: goto tr315;
		case 121: goto tr316;
		case 123: goto tr296;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr296;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr296;
		} else if ( (*p) >= 63 )
			goto tr298;
	} else
		goto tr296;
	goto st0;
tr119:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st143;
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
	goto st143;
tr317:
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
#line 4209 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr297;
		case 35: goto tr298;
		case 37: goto tr298;
		case 42: goto tr299;
		case 44: goto tr298;
		case 46: goto tr298;
		case 48: goto tr298;
		case 59: goto tr301;
		case 65: goto tr302;
		case 68: goto tr303;
		case 69: goto tr304;
		case 72: goto tr305;
		case 77: goto st143;
		case 80: goto tr307;
		case 91: goto tr308;
		case 92: goto tr309;
		case 94: goto tr296;
		case 95: goto tr299;
		case 97: goto tr310;
		case 100: goto tr311;
		case 101: goto tr304;
		case 104: goto tr312;
		case 109: goto tr313;
		case 112: goto tr314;
		case 115: goto tr315;
		case 121: goto tr316;
		case 123: goto tr296;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr296;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr296;
		} else if ( (*p) >= 63 )
			goto tr298;
	} else
		goto tr296;
	goto st0;
tr120:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st144;
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
	goto st144;
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
	goto st144;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
#line 4285 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr297;
		case 35: goto tr298;
		case 37: goto tr298;
		case 42: goto tr299;
		case 44: goto tr298;
		case 46: goto tr298;
		case 48: goto tr298;
		case 59: goto tr301;
		case 65: goto tr302;
		case 68: goto tr303;
		case 69: goto tr304;
		case 72: goto tr305;
		case 77: goto st140;
		case 80: goto tr307;
		case 91: goto tr308;
		case 92: goto tr309;
		case 94: goto tr296;
		case 95: goto tr299;
		case 97: goto tr310;
		case 100: goto tr311;
		case 101: goto tr304;
		case 104: goto tr312;
		case 109: goto tr313;
		case 112: goto tr314;
		case 115: goto tr315;
		case 121: goto tr316;
		case 123: goto tr296;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr296;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr296;
		} else if ( (*p) >= 63 )
			goto tr298;
	} else
		goto tr296;
	goto st0;
tr141:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st55;
tr308:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
#line 4347 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 60: goto st56;
		case 61: goto st61;
		case 62: goto st62;
	}
	goto st0;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	switch( (*p) ) {
		case 45: goto st57;
		case 46: goto st58;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 62 )
			goto st61;
	} else if ( (*p) >= 48 )
		goto st60;
	goto st0;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	if ( (*p) == 46 )
		goto st58;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st60;
	goto st0;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st59;
	goto st0;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	if ( (*p) == 93 )
		goto st98;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st59;
	goto st0;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	switch( (*p) ) {
		case 46: goto st58;
		case 93: goto st98;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st60;
	goto st0;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	switch( (*p) ) {
		case 45: goto st57;
		case 46: goto st58;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st60;
	goto st0;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	switch( (*p) ) {
		case 45: goto st57;
		case 46: goto st58;
		case 61: goto st61;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st60;
	goto st0;
tr142:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st63;
tr309:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
#line 4447 "src/tfs_excel_parser.c"
	goto tr53;
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
#line 4483 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr297;
		case 35: goto tr298;
		case 37: goto tr298;
		case 42: goto tr299;
		case 44: goto tr298;
		case 47: goto st64;
		case 59: goto tr301;
		case 65: goto tr302;
		case 68: goto tr303;
		case 69: goto tr304;
		case 72: goto tr305;
		case 77: goto tr317;
		case 80: goto tr307;
		case 91: goto tr308;
		case 92: goto tr309;
		case 94: goto tr296;
		case 95: goto tr299;
		case 97: goto tr310;
		case 100: goto tr311;
		case 101: goto tr304;
		case 104: goto tr312;
		case 109: goto st154;
		case 112: goto tr314;
		case 115: goto tr315;
		case 121: goto tr316;
		case 123: goto tr296;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr298;
		} else if ( (*p) >= 32 )
			goto tr296;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr296;
		} else if ( (*p) >= 63 )
			goto tr298;
	} else
		goto tr296;
	goto st0;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	if ( (*p) == 112 )
		goto st140;
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
#line 4568 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr297;
		case 35: goto tr298;
		case 37: goto tr298;
		case 42: goto tr299;
		case 44: goto tr298;
		case 46: goto tr298;
		case 48: goto tr298;
		case 59: goto tr301;
		case 65: goto tr302;
		case 68: goto tr303;
		case 69: goto tr304;
		case 72: goto tr305;
		case 77: goto tr317;
		case 80: goto tr307;
		case 91: goto tr308;
		case 92: goto tr309;
		case 94: goto tr296;
		case 95: goto tr299;
		case 97: goto tr310;
		case 100: goto st146;
		case 101: goto tr304;
		case 104: goto tr312;
		case 109: goto tr313;
		case 112: goto tr314;
		case 115: goto tr315;
		case 121: goto tr316;
		case 123: goto tr296;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr296;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr296;
		} else if ( (*p) >= 63 )
			goto tr298;
	} else
		goto tr296;
	goto st0;
tr125:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st147;
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
	goto st147;
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
	goto st147;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
#line 4644 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr297;
		case 35: goto tr298;
		case 37: goto tr298;
		case 42: goto tr299;
		case 44: goto tr298;
		case 46: goto tr298;
		case 48: goto tr298;
		case 59: goto tr301;
		case 65: goto tr302;
		case 68: goto tr303;
		case 69: goto tr304;
		case 72: goto tr305;
		case 77: goto tr317;
		case 80: goto tr307;
		case 91: goto tr308;
		case 92: goto tr309;
		case 94: goto tr296;
		case 95: goto tr299;
		case 97: goto tr310;
		case 100: goto tr311;
		case 101: goto tr304;
		case 104: goto st147;
		case 109: goto tr313;
		case 112: goto tr314;
		case 115: goto tr315;
		case 121: goto tr316;
		case 123: goto tr296;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr296;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr296;
		} else if ( (*p) >= 63 )
			goto tr298;
	} else
		goto tr296;
	goto st0;
tr126:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st148;
tr146:
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
	goto st148;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
#line 4720 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr297;
		case 35: goto tr298;
		case 37: goto tr298;
		case 42: goto tr299;
		case 44: goto tr298;
		case 46: goto tr298;
		case 48: goto tr298;
		case 59: goto tr301;
		case 65: goto tr302;
		case 68: goto tr303;
		case 69: goto tr304;
		case 72: goto tr305;
		case 77: goto tr317;
		case 80: goto tr307;
		case 91: goto tr308;
		case 92: goto tr309;
		case 94: goto tr296;
		case 95: goto tr299;
		case 97: goto tr310;
		case 100: goto tr311;
		case 101: goto tr304;
		case 104: goto tr312;
		case 109: goto st148;
		case 112: goto tr314;
		case 115: goto tr315;
		case 121: goto tr316;
		case 123: goto tr296;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr296;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr296;
		} else if ( (*p) >= 63 )
			goto tr298;
	} else
		goto tr296;
	goto st0;
tr127:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st149;
tr147:
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
	goto st149;
tr314:
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
	goto st149;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
#line 4796 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr297;
		case 35: goto tr298;
		case 37: goto tr298;
		case 42: goto tr299;
		case 44: goto tr298;
		case 46: goto tr298;
		case 48: goto tr298;
		case 59: goto tr301;
		case 65: goto tr302;
		case 68: goto tr303;
		case 69: goto tr304;
		case 72: goto tr305;
		case 77: goto tr317;
		case 80: goto tr307;
		case 91: goto tr308;
		case 92: goto tr309;
		case 94: goto tr296;
		case 95: goto tr299;
		case 97: goto tr310;
		case 100: goto tr311;
		case 101: goto tr304;
		case 104: goto tr312;
		case 109: goto st140;
		case 112: goto tr314;
		case 115: goto tr315;
		case 121: goto tr316;
		case 123: goto tr296;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr296;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr296;
		} else if ( (*p) >= 63 )
			goto tr298;
	} else
		goto tr296;
	goto st0;
tr128:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st150;
tr148:
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
	goto st150;
tr315:
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
	goto st150;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
#line 4872 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr297;
		case 35: goto tr298;
		case 37: goto tr298;
		case 42: goto tr299;
		case 44: goto tr298;
		case 46: goto st65;
		case 48: goto tr298;
		case 59: goto tr301;
		case 65: goto tr302;
		case 68: goto tr303;
		case 69: goto tr304;
		case 72: goto tr305;
		case 77: goto tr317;
		case 80: goto tr307;
		case 91: goto tr308;
		case 92: goto tr309;
		case 94: goto tr296;
		case 95: goto tr299;
		case 97: goto tr310;
		case 100: goto tr311;
		case 101: goto tr304;
		case 104: goto tr312;
		case 109: goto tr313;
		case 112: goto tr314;
		case 115: goto st153;
		case 121: goto tr316;
		case 123: goto tr296;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr296;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr296;
		} else if ( (*p) >= 63 )
			goto tr298;
	} else
		goto tr296;
	goto st0;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	switch( (*p) ) {
		case 35: goto st151;
		case 44: goto st151;
		case 48: goto st151;
		case 63: goto st151;
	}
	goto st0;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	switch( (*p) ) {
		case 34: goto tr297;
		case 35: goto st151;
		case 37: goto tr298;
		case 42: goto tr299;
		case 44: goto st151;
		case 46: goto tr298;
		case 48: goto st151;
		case 59: goto tr301;
		case 63: goto st151;
		case 64: goto tr298;
		case 65: goto tr302;
		case 68: goto tr303;
		case 69: goto tr304;
		case 72: goto tr305;
		case 77: goto tr317;
		case 80: goto tr307;
		case 91: goto tr308;
		case 92: goto tr309;
		case 94: goto tr296;
		case 95: goto tr299;
		case 97: goto tr310;
		case 100: goto tr311;
		case 101: goto tr304;
		case 104: goto tr312;
		case 109: goto tr313;
		case 112: goto tr314;
		case 115: goto tr315;
		case 121: goto tr316;
		case 123: goto tr296;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr296;
	} else if ( (*p) > 62 ) {
		if ( 125 <= (*p) && (*p) <= 126 )
			goto tr296;
	} else
		goto tr296;
	goto st0;
tr129:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st152;
tr149:
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
tr316:
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
#line 5003 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr297;
		case 35: goto tr298;
		case 37: goto tr298;
		case 42: goto tr299;
		case 44: goto tr298;
		case 46: goto tr298;
		case 48: goto tr298;
		case 59: goto tr301;
		case 65: goto tr302;
		case 68: goto tr303;
		case 69: goto tr304;
		case 72: goto tr305;
		case 77: goto tr317;
		case 80: goto tr307;
		case 91: goto tr308;
		case 92: goto tr309;
		case 94: goto tr296;
		case 95: goto tr299;
		case 97: goto tr310;
		case 100: goto tr311;
		case 101: goto tr304;
		case 104: goto tr312;
		case 109: goto tr313;
		case 112: goto tr314;
		case 115: goto tr315;
		case 121: goto st152;
		case 123: goto tr296;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr296;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr296;
		} else if ( (*p) >= 63 )
			goto tr298;
	} else
		goto tr296;
	goto st0;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	switch( (*p) ) {
		case 34: goto tr297;
		case 35: goto tr298;
		case 37: goto tr298;
		case 42: goto tr299;
		case 44: goto tr298;
		case 46: goto st65;
		case 48: goto tr298;
		case 59: goto tr301;
		case 65: goto tr302;
		case 68: goto tr303;
		case 69: goto tr304;
		case 72: goto tr305;
		case 77: goto tr317;
		case 80: goto tr307;
		case 91: goto tr308;
		case 92: goto tr309;
		case 94: goto tr296;
		case 95: goto tr299;
		case 97: goto tr310;
		case 100: goto tr311;
		case 101: goto tr304;
		case 104: goto tr312;
		case 109: goto tr313;
		case 112: goto tr314;
		case 115: goto tr315;
		case 121: goto tr316;
		case 123: goto tr296;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr296;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr296;
		} else if ( (*p) >= 63 )
			goto tr298;
	} else
		goto tr296;
	goto st0;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
	switch( (*p) ) {
		case 34: goto tr297;
		case 35: goto tr298;
		case 37: goto tr298;
		case 42: goto tr299;
		case 44: goto tr298;
		case 47: goto st66;
		case 59: goto tr301;
		case 65: goto tr302;
		case 68: goto tr303;
		case 69: goto tr304;
		case 72: goto tr305;
		case 77: goto tr317;
		case 80: goto tr307;
		case 91: goto tr308;
		case 92: goto tr309;
		case 94: goto tr296;
		case 95: goto tr299;
		case 97: goto tr310;
		case 100: goto tr311;
		case 101: goto tr304;
		case 104: goto tr312;
		case 109: goto tr313;
		case 112: goto tr314;
		case 115: goto tr315;
		case 121: goto tr316;
		case 123: goto tr296;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr298;
		} else if ( (*p) >= 32 )
			goto tr296;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr296;
		} else if ( (*p) >= 63 )
			goto tr298;
	} else
		goto tr296;
	goto st0;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	if ( (*p) == 112 )
		goto st67;
	goto st0;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
	if ( (*p) == 109 )
		goto st140;
	goto st0;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	switch( (*p) ) {
		case 34: goto tr297;
		case 35: goto tr298;
		case 37: goto tr298;
		case 42: goto tr299;
		case 44: goto tr298;
		case 47: goto st68;
		case 59: goto tr301;
		case 65: goto tr302;
		case 68: goto tr303;
		case 69: goto tr304;
		case 72: goto tr305;
		case 77: goto tr317;
		case 80: goto tr307;
		case 91: goto tr308;
		case 92: goto tr309;
		case 94: goto tr296;
		case 95: goto tr299;
		case 97: goto tr310;
		case 100: goto tr311;
		case 101: goto tr304;
		case 104: goto tr312;
		case 109: goto tr313;
		case 112: goto tr314;
		case 115: goto tr315;
		case 121: goto tr316;
		case 123: goto tr296;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr298;
		} else if ( (*p) >= 32 )
			goto tr296;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr296;
		} else if ( (*p) >= 63 )
			goto tr298;
	} else
		goto tr296;
	goto st0;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	if ( (*p) == 80 )
		goto st69;
	goto st0;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	if ( (*p) == 77 )
		goto st140;
	goto st0;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	switch( (*p) ) {
		case 36: goto st71;
		case 60: goto st56;
		case 61: goto st61;
		case 62: goto st62;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st72;
	} else if ( (*p) >= 65 )
		goto st72;
	goto st0;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	if ( (*p) == 45 )
		goto st58;
	goto st0;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	if ( (*p) == 93 )
		goto st98;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st72;
	} else if ( (*p) >= 65 )
		goto st72;
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
tr337:
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
#line 5281 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr332;
		case 35: goto tr333;
		case 37: goto tr333;
		case 42: goto tr334;
		case 44: goto tr333;
		case 47: goto st73;
		case 59: goto tr336;
		case 65: goto tr337;
		case 68: goto tr338;
		case 69: goto tr339;
		case 72: goto tr340;
		case 77: goto st172;
		case 80: goto tr342;
		case 91: goto tr343;
		case 92: goto tr344;
		case 94: goto tr331;
		case 95: goto tr334;
		case 97: goto tr345;
		case 100: goto tr346;
		case 101: goto tr339;
		case 104: goto tr347;
		case 109: goto tr348;
		case 112: goto tr349;
		case 115: goto tr350;
		case 121: goto tr351;
		case 123: goto tr331;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr333;
		} else if ( (*p) >= 32 )
			goto tr331;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr331;
		} else if ( (*p) >= 63 )
			goto tr333;
	} else
		goto tr331;
	goto st0;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	if ( (*p) == 80 )
		goto st157;
	goto st0;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
	switch( (*p) ) {
		case 34: goto tr332;
		case 35: goto tr333;
		case 37: goto tr333;
		case 42: goto tr334;
		case 44: goto tr333;
		case 46: goto tr333;
		case 48: goto tr333;
		case 59: goto tr336;
		case 65: goto tr337;
		case 68: goto tr338;
		case 69: goto tr339;
		case 72: goto tr340;
		case 77: goto tr352;
		case 80: goto tr342;
		case 91: goto tr343;
		case 92: goto tr344;
		case 94: goto tr331;
		case 95: goto tr334;
		case 97: goto tr345;
		case 100: goto tr346;
		case 101: goto tr339;
		case 104: goto tr347;
		case 109: goto tr348;
		case 112: goto tr349;
		case 115: goto tr350;
		case 121: goto tr351;
		case 123: goto tr331;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr331;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr331;
		} else if ( (*p) >= 63 )
			goto tr333;
	} else
		goto tr331;
	goto st0;
tr77:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st158;
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
	goto st158;
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
	goto st158;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
#line 5411 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr332;
		case 35: goto tr333;
		case 37: goto tr333;
		case 42: goto tr334;
		case 44: goto tr333;
		case 46: goto tr333;
		case 48: goto tr333;
		case 59: goto tr336;
		case 65: goto tr337;
		case 68: goto st158;
		case 69: goto tr339;
		case 72: goto tr340;
		case 77: goto tr352;
		case 80: goto tr342;
		case 91: goto tr343;
		case 92: goto tr344;
		case 94: goto tr331;
		case 95: goto tr334;
		case 97: goto tr345;
		case 100: goto tr346;
		case 101: goto tr339;
		case 104: goto tr347;
		case 109: goto tr348;
		case 112: goto tr349;
		case 115: goto tr350;
		case 121: goto tr351;
		case 123: goto tr331;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr331;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr331;
		} else if ( (*p) >= 63 )
			goto tr333;
	} else
		goto tr331;
	goto st0;
tr98:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st74;
tr339:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st74;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
#line 5473 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 43: goto st95;
		case 45: goto st95;
	}
	goto st0;
tr79:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st159;
tr99:
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
tr340:
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
#line 5513 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr332;
		case 35: goto tr333;
		case 37: goto tr333;
		case 42: goto tr334;
		case 44: goto tr333;
		case 46: goto tr333;
		case 48: goto tr333;
		case 59: goto tr336;
		case 65: goto tr337;
		case 68: goto tr338;
		case 69: goto tr339;
		case 72: goto st159;
		case 77: goto tr352;
		case 80: goto tr342;
		case 91: goto tr343;
		case 92: goto tr344;
		case 94: goto tr331;
		case 95: goto tr334;
		case 97: goto tr345;
		case 100: goto tr346;
		case 101: goto tr339;
		case 104: goto tr347;
		case 109: goto tr348;
		case 112: goto tr349;
		case 115: goto tr350;
		case 121: goto tr351;
		case 123: goto tr331;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr331;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr331;
		} else if ( (*p) >= 63 )
			goto tr333;
	} else
		goto tr331;
	goto st0;
tr80:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st160;
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
	goto st160;
tr352:
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
#line 5589 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr332;
		case 35: goto tr333;
		case 37: goto tr333;
		case 42: goto tr334;
		case 44: goto tr333;
		case 46: goto tr333;
		case 48: goto tr333;
		case 59: goto tr336;
		case 65: goto tr337;
		case 68: goto tr338;
		case 69: goto tr339;
		case 72: goto tr340;
		case 77: goto st160;
		case 80: goto tr342;
		case 91: goto tr343;
		case 92: goto tr344;
		case 94: goto tr331;
		case 95: goto tr334;
		case 97: goto tr345;
		case 100: goto tr346;
		case 101: goto tr339;
		case 104: goto tr347;
		case 109: goto tr348;
		case 112: goto tr349;
		case 115: goto tr350;
		case 121: goto tr351;
		case 123: goto tr331;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr331;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr331;
		} else if ( (*p) >= 63 )
			goto tr333;
	} else
		goto tr331;
	goto st0;
tr81:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st161;
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
	goto st161;
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
	goto st161;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
#line 5665 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr332;
		case 35: goto tr333;
		case 37: goto tr333;
		case 42: goto tr334;
		case 44: goto tr333;
		case 46: goto tr333;
		case 48: goto tr333;
		case 59: goto tr336;
		case 65: goto tr337;
		case 68: goto tr338;
		case 69: goto tr339;
		case 72: goto tr340;
		case 77: goto st157;
		case 80: goto tr342;
		case 91: goto tr343;
		case 92: goto tr344;
		case 94: goto tr331;
		case 95: goto tr334;
		case 97: goto tr345;
		case 100: goto tr346;
		case 101: goto tr339;
		case 104: goto tr347;
		case 109: goto tr348;
		case 112: goto tr349;
		case 115: goto tr350;
		case 121: goto tr351;
		case 123: goto tr331;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr331;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr331;
		} else if ( (*p) >= 63 )
			goto tr333;
	} else
		goto tr331;
	goto st0;
tr102:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st75;
tr343:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st75;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
#line 5727 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 60: goto st76;
		case 61: goto st81;
		case 62: goto st82;
	}
	goto st0;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	switch( (*p) ) {
		case 45: goto st77;
		case 46: goto st78;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 62 )
			goto st81;
	} else if ( (*p) >= 48 )
		goto st80;
	goto st0;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	if ( (*p) == 46 )
		goto st78;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st80;
	goto st0;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st79;
	goto st0;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	if ( (*p) == 93 )
		goto st95;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st79;
	goto st0;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	switch( (*p) ) {
		case 46: goto st78;
		case 93: goto st95;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st80;
	goto st0;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	switch( (*p) ) {
		case 45: goto st77;
		case 46: goto st78;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st80;
	goto st0;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	switch( (*p) ) {
		case 45: goto st77;
		case 46: goto st78;
		case 61: goto st81;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st80;
	goto st0;
tr103:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st83;
tr344:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st83;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
#line 5827 "src/tfs_excel_parser.c"
	goto tr67;
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
#line 5863 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr332;
		case 35: goto tr333;
		case 37: goto tr333;
		case 42: goto tr334;
		case 44: goto tr333;
		case 47: goto st84;
		case 59: goto tr336;
		case 65: goto tr337;
		case 68: goto tr338;
		case 69: goto tr339;
		case 72: goto tr340;
		case 77: goto tr352;
		case 80: goto tr342;
		case 91: goto tr343;
		case 92: goto tr344;
		case 94: goto tr331;
		case 95: goto tr334;
		case 97: goto tr345;
		case 100: goto tr346;
		case 101: goto tr339;
		case 104: goto tr347;
		case 109: goto st171;
		case 112: goto tr349;
		case 115: goto tr350;
		case 121: goto tr351;
		case 123: goto tr331;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr333;
		} else if ( (*p) >= 32 )
			goto tr331;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr331;
		} else if ( (*p) >= 63 )
			goto tr333;
	} else
		goto tr331;
	goto st0;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	if ( (*p) == 112 )
		goto st157;
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
#line 5948 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr332;
		case 35: goto tr333;
		case 37: goto tr333;
		case 42: goto tr334;
		case 44: goto tr333;
		case 46: goto tr333;
		case 48: goto tr333;
		case 59: goto tr336;
		case 65: goto tr337;
		case 68: goto tr338;
		case 69: goto tr339;
		case 72: goto tr340;
		case 77: goto tr352;
		case 80: goto tr342;
		case 91: goto tr343;
		case 92: goto tr344;
		case 94: goto tr331;
		case 95: goto tr334;
		case 97: goto tr345;
		case 100: goto st163;
		case 101: goto tr339;
		case 104: goto tr347;
		case 109: goto tr348;
		case 112: goto tr349;
		case 115: goto tr350;
		case 121: goto tr351;
		case 123: goto tr331;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr331;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr331;
		} else if ( (*p) >= 63 )
			goto tr333;
	} else
		goto tr331;
	goto st0;
tr86:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st164;
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
	goto st164;
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
	goto st164;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
#line 6024 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr332;
		case 35: goto tr333;
		case 37: goto tr333;
		case 42: goto tr334;
		case 44: goto tr333;
		case 46: goto tr333;
		case 48: goto tr333;
		case 59: goto tr336;
		case 65: goto tr337;
		case 68: goto tr338;
		case 69: goto tr339;
		case 72: goto tr340;
		case 77: goto tr352;
		case 80: goto tr342;
		case 91: goto tr343;
		case 92: goto tr344;
		case 94: goto tr331;
		case 95: goto tr334;
		case 97: goto tr345;
		case 100: goto tr346;
		case 101: goto tr339;
		case 104: goto st164;
		case 109: goto tr348;
		case 112: goto tr349;
		case 115: goto tr350;
		case 121: goto tr351;
		case 123: goto tr331;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr331;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr331;
		} else if ( (*p) >= 63 )
			goto tr333;
	} else
		goto tr331;
	goto st0;
tr87:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st165;
tr107:
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
	goto st165;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
#line 6100 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr332;
		case 35: goto tr333;
		case 37: goto tr333;
		case 42: goto tr334;
		case 44: goto tr333;
		case 46: goto tr333;
		case 48: goto tr333;
		case 59: goto tr336;
		case 65: goto tr337;
		case 68: goto tr338;
		case 69: goto tr339;
		case 72: goto tr340;
		case 77: goto tr352;
		case 80: goto tr342;
		case 91: goto tr343;
		case 92: goto tr344;
		case 94: goto tr331;
		case 95: goto tr334;
		case 97: goto tr345;
		case 100: goto tr346;
		case 101: goto tr339;
		case 104: goto tr347;
		case 109: goto st165;
		case 112: goto tr349;
		case 115: goto tr350;
		case 121: goto tr351;
		case 123: goto tr331;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr331;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr331;
		} else if ( (*p) >= 63 )
			goto tr333;
	} else
		goto tr331;
	goto st0;
tr88:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st166;
tr108:
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
	goto st166;
tr349:
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
	goto st166;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
#line 6176 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr332;
		case 35: goto tr333;
		case 37: goto tr333;
		case 42: goto tr334;
		case 44: goto tr333;
		case 46: goto tr333;
		case 48: goto tr333;
		case 59: goto tr336;
		case 65: goto tr337;
		case 68: goto tr338;
		case 69: goto tr339;
		case 72: goto tr340;
		case 77: goto tr352;
		case 80: goto tr342;
		case 91: goto tr343;
		case 92: goto tr344;
		case 94: goto tr331;
		case 95: goto tr334;
		case 97: goto tr345;
		case 100: goto tr346;
		case 101: goto tr339;
		case 104: goto tr347;
		case 109: goto st157;
		case 112: goto tr349;
		case 115: goto tr350;
		case 121: goto tr351;
		case 123: goto tr331;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr331;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr331;
		} else if ( (*p) >= 63 )
			goto tr333;
	} else
		goto tr331;
	goto st0;
tr89:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st167;
tr109:
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
	goto st167;
tr350:
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
	goto st167;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
#line 6252 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr332;
		case 35: goto tr333;
		case 37: goto tr333;
		case 42: goto tr334;
		case 44: goto tr333;
		case 46: goto st85;
		case 48: goto tr333;
		case 59: goto tr336;
		case 65: goto tr337;
		case 68: goto tr338;
		case 69: goto tr339;
		case 72: goto tr340;
		case 77: goto tr352;
		case 80: goto tr342;
		case 91: goto tr343;
		case 92: goto tr344;
		case 94: goto tr331;
		case 95: goto tr334;
		case 97: goto tr345;
		case 100: goto tr346;
		case 101: goto tr339;
		case 104: goto tr347;
		case 109: goto tr348;
		case 112: goto tr349;
		case 115: goto st170;
		case 121: goto tr351;
		case 123: goto tr331;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr331;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr331;
		} else if ( (*p) >= 63 )
			goto tr333;
	} else
		goto tr331;
	goto st0;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	switch( (*p) ) {
		case 35: goto st168;
		case 44: goto st168;
		case 48: goto st168;
		case 63: goto st168;
	}
	goto st0;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
	switch( (*p) ) {
		case 34: goto tr332;
		case 35: goto st168;
		case 37: goto tr333;
		case 42: goto tr334;
		case 44: goto st168;
		case 46: goto tr333;
		case 48: goto st168;
		case 59: goto tr336;
		case 63: goto st168;
		case 64: goto tr333;
		case 65: goto tr337;
		case 68: goto tr338;
		case 69: goto tr339;
		case 72: goto tr340;
		case 77: goto tr352;
		case 80: goto tr342;
		case 91: goto tr343;
		case 92: goto tr344;
		case 94: goto tr331;
		case 95: goto tr334;
		case 97: goto tr345;
		case 100: goto tr346;
		case 101: goto tr339;
		case 104: goto tr347;
		case 109: goto tr348;
		case 112: goto tr349;
		case 115: goto tr350;
		case 121: goto tr351;
		case 123: goto tr331;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr331;
	} else if ( (*p) > 62 ) {
		if ( 125 <= (*p) && (*p) <= 126 )
			goto tr331;
	} else
		goto tr331;
	goto st0;
tr90:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st169;
tr110:
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
	goto st169;
tr351:
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
	goto st169;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
#line 6383 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr332;
		case 35: goto tr333;
		case 37: goto tr333;
		case 42: goto tr334;
		case 44: goto tr333;
		case 46: goto tr333;
		case 48: goto tr333;
		case 59: goto tr336;
		case 65: goto tr337;
		case 68: goto tr338;
		case 69: goto tr339;
		case 72: goto tr340;
		case 77: goto tr352;
		case 80: goto tr342;
		case 91: goto tr343;
		case 92: goto tr344;
		case 94: goto tr331;
		case 95: goto tr334;
		case 97: goto tr345;
		case 100: goto tr346;
		case 101: goto tr339;
		case 104: goto tr347;
		case 109: goto tr348;
		case 112: goto tr349;
		case 115: goto tr350;
		case 121: goto st169;
		case 123: goto tr331;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr331;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr331;
		} else if ( (*p) >= 63 )
			goto tr333;
	} else
		goto tr331;
	goto st0;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
	switch( (*p) ) {
		case 34: goto tr332;
		case 35: goto tr333;
		case 37: goto tr333;
		case 42: goto tr334;
		case 44: goto tr333;
		case 46: goto st85;
		case 48: goto tr333;
		case 59: goto tr336;
		case 65: goto tr337;
		case 68: goto tr338;
		case 69: goto tr339;
		case 72: goto tr340;
		case 77: goto tr352;
		case 80: goto tr342;
		case 91: goto tr343;
		case 92: goto tr344;
		case 94: goto tr331;
		case 95: goto tr334;
		case 97: goto tr345;
		case 100: goto tr346;
		case 101: goto tr339;
		case 104: goto tr347;
		case 109: goto tr348;
		case 112: goto tr349;
		case 115: goto tr350;
		case 121: goto tr351;
		case 123: goto tr331;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr331;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr331;
		} else if ( (*p) >= 63 )
			goto tr333;
	} else
		goto tr331;
	goto st0;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
	switch( (*p) ) {
		case 34: goto tr332;
		case 35: goto tr333;
		case 37: goto tr333;
		case 42: goto tr334;
		case 44: goto tr333;
		case 47: goto st86;
		case 59: goto tr336;
		case 65: goto tr337;
		case 68: goto tr338;
		case 69: goto tr339;
		case 72: goto tr340;
		case 77: goto tr352;
		case 80: goto tr342;
		case 91: goto tr343;
		case 92: goto tr344;
		case 94: goto tr331;
		case 95: goto tr334;
		case 97: goto tr345;
		case 100: goto tr346;
		case 101: goto tr339;
		case 104: goto tr347;
		case 109: goto tr348;
		case 112: goto tr349;
		case 115: goto tr350;
		case 121: goto tr351;
		case 123: goto tr331;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr333;
		} else if ( (*p) >= 32 )
			goto tr331;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr331;
		} else if ( (*p) >= 63 )
			goto tr333;
	} else
		goto tr331;
	goto st0;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	if ( (*p) == 112 )
		goto st87;
	goto st0;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	if ( (*p) == 109 )
		goto st157;
	goto st0;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	switch( (*p) ) {
		case 34: goto tr332;
		case 35: goto tr333;
		case 37: goto tr333;
		case 42: goto tr334;
		case 44: goto tr333;
		case 47: goto st88;
		case 59: goto tr336;
		case 65: goto tr337;
		case 68: goto tr338;
		case 69: goto tr339;
		case 72: goto tr340;
		case 77: goto tr352;
		case 80: goto tr342;
		case 91: goto tr343;
		case 92: goto tr344;
		case 94: goto tr331;
		case 95: goto tr334;
		case 97: goto tr345;
		case 100: goto tr346;
		case 101: goto tr339;
		case 104: goto tr347;
		case 109: goto tr348;
		case 112: goto tr349;
		case 115: goto tr350;
		case 121: goto tr351;
		case 123: goto tr331;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr333;
		} else if ( (*p) >= 32 )
			goto tr331;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr331;
		} else if ( (*p) >= 63 )
			goto tr333;
	} else
		goto tr331;
	goto st0;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	if ( (*p) == 80 )
		goto st89;
	goto st0;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	if ( (*p) == 77 )
		goto st157;
	goto st0;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	switch( (*p) ) {
		case 36: goto st91;
		case 60: goto st76;
		case 61: goto st81;
		case 62: goto st82;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st92;
	} else if ( (*p) >= 65 )
		goto st92;
	goto st0;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	if ( (*p) == 45 )
		goto st78;
	goto st0;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	if ( (*p) == 93 )
		goto st95;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st92;
	} else if ( (*p) >= 65 )
		goto st92;
	goto st0;
	}
	_test_eof94: cs = 94; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof95: cs = 95; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof96: cs = 96; goto _test_eof; 
	_test_eof97: cs = 97; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof98: cs = 98; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof99: cs = 99; goto _test_eof; 
	_test_eof100: cs = 100; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof101: cs = 101; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof102: cs = 102; goto _test_eof; 
	_test_eof103: cs = 103; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof104: cs = 104; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof105: cs = 105; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof106: cs = 106; goto _test_eof; 
	_test_eof107: cs = 107; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof108: cs = 108; goto _test_eof; 
	_test_eof109: cs = 109; goto _test_eof; 
	_test_eof110: cs = 110; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof111: cs = 111; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof112: cs = 112; goto _test_eof; 
	_test_eof113: cs = 113; goto _test_eof; 
	_test_eof114: cs = 114; goto _test_eof; 
	_test_eof115: cs = 115; goto _test_eof; 
	_test_eof116: cs = 116; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof117: cs = 117; goto _test_eof; 
	_test_eof118: cs = 118; goto _test_eof; 
	_test_eof119: cs = 119; goto _test_eof; 
	_test_eof120: cs = 120; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof121: cs = 121; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof122: cs = 122; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof123: cs = 123; goto _test_eof; 
	_test_eof124: cs = 124; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof125: cs = 125; goto _test_eof; 
	_test_eof126: cs = 126; goto _test_eof; 
	_test_eof127: cs = 127; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof128: cs = 128; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof129: cs = 129; goto _test_eof; 
	_test_eof130: cs = 130; goto _test_eof; 
	_test_eof131: cs = 131; goto _test_eof; 
	_test_eof132: cs = 132; goto _test_eof; 
	_test_eof133: cs = 133; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof134: cs = 134; goto _test_eof; 
	_test_eof135: cs = 135; goto _test_eof; 
	_test_eof136: cs = 136; goto _test_eof; 
	_test_eof137: cs = 137; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof138: cs = 138; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof139: cs = 139; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof140: cs = 140; goto _test_eof; 
	_test_eof141: cs = 141; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof142: cs = 142; goto _test_eof; 
	_test_eof143: cs = 143; goto _test_eof; 
	_test_eof144: cs = 144; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof145: cs = 145; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof146: cs = 146; goto _test_eof; 
	_test_eof147: cs = 147; goto _test_eof; 
	_test_eof148: cs = 148; goto _test_eof; 
	_test_eof149: cs = 149; goto _test_eof; 
	_test_eof150: cs = 150; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof151: cs = 151; goto _test_eof; 
	_test_eof152: cs = 152; goto _test_eof; 
	_test_eof153: cs = 153; goto _test_eof; 
	_test_eof154: cs = 154; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof155: cs = 155; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof156: cs = 156; goto _test_eof; 
	_test_eof73: cs = 73; goto _test_eof; 
	_test_eof157: cs = 157; goto _test_eof; 
	_test_eof158: cs = 158; goto _test_eof; 
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof159: cs = 159; goto _test_eof; 
	_test_eof160: cs = 160; goto _test_eof; 
	_test_eof161: cs = 161; goto _test_eof; 
	_test_eof75: cs = 75; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof162: cs = 162; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof163: cs = 163; goto _test_eof; 
	_test_eof164: cs = 164; goto _test_eof; 
	_test_eof165: cs = 165; goto _test_eof; 
	_test_eof166: cs = 166; goto _test_eof; 
	_test_eof167: cs = 167; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof168: cs = 168; goto _test_eof; 
	_test_eof169: cs = 169; goto _test_eof; 
	_test_eof170: cs = 170; goto _test_eof; 
	_test_eof171: cs = 171; goto _test_eof; 
	_test_eof86: cs = 86; goto _test_eof; 
	_test_eof87: cs = 87; goto _test_eof; 
	_test_eof172: cs = 172; goto _test_eof; 
	_test_eof88: cs = 88; goto _test_eof; 
	_test_eof89: cs = 89; goto _test_eof; 
	_test_eof90: cs = 90; goto _test_eof; 
	_test_eof91: cs = 91; goto _test_eof; 
	_test_eof92: cs = 92; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
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
	case 169: 
	case 170: 
	case 171: 
	case 172: 
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	break;
	case 94: 
	case 97: 
	case 100: 
	case 103: 
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	break;
#line 6890 "src/tfs_excel_parser.c"
	}
	}

	_out: {}
	}

#line 103 "src/tfs_excel_parser.rl"


    if (cs < 93) {
        printf("Error parsing Excel format string '%s' around col #%ld (%c)",
            bytes, (long)(p - bytes + 1), *p);
        return 1;
    }

    return 0;
}
