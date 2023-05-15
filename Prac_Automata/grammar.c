#include<stdio.h> 
 //#include<conio.h>
#include<string.h>
void main() {
	char string[50];
	int flag,count=0;
	clrscr();
	printf("The grammar is: S->aS, S->Sb, S->ab\n");
	printf("Enter the string to be checked:\n");
	gets(string);
	if(string[0]=='a') {
		flag=0;
		for (count=1;string[count-1]!='\0';count++) {
			if(string[count]=='b') {
				flag=1;
				continue;
			} else if((flag==1)&&(string[count]=='a')) {
				printf("The string does not belong to the specified grammar");
				break;
			} else if(string[count]=='a')
			continue;
            else if(flag==1 &&(string[count]='\0')) {
				printf("String accepted…..!!!!");
				break;
			} else {
				printf("String not accepted");
			}
		}
	}
	getch();
}


// chat gpt
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PROD 100

// Structure to represent a production rule
typedef struct Production {
    char lhs;
    char rhs[50];
} Production;

// Function to check whether a given grammar is regular
bool isRegularGrammar(Production productions[], int numProductions) {
    for (int i = 0; i < numProductions; i++) {
        Production production = productions[i];
        int rhsLen = strlen(production.rhs);

        // Check if the production satisfies the conditions for a regular grammar
        if (rhsLen == 1 && production.rhs[0] >= 'a' && production.rhs[0] <= 'z') {
            continue;
        }
        if (rhsLen == 2 && production.rhs[0] >= 'A' && production.rhs[0] <= 'Z' &&
            production.rhs[1] >= 'A' && production.rhs[1] <= 'Z') {
            continue;
        }
        if (rhsLen == 0 && production.lhs >= 'A' && production.lhs <= 'Z') {
            continue;
        }
        return false;
    }

    return true;
}

int main() {
    int numProductions;
    Production productions[MAX_PROD];

    printf("Enter the number of productions: ");
    scanf("%d", &numProductions);

    printf("Enter the productions:\n");
    for (int i = 0; i < numProductions; i++) {
        scanf(" %c -> %s", &productions[i].lhs, productions[i].rhs);
    }

    // Check if the grammar is regular
    if (isRegularGrammar(productions, numProductions)) {
        printf("The given grammar is regular.\n");
    } else {
        printf("The given grammar is not regular.\n");
    }

    return 0;
}
