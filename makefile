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

MAPFILES = tests/maptest.c $(MAPDIR)/map.c $(MAPDIR)/tile.c $(MAPDIR)/exits.c $(MAPDIR)/gen.c $(UTILDIR)/printutil.c
MAPEXEC = ./tests/maptest

maptest: $(MAPFILES)
	@$(CC) -o $(MAPEXEC) -D TESTMODE=0 $(MAPFILES) game/Circle/*.c game/Circle/util/*.c
	@echo "executable 'maptest' created. Run with ./tests/maptest"

