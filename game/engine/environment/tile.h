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
    TOWNINT      = 16
} town_t;

typedef enum {
    FARMLAND     = 1,
    GRASSLAND    = 2,
    SHRUBLAND    = 3,
    FOREST       = 4,
    SWAMP        = 5,
    TUNDRA       = 6,
    DEEPFOREST   = 7,
    TAIGA        = 8,
    MOUNTAINCAVE = 9,
    LAIR         = 10,
    TOWN         = 11,
    TOWNGATEEXT  = 12,
    MOUNTAIN     = 13
} world_t;

typedef enum { /* Global BLANK defines edges of cave to simulate shape. */
    CAVEINT      = 1,
    DUNGEON      = 2,
    TREASUREROOM = 3
} cave_t;

#include "map.h"

typedef struct tile_t {
    int type; /* world, town, cave */
    int id;
    char* desc;
    int x;
    int y;
    int exits; /* Binary 1111 - indicates all four exits are available */
    struct map_t *sub_map;
    struct map_t *parent;
} tile_t;

tile_t* new_tile(int maptype, int x, int y, struct map_t *parent);
void print_tile(tile_t *cur_tile);

void set_id(tile_t *tile, int id);
void set_desc(tile_t *tile, char *desc);

int get_id(tile_t *tile);
char* get_desc(tile_t *tile);
char* get_name(tile_t *tile);
struct map_t* get_parent(tile_t *tile);

tile_t* get_n(tile_t *tile);
tile_t* get_e(tile_t *tile);
tile_t* get_s(tile_t *tile);
tile_t* get_w(tile_t *tile);

void link_sub_map(tile_t *tile, int maptype, int width, int length);

#endif /* TILE_H */
