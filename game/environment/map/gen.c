/* gen.c - takes a map structure and handles generation of terrain */
#include "gen.h"

#include <stdio.h>
#include <stdlib.h>

void world_gen(map_t *map) {
/* This function will generate a world map */
    if(map->id != WORLDMAP) {
        fprintf(stderr, "Error, provided map for world generation is not a WORLDMAP type\n");
        exit(1);
    }

    tile_t *tile_ptr;
    int i, j;
    int width_m = (map->width - 1)/2;
    int length_m = (map->length - 1)/2;

    /* Set centre tile_t structure to "town" type. Set tile sub_map to new town map. */
    tile_t *tile_m = map->grid[width_m][length_m];
    set_id(tile_m, TOWN);
    printf("Tile ID = %d; Sub Map is %s\n", tile_m->id, tile_m->sub_map != NULL ? "true" : "false");

    /* Town Gates to be places N, E, S and W of Town. */
    tile_ptr = map->grid[width_m][length_m - 1];
    set_id(tile_ptr, TOWNGATEEXT);
    set_desc(tile_ptr, "North Gate");

    tile_ptr = map->grid[width_m + 1][length_m];
    set_id(tile_ptr, TOWNGATEEXT);
    set_desc(tile_ptr, "East Gate");

    tile_ptr = map->grid[width_m][length_m + 1];
    set_id(tile_ptr, TOWNGATEEXT);
    set_desc(tile_ptr, "South Gate");

    tile_ptr = map->grid[width_m - 1][length_m];
    set_id(tile_ptr, TOWNGATEEXT);
    set_desc(tile_ptr, "West Gate");

    /* Farmland tiles radius 2 blocks from the Town, not replacing gates. */
    for(j = length_m - 2; j <= length_m + 2; j++) {
        for(i = width_m - 2; i <= width_m + 2; i++) {
            tile_ptr = map->grid[i][j];
            if(! tile_ptr->id) {
                if(! ((j == length_m - 2 || j == length_m + 2) && (i == width_m - 2 || i == width_m + 2)))
                    set_id(tile_ptr, FARMLAND);
            }
        }
    }

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
