#ifndef __IRCAD_H
#define __IRCAD_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "utils/hashmap.h"
typedef struct _IRCaD {

    hashmap_t *cfg;
    hashmap_t *events;
    hashmap_t *lstnrs;
    FILE **logfiles;
    char *test;
    
} IRCaD;

#include "cfg.h"
#include "engine.h"
#include "logs.h"

#endif /* __IRCAD_H */
