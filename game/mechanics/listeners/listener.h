#ifndef __LISTENER_H
#define __LISTENER_H

enum lstnr_e {
    ACTION,
    COMBAT,
    INTERFACE,
    PARTY,
    CHARACTER,
    GAME,
    INTERNAL,
    PLAYER,
    WORLD
};

typedef struct lstnr_t {
    enum lstnr_e lstnrtype;
    union {
        struct action_lstnr_t act;
        struct combat_lstnr_t com;
        struct iface_lstnr_t  iface;
        struct party_lstnr_t  party;
        struct chrctr_lstnr_t chrctr;
        struct game_lstnr_t   game;
        struct intrnl_lstnr_t intrnl;
        struct player_lstnr_t player;
        struct world_lstnr_t  world;
    };
} lstnr_t;

typedef struct lstnrdata_t {
    enum lstnr_e lstnrtype;
    union {
        struct action_lstnrdata_t act;
        struct combat_lstnrdata_t com;
        struct iface_lstnrdata_t  iface;
        struct party_lstnrdata_t  party;
        struct chrctr_lstnrdata_t chrctr;
        struct game_lstnrdata_t   game;
        struct intrnl_lstnrdata_t intrnl;
        struct player_lstnrdata_t player;
        struct world_lstnrdata_t  world;
    };
} lstnrdata_t;

#endif /* __LISTENER_H */
