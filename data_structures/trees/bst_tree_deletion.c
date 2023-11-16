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

node *deleteInorderPredeccessor(node *root)
{
    if (root->right == NULL)
    {
        return root;
    }
    else if (root->right->right == NULL)
    {
        node *tmp = root->right;
        root->right = (root->right->left) ? root->right->left : NULL;
        return tmp;
    }
    else
    {
        return deleteInorderPredeccessor(root->right);
    }
}

node *deleteInorderSuccessor(node *root)
{
    if (root->left == NULL)
    {
        return root;
    }
    else if (root->left->left == NULL)
    {
        node *tmp = root->left;
        root->left = (root->left->right) ? root->left->right : NULL;
        return tmp;
    }
    else
    {
        return deleteInorderSuccessor(root->left);
    }
}

node *deleteNodeSucc(node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    else
    {
        if (root->val > val)
        {
            root->left = deleteNodeSucc(root->left, val);
            return root;
        }
        else if (root->val < val)
        {
            root->right = deleteNodeSucc(root->right, val);
            return root;
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                free(root);
                return NULL;
            }
            else if (root->left == NULL)
            {
                node *tmp = root->right;
                free(root);
                return tmp;
            }
            else if (root->right == NULL)
            {
                node *tmp = root->left;
                free(root);
                return tmp;
            }
            else
            {
                node *n = deleteInorderSuccessor(root->right);
                if (root->right == n)
                {
                    n->left = root->left;
                }
                else
                {
                    n->left = root->left;
                    n->right = root->right;
                }
                free(root);
                return n;
            }
        }
    }
}

node *deleteNodePre(node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    else
    {
        if (root->val > val)
        {
            root->left = deleteNodePre(root->left, val);
            return root;
        }
        else if (root->val < val)
        {
            root->right = deleteNodePre(root->right, val);
            return root;
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                free(root);
                return NULL;
            }
            else if (root->left == NULL)
            {
                node *tmp = root->right;
                free(root);
                return tmp;
            }
            else if (root->right == NULL)
            {
                node *tmp = root->left;
                free(root);
                return tmp;
            }
            else
            {
                node *n = deleteInorderPredeccessor(root->left);
                if (root->left == n)
                {
                    n->right = root->right;
                }
                else
                {
                    n->left = root->left;
                    n->right = root->right;
                }
                free(root);
                return n;
            }
        }
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

    root = deleteNodeSucc(root, 10);
    preorderTraversal(root);
    printf("\n");

    root = deleteNodeSucc(root, 12);
    preorderTraversal(root);
    printf("\n");

    return 0;
}