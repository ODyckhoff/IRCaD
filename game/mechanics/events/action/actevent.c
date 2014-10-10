/* actevent.c - takes charge of action events and their population. */

#include <stdio.h>
#include <stdlib.h>

#include "actevent.h"


act_drop_ev *build_act_drop(int datasize, void *data) {

    act_drop_ev *drop = (act_drop_ev *) malloc( sizeof(act_drop_ev) );
    drop->item = (item_t *) get_act_data(ITEM, data);

    return drop;
}

act_inv_ev *build_act_inv(int datasize, void *data) {

    act_inv_ev *inv = (act_inv_ev *) malloc( sizeof(act_inv_ev) );
    inv->state = (int) *get_act_data(STATE, data);

    return inv;
}

act_look_ev *build_act_look(int datasize, void *data) {

    act_look_ev *look = (act_look_ev *) malloc( sizeof(act_look_ev) );
    look->direction = (int) *get_act_data(DIRECTION, data);

    return look;
}

act_move_ev *build_act_move(int datasize, void *data) {

    act_move_ev *move = (act_move_ev *) malloc( sizeof(act_move_ev) );
    move->direction = (int) *get_act_data(DIRECTION, data);

    return move;
}

act_take_ev *build_act_take(int datasize, void *data) {

    act_take_ev *take = (act_take_ev *) malloc( sizeof(act_take_ev) );
    take->item = (item_t *) get_act_data(ITEM, data);

    return take;
}

void *get_act_data(int type, int datasize, void *data) {

    int i;
    void *element;

    if( ! (data != NULL && datasize > 0) )
        return NULL;

    for( i = 0; i < datasize; i++ ) {
        element = data[i];
        if(element[0] == type)
            break;
    }

    return element[1];
}

