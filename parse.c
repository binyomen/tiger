#include <stddef.h>

#include "absyn.h"
#include "errormsg.h"
#include "parse.h"
#include "util.h"

extern int yyparse();
extern A_exp absyn_root;

A_exp parse(string filename) {
    EM_reset(filename);

    if (yyparse() == 0) {
        return absyn_root;
    } else {
        return NULL;
    }
}
