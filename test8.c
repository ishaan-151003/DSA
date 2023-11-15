#include <stdio.h>
#include <stdlib.h>
struct ls
{
    int data;
    struct ls *next;
    struct ls *prev;
};
typedef struct ls node;
node *start = NULL;
void create()
{
    if (start == NULL)
    {
        int n, i, elem;
        node *temp, *newnode;
        printf("Enter the number of nodes:\n");
        scanf("%d", &n);
        if (n != 0)
        {
            newnode = (node *)malloc(sizeof(node));
            start = newnode;
            temp = start;
            printf("Enter the number to be inserted:\n");
            scanf("%d", &elem);
            start->data = elem;
            for (i = 2; i <= n; i++)
            {
                newnode = (node *)malloc(sizeof(node));
                temp->next = newnode;
                printf("Enter the number to be inserted:\n");
                scanf("%d", &elem);
                newnode->data = elem;
                newnode->next = start;
                newnode->prev = temp;
                temp = temp->next;
            }
        }
        printf("The list was created successfully\n");
        printf("\n");
    }
    else
    {
        printf("The list has been created already\n");
    }
}
void traverse()
{
    node *temp;
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Printing the list:\n");
        printf("\n");
        temp = start;
        node *temp1;
        while (temp->next != start)
        {
            printf("Data:%d\n", temp->data);
            temp = temp->next;
        }
    }
}
int main()
{
    printf("Double Linked list\n");
    create();
    traverse();
    return 0;
}