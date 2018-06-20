
#line 1 "src/tfs_stata_parser.rl"

#include <sys/types.h>
#include <stdio.h>

#include "tfs.h"
#include "tfs_internal.h"
#include "tfs_stata_parser.h"

/* See http://www.stata.com/help.cgi?datetime_display_formats */


#line 15 "src/tfs_stata_parser.c"
static const char _stata_format_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 2, 1, 0, 2, 2, 0, 2, 
	3, 0
};

static const short _stata_format_key_offsets[] = {
	0, 0, 2, 4, 5, 6, 7, 10, 
	11, 12, 13, 14, 15, 17, 18, 19, 
	21, 22, 23, 24, 25, 26, 28, 29, 
	30, 32, 33, 34, 36, 37, 38, 39, 
	40, 41, 42, 43, 44, 73, 102, 131, 
	160, 189, 219, 248, 277, 306, 335, 364
};

static const char _stata_format_trans_keys[] = {
	-128, -1, 46, 77, 77, 46, 67, 65, 
	68, 97, 89, 78, 65, 77, 69, 72, 
	104, 74, 74, 77, 111, 110, 78, 83, 
	87, 89, 46, 109, 109, 99, 97, 100, 
	106, 106, 109, 111, 110, 115, 119, 121, 
	104, 97, 109, 101, 33, 43, 46, 58, 
	65, 67, 68, 72, 74, 77, 78, 83, 
	87, 89, 92, 95, 97, 99, 100, 104, 
	106, 109, 110, 113, 115, 119, 121, 44, 
	47, 33, 43, 46, 58, 65, 67, 68, 
	72, 74, 77, 78, 83, 87, 89, 92, 
	95, 97, 99, 100, 104, 106, 109, 110, 
	113, 115, 119, 121, 44, 47, 33, 43, 
	46, 58, 65, 67, 68, 72, 74, 77, 
	78, 83, 87, 89, 92, 95, 97, 99, 
	100, 104, 106, 109, 110, 113, 115, 119, 
	121, 44, 47, 33, 43, 46, 58, 65, 
	67, 68, 72, 74, 77, 78, 83, 87, 
	89, 92, 95, 97, 99, 100, 104, 106, 
	109, 110, 113, 115, 119, 121, 44, 47, 
	33, 43, 46, 58, 65, 67, 68, 72, 
	74, 77, 78, 83, 87, 89, 92, 95, 
	97, 99, 100, 104, 106, 109, 110, 113, 
	115, 119, 121, 44, 47, 33, 43, 46, 
	58, 65, 67, 68, 72, 74, 77, 78, 
	83, 87, 89, 92, 95, 97, 99, 100, 
	104, 106, 109, 110, 113, 115, 116, 119, 
	121, 44, 47, 33, 43, 46, 58, 65, 
	67, 68, 72, 74, 77, 78, 83, 87, 
	89, 92, 95, 97, 99, 100, 104, 106, 
	109, 110, 113, 115, 119, 121, 44, 47, 
	33, 43, 46, 58, 65, 67, 68, 72, 
	74, 77, 78, 83, 87, 89, 92, 95, 
	97, 99, 100, 104, 106, 109, 110, 113, 
	115, 119, 121, 44, 47, 33, 43, 46, 
	58, 65, 67, 68, 72, 74, 77, 78, 
	83, 87, 89, 92, 95, 97, 99, 100, 
	104, 106, 109, 110, 113, 115, 119, 121, 
	44, 47, 33, 43, 46, 58, 65, 67, 
	68, 72, 74, 77, 78, 83, 87, 89, 
	92, 95, 97, 99, 100, 104, 106, 109, 
	110, 113, 115, 119, 121, 44, 47, 33, 
	43, 46, 58, 65, 67, 68, 72, 74, 
	77, 78, 83, 87, 89, 92, 95, 97, 
	99, 100, 104, 106, 109, 110, 113, 115, 
	119, 121, 44, 47, 33, 43, 46, 58, 
	65, 67, 68, 72, 74, 77, 78, 83, 
	87, 89, 92, 95, 97, 99, 100, 104, 
	106, 109, 110, 113, 115, 119, 121, 44, 
	47, 0
};

static const char _stata_format_single_lengths[] = {
	0, 0, 2, 1, 1, 1, 3, 1, 
	1, 1, 1, 1, 2, 1, 1, 2, 
	1, 1, 1, 1, 1, 2, 1, 1, 
	2, 1, 1, 2, 1, 1, 1, 1, 
	1, 1, 1, 1, 27, 27, 27, 27, 
	27, 28, 27, 27, 27, 27, 27, 27
};

static const char _stata_format_range_lengths[] = {
	0, 1, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1
};

