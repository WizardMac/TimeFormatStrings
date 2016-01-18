
#line 1 "src/tfs_excel_parser.rl"

#include <sys/types.h>
#include <stdio.h>
#include "tfs.h"
#include "tfs_internal.h"
#include "tfs_excel_parser.h"

/* See http://office.microsoft.com/en-us/excel-help/text-function-HP010062580.aspx */


#line 14 "src/tfs_excel_parser.c"
static const int excel_format_start = 101;
static const int excel_format_first_final = 101;
static const int excel_format_error = 0;

static const int excel_format_en_main = 101;


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
case 101:
	switch( (*p) ) {
		case 34: goto tr81;
		case 35: goto st103;
		case 37: goto st103;
		case 42: goto st3;
		case 44: goto st103;
		case 46: goto st103;
		case 48: goto st103;
		case 59: goto st104;
		case 65: goto tr84;
		case 68: goto tr85;
		case 69: goto st80;
		case 72: goto tr87;
		case 77: goto tr88;
		case 80: goto tr89;
		case 91: goto st96;
		case 92: goto st89;
		case 94: goto tr73;
		case 95: goto st3;
		case 97: goto tr92;
		case 100: goto tr93;
		case 101: goto st80;
		case 104: goto tr94;
		case 109: goto tr95;
		case 112: goto tr96;
		case 115: goto tr97;
		case 121: goto tr98;
		case 123: goto tr73;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr73;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr73;
		} else if ( (*p) >= 63 )
			goto st103;
	} else
		goto tr73;
	goto st0;
st0:
cs = 0;
	goto _out;
tr73:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st102;
tr99:
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
	goto st102;
tr339:
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
	goto st102;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
#line 127 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr100;
		case 35: goto tr101;
		case 37: goto tr101;
		case 42: goto tr102;
		case 44: goto tr101;
		case 46: goto tr101;
		case 48: goto tr101;
		case 59: goto tr103;
		case 65: goto tr104;
		case 68: goto tr105;
		case 69: goto tr106;
		case 72: goto tr107;
		case 77: goto tr108;
		case 80: goto tr109;
		case 91: goto tr110;
		case 92: goto tr111;
		case 94: goto tr99;
		case 95: goto tr102;
		case 97: goto tr112;
		case 100: goto tr113;
		case 101: goto tr106;
		case 104: goto tr114;
		case 109: goto tr115;
		case 112: goto tr116;
		case 115: goto tr117;
		case 121: goto tr118;
		case 123: goto tr99;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr99;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr99;
		} else if ( (*p) >= 63 )
			goto tr101;
	} else
		goto tr99;
	goto st0;
tr81:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st1;
tr100:
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
tr340:
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
		case 34: goto st102;
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
tr101:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st103;
tr341:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st103;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
#line 236 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr81;
		case 35: goto st103;
		case 37: goto st103;
		case 42: goto st3;
		case 44: goto st103;
		case 46: goto st103;
		case 48: goto st103;
		case 59: goto st104;
		case 65: goto tr84;
		case 68: goto tr85;
		case 69: goto st80;
		case 72: goto tr87;
		case 77: goto tr88;
		case 80: goto tr89;
		case 91: goto st81;
		case 92: goto st89;
		case 94: goto tr73;
		case 95: goto st3;
		case 97: goto tr92;
		case 100: goto tr93;
		case 101: goto st80;
		case 104: goto tr94;
		case 109: goto tr95;
		case 112: goto tr96;
		case 115: goto tr97;
		case 121: goto tr98;
		case 123: goto tr73;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr73;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr73;
		} else if ( (*p) >= 63 )
			goto st103;
	} else
		goto tr73;
	goto st0;
tr102:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st3;
tr342:
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
	goto st103;
tr103:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st104;
tr344:
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
#line 320 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr120;
		case 35: goto st106;
		case 37: goto st106;
		case 42: goto st6;
		case 44: goto st106;
		case 46: goto st106;
		case 48: goto st106;
		case 59: goto st107;
		case 65: goto tr123;
		case 68: goto tr124;
		case 69: goto st58;
		case 72: goto tr126;
		case 77: goto tr127;
		case 80: goto tr128;
		case 91: goto st74;
		case 92: goto st67;
		case 94: goto tr57;
		case 95: goto st6;
		case 97: goto tr131;
		case 100: goto tr132;
		case 101: goto st58;
		case 104: goto tr133;
		case 109: goto tr134;
		case 112: goto tr135;
		case 115: goto tr136;
		case 121: goto tr137;
		case 123: goto tr57;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr57;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr57;
		} else if ( (*p) >= 63 )
			goto st106;
	} else
		goto tr57;
	goto st0;
tr57:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st105;
tr138:
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
	goto st105;
tr304:
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
	goto st105;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
#line 396 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr139;
		case 35: goto tr140;
		case 37: goto tr140;
		case 42: goto tr141;
		case 44: goto tr140;
		case 46: goto tr140;
		case 48: goto tr140;
		case 59: goto tr142;
		case 65: goto tr143;
		case 68: goto tr144;
		case 69: goto tr145;
		case 72: goto tr146;
		case 77: goto tr147;
		case 80: goto tr148;
		case 91: goto tr149;
		case 92: goto tr150;
		case 94: goto tr138;
		case 95: goto tr141;
		case 97: goto tr151;
		case 100: goto tr152;
		case 101: goto tr145;
		case 104: goto tr153;
		case 109: goto tr154;
		case 112: goto tr155;
		case 115: goto tr156;
		case 121: goto tr157;
		case 123: goto tr138;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr138;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr138;
		} else if ( (*p) >= 63 )
			goto tr140;
	} else
		goto tr138;
	goto st0;
tr120:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st4;
tr139:
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
tr305:
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
		case 34: goto st105;
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
tr140:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st106;
tr306:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st106;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
#line 505 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr120;
		case 35: goto st106;
		case 37: goto st106;
		case 42: goto st6;
		case 44: goto st106;
		case 46: goto st106;
		case 48: goto st106;
		case 59: goto st107;
		case 65: goto tr123;
		case 68: goto tr124;
		case 69: goto st58;
		case 72: goto tr126;
		case 77: goto tr127;
		case 80: goto tr128;
		case 91: goto st59;
		case 92: goto st67;
		case 94: goto tr57;
		case 95: goto st6;
		case 97: goto tr131;
		case 100: goto tr132;
		case 101: goto st58;
		case 104: goto tr133;
		case 109: goto tr134;
		case 112: goto tr135;
		case 115: goto tr136;
		case 121: goto tr137;
		case 123: goto tr57;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr57;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr57;
		} else if ( (*p) >= 63 )
			goto st106;
	} else
		goto tr57;
	goto st0;
tr141:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st6;
tr307:
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
	goto st106;
tr142:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st107;
tr309:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st107;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
#line 589 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr159;
		case 35: goto st109;
		case 37: goto st109;
		case 42: goto st9;
		case 44: goto st109;
		case 46: goto st109;
		case 48: goto st109;
		case 59: goto st110;
		case 65: goto tr162;
		case 68: goto tr163;
		case 69: goto st36;
		case 72: goto tr165;
		case 77: goto tr166;
		case 80: goto tr167;
		case 91: goto st52;
		case 92: goto st45;
		case 94: goto tr41;
		case 95: goto st9;
		case 97: goto tr170;
		case 100: goto tr171;
		case 101: goto st36;
		case 104: goto tr172;
		case 109: goto tr173;
		case 112: goto tr174;
		case 115: goto tr175;
		case 121: goto tr176;
		case 123: goto tr41;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr41;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr41;
		} else if ( (*p) >= 63 )
			goto st109;
	} else
		goto tr41;
	goto st0;
tr41:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st108;
tr177:
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
	goto st108;
tr269:
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
	goto st108;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
#line 665 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr178;
		case 35: goto tr179;
		case 37: goto tr179;
		case 42: goto tr180;
		case 44: goto tr179;
		case 46: goto tr179;
		case 48: goto tr179;
		case 59: goto tr181;
		case 65: goto tr182;
		case 68: goto tr183;
		case 69: goto tr184;
		case 72: goto tr185;
		case 77: goto tr186;
		case 80: goto tr187;
		case 91: goto tr188;
		case 92: goto tr189;
		case 94: goto tr177;
		case 95: goto tr180;
		case 97: goto tr190;
		case 100: goto tr191;
		case 101: goto tr184;
		case 104: goto tr192;
		case 109: goto tr193;
		case 112: goto tr194;
		case 115: goto tr195;
		case 121: goto tr196;
		case 123: goto tr177;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr177;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr177;
		} else if ( (*p) >= 63 )
			goto tr179;
	} else
		goto tr177;
	goto st0;
tr159:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st7;
tr178:
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
tr270:
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
		case 34: goto st108;
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
tr179:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st109;
tr271:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st109;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
#line 774 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr159;
		case 35: goto st109;
		case 37: goto st109;
		case 42: goto st9;
		case 44: goto st109;
		case 46: goto st109;
		case 48: goto st109;
		case 59: goto st110;
		case 65: goto tr162;
		case 68: goto tr163;
		case 69: goto st36;
		case 72: goto tr165;
		case 77: goto tr166;
		case 80: goto tr167;
		case 91: goto st37;
		case 92: goto st45;
		case 94: goto tr41;
		case 95: goto st9;
		case 97: goto tr170;
		case 100: goto tr171;
		case 101: goto st36;
		case 104: goto tr172;
		case 109: goto tr173;
		case 112: goto tr174;
		case 115: goto tr175;
		case 121: goto tr176;
		case 123: goto tr41;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr41;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr41;
		} else if ( (*p) >= 63 )
			goto st109;
	} else
		goto tr41;
	goto st0;
tr180:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st9;
tr272:
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
	goto st109;
tr181:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st110;
tr274:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st110;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
#line 858 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr198;
		case 35: goto st112;
		case 37: goto st112;
		case 42: goto st12;
		case 44: goto st112;
		case 46: goto st112;
		case 48: goto st112;
		case 58: goto tr25;
		case 65: goto tr200;
		case 68: goto tr201;
		case 69: goto st14;
		case 72: goto tr203;
		case 77: goto tr204;
		case 80: goto tr205;
		case 91: goto st30;
		case 92: goto st23;
		case 94: goto tr25;
		case 95: goto st12;
		case 97: goto tr208;
		case 100: goto tr209;
		case 101: goto st14;
		case 104: goto tr210;
		case 109: goto tr211;
		case 112: goto tr212;
		case 115: goto tr213;
		case 121: goto tr214;
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
			goto st112;
	} else
		goto tr25;
	goto st0;
tr25:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st111;
tr215:
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
	goto st111;
tr235:
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
	goto st111;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
#line 934 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr216;
		case 35: goto tr217;
		case 37: goto tr217;
		case 42: goto tr218;
		case 44: goto tr217;
		case 46: goto tr217;
		case 48: goto tr217;
		case 58: goto tr215;
		case 65: goto tr219;
		case 68: goto tr220;
		case 69: goto tr221;
		case 72: goto tr222;
		case 77: goto tr223;
		case 80: goto tr224;
		case 91: goto tr225;
		case 92: goto tr226;
		case 94: goto tr215;
		case 95: goto tr218;
		case 97: goto tr227;
		case 100: goto tr228;
		case 101: goto tr221;
		case 104: goto tr229;
		case 109: goto tr230;
		case 112: goto tr231;
		case 115: goto tr232;
		case 121: goto tr233;
		case 123: goto tr215;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr215;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr215;
		} else if ( (*p) >= 63 )
			goto tr217;
	} else
		goto tr215;
	goto st0;
