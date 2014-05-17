#ifndef MOVE_H
#define MOVE_H

#include "../../environment/exits.h"
#include "../../environment/tile.h"
#include "../../environment/map.h"

struct map_t mapswitch(struct map_t *cur_map, int maptype);
struct tile_t go(struct tile_t *cur_tile, int dir);


#endif /* MOVE_H */
