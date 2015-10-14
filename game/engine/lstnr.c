/* lstnr.c - interface for all listener related functions. */

#include <stdlib.h>
#include <stdio.h>

#include "lstnr.h"
#include "lstnr/internal.h"

lstnrlist_t *reglstnrs() {

    lstnrlist_t *list = malloc( sizeof( lstnrlist_t ) );

    /* Internal listeners last, so they can listen for other listeners */
    regintrnllstnrs(list);

    return list;
}
