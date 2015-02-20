#ifndef MOVE_H
#define MOVE_H

#include "../../environment/exits.h"
#include "../../environment/tile.h"
#include "../../environment/map.h"

typedef struct {
    int listener_count;
    void (*listener_list[10])(struct tile_t*, struct tile_t*);
} move_ev;

void move_init(struct move_ev *move);
void move_rmlist(void (*fp)(struct tile_t*, struct tile_t*));
void move_mklist(void (*fp)(struct tile_t*, struct tile_t*));
void move_exec(struct tile_t*, struct tile_t*);

void mapswitch(struct indiv_t *active, int maptype);
void go(struct indiv_t *active, struct tile_t *cur_tile, int dir);

#endif /* MOVE_H */
