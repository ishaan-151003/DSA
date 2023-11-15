#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct BST
{
    int data;
    struct BST *lchild, *rchild;
};

typedef struct BST node;
node *root = NULL;

int largest(node *tree);
int smallest(node *tree);

node *insert(node *p, int num)
{
    if (p == NULL)
    {
        p = (node *)malloc(sizeof(node));
        p->lchild = NULL;
        p->rchild = NULL;
        p->data = num;
    }
    else if (num < p->data)
    {
        p->lchild = insert(p->lchild, num);
    }
    else if (num > p->data)
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

bool search(node *tree, int elem)
{
    if (tree == NULL)
    {
        printf("%d not found.\n", elem);
        return false;
    }

    if (elem == tree->data)
    {
        printf("%d has been found.\n", elem);
        return true;
    }
    else if (elem < tree->data)
    {
        return search(tree->lchild, elem);
    }
    else
    {
        return search(tree->rchild, elem);
    }
}

node *delete_Element(node *tree, int elem)
{
    if (tree == NULL)
    {
        printf("%d is not found.\n", elem);
        return tree;
    }

    if (elem < tree->data)
    {
        tree->lchild = delete_Element(tree->lchild, elem);
    }
    else if (elem > tree->data)
    {
        tree->rchild = delete_Element(tree->rchild, elem);
    }
    else
    {
        if (tree->lchild == NULL)
        {
            node *temp = tree->rchild;
            free(tree);
            return temp;
        }
        else if (tree->rchild == NULL)
        {
            node *temp = tree->lchild;
            free(tree);
            return temp;
        }

        node *temp = tree->rchild;
        while (temp->lchild != NULL)
        {
            temp = temp->lchild;
        }

        tree->data = temp->data;
        tree->rchild = delete_Element(tree->rchild, temp->data);
    }

    return tree;
}

void deleteTree(node *root)
{
    if (root != NULL)
    {
        deleteTree(root->lchild);
        deleteTree(root->rchild);
        free(root);
    }
}

int totalNodes(node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        return (totalNodes(tree->lchild) + totalNodes(tree->rchild) + 1);
    }
}

int totalLeafNodes(node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else if (tree->lchild == NULL && tree->rchild == NULL)
    {
        return 1;
    }
    else
    {
        return totalLeafNodes(tree->lchild) + totalLeafNodes(tree->rchild);
    }
}

int totalInternalNodes(node *tree)
{
    if (tree == NULL || (tree->lchild == NULL && tree->rchild == NULL))
    {
        return 0;
    }
    else
    {
        return totalInternalNodes(tree->lchild) + totalInternalNodes(tree->rchild) + 1;
    }
}

int height(node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        int lheight = height(tree->lchild);
        int rheight = height(tree->rchild);
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}

int largest(node *tree)
{
    while (tree->rchild != NULL)
    {
        tree = tree->rchild;
    }
    return tree->data;
}

int smallest(node *tree)
{
    while (tree->lchild != NULL)
    {
        tree = tree->lchild;
    }
    return tree->data;
}

int main()
{
    printf("Hello! Welcome to my program.\n");
    int choice, num;
    do
    {
        printf("1. Insert in node in BST\n2. Search a node in BST\n3. Display (preorder) in BST\n4. Display (inorder) in BST\n5. Display (postorder) in BST\n6. Find largest element\n7. Find smallest element\n8. Delete the element\n9. Height\n10. Delete the tree\n11. Total nodes\n12. Total internal nodes\n13. Total leaf nodes\n14. Quit\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter Item:\n");
            scanf("%d", &num);
            root = insert(root, num);
            break;
        case 2:
            printf("Enter the element to be searched:\n");
            scanf("%d", &num);
            search(root, num);
            break;
        case 3:
            printf("\nPreorder Traversing\n");
            preorder(root);
            break;
        case 4:
            printf("\nInorder Traversal\n");
            inorder(root);
            break;
        case 5:
            printf("\nPostorder Traversal\n");
            postorder(root);
            break;
        case 6:
            num = largest(root);
            printf("Largest:%d\n", num);
            break;
        case 7:
            num = smallest(root);
            printf("Smallest:%d\n", num);
            break;
        case 8:
            printf("Enter the value to be deleted:\n");
            scanf("%d", &num);
            root = delete_Element(root, num);
            break;
        case 9:
            num = height(root);
            printf("Height of tree is %d\n", num);
            break;
        case 10:
            deleteTree(root);
            root = NULL; // Ensure root is set to NULL after deletion
            break;
        case 11:
            num = totalNodes(root);
            printf("Total number of nodes:%d\n", num);
            break;
        case 12:
            num = totalInternalNodes(root);
            printf("Total number of internal nodes:\n%d", num);
            break;
        case 13:
            num = totalLeafNodes(root);
            printf("Total number of leaf nodes:%d\n", num);
            break;
        case 14:
            exit(0);
            break;
        default:
            printf("\nWrong Input\n");
        }
    } while (choice != 14);

    return 0;
}
