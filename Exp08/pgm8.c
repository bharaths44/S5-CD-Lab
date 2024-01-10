#include <stdio.h>
#include <string.h>

#define SUCCESS 1
#define FAILED 0
const char *cursor;
char string[64];
int E(const char *E_rule, const char *Edash_rule, const char *T_rule, const char *Tdash_rule, const char *F_rule);
int Edash(const char *Edash_rule, const char *T_rule, const char *Tdash_rule, const char *F_rule);
int T(const char *T_rule, const char *Tdash_rule, const char *F_rule);
int Tdash(const char *Tdash_rule, const char *F_rule);
int F(const char *F_rule);
// Grammar rule: E -> T E'
int E(const char *E_rule, const char *Edash_rule, const char *T_rule, const char *Tdash_rule, const char *F_rule)
{
    printf("%-16s E->%s\n", cursor, E_rule);
    if (T(T_rule, Tdash_rule, F_rule))
    {                                                      // Call non-terminal T
        if (Edash(Edash_rule, T_rule, Tdash_rule, F_rule)) // Call non-terminal E'
            return SUCCESS;
        else
            return FAILED;
    }
    else
        return FAILED;
}

// Grammar rule: E' -> + T E' | $
int Edash(const char *Edash_rule, const char *T_rule, const char *Tdash_rule, const char *F_rule)
{
    if (*cursor == '+')
    {
        printf("%-16s E'->%s\n", cursor, Edash_rule);
        cursor++;
        if (T(T_rule, Tdash_rule, F_rule))
        {                                                      // Call non-terminal T
            if (Edash(Edash_rule, T_rule, Tdash_rule, F_rule)) // Call non-terminal E'
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
int T(const char *T_rule, const char *Tdash_rule, const char *F_rule)
{
    printf("%-16s T->%s\n", cursor, T_rule);
    if (F(F_rule))
    {                                  // Call non-terminal F
        if (Tdash(Tdash_rule, F_rule)) // Call non-terminal T'
            return SUCCESS;
        else
            return FAILED;
    }
    else
        return FAILED;
}

// Grammar rule: T' -> * F T' | $
int Tdash(const char *Tdash_rule, const char *F_rule)
{
    if (*cursor == '*')
    {
        printf("%-16s T'->%s\n", cursor, Tdash_rule);
        cursor++;
        if (F(F_rule))
        {                                  // Call non-terminal F
            if (Tdash(Tdash_rule, F_rule)) // Call non-terminal T'
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
int F(const char *F_rule)
{
    if (*cursor == '(')
    {
        printf("%-16s F->%s\n", cursor, F_rule);
        cursor++;
        if (E(F_rule, F_rule, F_rule, F_rule, F_rule))
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

// Function to input production rule
// void inputProduction(char *non_terminal, char *production_rule)
// {
//     printf("Enter production rule for %s: ", non_terminal);
//     scanf("%s", production_rule);
// }

int main()
{

    // inputProduction("E", E_rule);
    // inputProduction("E'", Edash_rule);
    // inputProduction("T", T_rule);
    // inputProduction("T'", Tdash_rule);
    // inputProduction("F", F_rule);
    char E_rule[] = "TE'";

    char Edash_rule[] = "+TE`|$";
    char T_rule[] = "FT`";
    char Tdash_rule[] = "*FT`|$";
    char F_rule[] = "(E)|i";
    puts("Enter the string");
    scanf("%s", string); // Read input from the user
    cursor = string;
    puts("");
    puts("Input         Action");
    puts("--------------------------------");

    // Call the starting non-terminal E
    if (E(E_rule, Edash_rule, T_rule, Tdash_rule, F_rule) && *cursor == '\0')
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
