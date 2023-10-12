## Experiment 1
1. Implementation of Lexical Analyzer using LEX Tool to eliminate white space and
comments. (Input source code can read from a file).

### Expected Result
INPUT :
```C
#include<stdio.h>
void main()
{
//printf("hello");
}
```

OUTPUT :
```C
#include&lt;stdio.h&gt;
voidmain()
{
}
```
### Commands used
```shell
 lex pgm1.l
```
```shell
gcc lex.yy.c -o pgm1 -lfl
```
```shell
./pgm1 < input_1.txt
```
