/* IRCaD.c - The mother ship. Gets the ball rolling. */

#include <stdlib.h>
#include <stdio.h>

#include "IRCaD.h"
/*#include "game.h"*/
#include "engine.h"
#include "irch.h"
/*#include "utils/share.h"*/

#include "Circle/init.h"
#include "Circle/handler.h"

int main( int argc, char **argv ) {

    /* So... it begins. Let's make the IRCaD instance. */
    IRCaD *ircad = malloc( sizeof( IRCaD ) );

    enginit( ircad );

    ircad->irc = init_irc();       /* Initialise the IRC instance. */
        addhndlr( ircad->irc, irchandler ); /* Register IRC handler. */

    irc_run();
    
    return EXIT_SUCCESS;
}

