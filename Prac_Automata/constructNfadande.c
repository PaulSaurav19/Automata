// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// // Structure to represent an NFA state transition
// typedef struct Transition {
//     int nextState;
//     char input;
//     struct Transition* next;
// } Transition;

// // Structure to represent an NFA state
// typedef struct State {
//     int stateId;
//     bool isAccepting;
//     Transition* transitions;
// } State;

// // Structure to represent an NFA
// typedef struct NFA {
//     State* startState;
//     State* acceptState;
// } NFA;

// // Function to create a new NFA state
// State* createNewState(int stateId, bool isAccepting) {
//     State* newState = (State*)malloc(sizeof(State));
//     newState->stateId = stateId;
//     newState->isAccepting = isAccepting;
//     newState->transitions = NULL;
//     return newState;
// }

// // Function to create a new NFA transition
// Transition* createNewTransition(int nextState, char input) {
//     Transition* newTransition = (Transition*)malloc(sizeof(Transition));
//     newTransition->nextState = nextState;
//     newTransition->input = input;
//     newTransition->next = NULL;
//     return newTransition;
// }

// // Function to add a transition to a state
// void addTransition(State* state, int nextState, char input) {
//     Transition* newTransition = createNewTransition(nextState, input);

//     if (state->transitions == NULL) {
//         state->transitions = newTransition;
//     } else {
//         Transition* currTransition = state->transitions;
//         while (currTransition->next != NULL) {
//             currTransition = currTransition->next;
//         }
//         currTransition->next = newTransition;
//     }
// }

// // Function to construct the NFA for the regular expression (0+1)*(01+10)
// NFA constructNFA_C() {
//     NFA nfa;

//     // Create start state and accept state
//     State* startState = createNewState(0, false);
//     State* acceptState = createNewState(1, true);

//     // Add transitions for (0+1)* part
//     addTransition(startState, startState->stateId, '0');
//     addTransition(startState, startState->stateId, '1');
//     addTransition(startState, acceptState->stateId, '0');

//     // Add transitions for (01+10) part
//     addTransition(startState, acceptState->stateId, '1');
//     addTransition(acceptState, acceptState->stateId, '0');
//     addTransition(acceptState, acceptState->stateId, '1');

//     // Set start state and accept state for the NFA
//     nfa.startState = startState;
//     nfa.acceptState = acceptState;

//     return nfa;
// }

// // Function to construct the NFA for the regular expression ((b*ab*ab*ab*)+b*)ab*
// NFA constructNFA_E() {
//     NFA nfa;

//     // Create start state and accept state
//     State* startState = createNewState(0, false);
//     State* acceptState = createNewState(1, true);

//     // Add transitions for (b*ab*ab*ab*)+ part
//     addTransition(startState, startState->stateId, 'b');
//     addTransition(startState, acceptState->stateId, 'b');

//     // Add transitions for ab*
//     addTransition
// }