#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *top, *top1, *temp;
typedef struct node Stack;
int count = 0;
void push(int data)
{
    if (top == NULL)
    {
        top = (Stack *)malloc(1 * sizeof(Stack));
        top->next = NULL;
        top->data = data;
    }
    else
    {
        temp = (Stack *)malloc(1 * sizeof(Stack));
        temp->next = top;
        temp->data = data;
        top = temp;
    }
    count++;
    printf("Stack is Inserted\n\n");
}

int pop()
{
    top1 = top;

    if (top1 == NULL)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else
        top1 = top1->next;
    int popped = top->data;
    free(top);
    top = top1;
    count--;
    return popped;
}

void display()
{
    // Display the elements of the stack
    top1 = top;

    if (top1 == NULL)
    {
        printf("\nStack Underflow\n");
        return;
    }

    printf("The stack is \n");
    while (top1 != NULL)
    {
        printf("%d ", top1->data);
        top1 = top1->next;
    }
}
int main()
{
    int choice, value;
    printf("\nImplementation of Stack using Linked List\n");
    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            printf("Popped element is :%d\n", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}
