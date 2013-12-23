
#include <sys/types.h>
#include <stdio.h>
#include "tfs.h"
#include "tfs_excel_parser.h"

/* See http://office.microsoft.com/en-us/excel-help/text-function-HP010062580.aspx */

%%{
    machine excel_format;
    write data;
}%%

int tfs_parse_excel_format_string_internal(const u_char *bytes, size_t len,
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

       action start_code {
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

       color = "[" alpha+ "]";

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

    if (cs < %%{ write first_final; }%%) {
        printf("Error parsing Excel format string '%s' around col #%ld (%c)",
            bytes, (long)(p - bytes + 1), *p);
        return 1;
    }

    return 0;
}
