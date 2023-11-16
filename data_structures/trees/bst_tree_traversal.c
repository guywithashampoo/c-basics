#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
} node;

node *newnode(int val)
{
    node *n = (node *)malloc(sizeof(node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

node *insertNode(node *root, int val)
{
    if (root == NULL)
    {
        return newnode(val);
    }
    else
    {
        if (root->val > val)
        {
            root->left = insertNode(root->left, val);
        }
        else if (root->val < val)
        {
            root->right = insertNode(root->right, val);
        }
        return root;
    }
}

void inorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorderTraversal(root->left);
        printf("%d\t", root->val);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d\t", root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postorderTraversal(root->left);
        printf("%d\t", root->val);
        postorderTraversal(root->right);
    }
}

int main()
{
    node *root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 8);
    root = insertNode(root, 9);
    root = insertNode(root, 16);
    root = insertNode(root, 12);
    root = insertNode(root, 20);
    root = insertNode(root, 14);
    root = insertNode(root, 13);
    root = insertNode(root, 15);

    preorderTraversal(root);
    printf("\n");
    postorderTraversal(root);
    printf("\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}