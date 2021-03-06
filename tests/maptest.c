/* maptest.c - A file intended solely for testing the map functionality and is not meant to be a part of the game itself. */
#include "../game/environment/map/map.h"
#include "../game/environment/map/tile.h"
#include "../game/environment/map/gen.h"
#include "../game/environment/map/exits.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char **argv) {
/* Main function only for purposes of map testing. TO BE REMOVED IN SUBSEQUENT CYCLES. */

    srand((unsigned) time(NULL)); /* seed for the entire program */

    printf("Generating Map.\n");
    map_t *map = new_map(WORLDMAP, 20, 20);    

    if(map == NULL)
        printf("Map generation failed.\n");
    else
        printf("Hurray, we have a map! Generation succeeded.\n");

    printf("Testing world generation in world_gen\n");
    clock_t cstart = clock();
    world_gen(map);
    clock_t cend = clock();
    clock_t cdiff = (long double )cend - cstart;

    time_t tstart = cstart/CLOCKS_PER_SEC;
    time_t tend = cend/CLOCKS_PER_SEC;
    long double tdiff = (long double)difftime(tend, tstart);

    printf("Generation complete in:\n\t%Lf CPU Clocks\n\t%Lf seconds\n", cdiff, tdiff);
    
    printf("Testing town generation in town_gen\n");
    town_gen(map->grid[(map->width - 1)/2][(map->length - 1)/2]->sub_map);

    printf("\nWorld Map\n========\n\n");
     print_map( ( irc_t * ) NULL, ( char * ) NULL, map);

    if(map->grid[(map->width - 1)/2][(map->length - 1)/2]->sub_map == NULL)
        fprintf(stderr, "Error, no Town Map linked\n");
    else
        printf("\nTown Map\n========\n\n");
        print_map( ( irc_t *) NULL, ( char * ) NULL,
                    map->grid[(map->width - 1)/2][(map->length - 1)/2]->sub_map);

    printf("Testing exits code\n");
    char *str = exitstr(15);
    printf("exit string = %s\n", str);
    if(isvalid(5, 5))
        printf("valid exits\n");

    if(isvalid(4, 6))
        printf("invalid exits\n");
    
    printf("Testing tile printing\n");
    /* four corners */
    print_tile(map->grid[0][0]);
    print_tile(map->grid[0][map->length - 1]);
    print_tile(map->grid[map->width - 1][map->length - 1]);
    print_tile(map->grid[map->width - 1][0]);

    /* pick an edge tile, any tile */
    print_tile(map->grid[0][(map->length - 1)/2]);
    print_tile(map->grid[(map->width - 1)/2][map->length - 1]);
    print_tile(map->grid[map->width - 1][(map->length - 1)/2]);
    print_tile(map->grid[(map->width - 1)/2][0]);

    map = map->grid[(map->width - 1)/2][(map->length - 1)/2]->sub_map;
    print_tile(map->grid[0][3]);

    /* test "spawn next to" rules */
/*    int x = atoi(argv[1]);
    printf("%d will spawn next to %d\n", snt(x), x);*/

    return 0;
}

