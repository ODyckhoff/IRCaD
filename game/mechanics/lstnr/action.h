typedef struct act_lstnrlist_t {

    struct drop_lstnrlist_t *drop;
    struct inv_lstnrlist_t *inv;
    struct look_lstnrlist_t *look;
    struct move_lstnrlist_t *move;
    struct take_lstnrlist_t *take;

} act_lstnrlist_t;
