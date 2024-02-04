%{
#include <stdio.h>
int vc = 0;
int cc = 0;
%}

%%
[aeiouyAEIOU]   { vc++; }
[^aeiouyAEIOU0-9\n] { cc++; }
\n              { printf("%d vowels\n%d consonants\n", vc, cc); vc = 0; cc = 0; 
                    return 0;}
%%

int main()
{
    printf("Enter String:\n");
    yylex();
    return 0;
}
int yywrap() {
    return 1; 
}

