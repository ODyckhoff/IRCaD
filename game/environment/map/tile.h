#ifndef TILE_H
#define TILE_H

/* Define tile types */
#define BLANK 0 /* Global BLANK type. */

typedef enum {
    TOWNGATEINT  = 1,
    GUILDHALL    = 2,
    BREWGARDEN   = 3,
    WORKSHOP     = 4,
    ALCHLAB      = 5,
    BLACKMARKET  = 6,
    FARMERMARKET = 7,
    WARMOURSHOP  = 8,
    POTIONSHOP   = 9,
    ABANDONHOUSE = 10,
    NPCHOUSE     = 11,
    PARK         = 12,
    SHRINE       = 13,
    OUTDOORCAFE  = 14,
    PLAZA        = 15,
    TOWNINT      = 16,
} town_t;

typedef enum {
    TOWN         = 1,
    TOWNGATEEXT  = 2,
    FARMLAND     = 3,
    MOUNTAINCAVE = 4,
    MOUNTAIN     = 5,
    LAIR         = 6,
    GRASSLAND    = 7,
    SHRUBLAND    = 8,
    FOREST       = 9,
    SWAMP        = 10,
    TUNDRA       = 11,
    DEEPFOREST   = 12,
    TAIGA        = 13,
    CAVE         = 14,
} world_t;

typedef enum { /* Global BLANK defines edges of cave to simulate shape. */
    CAVEINT      = 1,
    DUNGEON      = 2,
    TREASUREROOM = 3,
} cave_t;

#include "map.h"

typedef struct tile_t {
    int type; /* world, town, cave */
    int id;
    char* desc;
    int x;
    int y;
    struct map_t *sub_map;
} tile_t;

tile_t* new_tile(int maptype, int x, int y);
void print_tile(tile_t *cur_tile);

void set_id(tile_t *tile, int id);
void set_desc(tile_t *tile, char *desc);

int get_id(tile_t *tile);
char* get_desc(tile_t *tile);
char* get_name(tile_t *tile);

void link_sub_map(tile_t *tile, int maptype, int width, int length);

#endif /* TILE_H */
