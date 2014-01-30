#include "tile.h"

typedef struct {
    int width;
    int length;
    tile_t*** grid;
} map_t;

map_t* new_map(int width, int length);
void print_map(map_t *map);
