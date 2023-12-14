%{
	#include<stdio.h>
%}
%%
[a-z] {printf("%s is a small leter\n",yytext);}
[A-Z] {printf("%s is a Capital letter\n",yytext);}
%%

int main()
{
	printf("Enter string:\n");
	yylex();

}

int yywrap()
{ 
	return 1;
}
