#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "hashmap.h"

/* START HASHMAP */

/* Preamble
 * ---------
 *
 * Whilst, in theory, it's probably simpler to have a dynamically resized
 *   array of list_t structs, the look-up time increases drastically
 *   as the data set grows large.
 *
 * For this reason, I have made a generic type hashmap solution,
 *   which works on key/value pairs. The key is a string, and the value
 *   is a void pointer.
*/

hashmap_t *inithmap( int sizefactor ) {
    hashmap_t *hm = malloc( sizeof( hashmap_t ) );
    if( ! hm ) return NULL;
    if( sizefactor <= 0 ) sizefactor = 1;

    hm->capacity = sizefactor * INITIAL_SIZE;
    hm->size = 0;

    hm->buckets = calloc( hm->capacity, sizeof( bucket_t * ) );
    if( ! hm->buckets ) {
        freehmap( hm );
        return NULL;
    }

    return hm;
}

void freehmap( hashmap_t *hm ) {
    int i;
    entry_t *cur;

    if( ! hm ) return;

    if( hm->size == 0 || hm->buckets == NULL ) {
        free( hm );
        return;
    }

    if( hm->buckets ) {
        for( i = 0; i < hm->capacity; i++ ) {
            if( hm->buckets[ i ]->entries == NULL )
                continue;
            cur = &( hm->buckets[ i ]->entries[0] );
            do {
                free( cur->key );
                free( cur->value );
            }
            while( ( cur = cur->next ) != NULL );
        }
        free( hm->buckets );
    }

    free( hm );

    return;
}

int puthmap( hashmap_t *hm, char *key, void *value ) {

    int hashed;
    bucket_t *b_ptr = NULL;
    entry_t *e_ptr = NULL;

    if( ( hm->size + 1 ) >= THRESHOLD( hm->capacity ) )
        rehash( hm );

    hashed = hashstr( hm, key );

    if( hm->buckets[ hashed ] == NULL ) {
        /* No bucket. */

        b_ptr = malloc( sizeof( bucket_t ) );
        e_ptr = b_ptr->entries;
    }
    else if( b_ptr != NULL ) {
        /* Bucket exists. */
        if( b_ptr->numentries >= BUCKETTHOLD ) {
            rehash( hm );
        }
        for( ; ( e_ptr = b_ptr->entries->next ) != NULL ; ) {
            if( strcmp( e_ptr->key, key ) != 0 )
                return 1;
        }
        e_ptr = e_ptr->next;
    }

    e_ptr = malloc( sizeof( entry_t ) );
    if( e_ptr == NULL )
        return 2;

    e_ptr->key = malloc( strlen( key ) + 1 );
    if( e_ptr->key == NULL )
        return 3;

    e_ptr->key   = key;
    e_ptr->value = value;

    b_ptr->numentries++;
    b_ptr->entries =  e_ptr;
    hm->buckets[ hashed ] = b_ptr;
    hm->size++;

    return 0;
}

void *gethmap( hashmap_t *hm, char *str ) {
    entry_t *e_ptr;
    int hashed = hashstr( hm, str );

    if( hm->buckets[ hashed ] == NULL )
        return NULL;

    e_ptr = hm->buckets[ hashed ]->entries;
    
    while( strcmp( e_ptr->key, str ) != 0 ) {
        if( e_ptr->next != NULL )
            e_ptr = e_ptr->next;
        else
            return NULL;
    }

    return e_ptr->value;
}

int rehash( hashmap_t *oldhm ) {

    int curfactor = 1;
    int i;
    hashmap_t *newhm;
    entry_t *tmp;

    curfactor = oldhm->capacity / INITIAL_SIZE;
    newhm = inithmap( ++curfactor );

    for( i = 0; i < oldhm->capacity; i++ ) {
        if( oldhm->buckets[i] != NULL ) {
            tmp = oldhm->buckets[i]->entries;
            do {
                puthmap( newhm, tmp->key, tmp->value );
            }
            while( ( tmp = tmp->next ) != NULL );
        }
    }
    return EXIT_SUCCESS;
}

int hashstr( hashmap_t *hm, char *key ) {
/* Simple Bob Jenkins' hash algorithm. */

    size_t len = strlen( key );
    uint32_t hash = 0;
    int i = 0;

    for( hash = i = 0; i < ( int )len; ++i ) {
        hash += key[i];
        hash += ( hash << 10 );
        hash ^= ( hash >> 6  );
    }

    hash += ( hash << 3  );
    hash ^= ( hash >> 11 );
    hash += ( hash << 15 );

    return abs( hash ) % hm->capacity;
}
