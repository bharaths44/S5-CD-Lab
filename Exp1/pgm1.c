#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isOperator(char *token) {
    char operators[] = "+-*/=";
    return strchr(operators, token[0]) != NULL;
}


bool isPunctuation(char *token) {
    char punctuation[] = ",;:()";
    return strchr(punctuation, token[0]) != NULL;
}


bool isIdentifier(char *token) {
    if (isalpha(token[0]) || token[0] == '_') {
        for (int i = 1; i < strlen(token); i++) {
            if (!isalnum(token[i]) && token[i] != '_') {
                return false;
            }
        }
        return true;
    }
    return false;
}


bool isConstant(char *token) {
    if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) 
       return true;
    return false;
}

int main() {
    FILE *file;
    char token[100];
    int line = 1; 

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    printf("Lexeme classification with line numbers:\n");

    while (fgets(token, sizeof(token), file) != NULL) {
        char *tok = strtok(token, " \t\n");
        
        while (tok != NULL) {
            if (isOperator(tok)) {
                printf("%s \t operator \t\t Line %d\n", tok, line);
            } 
            
            else if (isPunctuation(tok)) {
                printf("%s \t punctuation symbol \t Line %d\n", tok, line);
            } 
            
            else if (isIdentifier(tok)) {
                printf("%s \t identifier \t\t Line %d\n", tok, line);
            } 
            
            else if (isConstant(tok)) {
                printf("%s \t constant \t\t Line %d\n", tok, line);
            } 
            
            else {
                printf("%s \t unknown token \t Line %d\n", tok, line);
            }
            
            tok = strtok(NULL, " \t\n");
        }
        line++;
    }

    fclose(file);
    return 0;
}

