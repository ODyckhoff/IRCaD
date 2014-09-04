/* tile.c - generates a tile_t structure and provides other tile manipulation functions. */

#include "tile.h"
#include "exits.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* town_t_names[] = {"blank", "Town Gate", "Guild Hall", "Brewing Garden", "Workshop", "Alchemical Lab", "Black Market", "Farmers Market", "Weapon and Armour Shop", "Potion Shop", "Abandoned House", "NPC House", "Park", "Shrine", "Outdoor Cafe", "Plaza"};

char* world_t_names[] = {"blank", "Farmland", "Grassland", "Shrubland", "Forest", "Swamp", "Tundra", "Deep Forest", "Taiga", "Mountain Cave", "Lair", "Town", "Town Gate", "Mountain"};

char* cave_t_names[] = {"blank", "Cave", "Dungeon", "Treasure Room"};

tile_t* new_tile(int maptype, int x, int y, map_t* map) {
    
    tile_t *tile = malloc(sizeof(tile_t));
    if(tile == NULL) {
        fprintf(stderr, "Error, could not allocate memory for tile_t structure\n");
        exit(1); /* Exit codes to be defined for subsequent cycles */
    }

    tile->type = maptype;
    tile->id = BLANK;
    tile->x = x;
    tile->y = y;
    tile->exits = 15; /* all four exits by default */
    tile->parent = map;

    return tile;
}

void set_id(tile_t *tile, int id) {
    /* Set the ID of a tile, and check if a sub map is needed */
    tile->id = id;

    /* Check if the name is significant */
    if(tile->type == WORLDMAP && tile->id == TOWN) {
        link_sub_map(tile, TOWNMAP, 5, 5); /* TODO: Optional town sizes */
        tile->parent->town = tile->sub_map;
    }
        

    /* cave map init code here */
}

void set_desc(tile_t *tile, char *desc) {
    /* Set the description property of a tile */
    tile->desc = desc;
}

char* get_name(tile_t* tile) {
    switch(tile->type) {
        case WORLDMAP:
            return world_t_names[tile->id];
            break;
        case TOWNMAP:
            return town_t_names[tile->id];
            break;
        case CAVEMAP:
            return cave_t_names[tile->id];
            break;
    }
}

int get_id(tile_t* tile) {
    /* return the ID of a given tile */
    return tile->id;
}

void link_sub_map(tile_t *tile, int maptype, int width, int length) {
/* Link a tile to a relevant sub map */
    tile->sub_map = new_map(maptype, width, length);
}

map_t* get_parent(tile_t *tile) {
/* return the map object that the tile exists in */

    return tile->parent;
}

tile_t* get_n(tile_t* tile) {
/* return north tile */
    map_t* parent = get_parent(tile);

    if(chk_map(parent, tile, 0, -1))
        return tile->parent->grid[tile->x][tile->y - 1];
}

tile_t* get_e(tile_t* tile) {
/* return east tile */
    map_t* parent = get_parent(tile);

    if(chk_map(parent, tile, 1, 0))
        return tile->parent->grid[tile->x + 1][tile->y];
}

tile_t* get_s(tile_t* tile) {
/* return south tile */
    map_t* parent = get_parent(tile);

    if(chk_map(parent, tile, 0, 1))
        tile->parent->grid[tile->x][tile->y + 1];
}

tile_t* get_w(tile_t* tile) {
/* return west tile */
    map_t* parent = get_parent(tile);

    if(chk_map(parent, tile, -1, -0))
        tile->parent->grid[tile->x - 1][tile->y];
}

void print_tile(tile_t *cur_tile) {
    /* May remain in subsequent cycles for web interface purposes.
       Will possibly also show printout of players and mobs in a tile */

    printf("Tile is part of the %s, its name is '%s', and its position is (%d, %d)\nIt has exits %s\n", get_map_name(cur_tile->type), get_name(cur_tile), cur_tile->x, cur_tile->y, exitstr(getexits(cur_tile)));
}
