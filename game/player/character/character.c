/* character.c - Creates a new character. */

#include <stdio.h>
#include <stdlib.h>

#include "character.h"

character_t* new_char(int id, char* name, int race, int class) {
    character_t *character = malloc(sizeof(character_t));

    character->id    = id;
    character->name  = name;
    character->race  = race;
    character->pclass = class;

    character->xp = 0;
    character->level = 0;
}

void set_parmap(character_t* character, map_t* map) {
    character->parmap = map; 
}

void set_curmap(character_t* character, map_t* map) {
    character->curmap = map;
}

void set_curpos_tile(character_t* character, tile_t* tile) {
    character->curpos = tile;
}

void set_curpos_coord(character_t* character, int x, int y) {
    if(character->curmap == NULL)
        return;

    tile_t* tmp = character->curmap->grid[x][y];
    if(character->curmap->grid[x][y] == NULL)
        return;

    set_curpos_tile(character, character->curmap->grid[x][y]);
}
