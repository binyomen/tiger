#include <assert.h>
#include <stddef.h>

#include "table.h"
#include "util.h"

#define TABSIZE 127

typedef struct binder_ {
    void* key;
    void* value;
    struct binder_* next;
    void* prevtop;
}* binder;

struct TAB_table_ {
  binder table[TABSIZE];
  void* top;
};

static binder Binder(void* key, void* value, binder next, void* prevtop) {
    MALLOC(binder, b);
    *b = (struct binder_){
        .key = key,
        .value = value,
        .next = next,
        .prevtop = prevtop,
    };
    return b;
}

TAB_table TAB_empty() {
    MALLOC(TAB_table, t);
    *t = (struct TAB_table_){
        .top = NULL,
    };
    for (unsigned int i = 0; i < TABSIZE; ++i) {
        t->table[i] = NULL;
    }
    return t;
}

void TAB_enter(TAB_table t, void* key, void* value) {
    assert(t && key);

    const int index = ((unsigned int)key) % TABSIZE;
    t->table[index] = Binder(key, value, t->table[index], t->top);
    t->top = key;
}

void* TAB_look(TAB_table t, void* key) {
    assert(t && key);

    const int index = ((unsigned int)key) % TABSIZE;
    for (binder b = t->table[index]; b; b = b->next) {
        if (b->key == key) {
            return b->value;
        }
    }

    return NULL;
}

void* TAB_pop(TAB_table t) {
    assert(t);
    assert(t->top);

    const int index = ((unsigned int)t->top) % TABSIZE;
    const binder b = t->table[index];
    assert(b);

    t->table[index] = b->next;
    t->top = b->prevtop;
    return b->key;
}

void TAB_dump(TAB_table t, void (*show)(void* key, void* value)) {
    void* k = t->top;
    const int index = ((unsigned int)k) % TABSIZE;

    const binder b = t->table[index];
    if (b == NULL) {
        return;
    }

    t->table[index] = b->next;
    t->top = b->prevtop;

    show(b->key, b->value);
    TAB_dump(t, show);
    assert(t->top == b->prevtop && t->table[index] == b->next);

    t->top = k;
    t->table[index] = b;
}
