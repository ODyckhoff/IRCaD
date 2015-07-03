/* engine.c - handler for the engine module. Will register engine listener with events and trigger events. */

#include <stdio.h>
#include <stdlib.h>

#include "engine.h"
#include "engine/event.h"
#include "engine/lstnr.h"


int enginit( IRCaD *ircad ) {

    ircad->listeners = reglstnrs(); /* Initialise all event listeners */

    if( ircad->listeners == NULL )
        return -1;

    return 0;
}
  
