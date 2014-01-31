/* map.c - generates a map structure with a grid full of pointers to tile structures and provides other map functions */
#include "map.h"
#include <stdio.h>
#include <stdlib.h>

map_t* new_map(char* id, int width, int length) {

    int i, j;

    /* Allocate memory the size of a map_t structure + the size of the contained grid of tile_t structures */
    map_t *map = malloc((sizeof(map_t) - sizeof(tile_t)) + (sizeof(tile_t)*width*length));
    if(map == NULL) {
        fprintf(stderr, "Error, could not allocate memory for map_t structure\n");
        exit(1); /* Exit codes to be defined for subsequent cycles */
    }

    map->id = id;
    map->width = width;
    map->length = length;
    map->grid = (tile_t***) malloc(width * sizeof(tile_t**)); /* Allocate memory for 1st dimension */
    if(map->grid == NULL) {
        fprintf(stderr, "Error, could not allocate memory for map_t->grid\n");
        exit(1); /* Exit codes to be defined for subsequent cycles */
    }

    /* Fill the grid with blank tiles - PRE-ALPHA STAGE ONLY; SUBSEQUENT SOFTWARE CYCLES WILL POPULATE INTELLIGENTLY */
    for(i = 0; i <= width; i++) {
        map->grid[i] = (tile_t**) malloc(length * sizeof(tile_t *)); /* Allocate memory per row for 2nd dimension */
        if(map->grid[i] == NULL) {
            fprintf(stderr, "Error, could not allocate memory for map_t->grid[%d]\n", i);
            exit(1); /* Exit codes to be defined for subsequent cycles */
        }
        
        /* In subsequent software cycles, this inner loop should be removed and `calloc` should be used above to zero-initialise pointers. */
        /* Map population will be be handled in a separate function in this file. */
        for(j = 0; j <= length; j++) {
            map->grid[i][j] = new_tile("blank", i, j);
        }
    }

    return map;
}

void print_map(map_t *map) {
/* This function will remain as it may be of use for web interface. */
    int i, j;

    for(j = 0; j < map->length; j++) {

        printf("[");
        for(i = 0; i < map->width; i++) {
            printf("['%s': (%d, %d)]", map->grid[i][j]->name, map->grid[i][j]->x, map->grid[i][j]->y);
        }
        printf("]\n");
    }
}

int main(int argc, char **argv) {
/* Main function only for purposes of map testing. TO BE REMOVED IN SUBSEQUENT CYCLES. */

    printf("Generating Map.\n");
    map_t *map = new_map(10, 10);

    if(map == NULL)
        printf("Map generation failed.\n");
    else
        printf("Hurray, we have a map! Generation succeeded.\n");

    printf("Testing printing of map.\n");
    print_map(map);

    return 0;
}

