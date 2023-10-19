## Experiment 3
Generate YACC specification for a few syntactic categories
* Implementation of calculator using LEX and YACC
* Program to recognise a valid arithmetic expression that uses operators +,-,* and /
* Program to recognise a valid variable which starts with a letter followed by any number of letters and digits

### Commands used
* ```shell
  lex <pgm_name>.l
  ```
* ```shell
  yacc -d <pgm_name>.y
    ```
* ```shell
  gcc lex.yy.c y.tab.c -o parser -ll
    ```
* ```
  ./parser
  ```
