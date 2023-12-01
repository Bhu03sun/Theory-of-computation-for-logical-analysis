#include <stdio.h>
#include <string.h>

// Define the number of states and symbols
#define NUM_STATES 3
#define NUM_SYMBOLS 2

// Declare the transition table for the NFA
int transitionTable[NUM_STATES][NUM_SYMBOLS][NUM_STATES];

// Function to check if a given string is accepted by the NFA
int isAccepted(char *input) {
    int currentState = 0; // Start in the initial state

    for (int i = 0; i < strlen(input); i++) {
        char symbol = input[i] - '0'; // Convert character to integer

        // Handle transitions based on the current symbol and state
        int nextState = transitionTable[currentState][symbol][0];
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
    // Provide the definition for the transition table
    // State 0
    transitionTable[0][0][0] = 0;
    transitionTable[0][0][1] = 1;
    transitionTable[0][1][0] = 0;
    transitionTable[0][1][1] = -1;
    // State 1
    transitionTable[1][0][0] = -1;
    transitionTable[1][0][1] = 2;
    transitionTable[1][1][0] = 1;
    transitionTable[1][1][1] = -1;
    // State 2
    transitionTable[2][0][0] = 2;
    transitionTable[2][0][1] = 2;
    transitionTable[2][1][0] = 2;
    transitionTable[2][1][1] = 2;

    char input[100];

    // Get input string from the user
    printf("Enter a string (binary) to check if it's in the language: ");
    scanf("%s", input);

    // Check if the input string is accepted by the NFA
    isAccepted(input);

    return 0;
}



