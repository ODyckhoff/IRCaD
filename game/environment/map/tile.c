/* tile.c - generates a tile_t structure and provides other tile manipulation functions. */
#include "tile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tile_t* new_tile(char *name, int x, int y) {
    
    tile_t *tile = malloc(sizeof(tile_t));
    if(tile == NULL) {
        fprintf(stderr, "Error, could not allocate memory for tile_t structure\n");
        exit(1); /* Exit codes to be defined for subsequent cycles */
    }

    tile->name = name;
    tile->x = x;
    tile->y = y;

    return tile;
}

void set_tile_name(tile_t *tile, char *name) {
    /* Set the ID of a tile, and check if a sub map is needed */
    tile->name = name;

    /* Check if the name is significant */
    if(strcmp(name, "town") == 0)
        link_sub_map(tile, "town", 5, 5); /* TODO: Optional town sizes */

    /* cave map init code here */
}

void link_sub_map(tile_t *tile, char *mapid, int width, int length) {
    /* Link a tile to a relevant sub map */

    tile->sub_map = new_map(mapid, width, length);
}

void print_tile(tile_t *cur_tile) {
    /* May remain in subsequent cycles for web interface purposes.
       Will possibly also show printout of players and mobs in a tile */

    printf("Tile name is: %s, and its position is (%d, %d)\n", cur_tile->name, cur_tile->x, cur_tile->y);
}
