#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
    struct node *prev;
} node;

typedef struct list
{
    node *head;
} list;

node *newnode(int val)
{
    node *n = (node *)malloc(sizeof(node));
    n->next = NULL;
    n->prev = NULL;
    n->val = val;
    return n;
}

list *initlist()
{
    list *l = (list *)malloc(sizeof(list));
    l->head = NULL;
    return l;
}

void addnode(list *l, int val)
{
    node *n = newnode(val);
    if (l->head == NULL)
    {
        l->head = n;
        n->next = l->head;
        n->prev = l->head;
    }
    else
    {
        node *p = l->head;
        while (p->next != l->head)
        {
            p = p->next;
        }
        p->next = n;
        n->prev = p;
        l->head->prev = n;
        n->next = l->head;
    }
}

void deletenode(list *l, int val)
{
    if (l->head == NULL)
    {
        printf("list empty\n");
    }
    else if (l->head->next == l->head)
    {
        if (l->head->val == val)
        {
            printf("%d deleted\n", l->head->val);
            free(l->head);
            l->head = NULL;
        }
        else
        {
            printf("element not found\n");
        }
    }
    else
    {
        node *p = l->head;
        while ((p->next->next != l->head) && (p->next->val != val))
        {
            p = p->next;
        }
        if (p->next->val == val)
        {
            printf("%d deleted\n", p->next->val);
            node *k = p->next;
            p->next = p->next->next;
            p->next->prev = p;
            free(k);
            k = NULL;
        }
        else
        {
            printf("element not found\n");
        }
    }
}

void printlist(list *l)
{
    if (l->head == NULL)
    {
        printf("list empty\n");
    }
    else
    {
        node *p = l->head;
        do
        {
            printf("%d\n", p->val);
            p = p->next;
        } while (p != l->head);
    }
}

int main()
{
    list *l1 = initlist();
    addnode(l1, 4);
    addnode(l1, 5);
    addnode(l1, 6);
    addnode(l1, 7);
    printlist(l1);
    deletenode(l1, 7);
    printlist(l1);
    return 0;
}