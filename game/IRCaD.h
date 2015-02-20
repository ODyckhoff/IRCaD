#ifndef IRCAD_H
#define IRCAD_H

#include "game.h"
#include "mechanics/events/listener.h"

typedef struct IRCaD {

    int game_count;
    struct game_t *game_list;
    struct listener_t *listeners;
    
} IRCaD;

#endif /* IRCAD_H */
