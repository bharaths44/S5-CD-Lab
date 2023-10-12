%{
#include <stdio.h>
%}

%%
[ \t\n]+    /* Ignore spaces, tabs, and newlines */
"//".*      /* Skip single-line comments */
"/[*][^*]*[*]+([^/*][^*]*[*]+)*[/]"   /* Skip multi-line comments */
.|\n        { printf("%s", yytext); } /* Print everything else */
%%

int main() {
    yylex();
    return 0;
}
int yywrap() {
	return 1;
}
