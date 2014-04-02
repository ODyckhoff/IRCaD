/* map.c - generates a map structure with a grid full of pointers to tile structures and provides other map functions */
#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* maptype_names[] = {"NULL", "World Map", "Town Map", "Cave Map"};

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
    int i, j;

    for(j = 0; j < map->length; j++) {

        for(i = 0; i < map->width; i++) {
            /* printf("[%d,%d]", map->grid[i][j]->x, map->grid[i][j]->y); */
            printf("[%02d]", get_id(map->grid[i][j]));
        }
        printf("\n");
    }
}

void world_gen(map_t *map) {
/* This function will generate a world map */
    if(map->id != WORLDMAP) {
        fprintf(stderr, "Error, provided map for world generation is not a WORLDMAP type\n");
        exit(1);
    }

    int width_m = (map->width - 1)/2;
    int length_m = (map->length - 1)/2;

    /* Set centre tile_t structure to "town" type. Set tile sub_map to new town map. */
    tile_t *tile_m = map->grid[width_m][length_m];
    set_id(tile_m, TOWN);
    print_tile(tile_m);

}

void town_gen(map_t *map) {
/* This function will generate a town map */
    if(map->id != TOWNMAP) {
        fprintf(stderr, "Error, provided map for world generation is not a TOWNMAP type\n");
        exit(1);
    }

    int features[] = {PARK, SHRINE, OUTDOORCAFE, PLAZA};

    int width_m = (map->width - 1)/2;
    int length_m = (map->length - 1)/2;

    /* Centre Tile becomes the Guild Hall */
    tile_t *tile_ptr = map->grid[width_m][length_m];
    set_id(tile_ptr, GUILDHALL);
    set_desc(tile_ptr, "The Guild Hall is the hub of the town's operations");

    /* Town Gates */
    tile_ptr = map->grid[2][0];
    set_id(tile_ptr, TOWNGATEINT);
    set_desc(tile_ptr, "North Gate");

    tile_ptr = map->grid[4][2];
    set_id(tile_ptr, TOWNGATEINT);
    set_desc(tile_ptr, "East Gate");

    tile_ptr = map->grid[2][4];
    set_id(tile_ptr, TOWNGATEINT);
    set_desc(tile_ptr, "South Gate");

    tile_ptr = map->grid[0][2];
    set_id(tile_ptr, TOWNGATEINT);
    set_desc(tile_ptr, "West Gate");

    /* Buildings */
        /* Corner Buildings */
    tile_ptr = map->grid[0][0];
    set_id(tile_ptr, BREWGARDEN);

    tile_ptr = map->grid[0][4];
    set_id(tile_ptr, WORKSHOP);

    tile_ptr = map->grid[4][0];
    set_id(tile_ptr, ALCHLAB);

    tile_ptr = map->grid[4][4];
    set_id(tile_ptr, BLACKMARKET);

        /* North and South edges */
    tile_ptr = map->grid[1][0];
    set_id(tile_ptr, FARMERMARKET);

    tile_ptr = map->grid[1][4];
    set_id(tile_ptr, WARMOURSHOP);

    tile_ptr = map->grid[3][0];
    set_id(tile_ptr, POTIONSHOP);

    tile_ptr = map->grid[3][4];
    set_id(tile_ptr, ABANDONHOUSE);

        /* NPC Houses */
    tile_ptr = map->grid[0][1];
    set_id(tile_ptr, NPCHOUSE);
    set_desc(tile_ptr, "North-West House");

    tile_ptr = map->grid[4][1];
    set_id(tile_ptr, NPCHOUSE);
    set_desc(tile_ptr, "North-East House");

    tile_ptr = map->grid[0][3];
    set_id(tile_ptr, NPCHOUSE);
    set_desc(tile_ptr, "South-West House");

    tile_ptr = map->grid[4][3];
    set_id(tile_ptr, NPCHOUSE);
    set_desc(tile_ptr, "South-East House");

    /* Randomly Assign Park, Shrine, Cafe and Plaza tiles */
    shuffle(features, sizeof(features)/sizeof(int));
    
    tile_ptr = map->grid[2][1];
    set_id(tile_ptr, features[0]);

    tile_ptr = map->grid[3][2];
    set_id(tile_ptr, features[1]);

    tile_ptr = map->grid[2][3];
    set_id(tile_ptr, features[2]);

    tile_ptr = map->grid[1][2];
    set_id(tile_ptr, features[3]);

    /* Set remaining squares to internal town tiles */
    tile_ptr = map->grid[1][1];
    set_id(tile_ptr, TOWNINT);

    tile_ptr = map->grid[3][1];
    set_id(tile_ptr, TOWNINT);

    tile_ptr = map->grid[1][3];
    set_id(tile_ptr, TOWNINT);

    tile_ptr = map->grid[3][3];
    set_id(tile_ptr, TOWNINT);
}

void cave_gen(map_t *map) {
/* This function will generate a cave map */
    if(map->id != CAVEMAP) {
        fprintf(stderr, "Error, provided map for world generation is not a WORLDMAP type\n");
        exit(1);
    }

}

void shuffle(int *array, int n) {
    srand((unsigned) time(NULL));

    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

int main(int argc, char **argv) {
/* Main function only for purposes of map testing. TO BE REMOVED IN SUBSEQUENT CYCLES. */

    printf("Generating Map.\n");
    map_t *map = new_map(WORLDMAP, 8, 8);

    if(map == NULL)
        printf("Map generation failed.\n");
    else
        printf("Hurray, we have a map! Generation succeeded.\n");

    printf("Testing town placement in world_gen\n");
    world_gen(map);
    printf("Testing town generation in town_gen\n");
    town_gen(map->grid[4][4]->sub_map);

    printf("Testing printing of map.\n");
    print_map(map);

    printf("Testing printing of town map\n");
    if(map->grid[4][4]->sub_map == NULL)
        fprintf(stderr, "Error, no Town Map linked\n");
    else
        print_map(map->grid[4][4]->sub_map);

    return 0;
}

