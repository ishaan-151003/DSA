// Priority Queue using Array
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
void insert_by_priority(int);
void delete_by_priority(int);
void check(int);
void display_Pqueue();
int pri_Que[MAX];
int front = -1, rear = -1;
void main()
{
    int n, ch;
    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value to be inserted:\n");
            scanf("%d", &n);
            insert_by_priority(n);
            break;
        case 2:
            printf("Enter the value to be deleted:\n");
            scanf("%d", &n);
            delete_by_priority(n);
            break;
        case 3:
            display_Pqueue();
            break;
        case 4:
            exit(-1);
            break;
        default:
            printf("Invalid choice:\n");
            break;
        }
    }
}
void insert_by_priority(int data)
{
    if (rear >= MAX - 1)
    {
        printf("Queue is full.\n");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        pri_Que[rear] = data;
        return;
    }
    else
        check(data);
    rear++;
}
void check(int data)
{
    int i, j;
    for (i = 0; i <= rear; i++)
    {
        if (data >= pri_Que[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                pri_Que[j] = pri_Que[j - 1];
            }
            pri_Que[i] = data;
            return;
        }
    }
    pri_Que[i] = data;
}
void delete_by_priority(int data)
{
    int i;
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is Empty.\n");
        return;
    }
    for (i = 0; i <= rear; i++)
    {
        if (data == pri_Que[i])
        {
            for (; i < rear; i++)
            {
                pri_Que[i] = pri_Que[i + 1];
            }
        }
        pri_Que[i] = -99;
        rear--;
        if (rear == -1)
        {
            front = -1;
        }
        return;
    }
    printf("\n%d not found in the queue to delete.\n", data);
}
void display_Pqueue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is Empty\n");
        return;
    }
    for (; front <= rear; front++)
    {
        printf("%d ", pri_Que[front]);
    }
    front = 0;
}