tr198:
#line 27 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st10;
tr216:
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
tr236:
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
		case 34: goto st111;
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
tr217:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st112;
tr237:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st112;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
#line 1043 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr198;
		case 35: goto st112;
		case 37: goto st112;
		case 42: goto st12;
		case 44: goto st112;
		case 46: goto st112;
		case 48: goto st112;
		case 58: goto tr25;
		case 65: goto tr200;
		case 68: goto tr201;
		case 69: goto st14;
		case 72: goto tr203;
		case 77: goto tr204;
		case 80: goto tr205;
		case 91: goto st15;
		case 92: goto st23;
		case 94: goto tr25;
		case 95: goto st12;
		case 97: goto tr208;
		case 100: goto tr209;
		case 101: goto st14;
		case 104: goto tr210;
		case 109: goto tr211;
		case 112: goto tr212;
		case 115: goto tr213;
		case 121: goto tr214;
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
			goto st112;
	} else
		goto tr25;
	goto st0;
tr218:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st12;
tr238:
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
	goto st112;
tr200:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st113;
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
	goto st113;
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
	goto st113;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
#line 1141 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr236;
		case 35: goto tr237;
		case 37: goto tr237;
		case 42: goto tr238;
		case 44: goto tr237;
		case 47: goto st13;
		case 58: goto tr235;
		case 65: goto tr240;
		case 68: goto tr241;
		case 69: goto tr242;
		case 72: goto tr243;
		case 77: goto st129;
		case 80: goto tr245;
		case 91: goto tr246;
		case 92: goto tr247;
		case 94: goto tr235;
		case 95: goto tr238;
		case 97: goto tr248;
		case 100: goto tr249;
		case 101: goto tr242;
		case 104: goto tr250;
		case 109: goto tr251;
		case 112: goto tr252;
		case 115: goto tr253;
		case 121: goto tr254;
		case 123: goto tr235;
	}
	if ( (*p) < 60 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr237;
		} else if ( (*p) >= 32 )
			goto tr235;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr235;
		} else if ( (*p) >= 63 )
			goto tr237;
	} else
		goto tr235;
	goto st0;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	if ( (*p) == 80 )
		goto st114;
	goto st0;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	switch( (*p) ) {
		case 34: goto tr236;
		case 35: goto tr237;
		case 37: goto tr237;
		case 42: goto tr238;
		case 44: goto tr237;
		case 46: goto tr237;
		case 48: goto tr237;
		case 58: goto tr235;
		case 65: goto tr240;
		case 68: goto tr241;
		case 69: goto tr242;
		case 72: goto tr243;
		case 77: goto tr255;
		case 80: goto tr245;
		case 91: goto tr246;
		case 92: goto tr247;
		case 94: goto tr235;
		case 95: goto tr238;
		case 97: goto tr248;
		case 100: goto tr249;
		case 101: goto tr242;
		case 104: goto tr250;
		case 109: goto tr251;
		case 112: goto tr252;
		case 115: goto tr253;
		case 121: goto tr254;
		case 123: goto tr235;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr235;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr235;
		} else if ( (*p) >= 63 )
			goto tr237;
	} else
		goto tr235;
	goto st0;
tr201:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st115;
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
	goto st115;
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
	goto st115;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
#line 1271 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr236;
		case 35: goto tr237;
		case 37: goto tr237;
		case 42: goto tr238;
		case 44: goto tr237;
		case 46: goto tr237;
		case 48: goto tr237;
		case 58: goto tr235;
		case 65: goto tr240;
		case 68: goto st115;
		case 69: goto tr242;
		case 72: goto tr243;
		case 77: goto tr255;
		case 80: goto tr245;
		case 91: goto tr246;
		case 92: goto tr247;
		case 94: goto tr235;
		case 95: goto tr238;
		case 97: goto tr248;
		case 100: goto tr249;
		case 101: goto tr242;
		case 104: goto tr250;
		case 109: goto tr251;
		case 112: goto tr252;
		case 115: goto tr253;
		case 121: goto tr254;
		case 123: goto tr235;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr235;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr235;
		} else if ( (*p) >= 63 )
			goto tr237;
	} else
		goto tr235;
	goto st0;
tr221:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st14;
tr242:
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
		case 43: goto st112;
		case 45: goto st112;
	}
	goto st0;
tr203:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st116;
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
	goto st116;
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
	goto st116;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
#line 1373 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr236;
		case 35: goto tr237;
		case 37: goto tr237;
		case 42: goto tr238;
		case 44: goto tr237;
		case 46: goto tr237;
		case 48: goto tr237;
		case 58: goto tr235;
		case 65: goto tr240;
		case 68: goto tr241;
		case 69: goto tr242;
		case 72: goto st116;
		case 77: goto tr255;
		case 80: goto tr245;
		case 91: goto tr246;
		case 92: goto tr247;
		case 94: goto tr235;
		case 95: goto tr238;
		case 97: goto tr248;
		case 100: goto tr249;
		case 101: goto tr242;
		case 104: goto tr250;
		case 109: goto tr251;
		case 112: goto tr252;
		case 115: goto tr253;
		case 121: goto tr254;
		case 123: goto tr235;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr235;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr235;
		} else if ( (*p) >= 63 )
			goto tr237;
	} else
		goto tr235;
	goto st0;
tr204:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st117;
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
	goto st117;
tr255:
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
	goto st117;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
#line 1449 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr236;
		case 35: goto tr237;
		case 37: goto tr237;
		case 42: goto tr238;
		case 44: goto tr237;
		case 46: goto tr237;
		case 48: goto tr237;
		case 58: goto tr235;
		case 65: goto tr240;
		case 68: goto tr241;
		case 69: goto tr242;
		case 72: goto tr243;
		case 77: goto st117;
		case 80: goto tr245;
		case 91: goto tr246;
		case 92: goto tr247;
		case 94: goto tr235;
		case 95: goto tr238;
		case 97: goto tr248;
		case 100: goto tr249;
		case 101: goto tr242;
		case 104: goto tr250;
		case 109: goto tr251;
		case 112: goto tr252;
		case 115: goto tr253;
		case 121: goto tr254;
		case 123: goto tr235;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr235;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr235;
		} else if ( (*p) >= 63 )
			goto tr237;
	} else
		goto tr235;
	goto st0;
tr205:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st118;
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
	goto st118;
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
	goto st118;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
#line 1525 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr236;
		case 35: goto tr237;
		case 37: goto tr237;
		case 42: goto tr238;
		case 44: goto tr237;
		case 46: goto tr237;
		case 48: goto tr237;
		case 58: goto tr235;
		case 65: goto tr240;
		case 68: goto tr241;
		case 69: goto tr242;
		case 72: goto tr243;
		case 77: goto st114;
		case 80: goto tr245;
		case 91: goto tr246;
		case 92: goto tr247;
		case 94: goto tr235;
		case 95: goto tr238;
		case 97: goto tr248;
		case 100: goto tr249;
		case 101: goto tr242;
		case 104: goto tr250;
		case 109: goto tr251;
		case 112: goto tr252;
		case 115: goto tr253;
		case 121: goto tr254;
		case 123: goto tr235;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr235;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr235;
		} else if ( (*p) >= 63 )
			goto tr237;
	} else
		goto tr235;
	goto st0;
tr225:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st15;
tr246:
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
		goto st112;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st19;
	goto st0;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	switch( (*p) ) {
		case 46: goto st18;
		case 93: goto st112;
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
tr226:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st23;
tr247:
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
tr208:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st119;
tr227:
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
	goto st119;
tr248:
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
	goto st119;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
#line 1723 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr236;
		case 35: goto tr237;
		case 37: goto tr237;
		case 42: goto tr238;
		case 44: goto tr237;
		case 47: goto st24;
		case 58: goto tr235;
		case 65: goto tr240;
		case 68: goto tr241;
		case 69: goto tr242;
		case 72: goto tr243;
		case 77: goto tr255;
		case 80: goto tr245;
		case 91: goto tr246;
		case 92: goto tr247;
		case 94: goto tr235;
		case 95: goto tr238;
		case 97: goto tr248;
		case 100: goto tr249;
		case 101: goto tr242;
		case 104: goto tr250;
		case 109: goto st128;
		case 112: goto tr252;
		case 115: goto tr253;
		case 121: goto tr254;
		case 123: goto tr235;
	}
	if ( (*p) < 60 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr237;
		} else if ( (*p) >= 32 )
			goto tr235;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr235;
		} else if ( (*p) >= 63 )
			goto tr237;
	} else
		goto tr235;
	goto st0;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	if ( (*p) == 112 )
		goto st114;
	goto st0;
tr209:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st120;
tr228:
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
tr249:
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
#line 1808 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr236;
		case 35: goto tr237;
		case 37: goto tr237;
		case 42: goto tr238;
		case 44: goto tr237;
		case 46: goto tr237;
		case 48: goto tr237;
		case 58: goto tr235;
		case 65: goto tr240;
		case 68: goto tr241;
		case 69: goto tr242;
		case 72: goto tr243;
		case 77: goto tr255;
		case 80: goto tr245;
		case 91: goto tr246;
		case 92: goto tr247;
		case 94: goto tr235;
		case 95: goto tr238;
		case 97: goto tr248;
		case 100: goto st120;
		case 101: goto tr242;
		case 104: goto tr250;
		case 109: goto tr251;
		case 112: goto tr252;
		case 115: goto tr253;
		case 121: goto tr254;
		case 123: goto tr235;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr235;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr235;
		} else if ( (*p) >= 63 )
			goto tr237;
	} else
		goto tr235;
	goto st0;
tr210:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st121;
tr229:
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
tr250:
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
#line 1884 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr236;
		case 35: goto tr237;
		case 37: goto tr237;
		case 42: goto tr238;
		case 44: goto tr237;
		case 46: goto tr237;
		case 48: goto tr237;
		case 58: goto tr235;
		case 65: goto tr240;
		case 68: goto tr241;
		case 69: goto tr242;
		case 72: goto tr243;
		case 77: goto tr255;
		case 80: goto tr245;
		case 91: goto tr246;
		case 92: goto tr247;
		case 94: goto tr235;
		case 95: goto tr238;
		case 97: goto tr248;
		case 100: goto tr249;
		case 101: goto tr242;
		case 104: goto st121;
		case 109: goto tr251;
		case 112: goto tr252;
		case 115: goto tr253;
		case 121: goto tr254;
		case 123: goto tr235;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr235;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr235;
		} else if ( (*p) >= 63 )
			goto tr237;
	} else
		goto tr235;
	goto st0;
tr211:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st122;
tr230:
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
tr251:
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
#line 1960 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr236;
		case 35: goto tr237;
		case 37: goto tr237;
		case 42: goto tr238;
		case 44: goto tr237;
		case 46: goto tr237;
		case 48: goto tr237;
		case 58: goto tr235;
		case 65: goto tr240;
		case 68: goto tr241;
		case 69: goto tr242;
		case 72: goto tr243;
		case 77: goto tr255;
		case 80: goto tr245;
		case 91: goto tr246;
		case 92: goto tr247;
		case 94: goto tr235;
		case 95: goto tr238;
		case 97: goto tr248;
		case 100: goto tr249;
		case 101: goto tr242;
		case 104: goto tr250;
		case 109: goto st122;
		case 112: goto tr252;
		case 115: goto tr253;
		case 121: goto tr254;
		case 123: goto tr235;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr235;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr235;
		} else if ( (*p) >= 63 )
			goto tr237;
	} else
		goto tr235;
	goto st0;
tr212:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st123;
tr231:
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
tr252:
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
#line 2036 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr236;
		case 35: goto tr237;
		case 37: goto tr237;
		case 42: goto tr238;
		case 44: goto tr237;
		case 46: goto tr237;
		case 48: goto tr237;
		case 58: goto tr235;
		case 65: goto tr240;
		case 68: goto tr241;
		case 69: goto tr242;
		case 72: goto tr243;
		case 77: goto tr255;
		case 80: goto tr245;
		case 91: goto tr246;
		case 92: goto tr247;
		case 94: goto tr235;
		case 95: goto tr238;
		case 97: goto tr248;
		case 100: goto tr249;
		case 101: goto tr242;
		case 104: goto tr250;
		case 109: goto st114;
		case 112: goto tr252;
		case 115: goto tr253;
		case 121: goto tr254;
		case 123: goto tr235;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr235;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr235;
		} else if ( (*p) >= 63 )
			goto tr237;
	} else
		goto tr235;
	goto st0;
