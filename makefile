CC = gcc
CFLAGS =
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

maptest: $(MAPFILES)
	@$(CC) -o $(MAPEXEC) -D TESTMODE=0 $(MAPFILES) tests/maptest.c game/Circle/*.c game/Circle/util/*.c
	@echo "executable 'maptest' created. Run with ./tests/maptest"

chartest:
	@$(CC) -o tests/chartest -D TESTMODE=0 $(MAPFILES) tests/chartest.c game/Circle/util/*.c game/Circle/*.c game/player/player.c game/player/character/character.c
	@echo "executable 'chartest' created. Run with ./tests/chartest"
