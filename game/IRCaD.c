/* IRCaD.c - The mother ship. Gets the ball rolling. */
#include "IRCaD.h"

#include "engine.h"
#include "logs.h"
#include "cfg.h"

#include "utils/termcol.h"

int main( int argc, char **argv ) {

    int err;
    IRCaD *ircad;

    if( argc > 1 ) {
        if( strcmp( argv[1], "-h" ) == 0 || strcmp( argv[1], "--help" ) == 0 ) {
            printf( "Here is some help.\n" );
            return EXIT_SUCCESS;
        }
    }

    /* So... it begins. Let's make the IRCaD instance. */

    printf( "Starting IRCaD . . . " );

    ircad = malloc( sizeof( IRCaD ) );
    ircad->id = 2;

    if( ircad == NULL ) {
        printf( KWHT "[" KNRM " " KRED "FAIL" KNRM " " KWHT "]" KNRM " : Unable to allocate memory for IRCaD core.\n" );
        return EXIT_FAILURE;
    }
    else {
        printf( KWHT "[" KNRM " " KGRN "OK" KNRM " " KWHT "]" KNRM "\n" );
    }

    /* Load Configuration files. */

    printf( "Loading Configuration . . . " );

    err = loadcfg( ircad );

    if( err < 0 ) {
        printf( KWHT "[" KNRM " " KRED "FAIL" KNRM " " KWHT "]" KNRM ": Unable to load configuration - %s\n", 
                strerror( errno )
        );
    }
    else {
        printf( KWHT "[" KNRM " " KGRN "OK" KNRM " " KWHT "]" KNRM "\n" );
    }

    /* Open log files. */
    err = loginit( ircad );

    /* Initialise IRCaD engine. */

    printf( "Initialising IRCaD Engine . . . " );

    enginit( ircad ); /* IRC_START event will print "[ OK ]"  message. */
    
    /* If we get here, engine initialisation failed
        somewhere prior to the IRCh taking control. */

    printf( KWHT "[" KNRM " " KRED "FAIL" KNRM " " KWHT "]" KNRM " : Engine initialisation failed.\n" );

    return EXIT_FAILURE;
}

