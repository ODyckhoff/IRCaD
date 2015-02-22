/* gen.c - takes a map structure and handles generation of terrain */
#include "gen.h"
#include "exits.h"

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
    map->signif = tile_m;

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

    if(TESTMODE) {
        return;
    }
        
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
                while(chk_map(map, tile_ptr, 1, 1) && map->grid[tile_ptr->x + 1][tile_ptr->y + 1]->id) {
                /* Whilst the South-East tile is occupied: */
                    tile_ptr = map->grid[tile_ptr->x + 1][tile_ptr->y]; /* Set pointer to East tile. */
                    if(tile_ptr->id) {
                        if(chk_map(map, tile_ptr, 0, -1)) {
                            tile_ptr = map->grid[tile_ptr->x][tile_ptr->y - 1]; /* If id is set, set pointer to North tile. */
                        }
                        else {
                            do {
                                if(tile_ptr->x + 1 < map->width)
                                    tile_ptr = map->grid[tile_ptr->x + 1][tile_ptr->y];
                            }
                            while(tile_ptr->id);
                        }
                    }
                    set_id(tile_ptr, snt(map->grid[tile_ptr->x][tile_ptr->y + 1]->id));
                }

                dir = 1;
                
                if(chk_map(map, tile_ptr, 1, 0))
                    tile_ptr = map->grid[tile_ptr->x + 1][tile_ptr->y];
            break;

            case 1:
                while(chk_map(map, tile_ptr, -1, 1) && map->grid[tile_ptr->x - 1][tile_ptr->y + 1]->id) {
                /* Whilst the South-West tile is occupied: */
                    tile_ptr = map->grid[tile_ptr->x][tile_ptr->y + 1]; /* Set pointer to South tile. */
                    if(tile_ptr->id) {
                        if(chk_map(map, tile_ptr, 1, 0)) {
                            tile_ptr = map->grid[tile_ptr->x + 1][tile_ptr->y]; /* If id is set, set pointer to East tile. */
                        }
                        else {
                            do {
                                if(tile_ptr->y + 1 < map->length)
                                    tile_ptr = map->grid[tile_ptr->x][tile_ptr->y + 1];
                            }
                            while(tile_ptr->id);
                        }
                    }
                    set_id(tile_ptr, snt(map->grid[tile_ptr->x - 1][tile_ptr->y]->id));
                }

                dir = 2;

                if(chk_map(map, tile_ptr, 0, 1))
                    tile_ptr = map->grid[tile_ptr->x][tile_ptr->y + 1];
            break;

            case 2:
                while(chk_map(map, tile_ptr, -1, -1) && map->grid[tile_ptr->x - 1][tile_ptr->y - 1]->id) {
                /* Whilst the North-West tile is occupied: */
                    tile_ptr = map->grid[tile_ptr->x - 1][tile_ptr->y]; /* Set pointer to West tile. */
                    if(tile_ptr->id) {
                        if(chk_map(map, tile_ptr, 0, 1)) {
                            tile_ptr = map->grid[tile_ptr->x][tile_ptr->y + 1]; /* If id is set, set pointer to South tile. */
                        }
                        else {
                            do {
                                if(tile_ptr->x - 1 >= 0)
                                    tile_ptr = map->grid[tile_ptr->x - 1][tile_ptr->y];
                            }
                            while(tile_ptr->id);
                        }
                    }
                    set_id(tile_ptr, snt(map->grid[tile_ptr->x][tile_ptr->y - 1]->id));
                }

                dir = 3;

                if(chk_map(map, tile_ptr, -1, 0))
                    tile_ptr = map->grid[tile_ptr->x - 1][tile_ptr->y];
            break;

            case 3:
                while(chk_map(map, tile_ptr, 1, -1) && map->grid[tile_ptr->x + 1][tile_ptr->y - 1]->id) {
                /* Whilst the North-East tile is occupied: */
                    tile_ptr = map->grid[tile_ptr->x][tile_ptr->y - 1]; /* Set pointer to North tile. */
                    if(tile_ptr->id) {
                        if(chk_map(map, tile_ptr, -1, 0)) {
                            tile_ptr = map->grid[tile_ptr->x - 1][tile_ptr->y]; /* If id is set, set pointer to West tile. */
                        }
                        else {
                            do {
                                if(tile_ptr->y - 1 >= 0)
                                    tile_ptr = map->grid[tile_ptr->x][tile_ptr->y - 1];
                            }
                            while(tile_ptr->id);
                        }
                    }
                    set_id(tile_ptr, snt(map->grid[tile_ptr->x + 1][tile_ptr->y]->id));
                }

                dir = 0;

                if(chk_map(map, tile_ptr, 0, -1))
                    tile_ptr = map->grid[tile_ptr->x][tile_ptr->y - 1];
            break;
        }

        if(
            (map->grid[0][0]->id)               && 
            (map->grid[0][map->length - 1]->id) && 
            (map->grid[map->width - 1][0]->id)  &&
            (map->grid[map->width - 1][map->length - 1]->id)
        ) {
            stop = 1;
        }

    } while(!stop);
}

