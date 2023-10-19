#include <stdio.h>
#include <stdbool.h>
#include <string.h>


int transition_table[10][10];

// Function to simulate the DFA
bool simulate_dfa(char input_string[], int final_state, int num_states) {
    int current_state = 0;
    int input_len = strlen(input_string);

    for (int i = 0; i < input_len; i++) {
        char symbol = input_string[i];
        int symbol_index = symbol - '0';

        if (symbol_index < 0 || symbol_index >= num_states) {
            printf("Invalid input symbol: %c\n", symbol);
            return false;
        }

        current_state = transition_table[current_state][symbol_index];
    }

    return current_state == final_state;
}

int main() {
    int num_states;
    int num_input_symbols;

    printf("Enter the number of states: ");
    scanf("%d", &num_states);

    printf("Enter the number of input symbols: ");
    scanf("%d", &num_input_symbols);

    // Initialize the DFA transition table
    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < num_input_symbols; j++) {
            printf("State %d symbol %d -> ", i, j);
            scanf("%d", &transition_table[i][j]);
        }
    }

    int final_state;
    printf("Enter the final state: ");
    scanf("%d", &final_state);

    char input_string[100];
    printf("Enter an input string : ");
    scanf("%s", input_string);

    bool accepted = simulate_dfa(input_string, final_state, num_states);

    if (accepted) {
        printf("The string is accepted\n");
    } else {
        printf("The string is rejected\n");
    }

    return 0;
}

