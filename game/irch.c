#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "irch.h"
#include "Circle/irc.h"
#include "Circle/command.h"
#include "environment/map/map.h"
#include "environment/map/tile.h"
#include "environment/map/gen.h"
#include "environment/map/exits.h"

int irchandler( irc_t *irc, char *nick, char *channel, char *msg ) {

    char *token;
    char *args;
    int mapwidth;

    if( strncmp( msg, "GEN MAP", 7 ) == 0 ) {

        args = malloc( strlen( msg + 8 ) );
        strcpy( args, msg + 8 );
        token = strsep( &args, " " );
        mapwidth = atoi( token );

        map_t *map = new_map( WORLDMAP, mapwidth, mapwidth );
        world_gen( map );
        town_gen(map->grid[(map->width - 1)/2][(map->length - 1)/2]->sub_map);

        print_map(irc, channel, map);
    }

}
