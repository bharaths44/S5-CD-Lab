%{
#include <stdio.h>
int yylex(void);
void yyerror(char *s);
%}

%token NUMBER
%left '+' '-'
%left '*' '/'

%% 
E : T{
		printf("Result = %d\n", $$);
		return 0;
	 }

T :	T '+' T 	{ $$ = $1 + $3; }
	| T '-' T	{ $$ = $1 - $3; }
	| T '*' T 	{ $$ = $1 * $3; }
	| T '/' T 	{ $$ = $1 / $3; }
	| '-' NUMBER { $$ = -$2; }
	| '(' T ')' { $$ = $2; }
	| NUMBER 	{ $$ = $1; }
	;
%%

int main()
{
        printf("Enter expression: ");
        yyparse();
}

void yyerror(char *s)
{
        printf("Invalid expression\n");
}