static const short _stata_format_index_offsets[] = {
	0, 0, 2, 5, 7, 9, 11, 15, 
	17, 19, 21, 23, 25, 28, 30, 32, 
	35, 37, 39, 41, 43, 45, 48, 50, 
	52, 55, 57, 59, 62, 64, 66, 68, 
	70, 72, 74, 76, 78, 107, 136, 165, 
	194, 223, 253, 282, 311, 340, 369, 398
};

static const char _stata_format_indicies[] = {
	1, 0, 2, 3, 1, 4, 1, 3, 
	1, 3, 1, 5, 3, 6, 1, 7, 
	1, 8, 1, 9, 1, 10, 1, 3, 
	1, 3, 3, 1, 11, 1, 3, 1, 
	3, 12, 1, 13, 1, 3, 1, 3, 
	1, 3, 1, 3, 1, 14, 3, 1, 
	4, 1, 3, 1, 15, 3, 1, 16, 
	1, 3, 1, 3, 12, 1, 3, 1, 
	3, 1, 3, 1, 3, 1, 3, 1, 
	17, 1, 18, 1, 3, 1, 19, 20, 
	21, 0, 22, 23, 24, 25, 26, 27, 
	28, 29, 30, 31, 0, 32, 33, 34, 
	35, 36, 37, 38, 39, 40, 41, 42, 
	43, 0, 1, 44, 45, 47, 46, 48, 
	49, 50, 51, 52, 53, 54, 55, 56, 
	57, 46, 58, 59, 60, 61, 62, 63, 
	64, 65, 66, 67, 68, 69, 46, 1, 
	44, 45, 47, 46, 48, 49, 50, 51, 
	52, 53, 54, 55, 56, 57, 46, 58, 
	59, 60, 61, 62, 63, 64, 65, 66, 
	70, 68, 69, 46, 1, 71, 72, 74, 
	73, 75, 76, 77, 78, 79, 80, 81, 
	82, 83, 84, 73, 85, 86, 87, 88, 
	89, 90, 91, 92, 93, 94, 95, 96, 
	73, 1, 71, 72, 74, 73, 75, 76, 
	77, 78, 79, 80, 81, 82, 83, 84, 
	73, 85, 86, 87, 88, 89, 90, 91, 
	92, 93, 94, 95, 97, 73, 1, 71, 
	72, 74, 73, 75, 76, 77, 78, 79, 
	80, 81, 82, 83, 84, 73, 85, 86, 
	87, 88, 89, 90, 91, 92, 93, 94, 
	98, 95, 96, 73, 1, 99, 100, 102, 
	101, 103, 104, 105, 106, 107, 108, 109, 
	110, 111, 112, 101, 113, 114, 115, 116, 
	117, 118, 119, 120, 121, 122, 123, 124, 
	101, 1, 71, 72, 74, 73, 75, 76, 
	77, 78, 79, 80, 81, 82, 83, 84, 
	73, 85, 86, 87, 88, 89, 90, 91, 
	92, 93, 94, 95, 3, 73, 1, 71, 
	72, 74, 73, 75, 76, 77, 3, 79, 
	80, 81, 82, 83, 84, 73, 85, 86, 
	87, 88, 3, 90, 91, 92, 93, 94, 
	95, 96, 73, 1, 71, 72, 74, 73, 
	75, 76, 77, 78, 79, 80, 81, 82, 
	83, 84, 73, 85, 86, 87, 88, 89, 
	90, 91, 125, 93, 94, 95, 96, 73, 
	1, 71, 72, 74, 73, 75, 76, 77, 
	78, 79, 80, 81, 82, 83, 84, 73, 
	85, 86, 87, 88, 89, 90, 91, 92, 
	93, 126, 95, 96, 73, 1, 71, 72, 
	74, 73, 75, 76, 77, 78, 79, 80, 
	81, 82, 83, 84, 73, 85, 86, 87, 
	88, 89, 90, 91, 92, 93, 3, 95, 
	96, 73, 1, 0
};

static const char _stata_format_trans_targs[] = {
	37, 0, 3, 39, 4, 7, 40, 8, 
	9, 10, 11, 14, 16, 41, 22, 43, 
	26, 34, 35, 1, 36, 38, 2, 5, 
	6, 12, 13, 15, 17, 18, 19, 20, 
	42, 21, 23, 24, 44, 25, 27, 28, 
	39, 29, 30, 31, 1, 36, 37, 38, 
	2, 5, 6, 12, 13, 15, 17, 18, 
	19, 20, 42, 21, 23, 24, 44, 25, 
	27, 28, 39, 29, 30, 31, 46, 1, 
	36, 37, 38, 2, 5, 6, 12, 13, 
	15, 17, 18, 19, 20, 42, 21, 23, 
	24, 44, 25, 27, 28, 39, 29, 30, 
	31, 45, 32, 1, 36, 37, 38, 2, 
	5, 6, 12, 13, 15, 17, 18, 19, 
	20, 42, 21, 23, 24, 44, 25, 27, 
	28, 39, 29, 30, 31, 33, 47
};

