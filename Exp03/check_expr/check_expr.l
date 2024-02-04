%{
#include "y.tab.h"
int yylval;
%}

%%

[0-9]+ { yylval = atoi(yytext); return NUMBER; }

[a-zA-Z]+ {yylval = (int)yytext[0]; return ID; }

["+*-/"] { return yytext[0];}

[ \t] ;  /* ignore whitespace */

\n { return '\n'; }

. { return yytext[0]; }

%%

int yywrap() {
    return 1;
}