void town_gen(map_t *map) {
/* This function will generate a town map */
    if(map->id != TOWNMAP) {
        fprintf(stderr, "Error, provided map for town generation is not a TOWNMAP type\n");
        exit(1);
    }
    int features[] = {PARK, SHRINE, OUTDOORCAFE, PLAZA};

    int width_m = (map->width - 1)/2;
    int length_m = (map->length - 1)/2;

    /* Centre Tile becomes the Guild Hall */
    tile_t *tile_ptr = map->grid[width_m][length_m];
    set_id(tile_ptr, GUILDHALL);
    set_desc(tile_ptr, "The Guild Hall is the hub of the town's operations");
    map->signif = tile_ptr;

    /* Town Gates */
    tile_ptr = map->grid[2][0];
    set_id(tile_ptr, TOWNGATEINT);
    set_desc(tile_ptr, "North Gate");
    rmexit(tile_ptr, EAST | WEST);
    mkexit(tile_ptr, NORTH);

    tile_ptr = map->grid[4][2];
    set_id(tile_ptr, TOWNGATEINT);
    set_desc(tile_ptr, "East Gate");
    rmexit(tile_ptr, NORTH | SOUTH);
    mkexit(tile_ptr, EAST);

    tile_ptr = map->grid[2][4];
    set_id(tile_ptr, TOWNGATEINT);
    set_desc(tile_ptr, "South Gate");
    rmexit(tile_ptr, EAST | WEST);
    mkexit(tile_ptr, SOUTH);

    tile_ptr = map->grid[0][2];
    set_id(tile_ptr, TOWNGATEINT);
    set_desc(tile_ptr, "West Gate");
    rmexit(tile_ptr, NORTH | SOUTH);
    mkexit(tile_ptr, WEST);

    /* Buildings */
        /* Corner Buildings */
    tile_ptr = map->grid[0][0];
    set_id(tile_ptr, BREWGARDEN);
    rmexit(tile_ptr, SOUTH);

    tile_ptr = map->grid[0][4];
    set_id(tile_ptr, WORKSHOP);
    rmexit(tile_ptr, NORTH);

    tile_ptr = map->grid[4][0];
    set_id(tile_ptr, ALCHLAB);
    rmexit(tile_ptr, SOUTH);

    tile_ptr = map->grid[4][4];
    set_id(tile_ptr, BLACKMARKET);
    rmexit(tile_ptr, NORTH);

        /* North and South edges */
    tile_ptr = map->grid[1][0];
    set_id(tile_ptr, FARMERMARKET);
    rmexit(tile_ptr, EAST);

    tile_ptr = map->grid[1][4];
    set_id(tile_ptr, WARMOURSHOP);
    rmexit(tile_ptr, EAST);

    tile_ptr = map->grid[3][0];
    set_id(tile_ptr, POTIONSHOP);
    rmexit(tile_ptr, WEST);

    tile_ptr = map->grid[3][4];
    set_id(tile_ptr, ABANDONHOUSE);
    rmexit(tile_ptr, WEST);

        /* NPC Houses */
    tile_ptr = map->grid[0][1];
    set_id(tile_ptr, NPCHOUSE);
    set_desc(tile_ptr, "North-West House");
    rmexit(tile_ptr, NORTH | SOUTH);

    tile_ptr = map->grid[4][1];
    set_id(tile_ptr, NPCHOUSE);
    set_desc(tile_ptr, "North-East House");
    rmexit(tile_ptr, NORTH | SOUTH);

    tile_ptr = map->grid[0][3];
    set_id(tile_ptr, NPCHOUSE);
    set_desc(tile_ptr, "South-West House");
    rmexit(tile_ptr, NORTH | SOUTH);

    tile_ptr = map->grid[4][3];
    set_id(tile_ptr, NPCHOUSE);
    set_desc(tile_ptr, "South-East House");
    rmexit(tile_ptr, NORTH | SOUTH);

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
        fprintf(stderr, "Error, provided map for world generation is not a CAVEMAP type\n");
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

    p gr[3] = {{0.4, GRASSLAND}, {0.4, SHRUBLAND}, {0.2, FOREST}};
    p sh[4] = {{0.3, SHRUBLAND}, {0.2, GRASSLAND}, {0.3, FOREST}, {0.2, SWAMP}};
    p fo[5] = {{0.4, FOREST}, {0.1, SHRUBLAND}, {0.2, DEEPFOREST}, {0.1, TAIGA}, {0.2, TUNDRA}};
    p sw[5] = {{0.3, SWAMP}, {0.2, SHRUBLAND}, {0.2, TUNDRA}, {0.2, TAIGA}, {0.1, FOREST}};
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
