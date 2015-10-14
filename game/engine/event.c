/* event.c - it does events */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "event.h"
#include "events/action.h"

int inittev( int type, int category, int datasize, void *data ) {
    event_t *e;

    e = mkev( type, category );
    buildev( e, datasize, data );

    trigev( e );
}

int ev_hndlr( event_t *e, int handler, ... ) {
    int i;
    void ( *fp )();
    va_list ap;
    int datasize;
    void *data;

    if( handler == BUILD ) {
        va_start( ap, handler );
        datasize = va_arg( ap, int );
        data = va_arg( ap, void * );
    }

    switch( e->type ) {
        case ACTION:
            handler == BUILD ?
                act_ev_hndlr( e, handler, datasize, data )
            :
                act_ev_hndlr( e, handler );
        break;
    }

}

int buildev( event_t *e, int datasize, void *data ) {
    switch( e->type ) {
        case ACTION:
            e->event = new_act_ev(e, datasize, data);
        break;
        case CHARACTER:
            e->event = new_character_ev(e, datasize, data);
        break;
        case COMBAT:
            e->event = new_combat_ev(e, datasize, data);
        break;
        case GAME:
            e->event = new_game_ev(e, datasize, data);
        break;
        case INTERACT:
            e->event = new_interact_ev(e, datasize, data);
        break;
        case INTERNAL:
            e->event = new_internal_ev(e, datasize, data);
        break;
        case PARTY:
            e->event = new_party_ev(e, datasize, data);
        break;
        case PLAYER:
            e->event = new_player_ev(e, datasize, data);
        break;
        case WORLD:
            e->event = new_world_ev(e, datasize, data);
        break;
        default:
            return 0;
        break;
    }
}

int trigev( event_t *e ) {
    
}

int regevlstnrs( event_t *e ) {
    
}
