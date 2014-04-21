/* gen.c - takes a map structure and handles generation of terrain */
#include "gen.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    int dir = 0;
    int stop = 0;

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
                if(! ((j == length_m - 2 || j == length_m + 2) && (i == width_m - 2 || i == width_m + 2))) {
                    set_id(tile_ptr, FARMLAND);
                }
            }
        }
    }

    /* Grassland around the farmland */
    for(j = length_m - 3; j <= length_m + 3; j++) {
        for(i = width_m - 3; i <= width_m + 3; i++) {
            tile_ptr = map->grid[i][j];
            if(! tile_ptr->id) {
                if(! ((j == length_m - 3 || j == length_m + 3) && (i == width_m - 3 || i == width_m + 3))) {
                    set_id(tile_ptr, GRASSLAND);
                }
            }
        }
    }

    /* Lair and mountain cave generation */

    
    /* Spawn terrain */
    tile_ptr = map->grid[width_m][length_m - 4]; /* Start at first blank tile north of town. */

    /* Go clockwise and outwards. */
    /* if South *and* East are  empty, move down and evaluate West tile.
       if North *and* East are empty, move East and evaluate South tile.
       if South *and* West are empty, move West and evaluate North tile.
       if North *and* West are empty, move North and evaluate East tile.
    */
    /* we start by moving east */

    srand((unsigned) time(NULL));
    do {
        switch(dir) {
            case 0:
                //printf("Beginning of case 0: All is well so far\n");
                while(chk_map(map, map->grid[tile_ptr->x + 1][tile_ptr->y + 1]) && map->grid[tile_ptr->x + 1][tile_ptr->y + 1]->id) {
                /* Whilst the South-East tile is occupied: */
                    tile_ptr = map->grid[tile_ptr->x + 1][tile_ptr->y]; /* Set pointer to East tile. */
                    if(tile_ptr->id) {
                        if(chk_map(map, map->grid[tile_ptr->x][tile_ptr->y - 1])) {
                            tile_ptr = map->grid[tile_ptr->x][tile_ptr->y - 1]; /* If id is set, set pointer to North tile. */
                        }
                        else {
                            do {
                                tile_ptr = map->grid[tile_ptr->x + 1][tile_ptr->y];
                            }
                            while(tile_ptr->id);
                        }
                    }
                    set_id(tile_ptr, snt(map->grid[tile_ptr->x][tile_ptr->y + 1]->id));
                            printf("x is %d and y is %d\n", tile_ptr->x, tile_ptr->y);
                }

                dir = 1;
                
                /* if(chk_map(map->grid[tile_ptr->x + 1][tile_ptr->y])) { */
                    tile_ptr = map->grid[tile_ptr->x + 1][tile_ptr->y];
                /* else {
                    do {
                        tile_ptr = map->grid[tile_ptr->x][tile_ptr->y];
                        dir = 0; */
                //printf("end of case 0: A-OK\n");
                print_map(map);
            break;

            case 1:
                //printf("Beginning of case 1: All is well so far\n");
                while(chk_map(map, map->grid[tile_ptr->x - 1][tile_ptr->y + 1]) && map->grid[tile_ptr->x - 1][tile_ptr->y + 1]->id) {
                //printf("BEGIN WHILE\n");
                /* Whilst the South-West tile is occupied: */
                    if(chk_map(map, map->grid[tile_ptr->x][tile_ptr->y + 1]))
                        tile_ptr = map->grid[tile_ptr->x][tile_ptr->y + 1]; /* Set pointer to South tile. */
                    if(tile_ptr->id) {
                        //printf("Tile has an ID\n");
                        if(chk_map(map, map->grid[tile_ptr->x + 1][tile_ptr->y])) {
                            //printf("This tile pointer is valid\n");
                            tile_ptr = map->grid[tile_ptr->x + 1][tile_ptr->y]; /* If id is set, set pointer to East tile. */
                        }
                        else {
                            //printf("this tile pointer is invalid\n");
                            do {
                                tile_ptr = map->grid[tile_ptr->x][tile_ptr->y + 1];
                                //printf("added 1 to y\n");
                            }
                            while(tile_ptr->id);
                        }
                    }
                    set_id(tile_ptr, snt(map->grid[tile_ptr->x - 1][tile_ptr->y]->id));
                            printf("x is %d and y is %d\n", tile_ptr->x, tile_ptr->y);
                }

                dir = 2;
                tile_ptr = map->grid[tile_ptr->x][tile_ptr->y + 1];
                //printf("end of case 1: A-OK\n");
                print_map(map);
            break;

            case 2:
                printf("Beginning of case 2: All is well so far\n");
                while(chk_map(map, map->grid[tile_ptr->x - 1][tile_ptr->y - 1]) && map->grid[tile_ptr->x - 1][tile_ptr->y - 1]->id) {
                /* Whilst the North-West tile is occupied: */
                    tile_ptr = map->grid[tile_ptr->x - 1][tile_ptr->y]; /* Set pointer to West tile. */
                    if(tile_ptr->id) {
                        if(chk_map(map, map->grid[tile_ptr->x][tile_ptr->y + 1])) {
                            tile_ptr = map->grid[tile_ptr->x][tile_ptr->y + 1]; /* If id is set, set pointer to South tile. */
                        }
                        else {
                            do {
                                tile_ptr = map->grid[tile_ptr->x - 1][tile_ptr->y];
                            }
                            while(tile_ptr->id);
                        }
                    }
                    set_id(tile_ptr, snt(map->grid[tile_ptr->x][tile_ptr->y - 1]->id));
                            printf("x is %d and y is %d\n", tile_ptr->x, tile_ptr->y);
                }

                dir = 3;
                tile_ptr = map->grid[tile_ptr->x - 1][tile_ptr->y];
                printf("end of case 2: A-OK\n");
                print_map(map);
            break;

            case 3:
                printf("Beginning of case 3: All is well so far\n");
                while(chk_map(map, map->grid[tile_ptr->x + 1][tile_ptr->y - 1]) && map->grid[tile_ptr->x + 1][tile_ptr->y - 1]->id) {
                /* Whilst the North-East tile is occupied: */
                    tile_ptr = map->grid[tile_ptr->x][tile_ptr->y - 1]; /* Set pointer to North tile. */
                    if(tile_ptr->id) {
                        if(chk_map(map, map->grid[tile_ptr->x - 1][tile_ptr->y])) {
                            tile_ptr = map->grid[tile_ptr->x - 1][tile_ptr->y]; /* If id is set, set pointer to West tile. */
                        }
                        else {
                            do {
                                tile_ptr = map->grid[tile_ptr->x][tile_ptr->y - 1];
                            }
                            while(tile_ptr->id);
                        }
                    }
                    set_id(tile_ptr, snt(map->grid[tile_ptr->x + 1][tile_ptr->y]->id));
                            printf("x is %d and y is %d\n", tile_ptr->x, tile_ptr->y);
                }

                print_map(map);
                dir = 0;
                tile_ptr = map->grid[tile_ptr->x][tile_ptr->y - 1];
                printf("end of case 3: A-OK\n");
            break;
        }
    } while(!stop);
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

