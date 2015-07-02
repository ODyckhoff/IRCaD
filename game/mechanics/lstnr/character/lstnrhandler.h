
#ifndef __CHRCTR_LSTNHANDLER_H
#define __CHRCTR_LSTNHANDLER_H

enum chrctr_lstnr_e {
    DEATH,
    INVENTORY,
    LEVEL,
    PARTY,
    QUEST,
    SPAWN,
    XP
};

typedef struct chrctr_lstnr_t {
    enum chrctr_lstnr_e lstnrtype;
    union {
        struct chrctr_death_lstnr_t death;
        struct chrctr_inv_lstnr_t inv;
        struct chrctr_level_lstnr_t level;
        struct chrctr_party_lstnr_t party;
        struct chrctr_quest_lstnr_t quest;
        struct chrctr_spawn_lstnr_t spawn;
        struct chrctr_xp_lstnr_t xp;
    };
} chrctr_lstnr_t;

typedef struct chrctr_lstnrdata_t {
    enum chrctr_lstnr_e lstnrtype;
    union {
        struct chrctr_death_lstnrdata_t death;
        struct chrctr_inv_lstnrdata_t inv;
        struct chrctr_level_lstnrdata_t level;
        struct chrctr_party_lstnrdata_t party;
        struct chrctr_quest_lstnrdata_t quest;
        struct chrctr_spawn_lstnrdata_t spawn;
        struct chrctr_xp_lstnrdata_t xp;
    };
} chrctr_lstnrdata_t;

#endif /* __CHRCTR_LSTNHANDLER_H */
