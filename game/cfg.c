/* cfg.c - First port of call for configuration files. */
#include "cfg.h"

int loadcfg( IRCaD *ircad ) {

    hashmap_t *cfg;

    cfg = inithmap( 1 );

    if( cfg == NULL ) {
        return 1;
    }

    /* Load files, put stuff in hashmap. */
    ircad->cfg = cfg;

    return 0;
}

void *cfg_get( hashmap_t *hm, char *key ) {
    /* return gethmap( hm, key ); */
    return "1";
}
