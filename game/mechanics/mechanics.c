/* mechanics.c - handler for the mechanics module. Will register mechanics listener with events and trigger events. */

#include <stdio.h>
#include <stdlib.h>

#include "mechanics.h"

int startevent(int type, int category, int datasize, void *data) {
    event_t *e;

    e = makeevent(type, category);
       buildevent(e, datasize, data);
}
