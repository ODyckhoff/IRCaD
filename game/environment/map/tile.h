#ifndef TILE_H
#define TILE_H

#include "map.h"

typedef struct tile_t {
    char* name;
    int x;
    int y;
    struct map_t *sub_map;
} tile_t;

tile_t* new_tile(char *name, int x, int y);
void print_tile(tile_t *cur_tile);

#endif /* TILE_H */
