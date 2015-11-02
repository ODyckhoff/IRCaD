/* event.c - it does events */
#include "event.h"

int evlstnrif_init( IRCaD *ircad ) {
    int i = 0;
    struct dispatch_table *d;
    for( i = 0; i < NUMEV; i++ ) {
        d = malloc( sizeof( struct dispatch_table ) );
        d->name = dispatcher[ i ].name;
        d->function = dispatcher[ i ].function;

        puthmap( ircad->events, dispatcher[ i ].name, d );
    }

    return 0;
}

int ev_start( IRCaD *ircad, char *name ) {
    int i;
    int err = -1;
    event_t *data = malloc( sizeof( event_t ) );

    struct dispatch_table *d = gethmap( ircad->events, name );
    err = d->function( ircad, data );

    if( err > 0) {
        fprintf( stderr, "failed: %d\n", err );
        return 1;
    }
    else if( err == -1 ) {
        /* no listeners or nothing happened. */
       return -1;
    }
    else {
        ev_trigger( ircad, name, data );
    }
    return 0;
}

int ev_trigger( IRCaD *ircad, char *name, event_t *data ) {
    /* Get listeners. */

    
}
