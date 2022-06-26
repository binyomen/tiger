%{
#include "errormsg.h"
#include "tokens.h"

int charPos = 1;

int yywrap() {
    charPos = 1;
    return 1;
}

void adjust() {
    EM_tokPos = charPos;
    charPos += yyleng;
}
%}

%%

" " {
    adjust();
    continue;
}

\n {
    adjust();
    EM_newline();
    continue;
}

"," {
    adjust();
    return COMMA;
}

for {
    adjust();
    return FOR;
}

[0-9]+ {
    adjust();
    yylval.ival = atoi(yytext);
    return INT;
}

. {
    adjust();
    EM_error(EM_tokPos, "illegal token");
}
