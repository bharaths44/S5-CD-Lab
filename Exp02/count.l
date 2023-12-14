%{
	#include<stdio.h>
	int v=0,c=0;
%}
%%
a|e|i|o|u|A|E|I|O|U {v++;}
[a-z]|[A-Z] 		{c++;}
\n 					{printf("vowel=%d\n consonents=%d\n",v,c);
						return 0;}
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

