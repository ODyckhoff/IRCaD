#ifndef EVENT_H
#define EVENT_H

enum types {
    ACTION    = 1,
    CHARACTER = 2,
    COMBAT    = 3,
    GAME      = 4,
    INTERACT  = 5,
    INTERNAL  = 6,
    PARTY     = 7,
    PLAYER    = 8,
    WORLD     = 9,
};

enum categories {

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

    COM_CRIT,
    COM_HITS,
    COM_MISS,
    COM_LOSE,
    COM_WINS,
    COM_PVE,
    COM_PVP,

    GAME_DICE,

    INTERACT_QUEST,
    INTERACT_SHOP,
    INTERACT_TALK,

    INTERN_CACHE,
    INTERN_DB,
    INTERN_LOAD,
    INTERN_SAVE,

    PARTY_MEMBER,
    PARTY_PARY,
    PARTY_LEAVE,

    PLAYER_ACC,
    PLAYER_CHAR,

    WORLD_MAP,
    WORLD_SPAWN

};

/* Generic Event */
typedef struct ev_t {
    const enum types type;
    const enum categories category;
    char* data;
} ev_t;

#endif /* EVENT_H */
