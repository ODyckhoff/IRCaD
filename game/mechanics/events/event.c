/* event.c - it does events */

#include <stdio.h>
#include <stdlib.h>

#include "event.h"
#include "action/actevent.h"

int buildevent(event_t *e, int datasize, void *data) {
    switch(e->type) {
        case ACTION:
            e->event = new_act_ev(e, datasize, data);
        break;

        case CHARACTER:
            e->event = new_character_ev(e, datasize, data);
        break;

        case COMBAT:
            e->event = new_combat_ev(e, datasize, data);
        break;

        case GAME:
            e->event = new_game_ev(e, datasize, data);
        break;

        case INTERACT:
            e->event = new_interact_ev(e, datasize, data);
        break;

        case INTERNAL:
            e->event = new_internal_ev(e, datasize, data);
        break;

        case PARTY:
            e->event = new_party_ev(e, datasize, data);
        break;

        case PLAYER:
            e->event = new_player_ev(e, datasize, data);
        break;

        case WORLD:
            e->event = new_world_ev(e, datasize, data);
        break;

        default:
            return 0;
        break;
    }
}
