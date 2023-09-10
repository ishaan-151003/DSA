#include<stdio.h>
int main()
{
    char str[100], *ptr;
    int count;
    printf("Enter a string: ");
    scanf("%[^\n]s", str);
    ptr = str;
    while(*ptr != '\0')
    {
        count++;
        ptr++;
    }
    printf("The length of the string is: %d", count);
    return 0;
}