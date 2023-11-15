// Priority Queue through Linked Lists.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    int priority;
    struct node *next;
};
typedef struct node PQueue;
PQueue *start = NULL;
PQueue *insert(PQueue *);
PQueue *delete(PQueue *);
void display(PQueue *);
int main()
{
    int option;
    do
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter Choice:\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = insert(start);
            break;
        case 2:
            start = delete (start);
            break;
        case 3:
            display(start);
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (option != 4);
    return 0;
}
void display(PQueue *start)
{
    PQueue *ptr;
    ptr = start;
    if (start == NULL)
    {
        printf("Queue is EMpty.\n");
    }
    else
    {
        printf("Priority Queue is:\n");
        while (ptr != NULL)
        {
            printf("%d[priority=%d] ", ptr->data, ptr->priority);
            ptr = ptr->next;
        }
    }
}
PQueue *insert(PQueue *start)
{
    int val, pri;
    PQueue *ptr, *p;
    ptr = (PQueue *)malloc(sizeof(PQueue));
    printf("Enter value and priority to be inserted in queue:\n");
    scanf("%d %d", &val, &pri);
    ptr->data = val;
    ptr->priority = pri;
    if (start == NULL || pri < start->priority)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        p = start;
        while (p->next != NULL && p->next->priority <= pri)
        {
            p = p->next;
        }
        ptr->next = p->next;
        p->next = ptr;
    }
    return start;
}
PQueue *delete(PQueue *start)
{
    PQueue *ptr;
    if (start == NULL)
    {
        printf("\nQueue is Empty.\n");
        return;
    }
    else
    {
        ptr = start;
        printf("\nDeleted item is:%d", ptr->data);
        start = start->next;
        free(ptr);
    }
    return start;
}