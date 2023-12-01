#include <stdio.h>

// Define the number of states
#define NUM_STATES 4

// Define the maximum number of transitions for each state
#define MAX_TRANSITIONS 5

// Define the epsilon symbol
#define EPSILON -1

// Structure to represent a state and its transitions
struct State {
    int transitions[MAX_TRANSITIONS];
};

// Function to perform depth-first search (DFS) to find e-closure for a state
void epsilonClosure(int state, struct State nfa[], int epsilonClosureSet[]) {
    // Mark the current state as visited
    epsilonClosureSet[state] = 1;

    // Iterate through transitions from the current state
    for (int i = 0; nfa[state].transitions[i] != -1; i++) {
        int nextState = nfa[state].transitions[i];

        // Check if the transition is an e-move and the next state is not visited
        if (nfa[state].transitions[i] == EPSILON && epsilonClosureSet[nextState] == 0) {
            epsilonClosure(nextState, nfa, epsilonClosureSet);
        }
    }
}

int main() {
    // Example NFA with e-moves
    struct State nfa[NUM_STATES] = {
        {.transitions = {1, 2, -1}},  // State 0
        {.transitions = {EPSILON, 3, -1}},  // State 1
        {.transitions = {EPSILON, -1}},  // State 2
        {.transitions = {0, 2, -1}}  // State 3
    };

    // Calculate e-closure for each state
    for (int i = 0; i < NUM_STATES; i++) {
        int epsilonClosureSet[NUM_STATES] = {0};

        // Find e-closure for the current state
        epsilonClosure(i, nfa, epsilonClosureSet);

        // Print e-closure for the current state
        printf("e-closure(%d): {", i);
        for (int j = 0; j < NUM_STATES; j++) {
            if (epsilonClosureSet[j] == 1) {
                printf(" %d", j);
            }
        }
        printf(" }\n");
    }

    return 0;
}



