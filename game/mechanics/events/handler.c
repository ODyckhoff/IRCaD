/* handler.c - will receive game and player input, validate it, then hand it to the listener for triggers. */

#include <stdio.h>
#include <stdlib.h>

#include "handler.h"

/* Invoke individual event type handlers. */
event_t *makeevent(int type, int category) {
    event_t *e = (event_t *) malloc( sizeof(event_t) );

    e->type = type;
    e->category = category;

    return e;
}


/* Pass control to the event validator. */



/* Success case: Pass control to event listener. */



/* Failure case: Report invalidity of event to player: e.g. "You cannot go that way!". */
