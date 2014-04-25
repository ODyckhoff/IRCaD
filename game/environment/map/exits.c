/* exits.c - provides functions for exit manipulations */

#include "exits.h"
#include "tile.h"
#include "../../utils/printutil.h"

#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

char* exitstr(int exits) {
/* Produces a string containing all available exits. */

    const char *names[4];
    char dir[4][6];
    char* format;
    char* str;
    int cpy = exits;
    int i = 0;
    int bitcount = 0;
    int dircount = -1;

    names[0] = "North";
    names[1] = "East";
    names[2] = "South";
    names[3] = "West";

    for(bitcount = 0; cpy != 0; cpy >>= 1) {
        dircount++;
        if(cpy & 1) {
            strcpy(dir[bitcount], names[dircount]);
            bitcount++;
        }
    }
    
    switch(bitcount) {
        case 1: format = "%s";
            return mprintf(format, dir[0]);
        break;

        case 2: format = "%s and %s";
           return  mprintf(format, dir[0], dir[1]);
        break;

        case 3: format = "%s, %s and %s";
            return mprintf(format, dir[0], dir[1], dir[2]);
        break;

        case 4: format = "%s, %s, %s and %s"; 
            return mprintf(format, dir[0], dir[1], dir[2], dir[3]);
        break;
        /* default: deal with this when error reporting is implemented */
    }
}

int isvalid(int exits, char dir) {
/* returns > 0 if proposed movement direction is valid */
    
    return exits & dir;
}

void rmexit(tile_t *tile, int dir) {
/* Removes an exit from a tile */

    dir = tile->exits & dir;
    tile->exits -= dir;
}

int getexits(tile_t *tile) {
/* returns an integer representing the tile exits */

    return tile->exits;
}
