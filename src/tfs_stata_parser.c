#line 1 "src/tfs_stata_parser.rl"

#include <sys/types.h>
#include <stdio.h>

#include "tfs.h"
#include "tfs_internal.h"
#include "tfs_stata_parser.h"

/* See http://www.stata.com/help.cgi?datetime_display_formats */


#line 14 "src/tfs_stata_parser.c"
static const signed char _stata_format_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1,
	3, 2, 1, 0, 2, 2, 0, 2,
	3, 0, 0
};

static const short _stata_format_key_offsets[] = {
	0, 0, 4, 6, 7, 8, 9, 12,
	13, 14, 15, 16, 17, 19, 20, 21,
	23, 24, 25, 26, 27, 28, 30, 31,
	32, 34, 35, 36, 38, 39, 40, 41,
	42, 43, 44, 45, 46, 48, 77, 106,
	135, 164, 193, 223, 252, 281, 310, 339,
	368, 397, 0
};

static const unsigned char _stata_format_trans_keys[] = {
	128u, 191u, 192u, 255u, 46u, 77u, 77u, 46u,
	67u, 65u, 68u, 97u, 89u, 78u, 65u, 77u,
	69u, 72u, 104u, 74u, 74u, 77u, 111u, 110u,
	78u, 83u, 87u, 89u, 46u, 109u, 109u, 99u,
	97u, 100u, 106u, 106u, 109u, 111u, 110u, 115u,
	119u, 121u, 104u, 97u, 109u, 101u, 128u, 191u,
	33u, 43u, 46u, 58u, 65u, 67u, 68u, 72u,
	74u, 77u, 78u, 83u, 87u, 89u, 92u, 95u,
	97u, 99u, 100u, 104u, 106u, 109u, 110u, 113u,
	115u, 119u, 121u, 44u, 47u, 33u, 43u, 46u,
	58u, 65u, 67u, 68u, 72u, 74u, 77u, 78u,
	83u, 87u, 89u, 92u, 95u, 97u, 99u, 100u,
	104u, 106u, 109u, 110u, 113u, 115u, 119u, 121u,
	44u, 47u, 33u, 43u, 46u, 58u, 65u, 67u,
	68u, 72u, 74u, 77u, 78u, 83u, 87u, 89u,
	92u, 95u, 97u, 99u, 100u, 104u, 106u, 109u,
	110u, 113u, 115u, 119u, 121u, 44u, 47u, 33u,
	43u, 46u, 58u, 65u, 67u, 68u, 72u, 74u,
	77u, 78u, 83u, 87u, 89u, 92u, 95u, 97u,
	99u, 100u, 104u, 106u, 109u, 110u, 113u, 115u,
	119u, 121u, 44u, 47u, 33u, 43u, 46u, 58u,
	65u, 67u, 68u, 72u, 74u, 77u, 78u, 83u,
	87u, 89u, 92u, 95u, 97u, 99u, 100u, 104u,
	106u, 109u, 110u, 113u, 115u, 119u, 121u, 44u,
	47u, 33u, 43u, 46u, 58u, 65u, 67u, 68u,
	72u, 74u, 77u, 78u, 83u, 87u, 89u, 92u,
	95u, 97u, 99u, 100u, 104u, 106u, 109u, 110u,
	113u, 115u, 116u, 119u, 121u, 44u, 47u, 33u,
	43u, 46u, 58u, 65u, 67u, 68u, 72u, 74u,
	77u, 78u, 83u, 87u, 89u, 92u, 95u, 97u,
	99u, 100u, 104u, 106u, 109u, 110u, 113u, 115u,
	119u, 121u, 44u, 47u, 33u, 43u, 46u, 58u,
	65u, 67u, 68u, 72u, 74u, 77u, 78u, 83u,
	87u, 89u, 92u, 95u, 97u, 99u, 100u, 104u,
	106u, 109u, 110u, 113u, 115u, 119u, 121u, 44u,
	47u, 33u, 43u, 46u, 58u, 65u, 67u, 68u,
	72u, 74u, 77u, 78u, 83u, 87u, 89u, 92u,
	95u, 97u, 99u, 100u, 104u, 106u, 109u, 110u,
	113u, 115u, 119u, 121u, 44u, 47u, 33u, 43u,
	46u, 58u, 65u, 67u, 68u, 72u, 74u, 77u,
	78u, 83u, 87u, 89u, 92u, 95u, 97u, 99u,
	100u, 104u, 106u, 109u, 110u, 113u, 115u, 119u,
	121u, 44u, 47u, 33u, 43u, 46u, 58u, 65u,
	67u, 68u, 72u, 74u, 77u, 78u, 83u, 87u,
	89u, 92u, 95u, 97u, 99u, 100u, 104u, 106u,
	109u, 110u, 113u, 115u, 119u, 121u, 44u, 47u,
	33u, 43u, 46u, 58u, 65u, 67u, 68u, 72u,
	74u, 77u, 78u, 83u, 87u, 89u, 92u, 95u,
	97u, 99u, 100u, 104u, 106u, 109u, 110u, 113u,
	115u, 119u, 121u, 44u, 47u, 33u, 43u, 46u,
	58u, 65u, 67u, 68u, 72u, 74u, 77u, 78u,
	83u, 87u, 89u, 92u, 95u, 97u, 99u, 100u,
	104u, 106u, 109u, 110u, 113u, 115u, 119u, 121u,
	44u, 47u, 128u, 191u, 0u
};

