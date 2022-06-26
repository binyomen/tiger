#include <stdio.h>
#include <stdlib.h>

#include "errormsg.h"
#include "tokens.h"
#include "util.h"

YYSTYPE yylval;
int yylex();

string toknames[] = {
    "ID",
    "STRING",
    "INT",
    "COMMA",
    "COLON",
    "SEMICOLON",
    "LPAREN",
    "RPAREN",
    "LBRACK",
    "RBRACK",
    "LBRACE",
    "RBRACE",
    "DOT",
    "PLUS",
    "MINUS",
    "TIMES",
    "DIVIDE",
    "EQ",
    "NEQ",
    "LT",
    "LE",
    "GT",
    "GE",
    "AND",
    "OR",
    "ASSIGN",
    "ARRAY",
    "IF",
    "THEN",
    "ELSE",
    "WHILE",
    "FOR",
    "TO",
    "DO",
    "LET",
    "IN",
    "END",
    "OF",
    "BREAK",
    "NIL",
    "FUNCTION",
    "VAR",
    "TYPE",
};

string tokname(int tok) {
    return tok < 257 || tok > 299 ?
        "BAD_TOKEN" :
        toknames[tok - 257];
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: lextest filename\n");
        exit(1);
    }

    string fname = argv[1];
    EM_reset(fname);

    while (TRUE) {
        int tok = yylex();
        if (tok == 0) {
            break;
        }

        switch (tok) {
            case ID:
            case STRING:
                printf("%10s %4d %s\n", tokname(tok), EM_tokPos, yylval.sval);
                break;
            case INT:
                printf("%10s %4d %d\n", tokname(tok), EM_tokPos, yylval.ival);
                break;
            default:
                printf("%10s %4d\n", tokname(tok), EM_tokPos);
        }
    }

    return 0;
}