tr213:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st124;
tr232:
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
tr253:
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
#line 2112 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr236;
		case 35: goto tr237;
		case 37: goto tr237;
		case 42: goto tr238;
		case 44: goto tr237;
		case 46: goto st25;
		case 48: goto tr237;
		case 58: goto tr235;
		case 65: goto tr240;
		case 68: goto tr241;
		case 69: goto tr242;
		case 72: goto tr243;
		case 77: goto tr255;
		case 80: goto tr245;
		case 91: goto tr246;
		case 92: goto tr247;
		case 94: goto tr235;
		case 95: goto tr238;
		case 97: goto tr248;
		case 100: goto tr249;
		case 101: goto tr242;
		case 104: goto tr250;
		case 109: goto tr251;
		case 112: goto tr252;
		case 115: goto st127;
		case 121: goto tr254;
		case 123: goto tr235;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr235;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr235;
		} else if ( (*p) >= 63 )
			goto tr237;
	} else
		goto tr235;
	goto st0;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	switch( (*p) ) {
		case 35: goto st125;
		case 44: goto st125;
		case 48: goto st125;
		case 63: goto st125;
	}
	goto st0;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	switch( (*p) ) {
		case 34: goto tr236;
		case 35: goto st125;
		case 37: goto tr237;
		case 42: goto tr238;
		case 44: goto st125;
		case 46: goto tr237;
		case 48: goto st125;
		case 58: goto tr235;
		case 63: goto st125;
		case 64: goto tr237;
		case 65: goto tr240;
		case 68: goto tr241;
		case 69: goto tr242;
		case 72: goto tr243;
		case 77: goto tr255;
		case 80: goto tr245;
		case 91: goto tr246;
		case 92: goto tr247;
		case 94: goto tr235;
		case 95: goto tr238;
		case 97: goto tr248;
		case 100: goto tr249;
		case 101: goto tr242;
		case 104: goto tr250;
		case 109: goto tr251;
		case 112: goto tr252;
		case 115: goto tr253;
		case 121: goto tr254;
		case 123: goto tr235;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr235;
	} else if ( (*p) > 62 ) {
		if ( 125 <= (*p) && (*p) <= 126 )
			goto tr235;
	} else
		goto tr235;
	goto st0;
tr214:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st126;
tr233:
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
tr254:
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
#line 2243 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr236;
		case 35: goto tr237;
		case 37: goto tr237;
		case 42: goto tr238;
		case 44: goto tr237;
		case 46: goto tr237;
		case 48: goto tr237;
		case 58: goto tr235;
		case 65: goto tr240;
		case 68: goto tr241;
		case 69: goto tr242;
		case 72: goto tr243;
		case 77: goto tr255;
		case 80: goto tr245;
		case 91: goto tr246;
		case 92: goto tr247;
		case 94: goto tr235;
		case 95: goto tr238;
		case 97: goto tr248;
		case 100: goto tr249;
		case 101: goto tr242;
		case 104: goto tr250;
		case 109: goto tr251;
		case 112: goto tr252;
		case 115: goto tr253;
		case 121: goto st126;
		case 123: goto tr235;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr235;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr235;
		} else if ( (*p) >= 63 )
			goto tr237;
	} else
		goto tr235;
	goto st0;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	switch( (*p) ) {
		case 34: goto tr236;
		case 35: goto tr237;
		case 37: goto tr237;
		case 42: goto tr238;
		case 44: goto tr237;
		case 46: goto st25;
		case 48: goto tr237;
		case 58: goto tr235;
		case 65: goto tr240;
		case 68: goto tr241;
		case 69: goto tr242;
		case 72: goto tr243;
		case 77: goto tr255;
		case 80: goto tr245;
		case 91: goto tr246;
		case 92: goto tr247;
		case 94: goto tr235;
		case 95: goto tr238;
		case 97: goto tr248;
		case 100: goto tr249;
		case 101: goto tr242;
		case 104: goto tr250;
		case 109: goto tr251;
		case 112: goto tr252;
		case 115: goto tr253;
		case 121: goto tr254;
		case 123: goto tr235;
	}
	if ( (*p) < 60 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr235;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr235;
		} else if ( (*p) >= 63 )
			goto tr237;
	} else
		goto tr235;
	goto st0;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	switch( (*p) ) {
		case 34: goto tr236;
		case 35: goto tr237;
		case 37: goto tr237;
		case 42: goto tr238;
		case 44: goto tr237;
		case 47: goto st26;
		case 58: goto tr235;
		case 65: goto tr240;
		case 68: goto tr241;
		case 69: goto tr242;
		case 72: goto tr243;
		case 77: goto tr255;
		case 80: goto tr245;
		case 91: goto tr246;
		case 92: goto tr247;
		case 94: goto tr235;
		case 95: goto tr238;
		case 97: goto tr248;
		case 100: goto tr249;
		case 101: goto tr242;
		case 104: goto tr250;
		case 109: goto tr251;
		case 112: goto tr252;
		case 115: goto tr253;
		case 121: goto tr254;
		case 123: goto tr235;
	}
	if ( (*p) < 60 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr237;
		} else if ( (*p) >= 32 )
			goto tr235;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr235;
		} else if ( (*p) >= 63 )
			goto tr237;
	} else
		goto tr235;
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
		goto st114;
	goto st0;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	switch( (*p) ) {
		case 34: goto tr236;
		case 35: goto tr237;
		case 37: goto tr237;
		case 42: goto tr238;
		case 44: goto tr237;
		case 47: goto st28;
		case 58: goto tr235;
		case 65: goto tr240;
		case 68: goto tr241;
		case 69: goto tr242;
		case 72: goto tr243;
		case 77: goto tr255;
		case 80: goto tr245;
		case 91: goto tr246;
		case 92: goto tr247;
		case 94: goto tr235;
		case 95: goto tr238;
		case 97: goto tr248;
		case 100: goto tr249;
		case 101: goto tr242;
		case 104: goto tr250;
		case 109: goto tr251;
		case 112: goto tr252;
		case 115: goto tr253;
		case 121: goto tr254;
		case 123: goto tr235;
	}
	if ( (*p) < 60 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr237;
		} else if ( (*p) >= 32 )
			goto tr235;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr235;
		} else if ( (*p) >= 63 )
			goto tr237;
	} else
		goto tr235;
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
		goto st114;
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
			goto st34;
	} else if ( (*p) >= 65 )
		goto st34;
	goto st0;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	if ( (*p) == 45 )
		goto st32;
	goto st0;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st33;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st33;
	} else
		goto st33;
	goto st0;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	if ( (*p) == 93 )
		goto st112;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st33;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st33;
	} else
		goto st33;
	goto st0;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	if ( (*p) == 93 )
		goto st112;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st34;
	} else if ( (*p) >= 65 )
		goto st34;
	goto st0;
tr162:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st130;
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
	goto st130;
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
	goto st130;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
#line 2549 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr270;
		case 35: goto tr271;
		case 37: goto tr271;
		case 42: goto tr272;
		case 44: goto tr271;
		case 47: goto st35;
		case 59: goto tr274;
		case 65: goto tr275;
		case 68: goto tr276;
		case 69: goto tr277;
		case 72: goto tr278;
		case 77: goto st146;
		case 80: goto tr280;
		case 91: goto tr281;
		case 92: goto tr282;
		case 94: goto tr269;
		case 95: goto tr272;
		case 97: goto tr283;
		case 100: goto tr284;
		case 101: goto tr277;
		case 104: goto tr285;
		case 109: goto tr286;
		case 112: goto tr287;
		case 115: goto tr288;
		case 121: goto tr289;
		case 123: goto tr269;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr271;
		} else if ( (*p) >= 32 )
			goto tr269;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr269;
		} else if ( (*p) >= 63 )
			goto tr271;
	} else
		goto tr269;
	goto st0;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	if ( (*p) == 80 )
		goto st131;
	goto st0;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	switch( (*p) ) {
		case 34: goto tr270;
		case 35: goto tr271;
		case 37: goto tr271;
		case 42: goto tr272;
		case 44: goto tr271;
		case 46: goto tr271;
		case 48: goto tr271;
		case 59: goto tr274;
		case 65: goto tr275;
		case 68: goto tr276;
		case 69: goto tr277;
		case 72: goto tr278;
		case 77: goto tr290;
		case 80: goto tr280;
		case 91: goto tr281;
		case 92: goto tr282;
		case 94: goto tr269;
		case 95: goto tr272;
		case 97: goto tr283;
		case 100: goto tr284;
		case 101: goto tr277;
		case 104: goto tr285;
		case 109: goto tr286;
		case 112: goto tr287;
		case 115: goto tr288;
		case 121: goto tr289;
		case 123: goto tr269;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr269;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr269;
		} else if ( (*p) >= 63 )
			goto tr271;
	} else
		goto tr269;
	goto st0;
tr163:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st132;
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
	goto st132;
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
	goto st132;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
#line 2679 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr270;
		case 35: goto tr271;
		case 37: goto tr271;
		case 42: goto tr272;
		case 44: goto tr271;
		case 46: goto tr271;
		case 48: goto tr271;
		case 59: goto tr274;
		case 65: goto tr275;
		case 68: goto st132;
		case 69: goto tr277;
		case 72: goto tr278;
		case 77: goto tr290;
		case 80: goto tr280;
		case 91: goto tr281;
		case 92: goto tr282;
		case 94: goto tr269;
		case 95: goto tr272;
		case 97: goto tr283;
		case 100: goto tr284;
		case 101: goto tr277;
		case 104: goto tr285;
		case 109: goto tr286;
		case 112: goto tr287;
		case 115: goto tr288;
		case 121: goto tr289;
		case 123: goto tr269;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr269;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr269;
		} else if ( (*p) >= 63 )
			goto tr271;
	} else
		goto tr269;
	goto st0;
tr184:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st36;
tr277:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
#line 2741 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 43: goto st109;
		case 45: goto st109;
	}
	goto st0;
tr165:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st133;
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
	goto st133;
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
	goto st133;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
#line 2781 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr270;
		case 35: goto tr271;
		case 37: goto tr271;
		case 42: goto tr272;
		case 44: goto tr271;
		case 46: goto tr271;
		case 48: goto tr271;
		case 59: goto tr274;
		case 65: goto tr275;
		case 68: goto tr276;
		case 69: goto tr277;
		case 72: goto st133;
		case 77: goto tr290;
		case 80: goto tr280;
		case 91: goto tr281;
		case 92: goto tr282;
		case 94: goto tr269;
		case 95: goto tr272;
		case 97: goto tr283;
		case 100: goto tr284;
		case 101: goto tr277;
		case 104: goto tr285;
		case 109: goto tr286;
		case 112: goto tr287;
		case 115: goto tr288;
		case 121: goto tr289;
		case 123: goto tr269;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr269;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr269;
		} else if ( (*p) >= 63 )
			goto tr271;
	} else
		goto tr269;
	goto st0;
tr166:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st134;
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
	goto st134;
tr290:
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
	goto st134;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