static const char _stata_format_trans_actions[] = {
	1, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	0, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 5, 5, 12, 12, 
	12, 12, 12, 12, 12, 12, 12, 12, 
	12, 12, 5, 12, 12, 12, 12, 12, 
	12, 12, 12, 12, 12, 12, 0, 3, 
	3, 9, 9, 9, 9, 9, 9, 9, 
	9, 9, 9, 9, 9, 3, 9, 9, 
	9, 9, 9, 9, 9, 9, 9, 9, 
	9, 0, 0, 7, 7, 15, 15, 15, 
	15, 15, 15, 15, 15, 15, 15, 15, 
	15, 7, 15, 15, 15, 15, 15, 15, 
	15, 15, 15, 15, 15, 0, 0
};

static const char _stata_format_eof_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 5, 5, 3, 
	3, 3, 7, 3, 3, 3, 3, 3
};

static const int stata_format_start = 36;

static const int stata_format_en_main = 36;


#line 14 "src/tfs_stata_parser.rl"


tfs_error_e tfs_parse_stata_format_string_internal(
        const unsigned char *bytes, size_t len,
        tfs_parse_ctx_t *ctx) {
    unsigned char *p = (unsigned char *)bytes;
    unsigned char *pe = (unsigned char *)bytes + len;
    unsigned char *str_start = NULL;

    unsigned char *eof = pe;

    int cs;

   
#line 235 "src/tfs_stata_parser.c"
	{
	cs = stata_format_start;
	}

#line 240 "src/tfs_stata_parser.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _stata_format_trans_keys + _stata_format_key_offsets[cs];
	_trans = _stata_format_index_offsets[cs];

	_klen = _stata_format_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _stata_format_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _stata_format_indicies[_trans];
	cs = _stata_format_trans_targs[_trans];

	if ( _stata_format_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _stata_format_actions + _stata_format_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 28 "src/tfs_stata_parser.rl"
	{
           str_start = p;
       }
	break;
	case 1:
#line 31 "src/tfs_stata_parser.rl"
	{
           if (ctx->handle_code) {
               ctx->handle_code((char *)str_start, p - str_start, ctx->user_ctx);
           }
       }
	break;
	case 2:
#line 37 "src/tfs_stata_parser.rl"
	{
           if (ctx->handle_literal) {
               ctx->handle_literal((char *)str_start, p - str_start, ctx->user_ctx);
           }
       }
	break;
	case 3:
#line 43 "src/tfs_stata_parser.rl"
	{
           if (ctx->handle_literal) {
               ctx->handle_literal(" ", 1, ctx->user_ctx);
           }
       }
	break;
#line 344 "src/tfs_stata_parser.c"
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	const char *__acts = _stata_format_actions + _stata_format_eof_actions[cs];
	unsigned int __nacts = (unsigned int) *__acts++;
	while ( __nacts-- > 0 ) {
		switch ( *__acts++ ) {
	case 1:
#line 31 "src/tfs_stata_parser.rl"
	{
           if (ctx->handle_code) {
               ctx->handle_code((char *)str_start, p - str_start, ctx->user_ctx);
           }
       }
	break;
	case 2:
#line 37 "src/tfs_stata_parser.rl"
	{
           if (ctx->handle_literal) {
               ctx->handle_literal((char *)str_start, p - str_start, ctx->user_ctx);
           }
       }
	break;
	case 3:
#line 43 "src/tfs_stata_parser.rl"
	{
           if (ctx->handle_literal) {
               ctx->handle_literal(" ", 1, ctx->user_ctx);
           }
       }
	break;
#line 384 "src/tfs_stata_parser.c"
		}
	}
	}

	_out: {}
	}

#line 81 "src/tfs_stata_parser.rl"


    /* suppress warning */
    (void)stata_format_en_main;

    if (cs < 36) {
        if (ctx->handle_error) {
            char buf[1024];
            snprintf(buf, sizeof(buf), "Error parsing Stata format string '%s' around col #%ld (%c)\n", 
                    p, (long)(p - bytes + 1), *p);
            ctx->handle_error(buf, sizeof(buf), ctx->user_ctx);
        }
        return TFS_PARSE_ERROR;
    }

    return TFS_OK;
}
