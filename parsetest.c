#include <stdio.h>
#include <stdlib.h>

#include "absyn.h"
#include "errormsg.h"
#include "parse.h"
#include "prabsyn.h"
#include "util.h"

extern int yyparse();

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: parsetest filename\n");
        exit(1);
    }

    A_exp exp = parse(argv[1]);
    pr_exp(stdout, exp, 100);

    return 0;
}
