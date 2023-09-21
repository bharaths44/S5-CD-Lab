%{
	#include<stdio.h>
%}
%%

if|else|printf {printf("%s is a keyword",yytext);}
[0-9]* {printf("%s is number",yytext);}
[a-zA-Z]+ {printf("%s is a word",yytext);}
.|\n {ECHO;}
%%
void main() {
	printf("Enter string : ");
	yylex();
}
int yywrap() {
	return 1;
}
