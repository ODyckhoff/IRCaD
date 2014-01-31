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

    if(strcmp(tile->name, "town") == 0)
        tile->sub_map = new_map("town", 3, 3);

    /* cave map init code here */

    return tile;
}

void print_tile(tile_t *cur_tile) {
    /* May remain in subsequent cycles for web interface purposes.
       Will possibly also show printout of players and mobs in a tile */

    printf("Tile name is: %s, and its position is (%d, %d)\n", cur_tile->name, cur_tile->x, cur_tile->y);
}
