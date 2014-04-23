#include "exits.h"
#include "../../utils/printutil.h"

#include <stdarg.h>

char* exitstr(char exits) {
/* Produces a string containing all available exits. */

    const char *names[4];
    char* format;
    char* str;
    char* cpy = exits;
    int bitcount = 0;
    int dircount = 0;

    names[0] = "North";
    names[1] = "East";
    names[2] = "South";
    names[3] = "West";

    for(bitcount = 0; cpy != 0; cpy >>= 1) {
        dircount++;
        if(cpy & 1) {
            bitcount++;
        }
    }
    
    switch(bitcount) {
        case 1: format = "%s";                break;
        case 2: format = "%s and %s";         break;
        case 3: format = "%s, %s and %s";     break;
        case 4: format = "%s, %s, %s and %s"; break;
        default: /* deal with this when error reporting is implemented */
    }

    /* Sort out figuring out which directions to send to mprintf. */

}

char isvalid(char exits, char dir) {
/* returns > 0 if proposed movement direction is valid */
    
    return exits & dir;
}