static const signed char _stata_format_single_lengths[] = {
	0, 0, 2, 1, 1, 1, 3, 1,
	1, 1, 1, 1, 2, 1, 1, 2,
	1, 1, 1, 1, 1, 2, 1, 1,
	2, 1, 1, 2, 1, 1, 1, 1,
	1, 1, 1, 1, 0, 27, 27, 27,
	27, 27, 28, 27, 27, 27, 27, 27,
	27, 27, 0
};

static const signed char _stata_format_range_lengths[] = {
	0, 2, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 2, 0
};

static const short _stata_format_index_offsets[] = {
	0, 0, 3, 6, 8, 10, 12, 16,
	18, 20, 22, 24, 26, 29, 31, 33,
	36, 38, 40, 42, 44, 46, 49, 51,
	53, 56, 58, 60, 63, 65, 67, 69,
	71, 73, 75, 77, 79, 81, 110, 139,
	168, 197, 226, 256, 285, 314, 343, 372,
	401, 430, 0
};

static const signed char _stata_format_cond_targs[] = {
	0, 36, 38, 3, 40, 0, 4, 0,
	40, 0, 40, 0, 7, 40, 41, 0,
	8, 0, 9, 0, 10, 0, 11, 0,
	40, 0, 40, 40, 0, 14, 0, 40,
	0, 40, 16, 0, 42, 0, 40, 0,
	40, 0, 40, 0, 40, 0, 22, 40,
	0, 4, 0, 40, 0, 44, 40, 0,
	26, 0, 40, 0, 40, 16, 0, 40,
	0, 40, 0, 40, 0, 40, 0, 40,
	0, 34, 0, 35, 0, 40, 0, 49,
	0, 1, 37, 39, 38, 2, 5, 6,
	12, 13, 15, 17, 18, 19, 20, 38,
	43, 21, 23, 24, 45, 25, 27, 28,
	40, 29, 30, 31, 38, 0, 1, 37,
	39, 38, 2, 5, 6, 12, 13, 15,
	17, 18, 19, 20, 38, 43, 21, 23,
	24, 45, 25, 27, 28, 40, 29, 30,
	31, 38, 0, 1, 37, 39, 38, 2,
	5, 6, 12, 13, 15, 17, 18, 19,
	20, 38, 43, 21, 23, 24, 45, 25,
	27, 28, 40, 47, 30, 31, 38, 0,
	1, 37, 39, 38, 2, 5, 6, 12,
	13, 15, 17, 18, 19, 20, 38, 43,
	21, 23, 24, 45, 25, 27, 28, 40,
	29, 30, 31, 38, 0, 1, 37, 39,
	38, 2, 5, 6, 12, 13, 15, 17,
	18, 19, 20, 38, 43, 21, 23, 24,
	45, 25, 27, 28, 40, 29, 30, 46,
	38, 0, 1, 37, 39, 38, 2, 5,
	6, 12, 13, 15, 17, 18, 19, 20,
	38, 43, 21, 23, 24, 45, 25, 27,
	28, 40, 29, 32, 30, 31, 38, 0,
	1, 37, 39, 38, 2, 5, 6, 12,
	13, 15, 17, 18, 19, 20, 38, 43,
	21, 23, 24, 45, 25, 27, 28, 40,
	29, 30, 31, 38, 0, 1, 37, 39,
	38, 2, 5, 6, 12, 13, 15, 17,
	18, 19, 20, 38, 43, 21, 23, 24,
	45, 25, 27, 28, 40, 29, 30, 40,
	38, 0, 1, 37, 39, 38, 2, 5,
	6, 40, 13, 15, 17, 18, 19, 20,
	38, 43, 21, 23, 24, 40, 25, 27,
	28, 40, 29, 30, 31, 38, 0, 1,
	37, 39, 38, 2, 5, 6, 12, 13,
	15, 17, 18, 19, 20, 38, 43, 21,
	23, 24, 45, 25, 27, 33, 40, 29,
	30, 31, 38, 0, 1, 37, 39, 38,
	2, 5, 6, 12, 13, 15, 17, 18,
	19, 20, 38, 43, 21, 23, 24, 45,
	25, 27, 28, 40, 48, 30, 31, 38,
	0, 1, 37, 39, 38, 2, 5, 6,
	12, 13, 15, 17, 18, 19, 20, 38,
	43, 21, 23, 24, 45, 25, 27, 28,
	40, 40, 30, 31, 38, 0, 1, 37,
	39, 38, 2, 5, 6, 12, 13, 15,
	17, 18, 19, 20, 38, 43, 21, 23,
	24, 45, 25, 27, 28, 40, 29, 30,
	31, 38, 49, 0, 0, 1, 2, 3,
	4, 5, 6, 7, 8, 9, 10, 11,
	12, 13, 14, 15, 16, 17, 18, 19,
	20, 21, 22, 23, 24, 25, 26, 27,
	28, 29, 30, 31, 32, 33, 34, 35,
	36, 37, 38, 39, 40, 41, 42, 43,
	44, 45, 46, 47, 48, 49, 0
};

