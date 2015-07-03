/* internal.c - interface for all internal listener related functions. */

#include <stdlib.h>
#include <stdio.h>

#include "internal.h"


intrnl_lstnrlist_t *regintrnllstnrs() {
    
    intrnl_lstnrlist_t list = malloc( sizeof( intrnl_lstnrlist_t ) );

    
    return list;
}
