#include <stdio.h>

int main() {
    int state = 0; // start in state A
    char digit;

    printf("Enter a binary number (LSB to MSB): ");

    while (scanf("%c", &digit) == 1 && digit != '\n') {
        switch (digit) {
            case '0':
                switch (state) {
                    case 0:
                        printf("0"); // output 0 for A state
                        break;
                    case 1:
                        printf("1"); // output 1 for A state with carry
                        break;
                    case 2:
                        printf("1"); // output 1 for B state
                        break;
                    default:
                        printf("Error: Invalid state\n");
                        return 1;
                }
                state = 0; // update state
                break;
            case '1':
                switch (state) {
                    case 0:
                        printf("1"); // output 1 for A state
                        state = 1;
                        break;
                    case 1:
                        printf("0"); // output 0 for A state with carry
                        state = 2;
                        break;
                    case 2:
                        printf("0"); // output 0 for B state
                        state = 2;
                        break;
                    default:
                        printf("Error: Invalid state\n");
                        return 1;
                }
                break;
            default:
                printf("Invalid input: %c\n", digit);
                return 1;
        }
    }

    // output final stage of 2's complement calculation
    switch (state) {
        case 0:
            printf("1\n"); // output -1 for input of all zeros
            break;
        case 1:
            printf("0\n"); // output 0 for input of all ones
            break;
        case 2:
            printf("1\n"); // output -1 for any other input
            break;
        default:
            printf("Error: Invalid state\n");
            return 1;
    }

    return 0;
}
