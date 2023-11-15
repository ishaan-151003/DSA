// Implementation of queue through Linked List
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 50
struct node
{
    int data;
    struct node *next;
} Node;
typedef struct node Node;
// Function to create a new node with the given data
Node *newNode(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to check if the queue is empty
int isEmpty(Node *front)
{
    return front == NULL;
}

// Function to enqueue an item to the queue
void enqueue(Node **front, Node **rear, int data)
{
    Node *new_node = newNode(data);
    if (*rear == NULL)
    {
        *front = *rear = new_node;
        return;
    }
    (*rear)->next = new_node;
    *rear = new_node;
}

// Function to dequeue an item from the queue
void dequeue(Node **front)
{
    if (isEmpty(*front))
    {
        printf("Queue is empty\n");
        return;
    }
    Node *temp = *front;
    *front = (*front)->next;
    if (*front == NULL)
    {
        *rear = NULL;
    }
    free(temp);
}

// Function to print the queue
void printQueue(Node *front)
{
    Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Node *front = NULL;
    Node *rear = NULL;
    int ch = 0;
    int item = 0;
    int c = 1;
    while (c = 1)
    {
        printf("1.Insert\n2.Delete\n3.Print\n4.Exit\nEnter choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted:\n");
            scanf("%d", &item);
            enqueue(&front, &rear, item);
            break;
        case 2:
        }
    }
    return 0;
}