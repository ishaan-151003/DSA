#include<stdio.h>
#include<stdlib.h>
struct ls{
    int data;
    struct ls *next;
    struct ls *prev;
};
typedef struct ls node;
node *addtoempty(node *start,int data)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = data;
    start = temp;
    start->next = start;
    start->prev = start;
    return start;
}
node *addtobeg(node *start,int data)
{
    node *temp, *temp1;
    temp = (node *)malloc(sizeof(node));
    temp->data = data;
    if(start->next==start)
    {
       
    }
    else
    {
        
    }
}
node * create(node *start)
{
    int i, n, elem;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    start = NULL;
    if(n==0)
        return start;
    printf("Enter the number to be inserted:\n");
    scanf("%d", &elem);
    start = addtoempty(start, elem);
    for (i = 2; i <= n;i++)
    {
        printf("Enter the number to be inserted:\n");
        scanf("%d", &elem);
        start = addtoend(start, elem);
    }
    return start;
}