#line 2857 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr270;
		case 35: goto tr271;
		case 37: goto tr271;
		case 42: goto tr272;
		case 44: goto tr271;
		case 46: goto tr271;
		case 48: goto tr271;
		case 59: goto tr274;
		case 65: goto tr275;
		case 68: goto tr276;
		case 69: goto tr277;
		case 72: goto tr278;
		case 77: goto st134;
		case 80: goto tr280;
		case 91: goto tr281;
		case 92: goto tr282;
		case 94: goto tr269;
		case 95: goto tr272;
		case 97: goto tr283;
		case 100: goto tr284;
		case 101: goto tr277;
		case 104: goto tr285;
		case 109: goto tr286;
		case 112: goto tr287;
		case 115: goto tr288;
		case 121: goto tr289;
		case 123: goto tr269;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr269;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr269;
		} else if ( (*p) >= 63 )
			goto tr271;
	} else
		goto tr269;
	goto st0;
tr167:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st135;
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
	goto st135;
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
	goto st135;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
#line 2933 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr270;
		case 35: goto tr271;
		case 37: goto tr271;
		case 42: goto tr272;
		case 44: goto tr271;
		case 46: goto tr271;
		case 48: goto tr271;
		case 59: goto tr274;
		case 65: goto tr275;
		case 68: goto tr276;
		case 69: goto tr277;
		case 72: goto tr278;
		case 77: goto st131;
		case 80: goto tr280;
		case 91: goto tr281;
		case 92: goto tr282;
		case 94: goto tr269;
		case 95: goto tr272;
		case 97: goto tr283;
		case 100: goto tr284;
		case 101: goto tr277;
		case 104: goto tr285;
		case 109: goto tr286;
		case 112: goto tr287;
		case 115: goto tr288;
		case 121: goto tr289;
		case 123: goto tr269;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr269;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr269;
		} else if ( (*p) >= 63 )
			goto tr271;
	} else
		goto tr269;
	goto st0;
tr188:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st37;
tr281:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 2995 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 60: goto st38;
		case 61: goto st43;
		case 62: goto st44;
	}
	goto st0;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	switch( (*p) ) {
		case 45: goto st39;
		case 46: goto st40;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 62 )
			goto st43;
	} else if ( (*p) >= 48 )
		goto st42;
	goto st0;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	if ( (*p) == 46 )
		goto st40;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st42;
	goto st0;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st41;
	goto st0;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	if ( (*p) == 93 )
		goto st109;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st41;
	goto st0;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	switch( (*p) ) {
		case 46: goto st40;
		case 93: goto st109;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st42;
	goto st0;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	switch( (*p) ) {
		case 45: goto st39;
		case 46: goto st40;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st42;
	goto st0;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	switch( (*p) ) {
		case 45: goto st39;
		case 46: goto st40;
		case 61: goto st43;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st42;
	goto st0;
tr189:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st45;
tr282:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
#line 3095 "src/tfs_excel_parser.c"
	goto tr41;
tr170:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st136;
tr190:
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
	goto st136;
tr283:
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
	goto st136;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
#line 3131 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr270;
		case 35: goto tr271;
		case 37: goto tr271;
		case 42: goto tr272;
		case 44: goto tr271;
		case 47: goto st46;
		case 59: goto tr274;
		case 65: goto tr275;
		case 68: goto tr276;
		case 69: goto tr277;
		case 72: goto tr278;
		case 77: goto tr290;
		case 80: goto tr280;
		case 91: goto tr281;
		case 92: goto tr282;
		case 94: goto tr269;
		case 95: goto tr272;
		case 97: goto tr283;
		case 100: goto tr284;
		case 101: goto tr277;
		case 104: goto tr285;
		case 109: goto st145;
		case 112: goto tr287;
		case 115: goto tr288;
		case 121: goto tr289;
		case 123: goto tr269;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr271;
		} else if ( (*p) >= 32 )
			goto tr269;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr269;
		} else if ( (*p) >= 63 )
			goto tr271;
	} else
		goto tr269;
	goto st0;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	if ( (*p) == 112 )
		goto st131;
	goto st0;
tr171:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st137;
tr191:
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
tr284:
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
#line 3216 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr270;
		case 35: goto tr271;
		case 37: goto tr271;
		case 42: goto tr272;
		case 44: goto tr271;
		case 46: goto tr271;
		case 48: goto tr271;
		case 59: goto tr274;
		case 65: goto tr275;
		case 68: goto tr276;
		case 69: goto tr277;
		case 72: goto tr278;
		case 77: goto tr290;
		case 80: goto tr280;
		case 91: goto tr281;
		case 92: goto tr282;
		case 94: goto tr269;
		case 95: goto tr272;
		case 97: goto tr283;
		case 100: goto st137;
		case 101: goto tr277;
		case 104: goto tr285;
		case 109: goto tr286;
		case 112: goto tr287;
		case 115: goto tr288;
		case 121: goto tr289;
		case 123: goto tr269;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr269;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr269;
		} else if ( (*p) >= 63 )
			goto tr271;
	} else
		goto tr269;
	goto st0;
tr172:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st138;
tr192:
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
tr285:
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
#line 3292 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr270;
		case 35: goto tr271;
		case 37: goto tr271;
		case 42: goto tr272;
		case 44: goto tr271;
		case 46: goto tr271;
		case 48: goto tr271;
		case 59: goto tr274;
		case 65: goto tr275;
		case 68: goto tr276;
		case 69: goto tr277;
		case 72: goto tr278;
		case 77: goto tr290;
		case 80: goto tr280;
		case 91: goto tr281;
		case 92: goto tr282;
		case 94: goto tr269;
		case 95: goto tr272;
		case 97: goto tr283;
		case 100: goto tr284;
		case 101: goto tr277;
		case 104: goto st138;
		case 109: goto tr286;
		case 112: goto tr287;
		case 115: goto tr288;
		case 121: goto tr289;
		case 123: goto tr269;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr269;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr269;
		} else if ( (*p) >= 63 )
			goto tr271;
	} else
		goto tr269;
	goto st0;
tr173:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st139;
tr193:
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
tr286:
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
#line 3368 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr270;
		case 35: goto tr271;
		case 37: goto tr271;
		case 42: goto tr272;
		case 44: goto tr271;
		case 46: goto tr271;
		case 48: goto tr271;
		case 59: goto tr274;
		case 65: goto tr275;
		case 68: goto tr276;
		case 69: goto tr277;
		case 72: goto tr278;
		case 77: goto tr290;
		case 80: goto tr280;
		case 91: goto tr281;
		case 92: goto tr282;
		case 94: goto tr269;
		case 95: goto tr272;
		case 97: goto tr283;
		case 100: goto tr284;
		case 101: goto tr277;
		case 104: goto tr285;
		case 109: goto st139;
		case 112: goto tr287;
		case 115: goto tr288;
		case 121: goto tr289;
		case 123: goto tr269;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr269;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr269;
		} else if ( (*p) >= 63 )
			goto tr271;
	} else
		goto tr269;
	goto st0;
tr174:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st140;
tr194:
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
tr287:
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
#line 3444 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr270;
		case 35: goto tr271;
		case 37: goto tr271;
		case 42: goto tr272;
		case 44: goto tr271;
		case 46: goto tr271;
		case 48: goto tr271;
		case 59: goto tr274;
		case 65: goto tr275;
		case 68: goto tr276;
		case 69: goto tr277;
		case 72: goto tr278;
		case 77: goto tr290;
		case 80: goto tr280;
		case 91: goto tr281;
		case 92: goto tr282;
		case 94: goto tr269;
		case 95: goto tr272;
		case 97: goto tr283;
		case 100: goto tr284;
		case 101: goto tr277;
		case 104: goto tr285;
		case 109: goto st131;
		case 112: goto tr287;
		case 115: goto tr288;
		case 121: goto tr289;
		case 123: goto tr269;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr269;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr269;
		} else if ( (*p) >= 63 )
			goto tr271;
	} else
		goto tr269;
	goto st0;
tr175:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st141;
tr195:
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
tr288:
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
#line 3520 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr270;
		case 35: goto tr271;
		case 37: goto tr271;
		case 42: goto tr272;
		case 44: goto tr271;
		case 46: goto st47;
		case 48: goto tr271;
		case 59: goto tr274;
		case 65: goto tr275;
		case 68: goto tr276;
		case 69: goto tr277;
		case 72: goto tr278;
		case 77: goto tr290;
		case 80: goto tr280;
		case 91: goto tr281;
		case 92: goto tr282;
		case 94: goto tr269;
		case 95: goto tr272;
		case 97: goto tr283;
		case 100: goto tr284;
		case 101: goto tr277;
		case 104: goto tr285;
		case 109: goto tr286;
		case 112: goto tr287;
		case 115: goto st144;
		case 121: goto tr289;
		case 123: goto tr269;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr269;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr269;
		} else if ( (*p) >= 63 )
			goto tr271;
	} else
		goto tr269;
	goto st0;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	switch( (*p) ) {
		case 35: goto st142;
		case 44: goto st142;
		case 48: goto st142;
		case 63: goto st142;
	}
	goto st0;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	switch( (*p) ) {
		case 34: goto tr270;
		case 35: goto st142;
		case 37: goto tr271;
		case 42: goto tr272;
		case 44: goto st142;
		case 46: goto tr271;
		case 48: goto st142;
		case 59: goto tr274;
		case 63: goto st142;
		case 64: goto tr271;
		case 65: goto tr275;
		case 68: goto tr276;
		case 69: goto tr277;
		case 72: goto tr278;
		case 77: goto tr290;
		case 80: goto tr280;
		case 91: goto tr281;
		case 92: goto tr282;
		case 94: goto tr269;
		case 95: goto tr272;
		case 97: goto tr283;
		case 100: goto tr284;
		case 101: goto tr277;
		case 104: goto tr285;
		case 109: goto tr286;
		case 112: goto tr287;
		case 115: goto tr288;
		case 121: goto tr289;
		case 123: goto tr269;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr269;
	} else if ( (*p) > 62 ) {
		if ( 125 <= (*p) && (*p) <= 126 )
			goto tr269;
	} else
		goto tr269;
	goto st0;
