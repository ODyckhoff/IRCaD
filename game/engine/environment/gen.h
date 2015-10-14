#ifndef GEN_H
#define GEN_H

#include "map.h"
#include "tile.h"

void world_gen(map_t *map);
void town_gen(map_t *map);
void cave_gen(map_t *map);
void shuffle(int *array, int n);
int snt(int id);

#endif /* GEN_H */