static const signed char _stata_format_cond_actions[] = {
	0, 1, 1, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	0, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 0, 5, 5,
	12, 12, 12, 12, 12, 12, 12, 12,
	12, 12, 12, 12, 12, 5, 12, 12,
	12, 12, 12, 12, 12, 12, 12, 12,
	12, 12, 0, 5, 5, 12, 12, 12,
	12, 12, 12, 12, 12, 12, 12, 12,
	12, 12, 5, 12, 12, 12, 12, 12,
	12, 12, 12, 0, 12, 12, 12, 0,
	3, 3, 9, 9, 9, 9, 9, 9,
	9, 9, 9, 9, 9, 9, 9, 3,
	9, 9, 9, 9, 9, 9, 9, 9,
	9, 9, 9, 9, 0, 3, 3, 9,
	9, 9, 9, 9, 9, 9, 9, 9,
	9, 9, 9, 9, 3, 9, 9, 9,
	9, 9, 9, 9, 9, 9, 9, 0,
	9, 0, 3, 3, 9, 9, 9, 9,
	9, 9, 9, 9, 9, 9, 9, 9,
	9, 3, 9, 9, 9, 9, 9, 9,
	9, 9, 9, 0, 9, 9, 9, 0,
	7, 7, 15, 15, 15, 15, 15, 15,
	15, 15, 15, 15, 15, 15, 15, 7,
	15, 15, 15, 15, 15, 15, 15, 15,
	15, 15, 15, 15, 0, 3, 3, 9,
	9, 9, 9, 9, 9, 9, 9, 9,
	9, 9, 9, 9, 3, 9, 9, 9,
	9, 9, 9, 9, 9, 9, 9, 0,
	9, 0, 3, 3, 9, 9, 9, 9,
	9, 0, 9, 9, 9, 9, 9, 9,
	9, 3, 9, 9, 9, 0, 9, 9,
	9, 9, 9, 9, 9, 9, 0, 3,
	3, 9, 9, 9, 9, 9, 9, 9,
	9, 9, 9, 9, 9, 9, 3, 9,
	9, 9, 9, 9, 9, 0, 9, 9,
	9, 9, 9, 0, 3, 3, 9, 9,
	9, 9, 9, 9, 9, 9, 9, 9,
	9, 9, 9, 3, 9, 9, 9, 9,
	9, 9, 9, 9, 0, 9, 9, 9,
	0, 3, 3, 9, 9, 9, 9, 9,
	9, 9, 9, 9, 9, 9, 9, 9,
	3, 9, 9, 9, 9, 9, 9, 9,
	9, 0, 9, 9, 9, 0, 5, 5,
	12, 12, 12, 12, 12, 12, 12, 12,
	12, 12, 12, 12, 12, 5, 12, 12,
	12, 12, 12, 12, 12, 12, 12, 12,
	12, 12, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 5, 5, 3, 3, 3, 7,
	3, 3, 3, 3, 3, 5, 0
};

static const short _stata_format_eof_trans[] = {
	461, 462, 463, 464, 465, 466, 467, 468,
	469, 470, 471, 472, 473, 474, 475, 476,
	477, 478, 479, 480, 481, 482, 483, 484,
	485, 486, 487, 488, 489, 490, 491, 492,
	493, 494, 495, 496, 497, 498, 499, 500,
	501, 502, 503, 504, 505, 506, 507, 508,
	509, 510, 0
};

static const int stata_format_start = 37;

static const int stata_format_en_main = 37;


#line 15 "src/tfs_stata_parser.rl"


