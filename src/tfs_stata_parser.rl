
#include <sys/types.h>
#include <stdio.h>

#include "tfs.h"
#include "tfs_internal.h"
#include "tfs_stata_parser.h"

/* See http://www.stata.com/help.cgi?datetime_display_formats */

%%{
    machine stata_format;
    write data nofinal noerror;
}%%

tfs_error_e tfs_parse_stata_format_string_internal(
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

       action handle_space{
           if (ctx->handle_literal) {
               ctx->handle_literal(" ", 1, ctx->user_ctx);
           }
       }

       century = "CC" | "cc";
       year = "YY" | "yy";
       day_of_year = "JJJ" | "jjj";

       month = [Mm] "on" "th"? | "NN" | "nn";
       day_of_month = "DD" | "dd";

       day_of_week = "DAYNAME" | "Da" ("y" "name"?)? | "da" "y"?;
       half = "h";
       quarter = "q";
       week = "WW" | "ww";

       hour = "hh"i;

       minute = "MM" | "mm";

       second = "SS" | "ss" | ".s" | ".ss" | ".sss";

       am_pm = "am" | "a.m." | "AM" | "A.M.";

       code = (century | year | day_of_year | month | day_of_month | day_of_week | 
                half | 
                quarter | week | hour | minute | second | am_pm) >start_string %handle_code;

       display_character = ( "." | "," | ":" | "-" | "/" | "\\" ) >start_string %handle_literal;

       underscore = "_" %handle_space;

       main := (code | "!" ascii >start_string %handle_literal | display_character | underscore | "+")**;

        write init;
        write exec;
    }%%

    /* suppress warning */
    (void)stata_format_en_main;

    if (cs < %%{ write first_final; }%%) {
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
