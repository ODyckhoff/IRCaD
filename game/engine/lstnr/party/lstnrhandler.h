

#ifndef __PARTY_LSTNHANDLER_H
#define __PARTY_LSTNHANDLER_H

enum party_lstnr_e {
    MEMBER,
    PARTY,
};

typedef struct party_lstnr_t {
    enum party_lstnr_e lstnrtype;
    union {
        struct party_member_lstnr_t member;
        struct party_party_lstnr_t party;
    };
} party_lstnr_t;

typedef struct party_lstnrdata_t {
    enum party_lstnr_e lstnrtype;
    union {
        struct party_member_lstnrdata_t member;
        struct party_party_lstnrdata_t party;
    };
} party_lstnrdata_t;

#endif /* __PARTY_LSTNHANDLER_H */
