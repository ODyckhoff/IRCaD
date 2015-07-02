#ifndef __ACT_LSTNHANDLER_H
#define __ACT_LSTNHANDLER_H

enum act_lstnr_e {
    DROP,
    INVENTORY,
    LOOK,
    MOVE,
    TAKE
};

typedef struct act_lstnr_t {
    enum act_lstnr_e lstnrtype;
    union {
        struct act_drop_lstnr_t drop;
        struct act_inv_lstnr_t inv;
        struct act_look_lstnr_t look;
        struct act_move_lstnr_t move;
        struct act_take_lstnr_t take;
    };
} act_lstnr_t;

typedef struct act_lstnrdata_t {
    enum act_lstnr_e lstnrtype;
    union {
        struct act_drop_lstnrdata_t drop;
        struct act_inv_lstnrdata_t inv;
        struct act_look_lstnrdata_t look;
        struct act_move_lstnrdata_t move;
        struct act_take_lstnrdata_t take;
    };
} act_lstnrdata_t;

#endif /* __ACT_LSTNHANDLER_H */
