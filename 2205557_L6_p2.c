#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int top;
    int capacity;
    int *item;
};
typedef struct node Stack;
Stack *createstack(int size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = size;
    stack->top = -1;
    stack->item = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}
bool isEmpty(Stack *stack)
{
    if (stack->top == -1)
        return true;
    return false;
}
bool isFull(Stack *stack)
{
    if (stack->top == (stack->capacity - 1))
        return true;
    return false;
}
void push(Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->top += 1;
    stack->item[stack->top] = item;
    printf("%d has been pushed into the the stack.\n", item);
}
int pop(Stack *stack)
{
    if (isEmpty(stack))
        exit(0);
    return stack->item[stack->top--];
}
/*int peek(Stack *stack)
{
    if (isEmpty(stack))
        return;
    return stack->item[stack->top];
}*/
void show(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("The elements present in the stack:\n");
        for (int i = stack->top; i >= 0; i--)
        {
            printf("%d ", stack->item[i]);
        }
        printf("\n");
    }
}
int main()
{
    int size = 0;
    int ch, elem, elem1, c = 1;
    printf("Enter the size of the stack:\n");
    scanf("%d", &size);
    Stack *stack = createstack(size);
    while (c == 1)
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted into the stack:\n");
            scanf("%d", &elem);
            push(stack, elem);
            break;
        case 2:
            elem1 = pop(stack);
            printf("%d has been popped from the stack\n", elem1);
            break;
        case 3:
            show(stack);
            break;
        case 4:
            c = 0;
            break;
        }
    }
    return 0;
}