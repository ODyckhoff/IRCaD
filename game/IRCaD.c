/* IRCaD.c - The mother ship. Gets the ball rolling. */

#include <stdlib.h>
#include <stdio.h>

#include "IRCaD.h"
/*#include "game.h"
#include "mechanics/event.h"*/
#include "irch.h"

#include "Circle/init.h"

IRCaD *ircad;

int main( int argc, char **argv ) {

    ircad = malloc( sizeof( IRCaD ) );
    ircad->irc = init_irc();

    sethandler( ircad->irc, irchandler );

    irc_run();

}

