/* internal.c - a internal event. */

#include "init.h"

int internal_init_init() {

    return 0;
}

int internal_init_unreg( void ( *lstnr )( void *data ) ) {

    return 0;
}

int internal_init_reg( void ( *lstnr )( void *data ) ) {

    return 0;
}

int internal_init( void *data ) {

    return 0;    
}

int internal_init_lstnr( IRCaD *ircad, event_t *data ) {
    init_t *t = data->ev_data.init_data;
    /*init_t *t = (init_t*)data;*/
    printf( "This is a internal event. %s\n", t->txt );
    return 0;
}

int internal_init_getdf( IRCaD *ircad, event_t *data ) {

    if( data == NULL )
        return 1;
    data->ev_data.init_data = malloc( sizeof( init_t ) );
    if( data->ev_data.init_data == NULL )
        return 2;

    data->ev_data.init_data->txt = malloc( strlen( ircad->test ) + 1 );
    strcpy( data->ev_data.init_data->txt, ircad->test );

    return 0;
}
