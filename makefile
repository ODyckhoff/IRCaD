CC = gcc
CFLAGS = -Wall -pedantic-errors -ansi -Wextra -Winit-self -Wuninitialized -Wmissing-declarations -g
LDFLAGS =

MAPDIR = ./game/environment/map
UTILDIR = ./game/utils

# target: all - Default target. Does nothing.
all:
	@echo "Hello $(LOGNAME), nothing to do by default"
	@echo "Try 'make help'"

# target: help - Display callable targets.
help:
	@egrep "^# target:" [Mm]akefile

# target: map - Compiles map features.

MAPFILES = $(MAPDIR)/map.c $(MAPDIR)/tile.c $(MAPDIR)/exits.c $(MAPDIR)/gen.c $(UTILDIR)/printutil.c
MAPEXEC = ./tests/maptest

MAINFILES = ./game/IRCaD.c ./game/engine.c ./game/cfg.c ./game/logs.c

maptest: $(MAPFILES)
	@$(CC) $(CFLAGS) -o $(MAPEXEC) -D TESTMODE=0 $(MAPFILES) tests/maptest.c game/Circle/*.c game/Circle/util/*.c
	@echo "executable 'maptest' created. Run with ./tests/maptest"

chartest:
	@$(CC) $(CFLAGS) -o tests/chartest -D TESTMODE=0 $(MAPFILES) tests/chartest.c game/Circle/util/*.c game/Circle/*.c game/player/player.c game/player/character/character.c
	@echo "executable 'chartest' created. Run with ./tests/chartest"

maintest:
	$(CC) $(CFLAGS) -o tests/maintest $(MAINFILES)
	@echo "executable 'maintest' created. Run with ./tests/maintest"