tfs_error_e tfs_parse_stata_format_string_internal(
const unsigned char *bytes, size_t len,
tfs_parse_ctx_t *ctx) {
	unsigned char *p = (unsigned char *)bytes;
	unsigned char *pe = (unsigned char *)bytes + len;
	unsigned char *str_start = NULL;
	
	unsigned char *eof = pe;
	
	int cs;
	
	
#line 282 "src/tfs_stata_parser.c"
	{
		cs = (int)stata_format_start;
	}
	
#line 287 "src/tfs_stata_parser.c"
	{
		int _klen;
		unsigned int _trans = 0;
		const unsigned char * _keys;
		const signed char * _acts;
		unsigned int _nacts;
		_resume: {}
		if ( p == pe && p != eof )
			goto _out;
		if ( p == eof ) {
			if ( _stata_format_eof_trans[cs] > 0 ) {
				_trans = (unsigned int)_stata_format_eof_trans[cs] - 1;
			}
		}
		else {
			_keys = ( _stata_format_trans_keys + (_stata_format_key_offsets[cs]));
			_trans = (unsigned int)_stata_format_index_offsets[cs];
			
			_klen = (int)_stata_format_single_lengths[cs];
			if ( _klen > 0 ) {
				const unsigned char *_lower = _keys;
				const unsigned char *_upper = _keys + _klen - 1;
				const unsigned char *_mid;
				while ( 1 ) {
					if ( _upper < _lower ) {
						_keys += _klen;
						_trans += (unsigned int)_klen;
						break;
					}
					
					_mid = _lower + ((_upper-_lower) >> 1);
					if ( ( (*( p))) < (*( _mid)) )
						_upper = _mid - 1;
					else if ( ( (*( p))) > (*( _mid)) )
						_lower = _mid + 1;
					else {
						_trans += (unsigned int)(_mid - _keys);
						goto _match;
					}
				}
			}
			
			_klen = (int)_stata_format_range_lengths[cs];
			if ( _klen > 0 ) {
				const unsigned char *_lower = _keys;
				const unsigned char *_upper = _keys + (_klen<<1) - 2;
				const unsigned char *_mid;
				while ( 1 ) {
					if ( _upper < _lower ) {
						_trans += (unsigned int)_klen;
						break;
					}
					
					_mid = _lower + (((_upper-_lower) >> 1) & ~1);
					if ( ( (*( p))) < (*( _mid)) )
						_upper = _mid - 2;
					else if ( ( (*( p))) > (*( _mid + 1)) )
						_lower = _mid + 2;
					else {
						_trans += (unsigned int)((_mid - _keys)>>1);
						break;
					}
				}
			}
			
			_match: {}
		}
		cs = (int)_stata_format_cond_targs[_trans];
		
		if ( _stata_format_cond_actions[_trans] != 0 ) {
			
			_acts = ( _stata_format_actions + (_stata_format_cond_actions[_trans]));
			_nacts = (unsigned int)(*( _acts));
			_acts += 1;
			while ( _nacts > 0 ) {
				switch ( (*( _acts)) )
				{
					case 0:  {
						{
#line 29 "src/tfs_stata_parser.rl"
							
							str_start = p;
						}
						
#line 372 "src/tfs_stata_parser.c"
						
						break; 
					}
					case 1:  {
						{
#line 32 "src/tfs_stata_parser.rl"
							
							if (ctx->handle_code) {
								ctx->handle_code((char *)str_start, p - str_start, ctx->user_ctx);
							}
						}
						
#line 385 "src/tfs_stata_parser.c"
						
						break; 
					}
					case 2:  {
						{
#line 38 "src/tfs_stata_parser.rl"
							
							if (ctx->handle_literal) {
								ctx->handle_literal((char *)str_start, p - str_start, ctx->user_ctx);
							}
						}
						
#line 398 "src/tfs_stata_parser.c"
						
						break; 
					}
					case 3:  {
						{
#line 44 "src/tfs_stata_parser.rl"
							
							if (ctx->handle_literal) {
								ctx->handle_literal(" ", 1, ctx->user_ctx);
							}
						}
						
#line 411 "src/tfs_stata_parser.c"
						
						break; 
					}
				}
				_nacts -= 1;
				_acts += 1;
			}
			
		}
		
		if ( p == eof ) {
			if ( cs >= 37 )
				goto _out;
		}
		else {
			if ( cs != 0 ) {
				p += 1;
				goto _resume;
			}
		}
		_out: {}
	}
	
#line 84 "src/tfs_stata_parser.rl"
	
	
	/* suppress warning */
	(void)stata_format_en_main;
	
	if (cs < 
#line 442 "src/tfs_stata_parser.c"
	37
#line 89 "src/tfs_stata_parser.rl"
	) {
		if (ctx->handle_error) {
			char buf[1024];
			snprintf(buf, sizeof(buf), "Error parsing Stata format string '%s' around col #%ld (%c)\n", 
			bytes, (long)(p - bytes + 1), *p);
			ctx->handle_error(buf, sizeof(buf), ctx->user_ctx);
		}
		return TFS_PARSE_ERROR;
	}
	
	return TFS_OK;
}
