#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

void* checked_malloc(const int len) {
    void* p = malloc(len);
    if (!p) {
        fprintf(stderr,"\nRan out of memory!\n");
        exit(1);
    }
    return p;
}

string String(char* s) {
    string p = checked_malloc(strlen(s)+1);
    strcpy(p, s);
    return p;
}

U_boolList U_BoolList(bool head, U_boolList tail) {
    MALLOC(U_boolList, list);
    *list = (struct U_boolList_){
        .head = head,
        .tail = tail,
    };
    return list;
}
