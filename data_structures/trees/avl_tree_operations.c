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

int height(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else if ((root->left == NULL && root->right == NULL))
    {
        return 0;
    }
    return (height(root->left) > height(root->right)) ? 1 + height(root->left) : 1 + height(root->right);
}

node *checkNRotate(node *root)
{
    int bf = height(root->left) - height(root->right);
    if (bf < -1)
    {
        bf = height(root->right->left) - height(root->right->right);
        if (bf > 0)
        {
            // rl
            node *tmp = root->right->left;
            root->right->left = tmp->right;
            tmp->right = root->right;
            root->right = tmp->left;
            tmp->left = root;
            return tmp;
        }
        else if (bf <= 0)
        {
            // rr
            node *tmp = root->right;
            root->right = root->right->left;
            tmp->left = root;
            return tmp;
        }
        // bf == 0 conditions does rr rotation. result will also be valid if chnaged to rl
    }
    else if (bf > 1)
    {
        bf = height(root->left->left) - height(root->left->right);
        if (bf > 0)
        {
            // ll
            node *tmp = root->left;
            root->left = root->left->right;
            tmp->right = root;
            return tmp;
        }
        else if (bf <= 0)
        {
            // lr
            node *tmp = root->left->right;
            root->left->right = tmp->left;
            tmp->left = root->left;
            root->left = tmp->right;
            tmp->right = root;
            return tmp;
        }
        // bf == 0 conditions does ll rotation. result will also be valid if chnaged to lr
    }
    else
    {
        return root;
    }
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
            return checkNRotate(root);
        }
        else if (root->val < val)
        {
            root->right = insertNode(root->right, val);
            return checkNRotate(root);
        }
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
            return checkNRotate(root);
        }
        else if (root->val < val)
        {
            root->right = deleteNodeSucc(root->right, val);
            return checkNRotate(root);
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
            return checkNRotate(root);
        }
        else if (root->val < val)
        {
            root->right = deleteNodePre(root->right, val);
            return checkNRotate(root);
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

node *searchNode(node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (root->val > val)
        {
            return searchNode(root->left, val);
        }
        else if (root->val < val)
        {
            return searchNode(root->right, val);
        }
        return root;
    }
}

void heightOf(node *root, int val)
{
    node *n = searchNode(root, val);
    if (!n)
    {
        printf("%d not found\n", val);
    }
    else
    {
        printf("height of %d : %d\n", val, height(n));
    }
}

int main()
{
    node *root = NULL;

    root = insertNode(root, 75);
    root = insertNode(root, 60);
    root = insertNode(root, 120);
    root = insertNode(root, 68);
    root = insertNode(root, 90);
    root = insertNode(root, 125);
    root = insertNode(root, 83);
    root = insertNode(root, 100);

    inorderTraversal(root);
    printf("\n");
    root = deleteNodeSucc(root, 125);

    inorderTraversal(root);
    printf("\n");

    return 0;
}