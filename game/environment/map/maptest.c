/* maptest.c - A file intended solely for testing the map functionality and is not meant to be a part of the game itself. */
#include "map.h"
#include "tile.h"
#include "gen.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

