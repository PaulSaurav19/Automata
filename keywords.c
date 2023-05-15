#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

int check1(char str[])
{
	if (!strcmp(str, "auto") || !strcmp(str, "default") || !strcmp(str, "signed") || !strcmp(str, "enum") 
		||!strcmp(str, "extern") || !strcmp(str, "for") || !strcmp(str, "register") || !strcmp(str, "if") 
		|| !strcmp(str, "else") || !strcmp(str, "int") || !strcmp(str, "while") || !strcmp(str, "do") 
		|| !strcmp(str, "break") || !strcmp(str, "continue") || !strcmp(str, "double") || !strcmp(str, "float") 
		|| !strcmp(str, "return") || !strcmp(str, "char") || !strcmp(str, "case") || !strcmp(str, "const") 
		|| !strcmp(str, "sizeof") || !strcmp(str, "long") || !strcmp(str, "short") || !strcmp(str, "typedef") 
		|| !strcmp(str, "switch") || !strcmp(str, "unsigned") || !strcmp(str, "void") || !strcmp(str, "static") 
		|| !strcmp(str, "struct") || !strcmp(str, "goto") || !strcmp(str, "union") || !strcmp(str, "volatile")) 
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	char str[30];
	int n;
	printf("Enter no. of strings to be checked: ");
	scanf("%d", &n);
	printf("Enter a string to be checked: ");
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%s", &str);
		if(check1(str))
		{
			printf("%s is a keyword.\n",str);
		}
		else
		printf("%s is not a keyword.\n",str);
    }
	return 0;
}
