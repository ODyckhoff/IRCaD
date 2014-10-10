/* game.c - will handle starting and ending of games. */

#include <stdlib.h>
#include <stdio.h>

#include "game.h"

game_t *new_game() {
    game_t *game = (game_t *) malloc( sizeof(game_t) );

    return game;
}
