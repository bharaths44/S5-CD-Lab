#include<stdio.h>

#include<string.h>

void main() {

    char line[20];
    int s[20];
    int t = 1;

    int i = 0;
    printf("Enter string  :");
    gets(line);
    for (i = 0; i < 20; i++) s[i] = 0;
    printf("Op\tArg1\tArg2\tResult\n");
    printf("----------------------------\n");
    for (i = 2; line[i] != '\0'; i++) {
        if (line[i] == '/' || line[i] == '*') {
          
            if (s[i] == 0) {
                if (s[i + 1] == 0) {
                    printf("=\t%c\t\t t%d\n", line[i + 1], t);
                    s[i + 1] = t++;
                     printf("----------------------------\n");
                }
                printf("%c\t", line[i]);
                (s[i - 1] == 0) ? printf("%c\t", line[i - 1]): printf("t%d\t", s[i - 1]);
                printf("t%d \t t%d", s[i + 1], t);
                printf("\n----------------------------\n");
                s[i - 1] = s[i + 1] = t++;
                s[i] = 1;
            }
        }
      
    }

    for (i = 2; line[i] != '\0'; i++) {
        if (line[i] == '+' || line[i] == '-') {
           
            if (s[i] == 0) {
                if (s[i + 1] == 0) {
                    printf("=\t%c\t\t t%d\n", line[i + 1], t);
                     printf("----------------------------\n");
                    s[i + 1] = t++;
                }
                printf("%c\t", line[i]);
                (s[i - 1] == 0) ? printf("%c\t", line[i - 1]): printf("t%d\t", s[i - 1]);
                printf("t%d \t t%d", s[i + 1], t);
                 printf("\n----------------------------\n");
                s[i - 1] = s[i + 1] = t++;
                s[i] = 1;
            }
        }
       ;
    }
    printf("\n=\tt%d\t\t%c", t - 1, line[0]);
    printf("\n");

}
