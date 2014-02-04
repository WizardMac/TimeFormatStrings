
#include <sys/types.h>
#include <stdio.h>

#include "tfs.h"
#include "tfs_internal.h"
#include "tfs_token.h"
#include "tfs_stata_parser.h"

/* See http://www.stata.com/help.cgi?datetime_display_formats */

%%{
    machine stata_format;
    write data;
}%%

int tfs_parse_stata_format_string_internal(const u_char *bytes, size_t len,
        tfs_handle_string_callback handle_literal_cb,
        tfs_handle_string_callback handle_code_cb, void *user_ctx) {
    u_char *p = (u_char *)bytes;
    u_char *pe = (u_char *)bytes + len;
    u_char *str_start = NULL;

    u_char *eof = pe;

    int cs;

   %%{
       action start_string {
           str_start = fpc;
       }
       action handle_code {
           if (handle_code_cb) {
               handle_code_cb((char *)str_start, fpc - str_start, user_ctx);
           }
       }

       action handle_literal {
           if (handle_literal_cb) {
               handle_literal_cb((char *)str_start, fpc - str_start, user_ctx);
           }
       }

       action handle_space{
           if (handle_literal_cb) {
               handle_literal_cb(" ", 1, user_ctx);
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

    if (cs < %%{ write first_final; }%%) {
        printf("Error parsing Stata format string '%s' around col #%ld (%c)", 
                p, (long)(p - bytes + 1), *p);
        return 1;
    }

    return 0;
}
