/* Utils file to provide common utilities not tied specifically to any aspect of the software */ 

#include "printutil.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

char* mprintf(const char * format, ...) {
/* Prints a statement containing a format and then multiple arguments. */

    char *buf;
    va_list args;

    va_start (args, format);
    buf = malloc(sizeof(format) + sizeof(args));
    vsprintf (buf, format, args);
    va_end (args);

    return buf;
}
