#ifndef IRCAD_H
#define IRCAD_H

#include "Circle/irc.h"

/*#include "game.h"*/
#include "mechanics/lstnr.h"

typedef struct IRCaD {

    int game_count;
    /*struct game_t *game_list;*/
    struct lstnrlist_t *listeners;

    struct irc_t *irc;
    
} IRCaD;

extern IRCaD ircad;

#endif /* IRCAD_H */
