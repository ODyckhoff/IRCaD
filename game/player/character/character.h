#ifndef CHARACTER_H
#define CHARACTER_H

#include "../../environment/map/map.h"
#include "../../environment/map/tile.h"

typedef struct character_t {
    struct player_t* account; /* pointer to the parent account this character is bound to */

    int id;
    char* name;
    int race;
    int pclass; /* Player's class */

    int xp;
    int level;
    int cur_health;

    /* struct stat_t stats; * character's stats */
    struct map_t *parmap; /* pointer to parent map character belongs to */
    struct map_t *curmap; /* pointer to map currently occupied by character */
    struct tile_t *curpos; /* pointer to current position on curmap */
    
} character_t;

struct character_t* new_char(int id, char* name, int race, int class);
void set_curmap(struct character_t* character, struct map_t* map);
void set_curpos_tile(struct character_t* character, struct tile_t* tile);
void set_curpos_coord(struct character_t* character, int x, int y);


#endif /* CHARACTER_H */
