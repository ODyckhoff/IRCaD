#ifndef __NPC_DEF_H
#define __NPC_DEF_H

typedef struct npc_t {
    int id;
    char *name;
    int type; /* shop, relationship, quest, special. */
    int prof; /* Profession: Marketeer, Blacksmith... */
    sched_t *timetable;

} npc_t;

typedef enum npc_type_e {
    NONE  = 0,
    SHOP  = 1,
    REL   = 2,
    QUEST = 3,
    SPEC  = 4

} npc_type_e;

typedef enum prof_e {
    NONE       = 0,
    MARKET     = 1,
    BLCKSMITH  = 2,
    MAGE       = 3,
    GUILDMSTR  = 4,
    INNKEEP1   = 5,
    INNKEEP2   = 6,
    TGUARD1    = 7,
    TGUARD2    = 8,
    TGUARD3    = 9,
    TGUARD4    = 10,
    BLCKMARKET = 11,
    AUCTION    = 12,
    FARMER     = 13,
    WOODSMAN   = 14,
    SHRINE     = 15,
    STPERFORM  = 16,
    WAITRESS   = 17,
    GARDENER   = 18,
    RELATION1  = 19,
    RELATION2  = 20,
    RELATION3  = 21,
    RELATION4  = 22

} prof_e;

#endif /* __NPC_DEF_H */
