// Implementation of deque through LL
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct st
{
    int data;
    struct st *next;
};
typedef struct st node;
struct dq
{
    node *front;
    node *rear;
};
typedef struct dq DQ;
void init(DQ *q)
{
    q->front = NULL;
    q->rear = NULL;
}
bool isEmpty(DQ q)
{
    if (q.front == NULL)
        return true;
    return false;
}
void insertAtfront(DQ *q, int x)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;
    if (q->front == NULL)
    {
        q->rear = temp;
    }
    else
    {
        temp->next = q->front;
    }
    q->front = temp;
}

void insertRear(DQ *q, int x)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;
    if (q->rear == NULL)
        q->front = temp;
    else
        (q->rear)->next = temp;
    q->rear = temp;
}

int deleteFront(DQ *q)
{
    node *temp;
    int x;
    temp = q->front;
    x = temp->data;
    q->front = temp->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return x;
}

int deleteRear(DQ *q)
{
    node *temp, *prev;
    int x;
    temp = q->front;
    prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    x = temp->data;
    if (prev != NULL)
    {
        prev->next = temp->next;
    }
    q->rear = prev;
    if (q->rear == NULL)
    {
        q->front = NULL;
    }
    free(temp);
    return x;
}

void displayQueue()
{
    DQ *q;
    node *temp;
    temp = q->front;
    if (temp == NULL)
    {
        printf("Empty queue\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

int main()
{
    DQ *q;
    int num;
    init(q);
    int c = 1;
    int ch = 0;
    while (c = 1)
    {
        printf("\n1. Insert at front\n2. Insert at rear\n3. Delete at front\n4. Delete at rear\n5. Print Queue\n6. Exit\nEnter choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number to be inserted at the front:\n");
            scanf("%d", &num);
            insertAtfront(q, num);
            break;
        case 2:
            printf("Enter the number to be inserted at the end:\n");
            scanf("%d", &num);
            insertAtfront(q, num);
            break;
        case 3:
            num = deleteFront(q);
            printf("Deleted element is %d\n", num);
            break;
        case 4:
            num = deleteRear(q);
            printf("Deleted element is %d\n", num);
            break;
        case 5:
            displayQueue();
            break;
        case 6:
            c = 0;
            exit(-1);
            break;
        }
    }
    return 0;
}