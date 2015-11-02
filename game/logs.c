/* logs.c - First port of call for log files. Configuration must be loaded first. */
#include "logs.h"

int loginit( IRCaD *ircad ) {

    FILE ** logfiles = malloc( NUMFILES * sizeof( FILE * ) );
    char *dbgpath;
    char *errpath;
    char *wrnpath;
    char *evtpath;
    char *ircpath;
    char *gmepath;
    void *tmp;

    if( ircad == NULL )
        return 1;
    if( ircad->cfg == NULL )
        return 2;

    dbgpath = cfg_get( ircad->cfg, "LOG_DEBUG_PATH" );
    errpath = cfg_get( ircad->cfg, "LOG_ERROR_PATH" );
    wrnpath = cfg_get( ircad->cfg, "LOG_WARN_PATH"  );
    evtpath = cfg_get( ircad->cfg, "LOG_EVENT_PATH" );
    ircpath = cfg_get( ircad->cfg, "LOG_IRC_PATH"   );
    gmepath = cfg_get( ircad->cfg, "LOG_GAME_PATH"  );

    /* Check the configs. */

    logfiles[ DEBUG ] = 
        ( dbgpath == NULL && ( tmp = cfg_get( ircad->cfg, "LOG_DEBUG" ) ) != NULL )
        ?
            ( atoi( tmp ) == 1 )
            ?
                fopen( DEFDEBUG, "a" )
            :
                fopen( dbgpath, "a" )
        : NULL
    ;
    
    logfiles[ ERROR ] = 
        ( errpath == NULL && ( tmp = cfg_get( ircad->cfg, "LOG_ERROR" ) ) != NULL )
        ?
            ( atoi( tmp ) == 1 )
            ?
                fopen( DEFERROR, "a" )
            :
                fopen( errpath, "a" )
        : NULL
    ;
    
    logfiles[ WARN ] = 
        ( wrnpath == NULL && ( tmp = cfg_get( ircad->cfg, "LOG_WARN" ) ) != NULL )
        ?
            ( atoi( tmp ) == 1 )
            ?
                fopen( DEFWARN, "a" )
            :
                fopen( wrnpath, "a" )
        : NULL
    ;
    
    logfiles[ EVENT ] = 
        ( evtpath == NULL && ( tmp = cfg_get( ircad->cfg, "LOG_EVENT" ) ) != NULL )
        ?
            ( atoi( tmp ) == 1 )
            ?
                fopen( DEFEVENT, "a" )
            :
                fopen( evtpath, "a" )
        : NULL
    ;
    
    logfiles[ IRC ] = 
        ( ircpath == NULL && ( tmp = cfg_get( ircad->cfg, "LOG_IRC" ) ) != NULL )
        ?
            ( atoi( tmp ) == 1 )
            ?
                fopen( DEFIRC, "a" )
            :
                fopen( ircpath, "a" )
        : NULL
    ;
    
    logfiles[ GAME ] = 
        ( gmepath == NULL && ( tmp = cfg_get( ircad->cfg, "LOG_GAME" ) ) != NULL )
        ?
            ( atoi( tmp ) == 1 )
            ?
                fopen( DEFGAME, "a" )
            :
                fopen( gmepath, "a" )
        : NULL
    ;


    ircad->logfiles = logfiles;
    
    return 0;
}

