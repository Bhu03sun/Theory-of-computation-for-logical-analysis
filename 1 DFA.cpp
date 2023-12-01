#include <stdio.h>

#define STATES 2
#define ALPHABETS 2

int transitionTable[STATES][ALPHABETS] = {
    {1, 0},   // State 0: 'a' transition goes to State 1, Other alphabets go to State 0
    {1, 1}    // State 1: Both 'a' and other alphabets transition go to State 1
};

int simulateDFA(char *input) {
    int currentState = 0;
    int i = 0;

    while (input[i] != '\0') {
        char currentSymbol = input[i];

        // Get the index of the current symbol in the alphabet set
        int symbolIndex = (currentSymbol == 'a') ? 0 : 1;

        // Transition to the next state based on the current state and input symbol
        currentState = transitionTable[currentState][symbolIndex];

        i++;
    }

    return currentState;
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    int finalState = simulateDFA(input);

    if (finalState == 1) {
        printf("The string is accepted by the DFA.\n");
    } else {
        printf("The string is not accepted by the DFA.\n");
    }

    return 0;
}






