#ifndef CHARACTER_H
#define CHARACTER_H

#include "../environment/map/map.h"
#include "../environment/map/tile.h"

typedef struct {
    struct player_t* account; /* pointer to the parent account this character is bound to */

    char* name;
    int race;
    int pclass; /* Player's class */

    int xp;
    int level;
    int cur_health;

    struct stat_t stats; /* character's stats */
    struct map_t *parmap; /* pointer to parent map character belongs to */
    struct map_t *curmap; /* pointer to map currently occupied by character */
    struct tile_t *curpos; /* pointer to current position on curmap */
    
} character_t;

#endif /* CHARACTER_H */
