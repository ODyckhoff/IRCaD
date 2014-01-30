/* DEFINE BASE STATS */

#define STAT_MIN  1
#define STAT_MAX  20
#define STAT_INIT 10

#define STAT_SPEND 5 /* Number of stat points players can allocate on a Level Up event. */
#define INIT_SPEND 8 /* Number of stat points players can allocate for character generation. */

/* DEFINE CLASS BONUS STATS */

#define STR_1 1
#define STR_2 2

#define DEX_1 1
#define DEX_2 2

#define CHA_1 1
#define CHA_2 2

#define WIS_1 1
#define WIS_2 2

#define INT_1 1
#define INT_2 2

#define CON_1 1
#define CON_2 2

/* DEFINE CLASS STATS */

/* Protector: +2 Constitution, +1 Strength */
#define PRO_STR STAT_INIT + STR_1
#define PRO_DEX STAT_INIT
#define PRO_CHA STAT_INIT
#define PRO_WIS STAT_INIT
#define PRO_INT STAT_INIT
#define PRO_CON STAT_INIT + CON_2

/* Ranger: +2 Dexterity, +1 Charisma */
#define RAN_STR STAT_INIT
#define RAN_DEX STAT_INIT + DEX_2
#define RAN_CHA STAT_INIT + CHA_1
#define RAN_WIS STAT_INIT
#define RAN_INT STAT_INIT
#define RAN_CON STAT_INIT

/* Rogue: +2 Intelligence, +1 Dexterity */
#define ROG_STR STAT_INIT
#define ROG_DEX STAT_INIT + DEX_1
#define ROG_CHA STAT_INIT
#define ROG_WIS STAT_INIT
#define ROG_INT STAT_INIT + INT_2
#define ROG_CON STAT_INIT

/* Sorcerer: +2 Charisma, +1 Wisdom */
#define SOR_STR STAT_INIT
#define SOR_DEX STAT_INIT
#define SOR_CHA STAT_INIT + CHA_2
#define SOR_WIS STAT_INIT + WIS_1
#define SOR_INT STAT_INIT
#define SOR_CON STAT_INIT

/* Warrior: +2 Strength, +1 Constitution */
#define WAR_STR STAT_INIT + STR_2
#define WAR_DEX STAT_INIT
#define WAR_CHA STAT_INIT
#define WAR_WIS STAT_INIT
#define WAR_INT STAT_INIT
#define WAR_CON STAT_INIT + CON_1

/* Wizard: +2 Wisdom, +1 Intelligence */
#define WIZ_STR STAT_INIT
#define WIZ_DEX STAT_INIT
#define WIZ_CHA STAT_INIT
#define WIZ_WIS STAT_INIT + WIS_2
#define WIZ_INT STAT_INIT + INT_1
#define WIZ_CON STAT_INIT

typedef enum {
    ALL = 0,
    PRO = 1,
    RAN = 2,
    ROG = 3,
    SOR = 4,
    WAR = 5,
    WIZ = 6
} class;
