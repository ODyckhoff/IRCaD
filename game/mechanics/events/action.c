#include <stdlib.h>
#include <stdio.h>

#include "action.h"

void *new_act_ev(event_t *e, int datasize, void *data) {
    void *event;
    switch(e->category) {
        case ACT_DROP:
            event = (act_drop_ev *) malloc( sizeof(act_drop_ev) );
            build_act_drop(event, datasize, data);
        break;
        case ACT_INV:
            event = (act_inv_ev *) malloc( sizeof(act_inv_ev) );
            event = build_act_inv(e, datasize, data);
        break;
        case ACT_LOOK:
            event = (act_look_ev *) malloc( sizeof(act_look_ev) );
            event = build_act_look(e, datasize, data);
        break;
        case ACT_MOVE:
            event = (act_move_ev *) malloc( sizeof(act_move_ev) );
            event = build_act_move(e, datasize, data);
        break;
        case ACT_TAKE:
            event = (act_take_ev *) malloc( sizeof(act_take_ev) );
            event = build_act_take(e, datasize, data);
        break;
        default:
            return NULL;
        }
    }
    
    return event;
}
