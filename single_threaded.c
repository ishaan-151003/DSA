#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct BST{
    int data;
    struct BST *left, *right;
    bool rthread;
};
typedef struct BST node;
node *root = NULL;
node *insert(node *tree, node *ptr, int elem);