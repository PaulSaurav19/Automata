#include <stdio.h>
int main()
{
int n, flag = 0;
printf("Enter the size of given string : "); scanf("%d", &n);
char str[n];
printf("Enter the string : ");
scanf("%s", str);
for (int i = 1; i < n; i++)
{
if (str[i] == '0' && str[i + 1] == '0') {
        flag = 1;
        break;
} }
// printf("%s", str);
if (flag) {
printf("This string is accepted.\n"); }
else
{
printf("This string is not accepted.\n");
}
return 0;
 }