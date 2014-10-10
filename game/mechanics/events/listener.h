#ifndef LISTENER_H
#define LISTENER_H

void addGenListener();
void addMoveListener();
void addTurnListener();
void addSpawnListener(); /* Death and respawns */
void addBattleListener();
void addMerchListener();
void addInvListener();

typedef struct listener_t {

    struct act_listener_t *action;
    struct char_listener_t *character;
    struct com_listener_t *combat;
    struct game_listener_t *game;
    struct interact_listener_t *interact;
    struct intern_listener_t *internal;
    struct party_listener_t *party;
    struct player_listener_t *player;
    struct world_listener_t *world;

} listener_t;

#endif /* LISTENER_H */
