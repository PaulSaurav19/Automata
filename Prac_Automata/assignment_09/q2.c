 #include <stdio.h> 
 #include <stdbool.h> 
 int main()
{
    int n;
    printf("Enter the size of given string : ");
    scanf("%d", &n);
    printf("Enter the string : "); 
    char str[n];
    scanf("%s", str);
    char res = 'a';
    if (n == 0)
    {
        res = 'a';
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            char x = str[i];
            if (x == '0' && res == 'a') {
            res = 'b'; }
            else if (x == '1' && res == 'a') {
            res = 'a'; }
            else if (x == '0' && res == 'b') {
            res = 'e'; }
            else if (x == '1' && res == 'b') {
            res = 'c'; }
            else if (x == '0' && res == 'c') {
            res = 'B'; }
            else if (x == '1' && res == 'c') {
            res = 'e'; }
            else if (x == '0' && res == 'B') {
            res = 'd';
            }
            else if (x == '1' && res == 'B') {
            res = 'c';

            }
            else if (x == '0' && res == 'd') {
            res = 'd'; }
            else if (x == '1' && res == 'd') {
            res = 'e'; }
            else if (x == '0' && res == 'e') {
            res = 'e'; }
            else
            {
            res = 'e';
            }
        }    
     }
    
    if (res == 'a' || res == 'c' || res == 'B' || res == 'd') {
    printf("This string is accepted."); }
    else
    {
    printf(" This string is not accepted.");
    }
    return 0;
}