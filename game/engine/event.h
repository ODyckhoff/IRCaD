#ifndef EVENT_H
#define EVENT_H

enum ev_hndlrs {
    BUILD,
    REGISTER
};

enum ev_types {
    ACTION    = 1,
    CHARACTER = 2,
    COMBAT    = 3,
    GAME      = 4,
    INTERACT  = 5,
    INTERNAL  = 6,
    PARTY     = 7,
    PLAYER    = 8,
    WORLD     = 9
};

enum ev_category {

    ACT_DROP,
    ACT_INV,
    ACT_LOOK,
    ACT_MOVE,
    ACT_TAKE,

    CHAR_DEATH,
    CHAR_INV,
    CHAR_LVL,
    CHAR_PARTY,
    CHAR_QUEST,
    CHAR_SPAWN,
    CHAR_EXP,
    CHAR_TURN,

    COM_START,
    COM_END,
    COM_CRIT,
    COM_HITS,
    COM_MISS,
    COM_LOSE,
    COM_WINS,
    COM_PVE,
    COM_PVP,

    GAME_START,
    GAME_DICE,
    GAME_END,

    INTERACT_QUEST,
    INTERACT_SHOP,
    INTERACT_TALK,

    INTERN_INIT,
    INTERN_CACHE,
    INTERN_DB,
    INTERN_LOAD,
    INTERN_SAVE,
    INTERN_IRC,
    INTERN_EXIT,

    PARTY_MEMBER,
    PARTY_PARTY,
    PARTY_LEAVE,

    PLAYER_ACC,
    PLAYER_CHAR,

    WORLD_MAP,
    WORLD_SPAWN

};

/* Main Event */

    typedef struct event_t {
        int listener_count;
        void (*listener_list[10])(void *);
        const enum types type;
        const enum categories category;
        void *event; /* Will point to a struct defined below. */
    } event_t;

/* Action Events */

    typedef struct act_drop_ev {
        /* struct item_t *item; // DOES NOT EXIST YET. */
    } act_drop_ev;

    typedef struct act_inv_ev {
        int status; /* Opening or closing inventory? */
    } act_inv_ev;

    typedef struct act_look_ev {
        int direction; /* What direction is the player looking? */
    } act_look_ev;

    typedef struct act_move_ev {
        int direction;
    } act_move_ev;

    typedef struct act_take_ev {
        /* struct item_t *item; // DOES NOT EXIST YET */
    } act_take_ev;

/* Character Events */


/* Combat Events */


/* Game Events */


/* Interact Events */


/* Internal Events */


/* Party Events */


/* Player Events */


/* World Events */


#endif /* EVENT_H */
