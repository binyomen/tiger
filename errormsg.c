#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "util.h"
#include "errormsg.h"

bool g_anyErrors = FALSE;
static string g_fileName = "";
static int g_lineNum = 1;

int EM_tokPos = 0;

extern FILE* yyin;

typedef struct intList {
    int i;
    struct intList* rest;
}* IntList;

static IntList intList(int i, IntList rest) {
    MALLOC(IntList, l);
    *l = (struct intList){
        .i = i,
        .rest = rest,
    };
    return l;
}

static IntList linePos = NULL;

void EM_newline() {
    ++g_lineNum;
    linePos = intList(EM_tokPos, linePos);
}

void EM_error(int pos, char* message, ...) {
    g_anyErrors = TRUE;

    IntList lines = linePos;
    int num = g_lineNum;
    while (lines && lines->i >= pos) {
        lines = lines->rest;
        --num;
    }

    if (g_fileName) {
        fprintf(stderr, "%s:", g_fileName);
    }
    if (lines) {
        fprintf(stderr, "%d.%d: ", num, pos - lines->i);
    }

    va_list ap;
    va_start(ap, message);
    vfprintf(stderr, message, ap);
    va_end(ap);

    fprintf(stderr, "\n");
}

void EM_reset(string filename) {
    g_anyErrors = FALSE;
    g_fileName = filename;
    g_lineNum = 1;
    linePos = intList(0, NULL);

    yyin = fopen(filename, "r");
    if (!yyin) {
        EM_error(0, " cannot open");
        exit(1);
    }
}
