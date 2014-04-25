#ifndef EXITS_H
#define EXITS_H

#include "tile.h"

enum {
    NORTH = 1,
    EAST  = 2,
    SOUTH = 4,
    WEST  = 8
};

char* exitstr(int exits);
int isvalid( int exits, char dir);
void rmexit(tile_t *tile, int dir);
int getexits(tile_t *tile);

#endif /* EXITS_H */
