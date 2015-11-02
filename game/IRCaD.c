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

    printf( "Starting IRCaD . . .           " );

    ircad = malloc( sizeof( IRCaD ) );

    if( ircad == NULL ) {
        printf( KWHT "[" KNRM " " KRED "FAIL" KNRM " " KWHT "]" KNRM " : Unable to allocate memory for IRCaD core.\n" );
        return EXIT_FAILURE;
    }
    else {
        printf( " " KWHT "[" KNRM " " KGRN "OK" KNRM " " KWHT "]" KNRM "\n" );
    }

    ircad->test = malloc( 7 );
    strcpy( ircad->test, "hello\0" );

    /* Load Configuration files. */

    printf( "Loading Configuration . . .    " );

    err = loadcfg( ircad );

    if( err < 0 ) {
        printf( KWHT "[" KNRM " " KRED "FAIL" KNRM " " KWHT "]" KNRM ": Unable to load configuration - %s\n", 
                strerror( errno )
        );
    }
    else {
        printf( " " KWHT "[" KNRM " " KGRN "OK" KNRM " " KWHT "]" KNRM "\n" );
    }

    /* Open log files. */
    err = loginit( ircad );

    /* Initialise IRCaD engine. */

    printf( "Initialising IRCaD Engine . . ." );

    err = enginit( ircad );
    
    if( err != 0 ) {
        printf( KWHT "[" KNRM " " KRED "FAIL" KNRM " " KWHT "]" KNRM "\nReason - Engine initialisation failed. Error code: %d\n", err );
        return EXIT_FAILURE;
    }
    printf( " " KWHT "[" KNRM " " KGRN "OK" KNRM " " KWHT "]" KNRM "\n" );
    
    printf( "Initialising IRC handler . . . " );
    err = engstart( ircad ); /* irc/start event will print "[ OK ]"  message. */

    if( err != 0 ) {
        printf( KWHT "[" KNRM " " KRED "FAIL" KNRM " " KWHT "]" KNRM "\nReason - IRC Handler failed. Error code: %d\n", err );
        return EXIT_FAILURE;
    }

    /* IRC Handler exited normally. */
    return EXIT_SUCCESS;
}

