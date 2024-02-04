%{
#include <stdio.h>
int yylex();
void yyerror(const char* s);
%}

%token NUMBER ID
%right '='
%left '+' '-'
%left '*' '/'

%%

program: expression '\n' {
    printf("Valid expression\n");
    return 0;
}
       | '\n'
       ;

expression: NUMBER
          | ID
          | expression '+' expression
          | expression '-' expression
          | expression '*' expression
          | expression '/' expression
          | ID '=' expression
          | '-' NUMBER
          | '-' ID
          | '(' expression ')'
          ;

%%

void yyerror(const char* s) {
    printf("Invalid expression\n");
}

int main() {
	printf("Enter an expression: ");
    yyparse();
    return 0;
}



