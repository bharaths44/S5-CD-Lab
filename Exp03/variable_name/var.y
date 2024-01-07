%{
#include <stdio.h>
int yyerror(const char *s);
int yylex();
int valid = 1;
%}

%token digit letter

%%

start: letter s
s: letter s
  | digit s
  |

%%

int yyerror(const char *s)
{
    printf("Not a vaild variable\n");
    valid = 0;
    return 0;
}

int main()
{
    printf("Enter the variable : ");
    yyparse();
    
    if (valid)
    {
        printf("Valid identifier\n");
    }
    
    return 0;
}

