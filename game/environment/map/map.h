#ifndef MAP_H
#define MAP_H

#include "tile.h"

typedef enum {
    WORLDMAP = 1,
    TOWNMAP  = 2,
    CAVEMAP  = 3,
} mapid_t;

typedef struct map_t {
    int id;
    int width;
    int length;
    struct tile_t ***grid;
} map_t;

map_t* new_map(int id, int width, int length);
void world_gen(map_t *map);
void town_gen(map_t *map);
void cave_gen(map_t *map);
void print_map(map_t *map);
char* get_map_name(int id);

#endif /* MAP_H */