tr176:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st143;
tr196:
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
tr289:
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
#line 3651 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr270;
		case 35: goto tr271;
		case 37: goto tr271;
		case 42: goto tr272;
		case 44: goto tr271;
		case 46: goto tr271;
		case 48: goto tr271;
		case 59: goto tr274;
		case 65: goto tr275;
		case 68: goto tr276;
		case 69: goto tr277;
		case 72: goto tr278;
		case 77: goto tr290;
		case 80: goto tr280;
		case 91: goto tr281;
		case 92: goto tr282;
		case 94: goto tr269;
		case 95: goto tr272;
		case 97: goto tr283;
		case 100: goto tr284;
		case 101: goto tr277;
		case 104: goto tr285;
		case 109: goto tr286;
		case 112: goto tr287;
		case 115: goto tr288;
		case 121: goto st143;
		case 123: goto tr269;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr269;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr269;
		} else if ( (*p) >= 63 )
			goto tr271;
	} else
		goto tr269;
	goto st0;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	switch( (*p) ) {
		case 34: goto tr270;
		case 35: goto tr271;
		case 37: goto tr271;
		case 42: goto tr272;
		case 44: goto tr271;
		case 46: goto st47;
		case 48: goto tr271;
		case 59: goto tr274;
		case 65: goto tr275;
		case 68: goto tr276;
		case 69: goto tr277;
		case 72: goto tr278;
		case 77: goto tr290;
		case 80: goto tr280;
		case 91: goto tr281;
		case 92: goto tr282;
		case 94: goto tr269;
		case 95: goto tr272;
		case 97: goto tr283;
		case 100: goto tr284;
		case 101: goto tr277;
		case 104: goto tr285;
		case 109: goto tr286;
		case 112: goto tr287;
		case 115: goto tr288;
		case 121: goto tr289;
		case 123: goto tr269;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr269;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr269;
		} else if ( (*p) >= 63 )
			goto tr271;
	} else
		goto tr269;
	goto st0;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	switch( (*p) ) {
		case 34: goto tr270;
		case 35: goto tr271;
		case 37: goto tr271;
		case 42: goto tr272;
		case 44: goto tr271;
		case 47: goto st48;
		case 59: goto tr274;
		case 65: goto tr275;
		case 68: goto tr276;
		case 69: goto tr277;
		case 72: goto tr278;
		case 77: goto tr290;
		case 80: goto tr280;
		case 91: goto tr281;
		case 92: goto tr282;
		case 94: goto tr269;
		case 95: goto tr272;
		case 97: goto tr283;
		case 100: goto tr284;
		case 101: goto tr277;
		case 104: goto tr285;
		case 109: goto tr286;
		case 112: goto tr287;
		case 115: goto tr288;
		case 121: goto tr289;
		case 123: goto tr269;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr271;
		} else if ( (*p) >= 32 )
			goto tr269;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr269;
		} else if ( (*p) >= 63 )
			goto tr271;
	} else
		goto tr269;
	goto st0;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	if ( (*p) == 112 )
		goto st49;
	goto st0;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	if ( (*p) == 109 )
		goto st131;
	goto st0;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	switch( (*p) ) {
		case 34: goto tr270;
		case 35: goto tr271;
		case 37: goto tr271;
		case 42: goto tr272;
		case 44: goto tr271;
		case 47: goto st50;
		case 59: goto tr274;
		case 65: goto tr275;
		case 68: goto tr276;
		case 69: goto tr277;
		case 72: goto tr278;
		case 77: goto tr290;
		case 80: goto tr280;
		case 91: goto tr281;
		case 92: goto tr282;
		case 94: goto tr269;
		case 95: goto tr272;
		case 97: goto tr283;
		case 100: goto tr284;
		case 101: goto tr277;
		case 104: goto tr285;
		case 109: goto tr286;
		case 112: goto tr287;
		case 115: goto tr288;
		case 121: goto tr289;
		case 123: goto tr269;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr271;
		} else if ( (*p) >= 32 )
			goto tr269;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr269;
		} else if ( (*p) >= 63 )
			goto tr271;
	} else
		goto tr269;
	goto st0;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	if ( (*p) == 80 )
		goto st51;
	goto st0;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	if ( (*p) == 77 )
		goto st131;
	goto st0;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	switch( (*p) ) {
		case 36: goto st53;
		case 60: goto st38;
		case 61: goto st43;
		case 62: goto st44;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st56;
	} else if ( (*p) >= 65 )
		goto st56;
	goto st0;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	if ( (*p) == 45 )
		goto st54;
	goto st0;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st55;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st55;
	} else
		goto st55;
	goto st0;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	if ( (*p) == 93 )
		goto st109;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st55;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st55;
	} else
		goto st55;
	goto st0;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	if ( (*p) == 93 )
		goto st109;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st56;
	} else if ( (*p) >= 65 )
		goto st56;
	goto st0;
tr123:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st147;
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
	goto st147;
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
	goto st147;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
#line 3957 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr305;
		case 35: goto tr306;
		case 37: goto tr306;
		case 42: goto tr307;
		case 44: goto tr306;
		case 47: goto st57;
		case 59: goto tr309;
		case 65: goto tr310;
		case 68: goto tr311;
		case 69: goto tr312;
		case 72: goto tr313;
		case 77: goto st163;
		case 80: goto tr315;
		case 91: goto tr316;
		case 92: goto tr317;
		case 94: goto tr304;
		case 95: goto tr307;
		case 97: goto tr318;
		case 100: goto tr319;
		case 101: goto tr312;
		case 104: goto tr320;
		case 109: goto tr321;
		case 112: goto tr322;
		case 115: goto tr323;
		case 121: goto tr324;
		case 123: goto tr304;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr306;
		} else if ( (*p) >= 32 )
			goto tr304;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr304;
		} else if ( (*p) >= 63 )
			goto tr306;
	} else
		goto tr304;
	goto st0;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	if ( (*p) == 80 )
		goto st148;
	goto st0;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	switch( (*p) ) {
		case 34: goto tr305;
		case 35: goto tr306;
		case 37: goto tr306;
		case 42: goto tr307;
		case 44: goto tr306;
		case 46: goto tr306;
		case 48: goto tr306;
		case 59: goto tr309;
		case 65: goto tr310;
		case 68: goto tr311;
		case 69: goto tr312;
		case 72: goto tr313;
		case 77: goto tr325;
		case 80: goto tr315;
		case 91: goto tr316;
		case 92: goto tr317;
		case 94: goto tr304;
		case 95: goto tr307;
		case 97: goto tr318;
		case 100: goto tr319;
		case 101: goto tr312;
		case 104: goto tr320;
		case 109: goto tr321;
		case 112: goto tr322;
		case 115: goto tr323;
		case 121: goto tr324;
		case 123: goto tr304;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr304;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr304;
		} else if ( (*p) >= 63 )
			goto tr306;
	} else
		goto tr304;
	goto st0;
tr124:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st149;
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
	goto st149;
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
	goto st149;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
#line 4087 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr305;
		case 35: goto tr306;
		case 37: goto tr306;
		case 42: goto tr307;
		case 44: goto tr306;
		case 46: goto tr306;
		case 48: goto tr306;
		case 59: goto tr309;
		case 65: goto tr310;
		case 68: goto st149;
		case 69: goto tr312;
		case 72: goto tr313;
		case 77: goto tr325;
		case 80: goto tr315;
		case 91: goto tr316;
		case 92: goto tr317;
		case 94: goto tr304;
		case 95: goto tr307;
		case 97: goto tr318;
		case 100: goto tr319;
		case 101: goto tr312;
		case 104: goto tr320;
		case 109: goto tr321;
		case 112: goto tr322;
		case 115: goto tr323;
		case 121: goto tr324;
		case 123: goto tr304;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr304;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr304;
		} else if ( (*p) >= 63 )
			goto tr306;
	} else
		goto tr304;
	goto st0;
tr145:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st58;
tr312:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st58;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
#line 4149 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 43: goto st106;
		case 45: goto st106;
	}
	goto st0;
tr126:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st150;
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
	goto st150;
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
	goto st150;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
#line 4189 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr305;
		case 35: goto tr306;
		case 37: goto tr306;
		case 42: goto tr307;
		case 44: goto tr306;
		case 46: goto tr306;
		case 48: goto tr306;
		case 59: goto tr309;
		case 65: goto tr310;
		case 68: goto tr311;
		case 69: goto tr312;
		case 72: goto st150;
		case 77: goto tr325;
		case 80: goto tr315;
		case 91: goto tr316;
		case 92: goto tr317;
		case 94: goto tr304;
		case 95: goto tr307;
		case 97: goto tr318;
		case 100: goto tr319;
		case 101: goto tr312;
		case 104: goto tr320;
		case 109: goto tr321;
		case 112: goto tr322;
		case 115: goto tr323;
		case 121: goto tr324;
		case 123: goto tr304;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr304;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr304;
		} else if ( (*p) >= 63 )
			goto tr306;
	} else
		goto tr304;
	goto st0;
tr127:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st151;
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
	goto st151;
tr325:
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
	goto st151;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
#line 4265 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr305;
		case 35: goto tr306;
		case 37: goto tr306;
		case 42: goto tr307;
		case 44: goto tr306;
		case 46: goto tr306;
		case 48: goto tr306;
		case 59: goto tr309;
		case 65: goto tr310;
		case 68: goto tr311;
		case 69: goto tr312;
		case 72: goto tr313;
		case 77: goto st151;
		case 80: goto tr315;
		case 91: goto tr316;
		case 92: goto tr317;
		case 94: goto tr304;
		case 95: goto tr307;
		case 97: goto tr318;
		case 100: goto tr319;
		case 101: goto tr312;
		case 104: goto tr320;
		case 109: goto tr321;
		case 112: goto tr322;
		case 115: goto tr323;
		case 121: goto tr324;
		case 123: goto tr304;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr304;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr304;
		} else if ( (*p) >= 63 )
			goto tr306;
	} else
		goto tr304;
	goto st0;
tr128:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st152;
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
	goto st152;
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
	goto st152;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
#line 4341 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr305;
		case 35: goto tr306;
		case 37: goto tr306;
		case 42: goto tr307;
		case 44: goto tr306;
		case 46: goto tr306;
		case 48: goto tr306;
		case 59: goto tr309;
		case 65: goto tr310;
		case 68: goto tr311;
		case 69: goto tr312;
		case 72: goto tr313;
		case 77: goto st148;
		case 80: goto tr315;
		case 91: goto tr316;
		case 92: goto tr317;
		case 94: goto tr304;
		case 95: goto tr307;
		case 97: goto tr318;
		case 100: goto tr319;
		case 101: goto tr312;
		case 104: goto tr320;
		case 109: goto tr321;
		case 112: goto tr322;
		case 115: goto tr323;
		case 121: goto tr324;
		case 123: goto tr304;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr304;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr304;
		} else if ( (*p) >= 63 )
			goto tr306;
	} else
		goto tr304;
	goto st0;
tr149:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st59;
tr316:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st59;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
#line 4403 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 60: goto st60;
		case 61: goto st65;
		case 62: goto st66;
	}
	goto st0;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	switch( (*p) ) {
		case 45: goto st61;
		case 46: goto st62;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 62 )
			goto st65;
	} else if ( (*p) >= 48 )
		goto st64;
	goto st0;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	if ( (*p) == 46 )
		goto st62;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st64;
	goto st0;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st63;
	goto st0;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	if ( (*p) == 93 )
		goto st106;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st63;
	goto st0;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	switch( (*p) ) {
		case 46: goto st62;
		case 93: goto st106;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st64;
	goto st0;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	switch( (*p) ) {
		case 45: goto st61;
		case 46: goto st62;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st64;
	goto st0;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	switch( (*p) ) {
		case 45: goto st61;
		case 46: goto st62;
		case 61: goto st65;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st64;
	goto st0;
tr150:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st67;
tr317:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 4503 "src/tfs_excel_parser.c"
	goto tr57;
tr131:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st153;
tr151:
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
	goto st153;
tr318:
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
	goto st153;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
#line 4539 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr305;
		case 35: goto tr306;
		case 37: goto tr306;
		case 42: goto tr307;
		case 44: goto tr306;
		case 47: goto st68;
		case 59: goto tr309;
		case 65: goto tr310;
		case 68: goto tr311;
		case 69: goto tr312;
		case 72: goto tr313;
		case 77: goto tr325;
		case 80: goto tr315;
		case 91: goto tr316;
		case 92: goto tr317;
		case 94: goto tr304;
		case 95: goto tr307;
		case 97: goto tr318;
		case 100: goto tr319;
		case 101: goto tr312;
		case 104: goto tr320;
		case 109: goto st162;
		case 112: goto tr322;
		case 115: goto tr323;
		case 121: goto tr324;
		case 123: goto tr304;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr306;
		} else if ( (*p) >= 32 )
			goto tr304;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr304;
		} else if ( (*p) >= 63 )
			goto tr306;
	} else
		goto tr304;
	goto st0;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	if ( (*p) == 112 )
		goto st148;
	goto st0;
tr132:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st154;
tr152:
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
tr319:
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
#line 4624 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr305;
		case 35: goto tr306;
		case 37: goto tr306;
		case 42: goto tr307;
		case 44: goto tr306;
		case 46: goto tr306;
		case 48: goto tr306;
		case 59: goto tr309;
		case 65: goto tr310;
		case 68: goto tr311;
		case 69: goto tr312;
		case 72: goto tr313;
		case 77: goto tr325;
		case 80: goto tr315;
		case 91: goto tr316;
		case 92: goto tr317;
		case 94: goto tr304;
		case 95: goto tr307;
		case 97: goto tr318;
		case 100: goto st154;
		case 101: goto tr312;
		case 104: goto tr320;
		case 109: goto tr321;
		case 112: goto tr322;
		case 115: goto tr323;
		case 121: goto tr324;
		case 123: goto tr304;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr304;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr304;
		} else if ( (*p) >= 63 )
			goto tr306;
	} else
		goto tr304;
	goto st0;
