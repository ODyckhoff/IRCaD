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

MAPFILES = $(MAPDIR)/maptest.c $(MAPDIR)/map.c $(MAPDIR)/tile.c $(MAPDIR)/exits.c $(MAPDIR)/gen.c $(UTILDIR)/printutil.c
MAPEXEC = maptest

map: $(MAPFILES)
	@$(CC) -o $(MAPEXEC) $(MAPFILES)
	@echo "executable 'maptest' created. Run with ./maptest"

