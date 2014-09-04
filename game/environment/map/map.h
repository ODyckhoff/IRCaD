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
    struct tile_t *signif;
    struct map_t *parent;
    struct map_t *town;
} map_t;

map_t* new_map(int id, int width, int length);
void print_map(map_t *map);
char* get_map_name(int id);
int chk_map(map_t* map, struct tile_t* tile, int xmod, int ymod);


#endif /* MAP_H */
