/* engine.c - handler for the engine module. Will register engine listener with events and trigger events. */

#include "engine.h"

int enginit( IRCaD *ircad  ) {
    int err;

    ircad->events = inithmap( 1 );
    ircad->lstnrs = inithmap( 1 );

    /* Initialise event/listener interface. */
    err = evlstnrif_init( ircad );
    return err;
}

int engstart( IRCaD *ircad ) {

    int err = ev_start( ircad, "internal/init" );
    return err;
}

