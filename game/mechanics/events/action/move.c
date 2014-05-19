/* move.c - controls movement around a map, and handles switching between maps */

#include "move.h"

void mapswitch(indiv_t *active, int maptype) {
/* Switches a player into a designated map. */

    switch(maptype) {
        case WORLDMAP:
            active->cur_map = get_parent(active->cur_map);
        break;
        case TOWNMAP:
            active->cur_map = active->cur_map->signif->sub_map;
            go(active, -2);
        break;
        case CAVEMAP:
            active->cur_map = active->pos->sub_map;
        break;
        default:
            /* error */
        break;
    }
}

void go(indiv_t *active, int dir) {
/* Will return a tile pointer. Validity of movement should be checked beforehand. */

    switch(dir) {
        case NORTH:
            active->pos = get_n(active->pos);
        break;
        case EAST:
            active->pos = get_e(active->pos);
        break;
        case SOUTH:
            active->pos = get_s(active->pos);
        break;
        case WEST:
            active->pos = get_w(active->pos);
        break;
        case -1:
            /* put the player in town from outside */
            mapswitch(active, TOWNMAP);
        break;
        case -2:
            /* put the player in the guild hall from inside town */
            active->pos = active->cur_map->signif;
        break;
    }
}
