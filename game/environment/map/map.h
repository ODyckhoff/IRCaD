#ifndef MAP_H
#define MAP_H

#include "tile.h"

typedef struct map_t {
    char *id;
    int width;
    int length;
    struct tile_t ***grid;
} map_t;

map_t* new_map(char* id, int width, int length);
void world_gen(map_t *map);
void town_gen(map_t *map);
void cave_gen(map_t *map);
void print_map(map_t *map);

#endif /* MAP_H */
