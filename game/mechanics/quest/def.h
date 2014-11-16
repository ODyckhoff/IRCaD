#ifndef __QUEST_DEF_H
#define __QUEST_DEF_H

typedef struct quest_t {
    int id;
    char *title;
    int type;
    list_t *prereqs;
    list_t *objetives;
    list_t *rewards;

} quest_t;

typedef enum quest_type_e {
    NONE    = 0,
    REL     = 1,
    KILL    = 2,
    ITEM    = 3,
    UNLOCK  = 4,
    DUNGEON = 5

} quest_type_e;

#endif /* __QUEST_DEF_H */
