
#ifndef __COM_LSTNHANDLER_H
#define __COM_LSTNHANDLER_H

enum com_lstnr_e {
    CRITICAL,
    HITS,
    LOSE,
    MISSES,
    PVE,
    PVP,
    WIN
};

typedef struct com_lstnr_t {
    enum com_lstnr_e lstnrtype;
    union {
        struct com_crit_lstnr_t crit;
        struct com_hit_lstnr_t hit;
        struct com_lose_lstnr_t lose;
        struct com_miss_lstnr_t miss;
        struct com_pve_lstnr_t pve;
        struct com_pvp_lstnr_t pvp;
        struct com_win_lstnr_t win;
    };
} com_lstnr_t;

typedef struct com_lstnrdata_t {
    enum com_lstnr_e lstnrtype;
    union {
        struct com_crit_lstnrdata_t crit;
        struct com_hit_lstnrdata_t hit;
        struct com_lose_lstnrdata_t lose;
        struct com_miss_lstnrdata_t miss;
        struct com_pve_lstnrdata_t pve;
        struct com_pvp_lstnrdata_t pvp;
        struct com_win_lstnrdata_t win;
    };
} com_lstnrdata_t;

#endif /* __COM_LSTNHANDLER_H */
