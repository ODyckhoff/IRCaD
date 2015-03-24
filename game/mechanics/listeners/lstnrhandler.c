

#include "lstnrhandler.h"

void rmlstnr( LstnrList_t ll, int type, int cat, void ( *fp )() ) {

    switch( type ) {

        case ACTION:
            rmactlstnr( ll, cat, fp );
        break;

        case COMBAT:
            rmcomlstnr( ll, cat, fp );
        break;

        case INTERFACE:
            rmifacelstnr( ll, cat, fp );
        break;

        case PARTY:
            rmpartylstnr( ll, cat, fp );
        break;

        case CHARACTER:
            rmchrctrlstnr( ll, cat, fp );
        break;

        case GAME:
            rmgamelstnr( ll, cat, fp );
        break;

        case INTERNAL:
            rmintrnllstnr( ll, cat, fp );
        break;

        case PLAYER:
            rmplayerlstnr( ll, cat, fp );
        break;

        case WORLD:
            rmworldlstnr( ll, cat, fp );
        break;

    }

}

void addlstnr( LstnrList_t ll, int type, int cat, void ( *fp )() ) {

    switch( type ) {

        case ACTION:
            addactlstnr( ll, cat, fp );
        break;

        case COMBAT:
            addcomlstnr( ll, cat, fp );
        break;

        case INTERFACE:
            addifacelstnr( ll, cat, fp );
        break;

        case PARTY:
            addpartylstnr( ll, cat, fp );
        break;

        case CHARACTER:
            addchrctrlstnr( ll, cat, fp );
        break;

        case GAME:
            addgamelstnr( ll, cat, fp );
        break;

        case INTERNAL:
            addintrnllstnr( ll, cat, fp );
        break;

        case PLAYER:
            addplayerlstnr( ll, cat, fp );
        break;

        case WORLD:
            addworldlstnr( ll, cat, fp );
        break;

    }

}
