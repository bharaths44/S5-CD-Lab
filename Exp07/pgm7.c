#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    int flag = 0;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character at the end of input
    input[strcspn(input, "\n")] = '\0';

    int len = strlen(input);
    int i = 0;

    // Check for an empty string
    if (len == 0)
    {
        printf("String recognized under 'a*'\n");
        flag = 1;
    }

    // Check for 'a*'
    for (i = 0; i < len; i++)
    {
        if (input[i] != 'a')
        {
            break;
        }
    }

    if (i == len)
    {
        printf("String recognized under 'a*'\n");
        flag = 1;
    }

    // Check for 'abb'
    if (len == 3 && strcmp(input, "abb") == 0)
    {
        printf("String recognized under 'abb'\n");
        flag = 1;
    }

    // Check for 'a*b+'
    int hasA = 0, hasB = 0;
    int j;

    for (j = 0; j < len; j++)
    {
        if (input[j] == 'a')
        {
            hasA = 1;
        }
        else
        {
            break;
        }
    }

    for (i = j; i < len; i++)
    {
        if (input[i] == 'b')
        {
            hasB = 1;
        }
        else
        {
            break;
        }
    }

    if ((hasA || j == 0) && hasB && i == len)
    {
        printf("String recognized under 'a*b+'\n");
        flag = 1;
    }

    if (flag != 1)
    {
        printf("String not recognized under any pattern\n");
    }

    return 0;
}
