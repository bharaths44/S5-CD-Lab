## Experiment 2
2.    Implementation of Lexical Analyzer using LEX Tool to ignore redundant spaces, tabs
and new lines. (Input source code can read from a file).
## Expected Result

INPUT :
```C
#include<stdio.h>
void main() 
{
printf("hello");
}
```

OUTPUT : 

    LEXEME   TOKEN                 LINE NUMBER
    \#       Special Symbols           1
    include  Identifier                1
    <        Relational Operators      1
    stdio    Identifier                1
    .        Special Symbols           1
    h        Identifier                1
    >        Relational Operators      1
    void     Keyword                   2
    main     Identifier                2
    (        Opening Brackets          2
    )        Closing Brackets          2
    {        Opening Brackets          3
    printf   Keyword                   4
    (        Opening Brackets          4
    "        Double Quotes             4
    hello    string                    4
    "        Double Quotes             4
    )        Closing Brackets          4
    ;        Semicolon                 4
    }        Closing Brackets          5
