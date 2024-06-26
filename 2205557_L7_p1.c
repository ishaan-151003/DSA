// Program to convert infix to postfix
#include <stdio.h>
#include <ctype.h>
char stack[100];
int top = -1;
void push(char item)
{
    stack[++top] = item;
}
char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}
int precedence(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}
int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%[^\n]s", exp);
    printf("\n");
    e = exp;
    while (*e != '\0')
    {
        if (isalnum(*e))
            printf("%c ", *e);
        else if (*e == '(')
            push(*e);
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
                printf("%c ", pop());
        }
        else
        {
            while (precedence(stack[top]) >= precedence(*e))
                printf("%c ", pop());
            push(*e);
        }
        e++;
    }
    while (top != -1)
    {
        printf("%c ", pop());
    }
    return 0;
}