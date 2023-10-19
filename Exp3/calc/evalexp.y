%{
#include <stdio.h>
%}

%token NUMBER ID
%left '+' '-'
%left '*' '/'

%%

E: T { printf("Result=%d\n", $1); return 0; }
 ;

T: T '+' T { $$ = $1 + $3; }
 | T '*' T { $$ = $1 * $3; }
 | T '-' T { $$ = $1 - $3; }
 | T '/' T { $$ = $1 / $3; }
 | '-' NUMBER { $$ = -$2; }
 | '(' T ')' { $$ = $2; }
 | ID { $$ = $1; };

%%

int main()
{
    printf("Enter expression: ");
    yyparse();
}

int yyerror(char *s)
{
    printf("Invalid expression\n");
}