tr133:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st155;
tr153:
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
tr320:
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
#line 4700 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr305;
		case 35: goto tr306;
		case 37: goto tr306;
		case 42: goto tr307;
		case 44: goto tr306;
		case 46: goto tr306;
		case 48: goto tr306;
		case 59: goto tr309;
		case 65: goto tr310;
		case 68: goto tr311;
		case 69: goto tr312;
		case 72: goto tr313;
		case 77: goto tr325;
		case 80: goto tr315;
		case 91: goto tr316;
		case 92: goto tr317;
		case 94: goto tr304;
		case 95: goto tr307;
		case 97: goto tr318;
		case 100: goto tr319;
		case 101: goto tr312;
		case 104: goto st155;
		case 109: goto tr321;
		case 112: goto tr322;
		case 115: goto tr323;
		case 121: goto tr324;
		case 123: goto tr304;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr304;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr304;
		} else if ( (*p) >= 63 )
			goto tr306;
	} else
		goto tr304;
	goto st0;
tr134:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st156;
tr154:
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
tr321:
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
#line 4776 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr305;
		case 35: goto tr306;
		case 37: goto tr306;
		case 42: goto tr307;
		case 44: goto tr306;
		case 46: goto tr306;
		case 48: goto tr306;
		case 59: goto tr309;
		case 65: goto tr310;
		case 68: goto tr311;
		case 69: goto tr312;
		case 72: goto tr313;
		case 77: goto tr325;
		case 80: goto tr315;
		case 91: goto tr316;
		case 92: goto tr317;
		case 94: goto tr304;
		case 95: goto tr307;
		case 97: goto tr318;
		case 100: goto tr319;
		case 101: goto tr312;
		case 104: goto tr320;
		case 109: goto st156;
		case 112: goto tr322;
		case 115: goto tr323;
		case 121: goto tr324;
		case 123: goto tr304;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr304;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr304;
		} else if ( (*p) >= 63 )
			goto tr306;
	} else
		goto tr304;
	goto st0;
tr135:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st157;
tr155:
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
tr322:
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
#line 4852 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr305;
		case 35: goto tr306;
		case 37: goto tr306;
		case 42: goto tr307;
		case 44: goto tr306;
		case 46: goto tr306;
		case 48: goto tr306;
		case 59: goto tr309;
		case 65: goto tr310;
		case 68: goto tr311;
		case 69: goto tr312;
		case 72: goto tr313;
		case 77: goto tr325;
		case 80: goto tr315;
		case 91: goto tr316;
		case 92: goto tr317;
		case 94: goto tr304;
		case 95: goto tr307;
		case 97: goto tr318;
		case 100: goto tr319;
		case 101: goto tr312;
		case 104: goto tr320;
		case 109: goto st148;
		case 112: goto tr322;
		case 115: goto tr323;
		case 121: goto tr324;
		case 123: goto tr304;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr304;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr304;
		} else if ( (*p) >= 63 )
			goto tr306;
	} else
		goto tr304;
	goto st0;
tr136:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st158;
tr156:
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
tr323:
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
#line 4928 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr305;
		case 35: goto tr306;
		case 37: goto tr306;
		case 42: goto tr307;
		case 44: goto tr306;
		case 46: goto st69;
		case 48: goto tr306;
		case 59: goto tr309;
		case 65: goto tr310;
		case 68: goto tr311;
		case 69: goto tr312;
		case 72: goto tr313;
		case 77: goto tr325;
		case 80: goto tr315;
		case 91: goto tr316;
		case 92: goto tr317;
		case 94: goto tr304;
		case 95: goto tr307;
		case 97: goto tr318;
		case 100: goto tr319;
		case 101: goto tr312;
		case 104: goto tr320;
		case 109: goto tr321;
		case 112: goto tr322;
		case 115: goto st161;
		case 121: goto tr324;
		case 123: goto tr304;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr304;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr304;
		} else if ( (*p) >= 63 )
			goto tr306;
	} else
		goto tr304;
	goto st0;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	switch( (*p) ) {
		case 35: goto st159;
		case 44: goto st159;
		case 48: goto st159;
		case 63: goto st159;
	}
	goto st0;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
	switch( (*p) ) {
		case 34: goto tr305;
		case 35: goto st159;
		case 37: goto tr306;
		case 42: goto tr307;
		case 44: goto st159;
		case 46: goto tr306;
		case 48: goto st159;
		case 59: goto tr309;
		case 63: goto st159;
		case 64: goto tr306;
		case 65: goto tr310;
		case 68: goto tr311;
		case 69: goto tr312;
		case 72: goto tr313;
		case 77: goto tr325;
		case 80: goto tr315;
		case 91: goto tr316;
		case 92: goto tr317;
		case 94: goto tr304;
		case 95: goto tr307;
		case 97: goto tr318;
		case 100: goto tr319;
		case 101: goto tr312;
		case 104: goto tr320;
		case 109: goto tr321;
		case 112: goto tr322;
		case 115: goto tr323;
		case 121: goto tr324;
		case 123: goto tr304;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr304;
	} else if ( (*p) > 62 ) {
		if ( 125 <= (*p) && (*p) <= 126 )
			goto tr304;
	} else
		goto tr304;
	goto st0;
tr137:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st160;
tr157:
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
tr324:
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
#line 5059 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr305;
		case 35: goto tr306;
		case 37: goto tr306;
		case 42: goto tr307;
		case 44: goto tr306;
		case 46: goto tr306;
		case 48: goto tr306;
		case 59: goto tr309;
		case 65: goto tr310;
		case 68: goto tr311;
		case 69: goto tr312;
		case 72: goto tr313;
		case 77: goto tr325;
		case 80: goto tr315;
		case 91: goto tr316;
		case 92: goto tr317;
		case 94: goto tr304;
		case 95: goto tr307;
		case 97: goto tr318;
		case 100: goto tr319;
		case 101: goto tr312;
		case 104: goto tr320;
		case 109: goto tr321;
		case 112: goto tr322;
		case 115: goto tr323;
		case 121: goto st160;
		case 123: goto tr304;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr304;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr304;
		} else if ( (*p) >= 63 )
			goto tr306;
	} else
		goto tr304;
	goto st0;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
	switch( (*p) ) {
		case 34: goto tr305;
		case 35: goto tr306;
		case 37: goto tr306;
		case 42: goto tr307;
		case 44: goto tr306;
		case 46: goto st69;
		case 48: goto tr306;
		case 59: goto tr309;
		case 65: goto tr310;
		case 68: goto tr311;
		case 69: goto tr312;
		case 72: goto tr313;
		case 77: goto tr325;
		case 80: goto tr315;
		case 91: goto tr316;
		case 92: goto tr317;
		case 94: goto tr304;
		case 95: goto tr307;
		case 97: goto tr318;
		case 100: goto tr319;
		case 101: goto tr312;
		case 104: goto tr320;
		case 109: goto tr321;
		case 112: goto tr322;
		case 115: goto tr323;
		case 121: goto tr324;
		case 123: goto tr304;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr304;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr304;
		} else if ( (*p) >= 63 )
			goto tr306;
	} else
		goto tr304;
	goto st0;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	switch( (*p) ) {
		case 34: goto tr305;
		case 35: goto tr306;
		case 37: goto tr306;
		case 42: goto tr307;
		case 44: goto tr306;
		case 47: goto st70;
		case 59: goto tr309;
		case 65: goto tr310;
		case 68: goto tr311;
		case 69: goto tr312;
		case 72: goto tr313;
		case 77: goto tr325;
		case 80: goto tr315;
		case 91: goto tr316;
		case 92: goto tr317;
		case 94: goto tr304;
		case 95: goto tr307;
		case 97: goto tr318;
		case 100: goto tr319;
		case 101: goto tr312;
		case 104: goto tr320;
		case 109: goto tr321;
		case 112: goto tr322;
		case 115: goto tr323;
		case 121: goto tr324;
		case 123: goto tr304;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr306;
		} else if ( (*p) >= 32 )
			goto tr304;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr304;
		} else if ( (*p) >= 63 )
			goto tr306;
	} else
		goto tr304;
	goto st0;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	if ( (*p) == 112 )
		goto st71;
	goto st0;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	if ( (*p) == 109 )
		goto st148;
	goto st0;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	switch( (*p) ) {
		case 34: goto tr305;
		case 35: goto tr306;
		case 37: goto tr306;
		case 42: goto tr307;
		case 44: goto tr306;
		case 47: goto st72;
		case 59: goto tr309;
		case 65: goto tr310;
		case 68: goto tr311;
		case 69: goto tr312;
		case 72: goto tr313;
		case 77: goto tr325;
		case 80: goto tr315;
		case 91: goto tr316;
		case 92: goto tr317;
		case 94: goto tr304;
		case 95: goto tr307;
		case 97: goto tr318;
		case 100: goto tr319;
		case 101: goto tr312;
		case 104: goto tr320;
		case 109: goto tr321;
		case 112: goto tr322;
		case 115: goto tr323;
		case 121: goto tr324;
		case 123: goto tr304;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr306;
		} else if ( (*p) >= 32 )
			goto tr304;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr304;
		} else if ( (*p) >= 63 )
			goto tr306;
	} else
		goto tr304;
	goto st0;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	if ( (*p) == 80 )
		goto st73;
	goto st0;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	if ( (*p) == 77 )
		goto st148;
	goto st0;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	switch( (*p) ) {
		case 36: goto st75;
		case 60: goto st60;
		case 61: goto st65;
		case 62: goto st66;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st78;
	} else if ( (*p) >= 65 )
		goto st78;
	goto st0;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	if ( (*p) == 45 )
		goto st76;
	goto st0;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st77;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st77;
	} else
		goto st77;
	goto st0;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	if ( (*p) == 93 )
		goto st106;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st77;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st77;
	} else
		goto st77;
	goto st0;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	if ( (*p) == 93 )
		goto st106;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st78;
	} else if ( (*p) >= 65 )
		goto st78;
	goto st0;
tr84:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st164;
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
	goto st164;
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
	goto st164;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
#line 5365 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr340;
		case 35: goto tr341;
		case 37: goto tr341;
		case 42: goto tr342;
		case 44: goto tr341;
		case 47: goto st79;
		case 59: goto tr344;
		case 65: goto tr345;
		case 68: goto tr346;
		case 69: goto tr347;
		case 72: goto tr348;
		case 77: goto st180;
		case 80: goto tr350;
		case 91: goto tr351;
		case 92: goto tr352;
		case 94: goto tr339;
		case 95: goto tr342;
		case 97: goto tr353;
		case 100: goto tr354;
		case 101: goto tr347;
		case 104: goto tr355;
		case 109: goto tr356;
		case 112: goto tr357;
		case 115: goto tr358;
		case 121: goto tr359;
		case 123: goto tr339;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr341;
		} else if ( (*p) >= 32 )
			goto tr339;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr339;
		} else if ( (*p) >= 63 )
			goto tr341;
	} else
		goto tr339;
	goto st0;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	if ( (*p) == 80 )
		goto st165;
	goto st0;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	switch( (*p) ) {
		case 34: goto tr340;
		case 35: goto tr341;
		case 37: goto tr341;
		case 42: goto tr342;
		case 44: goto tr341;
		case 46: goto tr341;
		case 48: goto tr341;
		case 59: goto tr344;
		case 65: goto tr345;
		case 68: goto tr346;
		case 69: goto tr347;
		case 72: goto tr348;
		case 77: goto tr360;
		case 80: goto tr350;
		case 91: goto tr351;
		case 92: goto tr352;
		case 94: goto tr339;
		case 95: goto tr342;
		case 97: goto tr353;
		case 100: goto tr354;
		case 101: goto tr347;
		case 104: goto tr355;
		case 109: goto tr356;
		case 112: goto tr357;
		case 115: goto tr358;
		case 121: goto tr359;
		case 123: goto tr339;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr339;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr339;
		} else if ( (*p) >= 63 )
			goto tr341;
	} else
		goto tr339;
	goto st0;
