#ifndef MOVE_H
#define MOVE_H

#include "../../environment/exits.h"
#include "../../environment/tile.h"
#include "../../environment/map.h"

void mapswitch(struct indiv_t *active, int maptype);
void go(struct indiv_t *active, struct tile_t *cur_tile, int dir);


#endif /* MOVE_H */
