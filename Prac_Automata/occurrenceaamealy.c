#include <stdio.h>

// Function to simulate the Moore machine
int mooreMachine(char *input) {
    int state = 0; // Initial state

    while (*input != '\0') {
        switch (state) {
            case 0:
                if (*input == 'a')
                    state = 1;
                else if (*input == 'b')
                    state = 2;
                break;
            case 1:
                if (*input == 'a')
                    return 1; // 'aa' detected
                else if (*input == 'b')
                    state = 2;
                break;
            case 2:
                if (*input == 'a')
                    state = 1;
                else if (*input == 'b')
                    return 1; // 'bb' detected
                break;
        }
        input++;
    }

    return 0; // No consecutive 'a's or 'b's detected
}

int main() {
    char input[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline character

    int result = mooreMachine(input);
    printf("Output: %d\n", result);

    return 0;
}
