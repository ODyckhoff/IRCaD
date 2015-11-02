#ifndef __IRCAD_INTERNAL_INIT
#define __IRCAD_INTERNAL_INIT

#define INTERNAL_INIT_INTEREST "internal/init"
#define INTERNAL_INIT_LISTENER internal_init_lstnr

typedef struct _init_t {
    char *txt;
} init_t;

#include "IRCaD.h"

int internal_init_init();
int internal_init_unreg( void ( *lstnr )( void *data ) );
int internal_init_reg( void ( *lstnr )( void *data ) );
int internal_init( void *data );
int internal_init_lstnr( IRCaD *ircad, struct _event_t *data );
int internal_init_getdf( IRCaD *ircad, struct _event_t *data );

#include "engine/_ev_dispatch.h"

#endif /* __IRCAD_INTERNAL_INIT */
