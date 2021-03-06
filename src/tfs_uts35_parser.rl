
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include "tfs.h"
#include "tfs_internal.h"
#include "tfs_uts35_parser.h"

/* See http://www.unicode.org/reports/tr35/tr35-dates.html#Date_Format_Patterns */

%%{
    machine uts35_format;
    write data nofinal noerror;
}%%

tfs_error_e tfs_parse_uts35_format_string_internal(
        const unsigned char *bytes, size_t len,
        tfs_parse_ctx_t *ctx) {
    unsigned char *p = (unsigned char *)bytes;
    unsigned char *pe = (unsigned char *)bytes + len;
    unsigned char *str_start = NULL;

    unsigned char *eof = pe;

    int cs;

   %%{
       action start_string {
           str_start = fpc;
       }
       action handle_code {
           if (ctx->handle_code) {
               ctx->handle_code((char *)str_start, fpc - str_start, ctx->user_ctx);
           }
       }

       action handle_literal {
           if (ctx->handle_literal) {
               ctx->handle_literal((char *)str_start, fpc - str_start, ctx->user_ctx);
           }
       }

       action handle_single_quote {
           if (ctx->handle_literal) {
               ctx->handle_literal("''''", 4, ctx->user_ctx);
           }
       }

       era = [G]{1,5};

       year = [y]{1,5} | [Y]{1,5} | [u]{1,5} | [U]{1,5};

       quarter = [q]{1,4} | [Q]{1,4};

       month = [M]{1,5} | [L]{1,5};

       week = "w" | "ww" | "W";

       day = [d]{1,2} | [D]{1,3} | "F" | [g]{1,7};

       week_day = [E]{1,6} | [e]{1,6} | [c]{1,6};

       period = "a";

       hour = [h]{1,2} | [H]{1,2} | [K]{1,2} | [k]{1,2};

       minute = [m]{1,2};

       second = [s]{1,2};

       fractional_second = [S]{1,8};

       millisecond = [A]{1,8};

       time_zone = [z]{1,4} | [Z]{1,5} | "O" | "OOOO" | "v" | "vvvv" | [V]{1,4} | [X]{1,5} | [x]{1,5};

       code = (era | year | quarter | month | week | day | week_day | period | hour | minute | second | fractional_second | millisecond) >start_string %handle_code; 

       quoted_string = ("'" ( "''" | [^'] )+  "'") >start_string %handle_literal;

       display_characters = ( ascii - alpha - ['] )+ >start_string %handle_literal;

       single_quote = "''" %handle_single_quote;

       main := (code | display_characters | quoted_string | single_quote | time_zone )**;

        write init;
        write exec;
    }%%

    (void)uts35_format_en_main;

    if (cs < %%{ write first_final; }%%) {
        if (ctx->handle_error) {
            char buf[1024];
            snprintf(buf, sizeof(buf), "Error parsing UTS35 format string around col #%ld (%c)\n", 
                    (long)(p + 1 - bytes), *p);
            ctx->handle_error(buf, sizeof(buf), ctx->user_ctx);
        }
        return TFS_PARSE_ERROR;
    }

    return TFS_OK;
}
