#ifndef UTIL_H
#define UTIL_H

typedef char* string;
typedef char bool;

#define TRUE 1
#define FALSE 0

#define MALLOC(type, name) \
    type name; \
    do { \
        name = checked_malloc(sizeof *name); \
    } while (FALSE)
void* checked_malloc(int len);

string String(char* s);

typedef struct U_boolList_* U_boolList;
struct U_boolList_ {
    bool head;
    U_boolList tail;
};

U_boolList U_BoolList(bool head, U_boolList tail);

#endif
