// Binary Trees through Linked List
#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE *lchild;
    struct NODE *rchild;
};
typedef struct NODE node;
node *root = NULL;
node *insert(node *tree, int num);
void preorder(node *tree);
void inorder(node *tree);
void postorder(node *tree);
int count = 1;
void main()
{
    int choice, num;
    do
    {
        printf("\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Exit\nEnter choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter Item:\n");
            scanf("%d", &num);
            root = insert(root, num);
            break;
        case 2:
            printf("\nPreorder Traversing\n");
            preorder(root);
            break;
        case 3:
            printf("\nInorder Traversal\n");
            inorder(root);
            break;
        case 4:
            printf("\nPostorder Traversal\n");
            postorder(root);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nWrong Input\n");
        }
    } while (choice != 5);
}
node *insert(node *p, int num)
{
    if (p == NULL)
    {
        p = (node *)malloc(sizeof(node));
        p->lchild = NULL;
        p->rchild = NULL;
        p->data = num;
        count++;
    }
    else if (count % 2 == 0)
    {
        p->lchild = insert(p->lchild, num);
    }
    else
    {
        p->rchild = insert(p->rchild, num);
    }
    return p;
}
void preorder(node *p)
{
    if (p != NULL)
    {
        printf("%d\n", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inorder(node *p)
{
    if (p != NULL)
    {
        inorder(p->lchild);
        printf("%d \n", p->data);
        inorder(p->rchild);
    }
}
void postorder(node *p)
{
    if (p != NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d \n", p->data);
    }
}