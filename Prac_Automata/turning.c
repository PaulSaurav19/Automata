#include <stdio.h>
#include <string.h>

#define TAPE_SIZE 1000
#define MAX_STATES 10

typedef struct {
    char symbol;
    int nextState;
    char writeSymbol;
    char moveDirection;
} Transition;

typedef struct {
    char tape[TAPE_SIZE];
    int headPosition;
    int currentState;
    Transition transitions[MAX_STATES][2];  // Transitions for each state and symbol (0, 1)
} TuringMachine;

void initializeTape(TuringMachine* tm, const char* input) {
    int inputLength = strlen(input);
    if (inputLength > TAPE_SIZE - 1) {
        printf("Input is too long for the tape.\n");
        return;
    }

    strcpy(tm->tape, input);
    tm->headPosition = 0;
    tm->currentState = 0;
}

void addTransition(TuringMachine* tm, int state, char symbol, int nextState, char writeSymbol, char moveDirection) {
    Transition transition;
    transition.symbol = symbol;
    transition.nextState = nextState;
    transition.writeSymbol = writeSymbol;
    transition.moveDirection = moveDirection;

    tm->transitions[state][symbol - '0'] = transition;
}

void executeTuringMachine(TuringMachine* tm) {
    while (1) {
        char symbol = tm->tape[tm->headPosition];
        Transition transition = tm->transitions[tm->currentState][symbol - '0'];

        tm->tape[tm->headPosition] = transition.writeSymbol;
        tm->currentState = transition.nextState;

        if (transition.moveDirection == 'L') {
            tm->headPosition--;
        } else if (transition.moveDirection == 'R') {
            tm->headPosition++;
        } else if (transition.moveDirection == 'H') {
            break;
        }
    }
}

int main() {
    TuringMachine tm;
    initializeTape(&tm, "101101");

    // Define transitions for doubling a binary number
    addTransition(&tm, 0, '0', 1, '0', 'R');
    addTransition(&tm, 0, '1', 1, '1', 'R');
    addTransition(&tm, 0, ' ', 4, ' ', 'H');

    addTransition(&tm, 1, '0', 1, '0', 'R');
    addTransition(&tm, 1, '1', 1, '1', 'R');
    addTransition(&tm, 1, ' ', 2, ' ', 'L');

    addTransition(&tm, 2, '0', 3, '1', 'L');
    addTransition(&tm, 2, '1', 2, '0', 'L');

    addTransition(&tm, 3, '0', 3, '1', 'L');
    addTransition(&tm, 3, '1', 3, '0', 'L');
    addTransition(&tm, 3, ' ', 0, ' ', 'R');

    executeTuringMachine(&tm);

    printf("Result: %s\n", tm.tape);

    return 0;
}
