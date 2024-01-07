%{
#include <stdio.h>
int yylex();
void yyerror(const char* s);
%}

%token NUMBER
%left '+' '-'
%left '*' '/'

%%

program: expression '\n' {
    printf("Valid expression\n");
}
       | '\n'
       ;

expression: NUMBER
          | expression '+' expression
          | expression '-' expression
          | expression '*' expression
          | expression '/' expression
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

int yylex() {
    int c = getchar();
    if (c == EOF) return 0;
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return c;
    }
    if (c >= '0' && c <= '9') {
        ungetc(c, stdin);
        scanf("%d", &yylval);
        return NUMBER;
    }
    return c;
}

