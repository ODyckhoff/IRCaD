#include "irch.h"
#include "Circle/irc.h"
#include "Circle/command.h"

int irchandler( irc_t *irc, char *nick, char *channel, char *msg ) {
    irc_privmsg( irc->s, channel, "Received channel message." );
    return 1;
}
