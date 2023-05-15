#include <stdio.h>

int main() {
    int state = 0; // start in state A
    char digit;

    printf("Enter a number in base 4: ");

    while (scanf("%c", &digit) == 1 && digit != '\n') {
        switch (digit) {
            case '0':
                printf("%d", state); // output current remainder
                state = 0; // update state
                break;
            case '1':
                printf("%d", state);
                state = 1;
                break;
            case '2':
                printf("%d", state);
                state = 2;
                break;
            case '3':
                printf("%d", state);
                state = (state + 1) % 3; // update state based on Mealy machine table
                break;
            default:
                printf("Invalid input: %c\n", digit);
                return 1;
        }
    }

    // output final remainder
    printf("%d\n", state);

    return 0;
}
