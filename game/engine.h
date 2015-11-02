#ifndef __IRCAD_ENGINE_H
#define __IRCAD_ENGINE_H

#include <stdlib.h>
#include <stdio.h>

#include "utils/hashmap.h"
#include "engine/event.h"
#include "IRCaD.h"

int enginit( IRCaD *ircad );
int engstart( IRCaD *ircad );

#endif /* __IRCAD_ENGINE_H */
