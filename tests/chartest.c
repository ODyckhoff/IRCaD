#include <stdio.h>

#include "player.h"
#include "../environment/map/map.h"

int main(int argc, char** argv) {
    /* Create a player */
    player_t* player = new_player(0, 0);

    /* Create a character for the player. */
    new_character(player, 0, "Owen", 4, 20);

    /* Generate map. */
    map_t* map = new_map(WORLDMAP, 20, 20);
    world_gen(map);
    town_gen(map->town);

    /* Assign character to map. */
    set_parmap(player->charlist[0], map);

    /* Set current map to town map. */
    set_curmap(player->charlist[0], map->town);

    /* Set position to center of map. */
    set_curpos_tile(player->charlist[0], map->town->grid[2][2]);


    /* Now we test some stuff. */

    print_tile(player->charlist[0]->curpos);
    printf("Char Name is %s\n", player->charlist[0]->name);
}
