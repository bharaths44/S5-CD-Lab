#include <stdio.h>

int main() {
    printf("Enter the number of states: ");
    int states;
    scanf("%d", &states);

    printf("Enter the number of input symbols: ");
    int nip;
    scanf("%d", &nip);
    char symbols[nip];

    printf("\n\nEnter input symbols\n");
    for (int i = 0; i < nip; i++) {
        printf("Enter input symbol %d: ", i + 1);
        scanf(" %c", &symbols[i]); // Notice the space before %c to consume the newline character
    }

    printf("Enter transition details:\n");
    int trans[states][nip];
    for (int i = 0; i < states; i++) {
        for (int j = 0; j < nip; j++) {
            printf("State %d Symbol %c -> ", i, symbols[j]);
            scanf("%d", &trans[i][j]);
        }
    }

    printf("\n\nEnter the number of final states: ");
    int nfinal;
    scanf("%d", &nfinal);
    int final[nfinal];

    printf("Enter final states\n");
    for (int i = 0; i < nfinal; i++) {
        printf("Enter final state %d: ", i + 1);
        scanf("%d", &final[i]);
    }

    char str[15];
    printf("Enter input string: ");
    scanf("%s", str);

    int ip = 0, state = 0, ip_index;
    char ch = str[0];
	printf("\n\n");
    while (ch != '\0') {
        ip_index = -1; // Initialize ip_index to an invalid value
        for (int i = 0; i < nip; i++) {
            if (ch == symbols[i]) {
                ip_index = i;
                break; // Exit the loop once the symbol is found
            }
        }

        if (ip_index == -1) {
            printf("Invalid input symbol: %c\n", ch);
            return 1;
        }

        state = trans[state][ip_index];
        ip++;
        printf("Character: %c\t", ch);
        printf("Current state: %d\n", state);
        ch = str[ip];
    }

    int flag = 0;
    for (int i = 0; i < nfinal; i++) {
        if (state == final[i]) {
            flag = 1;
            break; // Exit the loop once a final state is found
        }
    }

    if (flag == 1) {
        printf("\nSTRING ACCEPTED\n");
    } else {
        printf("\nSTRING REJECTED\n");
    }

    return 0;
}

