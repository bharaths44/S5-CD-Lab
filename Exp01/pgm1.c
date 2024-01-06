#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    char type[100];
    char value[100];
    int lineNumber;
} Token;

void printTableHeader()
{
    printf("| %-17s | %-17s | %-17s |\n", "Lexeme", "Token", "Line Number");
    printf("|-------------------|-------------------|-------------------|\n");
}

void printToken(Token token)
{
    printf("| %-17s | %-17s | %-17d |\n", token.value, token.type, token.lineNumber);
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '<' || c == '>' || c == '!' || c == '&' || c == '|');
}

int main()
{
    FILE *file = fopen("input_1.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    char currentChar;
    char buffer[100];
    int bufferIndex = 0;
    int lineNumber = 1;

    printTableHeader();

    while ((currentChar = fgetc(file)) != EOF)
    {
        if (isspace(currentChar))
        {
            // Ignore redundant spaces, tabs, and new lines
            if (currentChar == '\n')
            {
                lineNumber++;
            }
            continue;
        }
        else if (isalnum(currentChar))
        {
            // Collect alphanumeric characters into the buffer
            buffer[bufferIndex++] = currentChar;

            // Check if the next character is alphanumeric
            while (isalnum(currentChar = fgetc(file)) || currentChar == '_')
            {
                buffer[bufferIndex++] = currentChar;
            }

            // Null-terminate the buffer
            buffer[bufferIndex] = '\0';

            // Determine the token type
            Token token;
            token.lineNumber = lineNumber;
            if (isdigit(buffer[0]))
            {
                strcpy(token.type, "Number");
            }
            else
            {
                strcpy(token.type, "Identifier");
            }
            // Copy the value to the token
            strcpy(token.value, buffer);

            // Print the token
            printToken(token);

            // Reset the buffer index
            bufferIndex = 0;

            // Unget the last character to avoid skipping it
            ungetc(currentChar, file);
        }
        else if (isOperator(currentChar))
        {
            // Operators are treated as single-character tokens
            Token token;
            token.lineNumber = lineNumber;
            strcpy(token.type, "Operator");
            token.value[0] = currentChar;
            token.value[1] = '\0';

            // Print the token
            printToken(token);
        }
        else
        {
            // Other characters are treated as single-character tokens
            Token token;
            token.lineNumber = lineNumber;
            strcpy(token.type, "Other");
            token.value[0] = currentChar;
            token.value[1] = '\0';

            // Print the token
            printToken(token);
        }
    }

    fclose(file);
    return 0;
}
