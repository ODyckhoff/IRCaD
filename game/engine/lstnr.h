#ifndef __IRCAD_LSTNR_H
#define __IRCAD_LSTNR_H

#include "IRCaD.h"

typedef struct lstnrlist_t {

    struct act_lstnrlist_t *act;
    struct chrctr_lstnrlist_t *chrctr;
    struct com_lstnrlist_t *com;
    struct game_lstnrlist_t *game;
    struct iface_lstnrlist_t *iface;
    struct intrnl_lstnrlist_t *intrnl;
    struct player_lstnrlist_t *player;
    struct world_lstnrlist_t *world;
} lstnrlist_t;

struct lstnrlist_t *reglstnrs();

int lstnr_init( IRCaD *ircad );

#endif /* __IRCAD_LSTNR_H */

