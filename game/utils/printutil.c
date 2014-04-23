/* Utils file to provide common utilities not tied specifically to any aspect of the software */

#include "utils.h"

#include <stdio.h>
#include <stdarg.h>

void mprintf(const char * format, ...) {
/* Prints a statement containing a format and then multiple arguments. */
  va_list args;
  va_start (args, format);
  vprintf (format, args);
  va_end (args);
}
