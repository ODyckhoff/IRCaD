#include <stdio.h>
#include <strings.h>
#include "stats.h"

const char *program_name;

void printHumanStats();
void printElfStats();
void printHalfElfStats();
void printDwarfStats();
void printGnomeStats();
void printHalfGiantStats();
int strcmp(char*, char*);

int main(int argc, char *argv[]) {

/*int StatArr[6];*/

    program_name = argv[0];
    
    int race, i;
    for(i = 1; i <= argc - 1; i++) {
        printf("value of i is %d and the value of argv at this point is %s\n", i, argv[i]);
        race = 0;

        if(strcmp(argv[i], "human") == 0) {
            race = HUMAN;
            printf("TEST: human: %d\n", race);
        }
        if(strcmp(argv[i], "elf") == 0) {
            race = ELF;
            printf("TEST: elf: %d\n", race);
        }
        if((strcmp(argv[i], "halfelf") == 0 || strcmp(argv[i], "half-elf") == 0) || strcmp(argv[i], "half elf") == 0) {
            race = HALF_ELF;
            printf("TEST: half elf: %d\n", race);
        }
        if(strcmp(argv[i], "dwarf") == 0) {
            race = DWARF;
            printf("TEST: dwarf: %d\n", race);
        }
        if(strcmp(argv[i], "gnome") == 0) {
            race = GNOME;
            printf("TEST: gnome: %d\n", race);
        }
        if((strcmp(argv[i], "halfgiant") == 0 || strcmp(argv[i], "half-giant") == 0) || strcmp(argv[i], "half giant") == 0) {
            race = HALF_GIANT;
            printf("TEST: half giant: %d\n", race);
        }
        if(!race) {
            race = ALL;
            printf("TEST: all: %d\n", race);
        }

        switch(race) {
            case HUMAN:
                printHumanStats();
                break;
            case ELF:
                printElfStats();
                break;
            case HALF_ELF:
                printHalfElfStats();
                break;
            case DWARF:
                printDwarfStats();
                break;
            case GNOME:
                printGnomeStats();
                break;
            case HALF_GIANT:
                printHalfGiantStats();
                break;
            case ALL:
                printHumanStats();
                printElfStats();
                printHalfElfStats();
                printDwarfStats();
                printGnomeStats();
                printHalfGiantStats();
                break;
            default:
                break;
        }
    }
    printf("\n");
    return 0;
}

void printHumanStats() {

    printf("HUMAN STATS\n");
    printf("{\n");
    printf("    STR: %d\n", HUMAN_STR);
    printf("    DEX: %d\n", HUMAN_DEX);
    printf("    CHA: %d\n", HUMAN_CHA);
    printf("    WIS: %d\n", HUMAN_WIS);
    printf("    INT: %d\n", HUMAN_INT);
    printf("    CON: %d\n", HUMAN_CON);
    printf("}\n");
}

void printElfStats() {

    printf("ELF STATS\n");
    printf("{\n");
    printf("    STR: %d\n", ELF_STR);
    printf("    DEX: %d\n", ELF_DEX);
    printf("    CHA: %d\n", ELF_CHA);
    printf("    WIS: %d\n", ELF_WIS);
    printf("    INT: %d\n", ELF_INT);
    printf("    CON: %d\n", ELF_CON);
    printf("}\n");
}

void printHalfElfStats() {

    printf("HALF_ELF STATS\n");
    printf("{\n");
    printf("    STR: %d\n", HALF_ELF_STR);
    printf("    DEX: %d\n", HALF_ELF_DEX);
    printf("    CHA: %d\n", HALF_ELF_CHA);
    printf("    WIS: %d\n", HALF_ELF_WIS);
    printf("    INT: %d\n", HALF_ELF_INT);
    printf("    CON: %d\n", HALF_ELF_CON);
    printf("}\n");
}

void printDwarfStats() {

    printf("DWARF STATS\n");
    printf("{\n");
    printf("    STR: %d\n", DWARF_STR);
    printf("    DEX: %d\n", DWARF_DEX);
    printf("    CHA: %d\n", DWARF_CHA);
    printf("    WIS: %d\n", DWARF_WIS);
    printf("    INT: %d\n", DWARF_INT);
    printf("    CON: %d\n", DWARF_CON);
    printf("}\n");
}

void printGnomeStats() {

    printf("GNOME STATS\n");
    printf("{\n");
    printf("    STR: %d\n", GNOME_STR);
    printf("    DEX: %d\n", GNOME_DEX);
    printf("    CHA: %d\n", GNOME_CHA);
    printf("    WIS: %d\n", GNOME_WIS);
    printf("    INT: %d\n", GNOME_INT);
    printf("    CON: %d\n", GNOME_CON);
    printf("}\n");
}

void printHalfGiantStats() {

    printf("HALF_GIANT STATS\n");
    printf("{\n");
    printf("    STR: %d\n", HALF_GIANT_STR);
    printf("    DEX: %d\n", HALF_GIANT_DEX);
    printf("    CHA: %d\n", HALF_GIANT_CHA);
    printf("    WIS: %d\n", HALF_GIANT_WIS);
    printf("    INT: %d\n", HALF_GIANT_INT);
    printf("    CON: %d\n", HALF_GIANT_CON);
    printf("}\n");
}
