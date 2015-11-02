#ifndef __IRCAD_EVENT_H
#define __IRCAD_EVENT_H

#include <stdlib.h>
#include <stdio.h>

#include "engine/_ev_dispatch.h"

typedef struct _lstnr_list {
    int num;
    int ( **functions )( IRCaD *ircad, struct _event_t *data );
} lstnr_list;

#include "IRCaD.h"
#include "utils/hashmap.h"

int evlstnrif_init( IRCaD *ircad );
int ev_start( IRCaD *ircad, char *name );
int ev_trigger( IRCaD *ircad, char *name, struct _event_t *data );

#endif /* __IRCAD_EVENT_H */
