#ifndef ACTEVENT_H
#define ACTEVENT_H

#include "../event.h"

typedef enum act_data {
    DIRECTION,
    ITEM,
    STATE
} act_data;

void *new_act_ev(struct event_t *e, int datasize, void *data);

struct act_drop_ev *build_act_drop(int datasize, void *data);
struct act_inv_ev  *build_act_inv (int datasize, void *data);
struct act_look_ev *build_act_look(int datasize, void *data);
struct act_move_ev *build_act_move(int datasize, void *data);
struct act_take_ev *build_act_take(int datasize, void *data);

void *get_act_data(int type, int datasize, void *data);

#endif /* ACTEVENT_H */
