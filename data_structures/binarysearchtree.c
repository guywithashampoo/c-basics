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

void insertNode(node *root, int val)
{
    node *n = newnode(val);
    if (root == NULL)
    {
        root = n;
    }
    else
    {
        if (root->val > val)
        {
            insertNode(root->left, val);
        }
        else if (root->val < val)
        {
            insertNode(root->right, val);
        }
        else
        {
            return;
        }
    }
}

node *deleteNode(node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    else
    {
        if (root->val > val)
        {
            root->left = deleteNode(root->left, val);
            return root;
        }
        else if (root->val < val)
        {
            root->right = deleteNode(root->left, val);
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
                node *n = deleteInorderSuccessor(root->left);
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

                // node* n = deleteInorderPredeccessor(root->left);
                // if(root->left == n){
                //     n->right = root->right;
                // }else{
                //     n->left = root->left;
                //     n->right = root->right;
                // }
                // free(root);
                // return n;
            }
        }
    }
}

// node* swap(node* root){
//     node* s = inorderSuccessor(root->right);
//     node* pre = root->right;
//     while(pre->left!=s){
//         pre = pre->left;
//     }

//     s->left = root->left;
//     s->right = root->right;

//     pre->left = root;

//     free(root);
//     root->left = NULL;
//     root->right = NULL;

//     return s;
// }

// node* inorderSuccessor(node* root){
//     if(root->left == NULL){
//         return root;
//     }else{
//         return inorderSuccessor(root->left);
//     }
// }

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
    printf("\n");
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
    printf("\n");
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
    printf("\n");
}

int main()
{
    node *root = NULL;
    insertNode(root, 10);
    insertNode(root, 8);
    insertNode(root, 9);
    insertNode(root, 16);
    insertNode(root, 12);
    insertNode(root, 20);
    insertNode(root, 14);
    insertNode(root, 13);
    insertNode(root, 15);

    inorderTraversal(root);

    return 0;
}