tr85:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st166;
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
	goto st166;
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
	goto st166;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
#line 5495 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr340;
		case 35: goto tr341;
		case 37: goto tr341;
		case 42: goto tr342;
		case 44: goto tr341;
		case 46: goto tr341;
		case 48: goto tr341;
		case 59: goto tr344;
		case 65: goto tr345;
		case 68: goto st166;
		case 69: goto tr347;
		case 72: goto tr348;
		case 77: goto tr360;
		case 80: goto tr350;
		case 91: goto tr351;
		case 92: goto tr352;
		case 94: goto tr339;
		case 95: goto tr342;
		case 97: goto tr353;
		case 100: goto tr354;
		case 101: goto tr347;
		case 104: goto tr355;
		case 109: goto tr356;
		case 112: goto tr357;
		case 115: goto tr358;
		case 121: goto tr359;
		case 123: goto tr339;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr339;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr339;
		} else if ( (*p) >= 63 )
			goto tr341;
	} else
		goto tr339;
	goto st0;
tr106:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st80;
tr347:
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
#line 5557 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 43: goto st103;
		case 45: goto st103;
	}
	goto st0;
tr87:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st167;
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
	goto st167;
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
	goto st167;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
#line 5597 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr340;
		case 35: goto tr341;
		case 37: goto tr341;
		case 42: goto tr342;
		case 44: goto tr341;
		case 46: goto tr341;
		case 48: goto tr341;
		case 59: goto tr344;
		case 65: goto tr345;
		case 68: goto tr346;
		case 69: goto tr347;
		case 72: goto st167;
		case 77: goto tr360;
		case 80: goto tr350;
		case 91: goto tr351;
		case 92: goto tr352;
		case 94: goto tr339;
		case 95: goto tr342;
		case 97: goto tr353;
		case 100: goto tr354;
		case 101: goto tr347;
		case 104: goto tr355;
		case 109: goto tr356;
		case 112: goto tr357;
		case 115: goto tr358;
		case 121: goto tr359;
		case 123: goto tr339;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr339;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr339;
		} else if ( (*p) >= 63 )
			goto tr341;
	} else
		goto tr339;
	goto st0;
tr88:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st168;
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
	goto st168;
tr360:
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
	goto st168;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
#line 5673 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr340;
		case 35: goto tr341;
		case 37: goto tr341;
		case 42: goto tr342;
		case 44: goto tr341;
		case 46: goto tr341;
		case 48: goto tr341;
		case 59: goto tr344;
		case 65: goto tr345;
		case 68: goto tr346;
		case 69: goto tr347;
		case 72: goto tr348;
		case 77: goto st168;
		case 80: goto tr350;
		case 91: goto tr351;
		case 92: goto tr352;
		case 94: goto tr339;
		case 95: goto tr342;
		case 97: goto tr353;
		case 100: goto tr354;
		case 101: goto tr347;
		case 104: goto tr355;
		case 109: goto tr356;
		case 112: goto tr357;
		case 115: goto tr358;
		case 121: goto tr359;
		case 123: goto tr339;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr339;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr339;
		} else if ( (*p) >= 63 )
			goto tr341;
	} else
		goto tr339;
	goto st0;
tr89:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st169;
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
	goto st169;
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
	goto st169;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
#line 5749 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr340;
		case 35: goto tr341;
		case 37: goto tr341;
		case 42: goto tr342;
		case 44: goto tr341;
		case 46: goto tr341;
		case 48: goto tr341;
		case 59: goto tr344;
		case 65: goto tr345;
		case 68: goto tr346;
		case 69: goto tr347;
		case 72: goto tr348;
		case 77: goto st165;
		case 80: goto tr350;
		case 91: goto tr351;
		case 92: goto tr352;
		case 94: goto tr339;
		case 95: goto tr342;
		case 97: goto tr353;
		case 100: goto tr354;
		case 101: goto tr347;
		case 104: goto tr355;
		case 109: goto tr356;
		case 112: goto tr357;
		case 115: goto tr358;
		case 121: goto tr359;
		case 123: goto tr339;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr339;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr339;
		} else if ( (*p) >= 63 )
			goto tr341;
	} else
		goto tr339;
	goto st0;
tr110:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st81;
tr351:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st81;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
#line 5811 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 60: goto st82;
		case 61: goto st87;
		case 62: goto st88;
	}
	goto st0;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	switch( (*p) ) {
		case 45: goto st83;
		case 46: goto st84;
	}
	if ( (*p) > 57 ) {
		if ( 61 <= (*p) && (*p) <= 62 )
			goto st87;
	} else if ( (*p) >= 48 )
		goto st86;
	goto st0;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	if ( (*p) == 46 )
		goto st84;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st86;
	goto st0;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st85;
	goto st0;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	if ( (*p) == 93 )
		goto st103;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st85;
	goto st0;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	switch( (*p) ) {
		case 46: goto st84;
		case 93: goto st103;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st86;
	goto st0;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	switch( (*p) ) {
		case 45: goto st83;
		case 46: goto st84;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st86;
	goto st0;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	switch( (*p) ) {
		case 45: goto st83;
		case 46: goto st84;
		case 61: goto st87;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st86;
	goto st0;
tr111:
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st89;
tr352:
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	goto st89;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
#line 5911 "src/tfs_excel_parser.c"
	goto tr73;
tr92:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st170;
tr112:
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
	goto st170;
tr353:
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
	goto st170;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
#line 5947 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr340;
		case 35: goto tr341;
		case 37: goto tr341;
		case 42: goto tr342;
		case 44: goto tr341;
		case 47: goto st90;
		case 59: goto tr344;
		case 65: goto tr345;
		case 68: goto tr346;
		case 69: goto tr347;
		case 72: goto tr348;
		case 77: goto tr360;
		case 80: goto tr350;
		case 91: goto tr351;
		case 92: goto tr352;
		case 94: goto tr339;
		case 95: goto tr342;
		case 97: goto tr353;
		case 100: goto tr354;
		case 101: goto tr347;
		case 104: goto tr355;
		case 109: goto st179;
		case 112: goto tr357;
		case 115: goto tr358;
		case 121: goto tr359;
		case 123: goto tr339;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr341;
		} else if ( (*p) >= 32 )
			goto tr339;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr339;
		} else if ( (*p) >= 63 )
			goto tr341;
	} else
		goto tr339;
	goto st0;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	if ( (*p) == 112 )
		goto st165;
	goto st0;
tr93:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st171;
tr113:
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
	goto st171;
tr354:
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
	goto st171;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
#line 6032 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr340;
		case 35: goto tr341;
		case 37: goto tr341;
		case 42: goto tr342;
		case 44: goto tr341;
		case 46: goto tr341;
		case 48: goto tr341;
		case 59: goto tr344;
		case 65: goto tr345;
		case 68: goto tr346;
		case 69: goto tr347;
		case 72: goto tr348;
		case 77: goto tr360;
		case 80: goto tr350;
		case 91: goto tr351;
		case 92: goto tr352;
		case 94: goto tr339;
		case 95: goto tr342;
		case 97: goto tr353;
		case 100: goto st171;
		case 101: goto tr347;
		case 104: goto tr355;
		case 109: goto tr356;
		case 112: goto tr357;
		case 115: goto tr358;
		case 121: goto tr359;
		case 123: goto tr339;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr339;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr339;
		} else if ( (*p) >= 63 )
			goto tr341;
	} else
		goto tr339;
	goto st0;
tr94:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st172;
tr114:
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
	goto st172;
tr355:
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
	goto st172;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
#line 6108 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr340;
		case 35: goto tr341;
		case 37: goto tr341;
		case 42: goto tr342;
		case 44: goto tr341;
		case 46: goto tr341;
		case 48: goto tr341;
		case 59: goto tr344;
		case 65: goto tr345;
		case 68: goto tr346;
		case 69: goto tr347;
		case 72: goto tr348;
		case 77: goto tr360;
		case 80: goto tr350;
		case 91: goto tr351;
		case 92: goto tr352;
		case 94: goto tr339;
		case 95: goto tr342;
		case 97: goto tr353;
		case 100: goto tr354;
		case 101: goto tr347;
		case 104: goto st172;
		case 109: goto tr356;
		case 112: goto tr357;
		case 115: goto tr358;
		case 121: goto tr359;
		case 123: goto tr339;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr339;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr339;
		} else if ( (*p) >= 63 )
			goto tr341;
	} else
		goto tr339;
	goto st0;
tr95:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st173;
tr115:
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
	goto st173;
tr356:
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
	goto st173;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
#line 6184 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr340;
		case 35: goto tr341;
		case 37: goto tr341;
		case 42: goto tr342;
		case 44: goto tr341;
		case 46: goto tr341;
		case 48: goto tr341;
		case 59: goto tr344;
		case 65: goto tr345;
		case 68: goto tr346;
		case 69: goto tr347;
		case 72: goto tr348;
		case 77: goto tr360;
		case 80: goto tr350;
		case 91: goto tr351;
		case 92: goto tr352;
		case 94: goto tr339;
		case 95: goto tr342;
		case 97: goto tr353;
		case 100: goto tr354;
		case 101: goto tr347;
		case 104: goto tr355;
		case 109: goto st173;
		case 112: goto tr357;
		case 115: goto tr358;
		case 121: goto tr359;
		case 123: goto tr339;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr339;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr339;
		} else if ( (*p) >= 63 )
			goto tr341;
	} else
		goto tr339;
	goto st0;
tr96:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st174;
tr116:
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
	goto st174;
tr357:
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
	goto st174;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
#line 6260 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr340;
		case 35: goto tr341;
		case 37: goto tr341;
		case 42: goto tr342;
		case 44: goto tr341;
		case 46: goto tr341;
		case 48: goto tr341;
		case 59: goto tr344;
		case 65: goto tr345;
		case 68: goto tr346;
		case 69: goto tr347;
		case 72: goto tr348;
		case 77: goto tr360;
		case 80: goto tr350;
		case 91: goto tr351;
		case 92: goto tr352;
		case 94: goto tr339;
		case 95: goto tr342;
		case 97: goto tr353;
		case 100: goto tr354;
		case 101: goto tr347;
		case 104: goto tr355;
		case 109: goto st165;
		case 112: goto tr357;
		case 115: goto tr358;
		case 121: goto tr359;
		case 123: goto tr339;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr339;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr339;
		} else if ( (*p) >= 63 )
			goto tr341;
	} else
		goto tr339;
	goto st0;
tr97:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st175;
tr117:
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
	goto st175;
tr358:
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
	goto st175;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
