#ifndef __IRCAD_CFG_H
#define __IRCAD_CFG_H

#include <stdlib.h>
#include <stdio.h>

#include "utils/hashmap.h"
#include "cfg/hndlr.h"

#include "IRCaD.h"

int loadcfg( IRCaD *ircad );
void *cfg_get( hashmap_t *hm, char *key );

#endif /* __IRCAD_CFG_H */
