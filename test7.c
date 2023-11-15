#include<stdio.h>
#include<stdlib.h>
struct ls{
    int data;
    struct ls *next;
};
typedef struct ls node;
node *start = NULL;
node *addtoempty(node *newnode, int data);
node *addtoend(node *newnode, int data);
node *addtobegin(node *newnode, int data);
node * createList(node *newnode)
{
    int i, n, data;
    printf("Enter the number of nodes :\n ");
    scanf("%d", &n);
    if(n==0)
    {
        return newnode;
    }
    printf("Enter the element to be inserted:\n");
    scanf("%d",&data);
    newnode = addtoempty(newnode, data);
    for (i = 2; i <= n;i++)
    {
        printf("Enter the element to be inserted:\n");
        scnaf("%d" & data);
        newnode = addtoend(newnode, data);
    }
    return newnode;
}
node *addtoempty(node *newnode,int data)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = data;
    newnode = temp;
    newnode->next = newnode;
    return newnode;
}
node *addtobegin(node *newnode,int data)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = newnode->next;
    newnode->next = temp;
    return newnode;
}
node *addtoend(node *newnode,int data)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = newnode->next;
    newnode->next = temp;
    newnode = temp;
    return newnode;
}
void delete_beg()
{
    node *temp,*temp1;
    if(start==NULL)
    {
        printf("List is empty.\n");
    }
    else if(start->next==start)
    {
        temp = start;
        start = NULL;
        printf("Data to be deleted is %d", temp->data);
        free(temp);
    }
    else
    {
        temp = start;
        temp1 = start;
        while(temp1->next!=start)
        {
            temp1 = temp1->next;
        }
        start = start->next;
        temp1->next = start;
        printf("%d is being deleted from the list", temp->data);
        free(temp);
    }
}
node *