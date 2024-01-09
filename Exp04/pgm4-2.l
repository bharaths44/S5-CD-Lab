%{
#include <stdio.h>
int lineno = 1;
%}

%option noyywrap

%%
[\t ]*\n     { lineno++; }
[<>]        { printf("%s\t Relational Operators\t Line %d\n", yytext,lineno); }
"void"|"printf"|"scanf" { printf("%s\t Keyword\t\t Line %d\n", yytext,lineno); }
"{"|"("         { printf("%s\t Opening Brackets\t Line %d\n", yytext, lineno); }
"}"|")"      { printf("%s\t Closing Brackets\t Line %d\n", yytext, lineno); }
[a-zA-Z_][a-zA-Z0-9_]* { printf("%s\t Identifier\t\t Line %d\n", yytext, lineno); }
\"          { printf("%s\t Double Quotes\t Line %d\n", yytext, lineno); }
";"         { printf(";\t Semicolon\t\t Line %d\n", lineno); }
[+/*=]      { printf("%s\t Operator\t\t Line %d\n", yytext, lineno); }
\"[^\"\n]*\" { printf("%s\t String\t\t Line %d\n", yytext, lineno); }
.           { printf("%s\t Special Symbols\t Line %d\n", yytext, lineno); }
%%

int main() {
    yylex();
    return 0;
}

