/* cfg.c - loads relevant configurations. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "cfg.h"
#include "err.h"
#include "data.h"

void lsrvcfg( data_t *databuf ) {


    return;
}

void ldbcfg( data_t *databuf ) {

    FILE *f;
    char *dblist[2] = { "keydb", "ivdb" };
    char *fn;
    char *buffer = 0;
    char *ptr;
    char **lines;
    long length;
    int i, count;
    int len;
    int found = 0;

    databuf->dbh->name = malloc( sizeof( char ) * ( strlen( dblist[ databuf->dbh->db ] ) + 1 ) );
    strncpy( databuf->dbh->name, dblist[ databuf->dbh->db ], strlen( dblist[ databuf->dbh->db ] ) );

    fn = malloc( ( strlen( databuf->dbh->name ) + 5 ) * sizeof( char ) );

    sprintf( fn, "%s.cfg", databuf->dbh->name );
    f = fopen( fn, "r" );

    if( f == NULL ) {
        fprintf( stderr, "Error opening DB config file.\n" );
        databuf->err = ERR_DB_LOADCFG;
        return;
    }
    
    if( f ) {
        fseek( f, 0, SEEK_END );
        length = len = ftell( f );
        fseek( f, 0, SEEK_SET );
        buffer = malloc( length );
        if( buffer ) {
            fread( buffer, 1, length, f );
        }
        fclose( f );
    }

    if( buffer ) {
        for( i = 0, count = 0; i < len; i++ )
            count += ( buffer[i] == '\n' );

        buffer[ len - 1 ] = '\0';

        strsplit( lines, buffer, "\n" );
        if( lines == NULL ) {
            databuf->err = ERR_DB_EMPTYCFG;
            return;
        }

        for( i = 0; i < count; i++ ) {
            ptr = strsep( &lines[i], ":" );
            if( strncmp( lines[i], "DBUser", 6 ) == 0 )
                strncpy( databuf->dbh->user, lines[i], strlen( lines[i] ) );
            else if( strncmp( lines[i], "DBPass", 6 ) == 0)
                strncpy( databuf->dbh->user, lines[i], strlen( lines[i] ) );
            else {
                databuf->err = ERR_DB_BADCFG;
                return;
            }
        }
    }
    return;
}

void llogcfg( data_t *databuf ) {


    return;
}
