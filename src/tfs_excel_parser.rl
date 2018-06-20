
#include <sys/types.h>
#include <stdio.h>
#include "tfs.h"
#include "tfs_internal.h"
#include "tfs_excel_parser.h"

/* See http://office.microsoft.com/en-us/excel-help/text-function-HP010062580.aspx */

%%{
    machine excel_format;
    write data nofinal noerror;
}%%

tfs_error_e tfs_parse_excel_format_string_internal(const unsigned char *bytes, size_t len, tfs_parse_ctx_t *ctx) {
    unsigned char *p = (unsigned char *)bytes;
    unsigned char *pe = (unsigned char *)bytes + len;
    unsigned char *str_start = NULL;

    unsigned char *eof = pe;

    int cs;

   %%{
       action start_string {
           str_start = fpc;
       }

       action start_code {
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

       display_character = ( "$" | "-" | "+" | "/" | "(" | ")" | ":" | "!" | "^" | "&" | "'" | "~" | "{" | "}" | "<" | ">" | "=" | " " ) >start_string %handle_literal;

       escaped_character = "\\" any >start_string %handle_literal;

       quoted_string = ( "\"" ( "\\\"" | [^\\"] )* "\"" ) >start_string %handle_literal;

       width_character = "_" any;

       pad_character = "*" any;

       decimal_digit = ( "#" | "0" | "?" | "," );

       number = decimal_digit+ | (decimal_digit* "." decimal_digit*);

       exponent = "E+" | "E-" | "e+" | "e-";

       month = "M"+ | "m"+;

       day = "D"+ | "d"+;

       year = "y"+;

       hour = "H"+ | "h"+;

       second = ("s" | "ss") ( "." decimal_digit+ )?;

       am_pm = "AM/PM" | "am/pm" | "A/P" | "a/p" | "AM" | "am" | "A" | "a" | "PM" | "pm" | "P" | "p";

       date_time = ( year | month | day | hour | second | am_pm ) >start_code %handle_code;

       color = "[" ( alpha+ | ( "$-" alnum+ ) ) "]";

       comparison_operator = "=" | ">" | "<" | ">=" | "<=" | "<>";

       value = ( "-"? digit* "." digit+ ) | ( "-"? digit+ );

       condition = "[" comparison_operator value "]";

       section = color? ( 
               display_character | 
               escaped_character | 
               quoted_string | 
               "@" | 
               width_character | 
               pad_character | 
               number | 
               "%" | 
               exponent | 
               date_time | 
               condition 
               )**;

       main := section ( ";" section ( ";" section ( ";" section )? )? )?;

        write init;
        write exec;
   }%%

    /* suppress warning */
   (void)excel_format_en_main;

    if (cs < %%{ write first_final; }%%) {
        if (ctx->handle_error) {
            char error_buf[1024];
            snprintf(error_buf, sizeof(error_buf), "Error parsing Excel format string '%s' around col #%ld (%c)\n",
                    bytes, (long)(p - bytes + 1), *p);
            ctx->handle_error(error_buf, sizeof(error_buf), ctx->user_ctx);
        }
        return TFS_PARSE_ERROR;
    }

    return TFS_OK;
}
