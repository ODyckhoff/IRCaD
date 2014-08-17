/* validate.c - validates event data. For example, checks that there is a tile where a player wants to move. */

#include <stdio.h>
#include <stdlib.h>

#include "validate.h"

/* Invoke validators for individual event types. */



/* Failure case: 'invalid event'. For when an event is not possible e.g. moving to a non-existent tile. */
    /* Report to event handler. */



/* Failure case: 'illegal event'. Indicates that data is corrupted, doesn't make sense, or violates game rules. */
    /* Report to system error handler. */
