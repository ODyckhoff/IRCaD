/* IRCaD.c - The mother ship. Gets the ball rolling. */

#include <stdlib.h>
#include <stdio.h>

#include "IRCaD.h"
/*#include "game.h"*/
#include "mechanics.h"
#include "irch.h"
#include "utils/share.h"

#include "Circle/init.h"
#include "Circle/handler.h"

IRCaD *ircad;

int main( int argc, char **argv ) {

    /* So... it begins. Let's make the IRCaD instance. */
    ircad = malloc( sizeof( IRCaD ) );

    ircad->listeners = reglstnr(); /* Initialise all event listeners */
    ircad->irc = init_irc();       /* Initialise the IRC instance. */
        addhndlr( ircad->irc, irchandler ); /* Register IRC handler. */

    irc_run();
    
    return EXIT_SUCCESS;
}

