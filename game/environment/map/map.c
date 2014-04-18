/* map.c - generates a map structure with a grid full of pointers to tile structures and provides other map functions */
#include "colour.h"
#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* maptype_names[] = {"NULL", "World Map", "Town Map", "Cave Map"};
char* colours[] = { KNRM, KRED, KGRN, KYEL, KBLU, KMAG, KCYN, KWHT };

map_t* new_map(int mapid, int width, int length) {

    int i, j;

    /* First we ensure that width and length are odd numbers */
    if((width & 1) == 0)
        width++;

    if((length & 1) == 0)
        length++;

    /* Allocate memory the size of a map_t structure + the size of the contained grid of tile_t structures */
    map_t *map = malloc((sizeof(map_t) - sizeof(tile_t)) + (sizeof(tile_t)*width*length));
    if(map == NULL) {
        fprintf(stderr, "Error, could not allocate memory for map_t structure\n");
        exit(1); /* Exit codes to be defined for subsequent cycles */
    }
    
    map->id = mapid;
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
            map->grid[i][j] = new_tile(mapid, i, j);
        }
    }

    return map;
}

char* get_map_name(int id) {
    return maptype_names[id];
}

void print_map(map_t *map) {
/* This function will remain as it may be of use for web interface. */
    int i, j, id, tmp;
    char* colour;

    for(j = 0; j < map->length; j++) {

        for(i = 0; i < map->width; i++) {
            id = get_id(map->grid[i][j]);
            tmp = id;

            while(tmp > 7) {
                tmp -= 7; /* Make sure we don't go outside bounds of array. */
            }

            colour = colours[tmp];
            printf("[%s%02d%s]", colour, id, KNRM);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
/* Main function only for purposes of map testing. TO BE REMOVED IN SUBSEQUENT CYCLES. */

    printf("Generating Map.\n");
    map_t *map = new_map(WORLDMAP, 20, 20);

    if(map == NULL)
        printf("Map generation failed.\n");
    else
        printf("Hurray, we have a map! Generation succeeded.\n");

    printf("Testing town placement in world_gen\n");
    world_gen(map);
    printf("Testing town generation in town_gen\n");
    town_gen(map->grid[(map->width - 1)/2][(map->length - 1)/2]->sub_map);

    printf("Testing printing of map.\n");
    print_map(map);

    printf("Testing printing of town map\n");
    if(map->grid[(map->width - 1)/2][(map->length - 1)/2]->sub_map == NULL)
        fprintf(stderr, "Error, no Town Map linked\n");
    else
        print_map(map->grid[(map->width - 1)/2][(map->length - 1)/2]->sub_map);

    return 0;
}

