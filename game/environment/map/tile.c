/* tile.c - generates a tile_t structure and provides other tile manipulation functions. */
#include "tile.h"
#include <stdio.h>
#include <stdlib.h>

tile_t* new_tile(char *name, int x, int y) {
    
    tile_t *init = malloc(sizeof(tile_t));
    if(init == NULL) {
        fprintf(stderr, "Error, could not allocate memory for tile_t structure\n");
        exit(1); /* Exit codes to be defined for subsequent cycles */
    }

    init->name = name;
    init->x = x;
    init->y = y;

    return init;
}

void print_tile(tile_t *cur_tile) {
    /* May remain in subsequent cycles for web interface purposes.
       Will possibly also show printout of players and mobs in a tile */

    printf("Tile name is: %s, and its position is (%d, %d)\n", cur_tile->name, cur_tile->x, cur_tile->y);
}
