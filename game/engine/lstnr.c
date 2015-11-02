/* lstnr.c - interface for all listener related functions. */

#include <stdlib.h>
#include <stdio.h>

#include "lstnr.h"
#include "lstnr/internal.h"

int lstnr_init( IRCaD *ircad ) {

    lstnrlist_t *list = malloc( sizeof( lstnrlist_t ) );
    if( list == NULL ) {
        return 1;
    }


    return 0;
}