#line 6336 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr340;
		case 35: goto tr341;
		case 37: goto tr341;
		case 42: goto tr342;
		case 44: goto tr341;
		case 46: goto st91;
		case 48: goto tr341;
		case 59: goto tr344;
		case 65: goto tr345;
		case 68: goto tr346;
		case 69: goto tr347;
		case 72: goto tr348;
		case 77: goto tr360;
		case 80: goto tr350;
		case 91: goto tr351;
		case 92: goto tr352;
		case 94: goto tr339;
		case 95: goto tr342;
		case 97: goto tr353;
		case 100: goto tr354;
		case 101: goto tr347;
		case 104: goto tr355;
		case 109: goto tr356;
		case 112: goto tr357;
		case 115: goto st178;
		case 121: goto tr359;
		case 123: goto tr339;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr339;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr339;
		} else if ( (*p) >= 63 )
			goto tr341;
	} else
		goto tr339;
	goto st0;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	switch( (*p) ) {
		case 35: goto st176;
		case 44: goto st176;
		case 48: goto st176;
		case 63: goto st176;
	}
	goto st0;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
	switch( (*p) ) {
		case 34: goto tr340;
		case 35: goto st176;
		case 37: goto tr341;
		case 42: goto tr342;
		case 44: goto st176;
		case 46: goto tr341;
		case 48: goto st176;
		case 59: goto tr344;
		case 63: goto st176;
		case 64: goto tr341;
		case 65: goto tr345;
		case 68: goto tr346;
		case 69: goto tr347;
		case 72: goto tr348;
		case 77: goto tr360;
		case 80: goto tr350;
		case 91: goto tr351;
		case 92: goto tr352;
		case 94: goto tr339;
		case 95: goto tr342;
		case 97: goto tr353;
		case 100: goto tr354;
		case 101: goto tr347;
		case 104: goto tr355;
		case 109: goto tr356;
		case 112: goto tr357;
		case 115: goto tr358;
		case 121: goto tr359;
		case 123: goto tr339;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr339;
	} else if ( (*p) > 62 ) {
		if ( 125 <= (*p) && (*p) <= 126 )
			goto tr339;
	} else
		goto tr339;
	goto st0;
tr98:
#line 31 "src/tfs_excel_parser.rl"
	{
           str_start = p;
       }
	goto st177;
tr118:
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
	goto st177;
tr359:
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
	goto st177;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
#line 6467 "src/tfs_excel_parser.c"
	switch( (*p) ) {
		case 34: goto tr340;
		case 35: goto tr341;
		case 37: goto tr341;
		case 42: goto tr342;
		case 44: goto tr341;
		case 46: goto tr341;
		case 48: goto tr341;
		case 59: goto tr344;
		case 65: goto tr345;
		case 68: goto tr346;
		case 69: goto tr347;
		case 72: goto tr348;
		case 77: goto tr360;
		case 80: goto tr350;
		case 91: goto tr351;
		case 92: goto tr352;
		case 94: goto tr339;
		case 95: goto tr342;
		case 97: goto tr353;
		case 100: goto tr354;
		case 101: goto tr347;
		case 104: goto tr355;
		case 109: goto tr356;
		case 112: goto tr357;
		case 115: goto tr358;
		case 121: goto st177;
		case 123: goto tr339;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr339;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr339;
		} else if ( (*p) >= 63 )
			goto tr341;
	} else
		goto tr339;
	goto st0;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
	switch( (*p) ) {
		case 34: goto tr340;
		case 35: goto tr341;
		case 37: goto tr341;
		case 42: goto tr342;
		case 44: goto tr341;
		case 46: goto st91;
		case 48: goto tr341;
		case 59: goto tr344;
		case 65: goto tr345;
		case 68: goto tr346;
		case 69: goto tr347;
		case 72: goto tr348;
		case 77: goto tr360;
		case 80: goto tr350;
		case 91: goto tr351;
		case 92: goto tr352;
		case 94: goto tr339;
		case 95: goto tr342;
		case 97: goto tr353;
		case 100: goto tr354;
		case 101: goto tr347;
		case 104: goto tr355;
		case 109: goto tr356;
		case 112: goto tr357;
		case 115: goto tr358;
		case 121: goto tr359;
		case 123: goto tr339;
	}
	if ( (*p) < 58 ) {
		if ( 32 <= (*p) && (*p) <= 47 )
			goto tr339;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr339;
		} else if ( (*p) >= 63 )
			goto tr341;
	} else
		goto tr339;
	goto st0;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	switch( (*p) ) {
		case 34: goto tr340;
		case 35: goto tr341;
		case 37: goto tr341;
		case 42: goto tr342;
		case 44: goto tr341;
		case 47: goto st92;
		case 59: goto tr344;
		case 65: goto tr345;
		case 68: goto tr346;
		case 69: goto tr347;
		case 72: goto tr348;
		case 77: goto tr360;
		case 80: goto tr350;
		case 91: goto tr351;
		case 92: goto tr352;
		case 94: goto tr339;
		case 95: goto tr342;
		case 97: goto tr353;
		case 100: goto tr354;
		case 101: goto tr347;
		case 104: goto tr355;
		case 109: goto tr356;
		case 112: goto tr357;
		case 115: goto tr358;
		case 121: goto tr359;
		case 123: goto tr339;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr341;
		} else if ( (*p) >= 32 )
			goto tr339;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr339;
		} else if ( (*p) >= 63 )
			goto tr341;
	} else
		goto tr339;
	goto st0;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	if ( (*p) == 112 )
		goto st93;
	goto st0;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	if ( (*p) == 109 )
		goto st165;
	goto st0;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	switch( (*p) ) {
		case 34: goto tr340;
		case 35: goto tr341;
		case 37: goto tr341;
		case 42: goto tr342;
		case 44: goto tr341;
		case 47: goto st94;
		case 59: goto tr344;
		case 65: goto tr345;
		case 68: goto tr346;
		case 69: goto tr347;
		case 72: goto tr348;
		case 77: goto tr360;
		case 80: goto tr350;
		case 91: goto tr351;
		case 92: goto tr352;
		case 94: goto tr339;
		case 95: goto tr342;
		case 97: goto tr353;
		case 100: goto tr354;
		case 101: goto tr347;
		case 104: goto tr355;
		case 109: goto tr356;
		case 112: goto tr357;
		case 115: goto tr358;
		case 121: goto tr359;
		case 123: goto tr339;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 45 ) {
			if ( 46 <= (*p) && (*p) <= 48 )
				goto tr341;
		} else if ( (*p) >= 32 )
			goto tr339;
	} else if ( (*p) > 62 ) {
		if ( (*p) > 64 ) {
			if ( 125 <= (*p) && (*p) <= 126 )
				goto tr339;
		} else if ( (*p) >= 63 )
			goto tr341;
	} else
		goto tr339;
	goto st0;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	if ( (*p) == 80 )
		goto st95;
	goto st0;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	if ( (*p) == 77 )
		goto st165;
	goto st0;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	switch( (*p) ) {
		case 36: goto st97;
		case 60: goto st82;
		case 61: goto st87;
		case 62: goto st88;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st100;
	} else if ( (*p) >= 65 )
		goto st100;
	goto st0;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	if ( (*p) == 45 )
		goto st98;
	goto st0;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st99;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st99;
	} else
		goto st99;
	goto st0;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	if ( (*p) == 93 )
		goto st103;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st99;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st99;
	} else
		goto st99;
	goto st0;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	if ( (*p) == 93 )
		goto st103;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st100;
	} else if ( (*p) >= 65 )
		goto st100;
	goto st0;
	}
	_test_eof102: cs = 102; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof103: cs = 103; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof104: cs = 104; goto _test_eof; 
	_test_eof105: cs = 105; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof106: cs = 106; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof107: cs = 107; goto _test_eof; 
	_test_eof108: cs = 108; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof109: cs = 109; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof110: cs = 110; goto _test_eof; 
	_test_eof111: cs = 111; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof112: cs = 112; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof113: cs = 113; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof114: cs = 114; goto _test_eof; 
	_test_eof115: cs = 115; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof116: cs = 116; goto _test_eof; 
	_test_eof117: cs = 117; goto _test_eof; 
	_test_eof118: cs = 118; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof119: cs = 119; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof120: cs = 120; goto _test_eof; 
	_test_eof121: cs = 121; goto _test_eof; 
	_test_eof122: cs = 122; goto _test_eof; 
	_test_eof123: cs = 123; goto _test_eof; 
	_test_eof124: cs = 124; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof125: cs = 125; goto _test_eof; 
	_test_eof126: cs = 126; goto _test_eof; 
	_test_eof127: cs = 127; goto _test_eof; 
	_test_eof128: cs = 128; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof129: cs = 129; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof130: cs = 130; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof131: cs = 131; goto _test_eof; 
	_test_eof132: cs = 132; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof133: cs = 133; goto _test_eof; 
	_test_eof134: cs = 134; goto _test_eof; 
	_test_eof135: cs = 135; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof136: cs = 136; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof137: cs = 137; goto _test_eof; 
	_test_eof138: cs = 138; goto _test_eof; 
	_test_eof139: cs = 139; goto _test_eof; 
	_test_eof140: cs = 140; goto _test_eof; 
	_test_eof141: cs = 141; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof142: cs = 142; goto _test_eof; 
	_test_eof143: cs = 143; goto _test_eof; 
	_test_eof144: cs = 144; goto _test_eof; 
	_test_eof145: cs = 145; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof146: cs = 146; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof147: cs = 147; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof148: cs = 148; goto _test_eof; 
	_test_eof149: cs = 149; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof150: cs = 150; goto _test_eof; 
	_test_eof151: cs = 151; goto _test_eof; 
	_test_eof152: cs = 152; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof153: cs = 153; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof154: cs = 154; goto _test_eof; 
	_test_eof155: cs = 155; goto _test_eof; 
	_test_eof156: cs = 156; goto _test_eof; 
	_test_eof157: cs = 157; goto _test_eof; 
	_test_eof158: cs = 158; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof159: cs = 159; goto _test_eof; 
	_test_eof160: cs = 160; goto _test_eof; 
	_test_eof161: cs = 161; goto _test_eof; 
	_test_eof162: cs = 162; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof163: cs = 163; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof73: cs = 73; goto _test_eof; 
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof75: cs = 75; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof164: cs = 164; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof165: cs = 165; goto _test_eof; 
	_test_eof166: cs = 166; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof167: cs = 167; goto _test_eof; 
	_test_eof168: cs = 168; goto _test_eof; 
	_test_eof169: cs = 169; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof86: cs = 86; goto _test_eof; 
	_test_eof87: cs = 87; goto _test_eof; 
	_test_eof88: cs = 88; goto _test_eof; 
	_test_eof89: cs = 89; goto _test_eof; 
	_test_eof170: cs = 170; goto _test_eof; 
	_test_eof90: cs = 90; goto _test_eof; 
	_test_eof171: cs = 171; goto _test_eof; 
	_test_eof172: cs = 172; goto _test_eof; 
	_test_eof173: cs = 173; goto _test_eof; 
	_test_eof174: cs = 174; goto _test_eof; 
	_test_eof175: cs = 175; goto _test_eof; 
	_test_eof91: cs = 91; goto _test_eof; 
	_test_eof176: cs = 176; goto _test_eof; 
	_test_eof177: cs = 177; goto _test_eof; 
	_test_eof178: cs = 178; goto _test_eof; 
	_test_eof179: cs = 179; goto _test_eof; 
	_test_eof92: cs = 92; goto _test_eof; 
	_test_eof93: cs = 93; goto _test_eof; 
	_test_eof180: cs = 180; goto _test_eof; 
	_test_eof94: cs = 94; goto _test_eof; 
	_test_eof95: cs = 95; goto _test_eof; 
	_test_eof96: cs = 96; goto _test_eof; 
	_test_eof97: cs = 97; goto _test_eof; 
	_test_eof98: cs = 98; goto _test_eof; 
	_test_eof99: cs = 99; goto _test_eof; 
	_test_eof100: cs = 100; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
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
	case 173: 
	case 174: 
	case 175: 
	case 176: 
	case 177: 
	case 178: 
	case 179: 
	case 180: 
#line 35 "src/tfs_excel_parser.rl"
	{
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	break;
	case 102: 
	case 105: 
	case 108: 
	case 111: 
#line 41 "src/tfs_excel_parser.rl"
	{
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, p - str_start, user_ctx);
           }
       }
	break;
#line 7010 "src/tfs_excel_parser.c"
	}
	}

	_out: {}
	}

#line 103 "src/tfs_excel_parser.rl"


    if (cs < 101) {
        printf("Error parsing Excel format string '%s' around col #%ld (%c)\n",
            bytes, (long)(p - bytes + 1), *p);
        return 1;
    }

    return 0;
}
