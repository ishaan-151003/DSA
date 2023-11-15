#include <stdio.h>
#include <stdlib.h>
struct sparse
{
    int row;
    int col;
    int value;
    struct sparse *next;
};
typedef struct sparse node;
node *start = NULL;
void create()
{
    node *temp, *newnode,*start1;
    if(start==NULL)
    {
        int m, n,elem,i,j;
        printf("Enter the number of rows and columns:\n");
        scanf("%d %d", &m, &n);
        start = (node *)malloc(sizeof(node));
        start1->row = m;
        start1->col = n;
        start1->next = NULL;
        start->row = 0;
        start->col = 0;
        start->value = 0;
        start->next = NULL;
        temp = start;
        for (i = 0; i < m;i++)
        {
            for (j = 0;)
        }
    }
}
void display()
{
    node *temp = start;
    printf("%4d\t%4d\t%4d\n", start->row, start->col, start->value);
    while (temp->next != NULL)
    {
        if (temp->value == 0)
        {
            continue;
        }
        printf("%4d\t%4d\t%4d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}
int main()
{
    create();
    display();
    return 0;
}