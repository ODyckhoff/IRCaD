CC = gcc
CFLAGS = -Wall -pedantic-errors -ansi -Wextra -Winit-self -Wuninitialized -Wmissing-declarations -g
LDFLAGS = -I game/

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

MAINFILES = ./game/IRCaD.c ./game/engine.c ./game/cfg.c ./game/logs.c ./game/utils/hashmap.c ./game/engine/lstnr.c ./game/engine/event.c

FILES=`find game/engine/event/ -name "*.c" | xargs echo`
NUMEV=`find game/engine/event/ -name "*.h" | wc -l`

maptest: $(MAPFILES)

	@$(CC) $(CFLAGS) -o $(MAPEXEC) -D TESTMODE=0 $(MAPFILES) tests/maptest.c game/Circle/*.c game/Circle/util/*.c
	@echo "executable 'maptest' created. Run with ./tests/maptest"

chartest:

	@$(CC) $(CFLAGS) -o tests/chartest -D TESTMODE=0 $(MAPFILES) tests/chartest.c game/Circle/util/*.c game/Circle/*.c game/player/player.c game/player/character/character.c
	@echo "executable 'chartest' created. Run with ./tests/chartest"

maintest:

	@printf "#ifndef __IRCAD_EVENT_DISPATCH\n" > game/engine/_ev_dispatch.h
	@printf "#define __IRCAD_EVENT_DISPATCH\n\n" >> game/engine/_ev_dispatch.h
	@printf "#include \"utils/hashmap.h\"\n" >> game/engine/_ev_dispatch.h
	@printf "typedef struct _event_t {\n    char *name;\n    union {\n" >> game/engine/_ev_dispatch.h
	
	
	@find game/engine/event/ -name "*.h" | sed 's/game\/engine\/event\/\(.*\)\.h/{ "\1", \1_getdf, \1_lstnr, \1_interest },/' | awk '{ gsub("/","_",$$3); gsub("/","_",$$4);$$5=toupper($$5); gsub("/","_",$$5); print; }' > _tmp
	@printf "#include \"_ev_dispatch.h\"\n" > game/engine/_ev_dispatch.c
	@find game/engine/event/ -name "*.h" | sed 's/game\/engine\/event\/\(.*\)\/\(.*\)\.h/        struct _\2_t *\2_data;/' >> game/engine/_ev_dispatch.h
	@printf "    } ev_data;\n} event_t;\n\n" >> game/engine/_ev_dispatch.h
	@printf "#include \"IRCaD.h\"\n\n" >> game/engine/_ev_dispatch.h
	@printf "struct dispatch_table { char *name; int ( *function )( IRCaD *ircad, struct _event_t *data ); int ( *lstnr )( IRCaD *ircad, struct _event_t *data ); char *interest; };\n" >> game/engine/_ev_dispatch.h 
	@printf "extern struct dispatch_table dispatcher[%d];\n" $(NUMEV) >> game/engine/_ev_dispatch.h
	@printf "extern hashmap_t hm;\n" >> game/engine/_ev_dispatch.h
	@find game/engine/event/ -name "*.h" | sed 's/game\/engine\/\(.*\)/#include "\1"/' >> game/engine/_ev_dispatch.h
	@printf "\n#endif /* __IRCAD_EVENT_DISPATCH */\n" >> game/engine/_ev_dispatch.h
	
	@printf "struct dispatch_table dispatcher[%d] = {\n" $(NUMEV) >> game/engine/_ev_dispatch.c
	@cat _tmp | sed 's/^/    /' >> game/engine/_ev_dispatch.c
	@sed -i '$$s/,$$//' game/engine/_ev_dispatch.c
	@printf "};\n" >> game/engine/_ev_dispatch.c
	
	@rm _tmp
	$(CC) $(CFLAGS) $(LDFLAGS) -DNUMEV=$(NUMEV) -o tests/maintest $(MAINFILES) game/engine/_ev_dispatch.c $(FILES)
	@echo "executable 'maintest' created. Run with ./tests/maintest"
