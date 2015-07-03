
#ifndef __IFACE_LSTNHANDLER_H
#define __IFACE_LSTNHANDLER_H

enum iface_lstnr_e {
    QUEST,
    SHOP,
    TALK,
};

typedef struct iface_lstnr_t {
    enum iface_lstnr_e lstnrtype;
    union {
        struct iface_quest_lstnr_t quest;
        struct iface_shop_lstnr_t shop;
        struct iface_talk_lstnr_t talk;
    };
} iface_lstnr_t;

typedef struct iface_lstnrdata_t {
    enum iface_lstnr_e lstnrtype;
    union {
        struct iface_quest_lstnrdata_t quest;
        struct iface_shop_lstnrdata_t shop;
        struct iface_talk_lstnrdata_t talk;
    };
} iface_lstnrdata_t;

#endif /* __IFACE_LSTNHANDLER_H */
