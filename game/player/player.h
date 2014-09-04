#ifndef PLAYER_H
#define PLAYER_H

#include "character/character.h"

typedef struct player_t {
    int account;
    int priv;
    int num_chars;
    struct character_t **charlist;
} player_t;

player_t* new_player(int account, int priv);
void new_character(player_t* player, int id, char* name, int race, int class);


#endif /* PLAYER_H */
