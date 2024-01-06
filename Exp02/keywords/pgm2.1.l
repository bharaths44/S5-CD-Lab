%{
	#include<stdio.h>
%}
%%
if|else|printf {printf("\n%s is a keyword\n",yytext);}
[0-9]+ {printf("\n%s is a number\n",yytext);}
[a-z,A-Z]+ {printf("\n%s is a word\n",yytext);}
%%

int main()
{
	printf("Enter string: ");
	yylex();
	return 0;

}

int yywrap()
{ 
	return 1;
}

