#include <stdio.h>
#include <stdbool.h>

int main() {
    bool currentState = false;
    char input;

    while (true) {
        printf("Current state: %d\n", currentState);
        printf("Input: ");
        scanf(" %c", &input);

        if (input == '0') {
            currentState = false;
        } else if (input == '1') {
            currentState = true;
        } else if (input == 'x') {
            break;
        } else {
            printf("Invalid input!\n");
        }

        printf("Output: %d\n", currentState);
    }

    return 0;
}
//Moore Machine:

//c
//Copy code
#include <stdio.h>

int main() {
    int currentState = 0;
    char input;

    while (true) {
        printf("Current state: %d\n", currentState);
        printf("Input: ");
        scanf(" %c", &input);

        if (input == '0') {
            if (currentState == 0) {
                printf("Output: 0\n");
            } else if (currentState == 1) {
                printf("Output: 1\n");
            } else {
                printf("Invalid state!\n");
            }
        } else if (input == '1') {
            if (currentState == 0) {
                printf("Output: 0\n");
                currentState = 1;
            } else if (currentState == 1) {
                printf("Output: 2\n");
                currentState = 2;
            } else {
                printf("Invalid state!\n");
            }
        } else if (input == 'x') {
            break;
        } else {
            printf("Invalid input!\n");
        }
    }

    return 0;
}


// 2nd code chatgpt

#include <stdio.h>

// Mealy Machine function
int mealyMachine(int input) {
    int state = 0;
    int output;

    switch (state) {
        case 0:
            if (input == 0) {
                state = 0;
                output = 0;
            } else if (input == 1) {
                state = 1;
                output = 1;
            }
            break;
        case 1:
            if (input == 0) {
                state = 2;
                output = 1;
            } else if (input == 1) {
                state = 0;
                output = 0;
            }
            break;
        case 2:
            if (input == 0) {
                state = 1;
                output = 1;
            } else if (input == 1) {
                state = 2;
                output = 0;
            }
            break;
    }

    return output;
}

int main() {
    int input;

    printf("Enter an input (0 or 1): ");
    scanf("%d", &input);

    // Call the Mealy Machine function
    int output = mealyMachine(input);

    printf("Output: %d\n", output);

    return 0;
}

//Moore Machine:
//c
//Copy code
#include <stdio.h>

// Moore Machine function
int mooreMachine(int state) {
    int output;

    switch (state) {
        case 0:
            output = 0;
            break;
        case 1:
            output = 1;
            break;
        case 2:
            output = 2;
            break;
    }

    return output;
}

int main() {
    int state;

    printf("Enter the current state (0, 1, or 2): ");
    scanf("%d", &state);

    // Call the Moore Machine function
    int output = mooreMachine(state);

    printf("Output: %d\n", output);

    return 0;
}