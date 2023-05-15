 //a) (a+b)*abb

#include <stdio.h>
#include <string.h>

// Function to check if a given string is accepted by the NFA
int checkString(char *str) {
    int currentState = 0;
    int i, len = strlen(str);

    for (i = 0; i < len; i++) {
        if (currentState == 0 && str[i] == 'a') {
            currentState = 1;
        } else if (currentState == 0 && str[i] == 'b') {
            currentState = 0;
        } else if (currentState == 1 && str[i] == 'a') {
            currentState = 1;
        } else if (currentState == 1 && str[i] == 'b') {
            currentState = 2;
        } else if (currentState == 2 && str[i] == 'a') {
            currentState = 1;
        } else if (currentState == 2 && str[i] == 'b') {
            currentState = 3;
        } else if (currentState == 3) {
            return 1; // string is accepted
        }
    }

    return 0; // string is not accepted
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    // Check if the string is accepted by the NFA
    if (checkString(str)) {
        printf("String is accepted\n");
    } else {
        printf("String is not accepted\n");
    }

    return 0;
}

//b) 0(0+1)*0+1(0+1)*+0+1

#include <stdio.h>
#include <string.h>

// Function to check if a given string is accepted by the NFA
int checkString(char *str) {
    int currentState = 0;
    int i, len = strlen(str);

    for (i = 0; i < len; i++) {
        if (currentState == 0 && str[i] == '0') {
            currentState = 1;
        } else if (currentState == 0 && str[i] == '1') {
            currentState = 2;
        } else if (currentState == 1 && str[i] == '0') {
            currentState = 1;
        } else if (currentState == 1 && str[i] == '1') {
            currentState = 2;
        } else if (currentState == 2 && str[i] == '0') {
            currentState = 3;
        } else if (currentState == 2 && str[i] == '1') {
            currentState = 2;
        } else if (currentState == 3 && str[i] == '0') {
            currentState = 3;
        } else if (currentState == 3 && str[i] == '1') {
            currentState = 3;
        }
    }

    // Check final states
    if (currentState == 1 || currentState == 3) {
        return 1; // string is accepted
    } else {
        return 0; // string is not accepted
    }
}

 // 11(0+1)*11+111

#include <stdio.h>
#include <string.h>

// Function to check if a given string is accepted by the NFA
int checkString(char *str) {
    int currentState = 0;
    int i, len = strlen(str);

    for (i = 0; i < len; i++) {
        if (currentState == 0 && str[i] == '1') {
            currentState = 1;
        } else if (currentState == 1 && (str[i] == '0' || str[i] == '1')) {
            currentState = 1;
        } else if (currentState == 1 && str[i] == '1') {
            currentState = 2;
        } else if (currentState == 2 && (str[i] == '0' || str[i] == '1')) {
            currentState = 2;
        } else if (currentState == 2 && str[i] == '1') {
            currentState = 3;
        } else if (currentState == 3 && str[i] == '1') {
            currentState = 3;
        }
    }

    // Check final states
    if (currentState == 2 || currentState == 3) {
        return 1; // string is accepted
    } else {
        return 0; // string is not accepted
    }
}
