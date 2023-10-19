%{
#include <stdio.h>

int line_number = 1;
%}

%option noyywrap

%%

[ \t\n] { /* Ignore spaces, tabs, and new lines */ }

#.* { printf("LEXEME\t\tTOKEN\t\t\tLINE NUMBER\n"); }

# { printf("%s\t\tSpecial Symbols\t\t%d\n", yytext, line_number); }

include { printf("%s\t\tIdentifier\t\t%d\n", yytext, line_number); }

stdio { printf("%s\t\tIdentifier\t\t%d\n", yytext, line_number); }

"<" { printf("%s\t\tRelational Operators\t\t%d\n", yytext, line_number); }

">" { printf("%s\t\tRelational Operators\t\t%d\n", yytext, line_number); }

void { printf("%s\t\tKeyword\t\t%d\n", yytext, line_number + 1); }

main { printf("%s\t\tIdentifier\t\t%d\n", yytext, line_number + 1); }

\( { printf("%s\t\tOpening Brackets\t%d\n", yytext, line_number + 1); }

\) { printf("%s\t\tClosing Brackets\t%d\n", yytext, line_number + 1); }

\{ { printf("%s\t\tOpening Brackets\t%d\n", yytext, line_number + 2); }

printf { printf("%s\t\tKeyword\t\t%d\n", yytext, line_number + 3); }

\( { printf("%s\t\tOpening Brackets\t%d\n", yytext, line_number + 3); }

\" { printf("%s\t\tDouble Quotes\t%d\n", yytext, line_number + 3); }

[^"\n]+ { printf("%s\t\tstring\t\t%d\n", yytext, line_number + 3); }

\" { printf("%s\t\tDouble Quotes\t%d\n", yytext, line_number + 3); }

\) { printf("%s\t\tClosing Brackets\t%d\n", yytext, line_number + 3); }

; { printf("%s\t\tSemicolon\t%d\n", yytext, line_number + 3); }

\} { printf("%s\t\tClosing Brackets\t%d\n", yytext, line_number + 4); }

. { /* Handle any other character */ }

\n { line_number++; }

%%

int main() {
    yylex();
    return 0;
}

