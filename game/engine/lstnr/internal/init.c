/* init.c - initialisation listener */

/* An event is triggered when the engine has finished initialising.
     This listener will catch that event and start the IRC interface. */

#include <stdlib.h>
#include <stdio.h>

#include "init.h"
#include "../../../Circle/init.h"
#include "../../../Circle/handler.h"

int init_lstnr( init_ev *event ) {

    int SUCCESS = 0;
    int BADDATA = 1; /* Corrupted event struct */
    int NOEVENT = 2; /* Given event pointer is NULL */
    int INVALID = 3; /* The result of the operation(s) is a non-SUCCESS. */

    

}
