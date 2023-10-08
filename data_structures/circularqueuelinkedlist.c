#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} node;

typedef struct list
{
    node *head;
} list;

node *newnode(int val)
{
    node *n = (node *)malloc(sizeof(node));
    n->val = val;
    n->next = NULL;
    return n;
}

list *initlist()
{
    list *l = (list *)malloc(sizeof(list));
    l->head = NULL;
    return l;
}

void addlist(list *l, int val)
{
    node *n = newnode(val);
    if (l->head == NULL)
    {
        l->head = n;
        l->head->next = n;
    }
    else
    {
        node *p = l->head;
        while (p->next != l->head)
        {
            p = p->next;
        }
        p->next = n;
        n->next = l->head;
    }
}

void deletelist(list *l)
{
    if (l->head == NULL)
    {
        printf("empty list\n");
    }
    else if (l->head->next == l->head)
    {
        free(l->head);
        l->head = NULL;
    }
    else
    {
        node *p = l->head;
        while (p->next->next != l->head)
        {
            p = p->next;
        }
        free(p->next);
        p->next = l->head;
    }
}

void printlist(list *l)
{
    if (l->head == NULL)
    {
        printf("empty queue\n");
    }
    else
    {
        node *p = l->head;
        while (p != l->head)
        {
            printf("%d\n", p->val);
            p = p->next;
        }
    }
}

int main()
{
    list *l1 = initlist();
    addlist(l1, 3);
    addlist(l1, 4);
    addlist(l1, 5);
    printlist(l1);
    deletelist(l1);
    printlist(l1);

    return 0;
}