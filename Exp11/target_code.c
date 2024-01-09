#include <stdio.h>
#include <stdlib.h>

// Structure to represent a 3-address code instruction
typedef struct
{
    char op;         // Operation (e.g., +, -, *, =)
    char arg1[20];   // Operand 1
    char arg2[20];   // Operand 2
    char result[20]; // Result
} ThreeAddressCode;

// Function to generate target code from 3-address code
void generateTargetCode(ThreeAddressCode *code, int numInstructions)
{
    printf("Target Code:\n");

    for (int i = 0; i < numInstructions; i++)
    {
        ThreeAddressCode instruction = code[i];

        // Translate 3-address code to target code (assembly or machine code)
        // This is a simple example, and you need to customize it based on the target architecture.

        if (instruction.op == '=')
        {
            printf("MOV %s, %s\n", instruction.result, instruction.arg1);
        }
        else if (instruction.op == '+')
        {
            printf("ADD %s, %s, %s\n", instruction.result, instruction.arg1, instruction.arg2);
        }
        else if (instruction.op == '-')
        {
            printf("SUB %s, %s, %s\n", instruction.result, instruction.arg1, instruction.arg2);
        }
        else if (instruction.op == '*')
        {
            printf("MUL %s, %s, %s\n", instruction.result, instruction.arg1, instruction.arg2);
        }
        else if (instruction.op == '/')
        {
            printf("DIV %s, %s, %s\n", instruction.result, instruction.arg1, instruction.arg2);
        }
    }
}

int main()
{
    int numInstructions;

    // Get the number of instructions from the user
    printf("Enter the number of 3-address code instructions: ");
    scanf("%d", &numInstructions);
    getchar();
    // Allocate memory for the array of 3-address code instructions
    ThreeAddressCode *code = (ThreeAddressCode *)malloc(numInstructions * sizeof(ThreeAddressCode));

    printf("Enter the instructions ( '_' for empty operands)\n");
    // Get 3-address code instructions from the user
    for (int i = 0; i < numInstructions; i++)
    {
        printf("Enter for instruction %d\n", i + 1);
        printf("Enter operator : ");
        scanf("%c", &code[i].op);
        printf("Enter arg1 :");
        scanf("%s", code[i].arg1);
        printf("Enter arg2 :");
        scanf("%s", code[i].arg2);
        printf("Enter result variable :");
        scanf("%s", code[i].result);
        getchar();
        printf("\n\n");
    }

    // Generate target code
    generateTargetCode(code, numInstructions);

    // Free the allocated memory
    free(code);

    return 0;
}
