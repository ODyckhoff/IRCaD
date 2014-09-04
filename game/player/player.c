#include <stdlib.h>

#include "player.h"

player_t* new_player(int account, int priv) {
    player_t *player = malloc(sizeof(player_t));
    
    player->account = account;
    player->priv = priv;
    player->num_chars = 0;

    player->charlist = malloc(sizeof(character_t*) * 10);

    return player;
}

void new_character(player_t* player, int id, char* name, int race, int class) {
    if(player->num_chars < 10) {
        character_t* character = new_char(id, name, race, class);

        if(character == NULL)
            return;

        player->charlist[player->num_chars] = character;
        player->num_chars++;
    }
}
>>>>>>> master
