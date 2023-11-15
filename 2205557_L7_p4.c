#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct ls
{
    int data;
    struct ls *next;
};
typedef struct ls node;
node *front = NULL;
node *rear = NULL;
bool isEmpty(node *front)
{
    if (front == NULL)
        return true;
    else
        return false;
}
void insert(int item)
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = item;
    newnode->next = NULL;
    if (isEmpty(front) && isEmpty(rear))
        front = rear = newnode;
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
    printf("The node has been inserted.\n");
}
void delete()
{
    int item;
    if (isEmpty(front))
    {
        printf("Underflow");
        return;
    }
    else
    {
        node *temp = front;
        front = front->next;
        item = temp->data;
        free(temp);
        printf("\nThe value being dequeued is %d.\n", item);
    }
}
void display()
{
    node *temp = front;
    if (isEmpty(front) && isEmpty(rear))
    {
        printf("Queue is Empty\n");
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int c = 1;
    int ch = 0;
    int item = 0;
    while (c = 1)
    {
        printf("\n1.Insert\n2.Delete\n3.Print\n4.Exit\nEnter choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value to be inserted:\n");
            scanf("%d", &item);
            insert(item);
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(-1);
        }
    }
    return 0;
}