int snt(int id) {
    float total_p = 1; /* total probability of a given spawn set will be 1 */
    typedef struct p {
        float probability;
        int id;
    } p;

    p gr[3] = {{0.5, GRASSLAND}, {0.4, SHRUBLAND}, {0.1, FOREST}};
    p sh[5] = {{0.3, SHRUBLAND}, {0.2, GRASSLAND}, {0.2, FOREST}, {0.2, SWAMP}, {0.1, TUNDRA}};
    p fo[6] = {{0.4, FOREST}, {0.1, SHRUBLAND}, {0.2, DEEPFOREST}, {0.1, GRASSLAND}, {0.1, TAIGA}, {0.1, TUNDRA}};
    p sw[4] = {{0.4, SWAMP}, {0.4, SHRUBLAND}, {0.1, TUNDRA}, {0.1, TAIGA}};
    p tu[5] = {{0.3, TUNDRA}, {0.3, TAIGA}, {0.2, FOREST}, {0.1, SHRUBLAND}, {0.1, SWAMP}};
    p df[2] = {{0.5, DEEPFOREST}, {0.5, FOREST}};
    p ta[4] = {{0.4, TAIGA}, {0.3, TUNDRA}, {0.2, FOREST}, {0.1, SWAMP}};
    
    float x = ((float)rand()/(float)(RAND_MAX)) * total_p;
    p* current;

    switch(id) {
        case GRASSLAND:  current = &gr[0]; break;
        case SHRUBLAND:  current = &sh[0]; break;
        case FOREST:     current = &fo[0]; break;
        case SWAMP:      current = &sw[0]; break;
        case TUNDRA:     current = &tu[0]; break;
        case DEEPFOREST: current = &df[0]; break;
        case TAIGA:      current = &ta[0]; break;
    }

    while((x -= current->probability) > 0)
        ++current;

    /* `current` now points to selected value */
    return current->id;
}
