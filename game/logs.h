#ifndef __IRCAD_LOGS_H
#define __IRCAD_LOGS_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "IRCaD.h"
#include "cfg.h"
#include "logs/hndlr.h"

typedef enum _logtype_e {

    DEBUG = 0,
    ERROR,
    WARN,
    EVENT,
    IRC,
    GAME

} logtype_e;

#define NUMFILES 6
#define DEFDEBUG "/logs/debug.log"
#define DEFERROR "/logs/error.log"
#define DEFWARN  "/logs/warn.log"
#define DEFEVENT "/logs/event.log"
#define DEFIRC   "/logs/irc.log"
#define DEFGAME  "/logs/game.log"

int loginit( IRCaD *ircad );

#endif /* __IRCAD_LOGS_H */
