/* listener.c - main listener that broadcasts to all registered sub-listeners for that event type. */
/*            - also responsible for registering and removing listeners. */

#include <stdio.h>
#include <stdlib.h>

#include "listener.h"

/* Utility functions. */
    /* Register listener. */



    /* Remove listener. */



    /* Sort listeners by priority: System, Logs, Achievements. */



/* Trigger registered listeners with event structs. */




/* Report to handler that all listeners have been triggered. */
