%{
#include <stdio.h>
%}

%%
[ \t\n]+    { /* skip white spaces and newlines */ }
"//"(.*)    { /* skip C++ style comments */ }
"/*"([^*]|[*][^/])*"*/"    { /* skip C-style comments */ }
.    { putchar(yytext[0]); }    /* print all other characters */
%%

int main() {
    yylex();    // Start lexical analysis
    return 0;
}
int yywrap() {
    return 1;  // Indicate no more input
}

