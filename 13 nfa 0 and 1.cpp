#include <stdio.h>
#include <string.h>

// Define the number of states and symbols
#define NUM_STATES 3
#define NUM_SYMBOLS 2

// Define the transition table for the NFA
int transitionTable[NUM_STATES][NUM_SYMBOLS][NUM_STATES] = {
    // State 0
    {{1, -1}, {-1, -1}},  // on input '0', move to state 1; on input '1', no valid transition
    // State 1
    {{1, 2}, {-1, -1}},   // on input '0', stay in state 1; on input '1', move to state 2
    // State 2
    {{-1, -1}, {-1, -1}}  // no valid transitions for state 2
};

// Function to check if a given string is accepted by the NFA
int isAccepted(char *input) {
    int currentState = 0; // Start in the initial state

    for (int i = 0; i < strlen(input); i++) {
        char symbol = input[i]; // Current symbol

        // Handle transitions based on the current symbol and state
        int nextState = transitionTable[currentState][symbol - '0'][0];
        if (nextState == -1) {
            printf("Rejected\n");
            return 0; // No valid transition for the current symbol and state
        }
        currentState = nextState;
    }

    // Check if the final state is an accepting state (state 2)
    if (currentState == 2) {
        printf("Accepted\n");
        return 1;
    } else {
        printf("Rejected\n");
        return 0;
    }
}

int main() {
    char input[100];

    // Get input string from the user
    printf("Enter a string to check if it starts with '0' and ends with '1': ");
    scanf("%s", input);

    // Check if the input string is accepted by the NFA
    isAccepted(input);

    return 0;
}

