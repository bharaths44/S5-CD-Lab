#include <stdio.h>
#include <string.h>

#define SUCCESS 1
#define FAILED 0
const char *cursor;
char string[64];
char E_rule[] = "TE'";
char Edash_rule[] = "+TE`|$";
char T_rule[] = "FT`";
char Tdash_rule[] = "*FT`|$";
char F_rule[] = "(E)|i";

int E();
int Edash();
int T();
int Tdash();
int F();

// Grammar rule: E -> T E'
int E()
{
    printf("%-16s E->%s\n", cursor, E_rule);
    if (T())
    {                // Call non-terminal T
        if (Edash()) // Call non-terminal E'
            return SUCCESS;
        else
            return FAILED;
    }
    else
        return FAILED;
}

// Grammar rule: E' -> + T E' | $
int Edash()
{
    if (*cursor == '+')
    {
        printf("%-16s E'->%s\n", cursor, Edash_rule);
        cursor++;
        if (T())
        {                // Call non-terminal T
            if (Edash()) // Call non-terminal E'
                return SUCCESS;
            else
                return FAILED;
        }
        else
            return FAILED;
    }
    else
    {
        printf("%-16s E'->$\n", cursor);
        return SUCCESS;
    }
}

// Grammar rule: T -> F T'
int T()
{
    printf("%-16s T->%s\n", cursor, T_rule);
    if (F())
    {                // Call non-terminal F
        if (Tdash()) // Call non-terminal T'
            return SUCCESS;
        else
            return FAILED;
    }
    else
        return FAILED;
}

// Grammar rule: T' -> * F T' | $
int Tdash()
{
    if (*cursor == '*')
    {
        printf("%-16s T'->%s\n", cursor, Tdash_rule);
        cursor++;
        if (F())
        {                // Call non-terminal F
            if (Tdash()) // Call non-terminal T'
                return SUCCESS;
            else
                return FAILED;
        }
        else
            return FAILED;
    }
    else
    {
        printf("%-16s T'->$\n", cursor);
        return SUCCESS;
    }
}

// Grammar rule: F -> ( E ) | i
int F()
{
    if (*cursor == '(')
    {
        printf("%-16s F->%s\n", cursor, F_rule);
        cursor++;
        if (E())
        { // Call non-terminal E
            if (*cursor == ')')
            {
                cursor++;
                return SUCCESS;
            }
            else
                return FAILED;
        }
        else
            return FAILED;
    }
    else if (*cursor == 'i')
    {
        printf("%-16s F->%s\n", cursor, F_rule);
        cursor++;
        return SUCCESS;
    }
    else
        return FAILED;
}

int main()
{

    puts("Enter the string");
    scanf("%s", string); // Read input from the user
    cursor = string;
    puts("");
    puts("Input         Action");
    puts("--------------------------------");

    // Call the starting non-terminal E
    if (E() && *cursor == '\0')
    { // If parsing is successful and the cursor has reached the end
        puts("--------------------------------");
        puts("String is successfully parsed");
        return 0;
    }
    else
    {
        puts("--------------------------------");
        puts("Error in parsing String");
        return 1;
    }
}

/*Enter production rule for E: TE`
Enter production rule for E': +TE`|$
Enter production rule for T: FT`
Enter production rule for T': *FT`|$
Enter production rule for F: (E)|i
*/
