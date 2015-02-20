/* IRCaD.c - The mother ship. Gets the ball rolling. */

#include <stdlib.h>
#include <stdio.h>

#include "IRCaD.h"
#include "game.h"
#include "mechanics/event.h"

int main( int argc, char **argv ) {

    IRCaD *ircad = new_ircad();
    

}


IRCaD *new_ircad() {

    IRCaD *ircad = malloc( sizeof( IRCaD ) );

    return ircad;
}
