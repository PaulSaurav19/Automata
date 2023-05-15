#include <stdio.h>

int moore_machine(char input[]) {
    int state = 0; // initial state is S0
    int i = 0;
    while (input[i] != '\0') { // loop through input string
        if (input[i] == 'a') {
            if (state == 0) {
                state = 1;
            } else if (state == 1) {
                state = 2;
            } else {
                state = 1;
            }
        } else { // input[i] == 'b'
            if (state == 0) {
                state = 0;
            } else if (state == 1) {
                state = 0;
            } else {
                state = 0;
            }
        }
        i++;
    }
    // determine output based on final state
    if (state == 1) {
        return 2;
    } else if (state == 2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char input[100];
    printf("Enter input string: ");
    scanf("%s", input);
    int output = moore_machine(input);
    printf("Output: %d\n", output);
    return 0;
}
