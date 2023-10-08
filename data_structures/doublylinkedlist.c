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
    node *tail;
} list;

node *newnode(int val)
{
    node *n = (node *)malloc(sizeof(node));
    n->val = val;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

list *initlist()
{
    list *l = (list *)malloc(sizeof(list));
    l->head = NULL;
    l->tail = NULL;
    return l;
}

void insertnodelast(list *l, int val)
{
    node *n = newnode(val);
    if (l->head == NULL)
    {
        l->head = n;
        l->tail = n;
    }
    else
    {
        l->tail->next = n;
        n->prev = l->tail;
        l->tail = n;
    }
}

void insertnodebeginning(list *l, int val)
{
    node *n = newnode(val);
    if (l->head == NULL)
    {
        l->head = n;
        l->tail = n;
    }
    else
    {
        l->head->prev = n;
        n->next = l->head;
        l->head = n;
    }
}

void insertatindex(list *l, int val, int i)
{
    if (i == 0)
    {
        insertnodebeginning(l, val);
        return;
    }
    node *n = newnode(val);
    node *p = l->head;
    for (int j = 1; j < i; j++)
    {
        if (p != NULL)
        {
            p = p->next;
        }
        else
        {
            printf("index out of bounds\n");
            return;
        }
    }
    if (p == l->tail)
    {
        insertnodelast(l, val);
        return;
    }
    n->next = p->next;
    p->next->prev = n;
    n->prev = p;
    p->next = n;
}

void deletelastnode(list *l)
{
    if (l->head == NULL)
    {
        printf("list empty\n");
    }
    else if (l->head == l->tail)
    {
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
    }
    else
    {
        node *p = l->tail->prev;
        free(p->next);
        p->next = NULL;
        l->tail = p;
    }
}

void deletefirstnode(list *l)
{
    if (l->head == NULL)
    {
        printf("list empty\n");
    }
    else if (l->head == l->tail)
    {
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
    }
    else
    {
        node *p = l->head->next;
        free(p->prev);
        p->prev = NULL;
        l->head = p;
    }
}

void deleteatindex(list *l, int i)
{
    if (i == 0)
    {
        deletefirstnode(l);
        return;
    }
    node *p = l->head;
    for (int j = 1; j < i; j++)
    {
        if (p != NULL)
        {
            p = p->next;
        }
        else
        {
            printf("index out of bounds\n");
            return;
        }
    }
    if (p == l->tail)
    {
        deletelastnode(l);
        return;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
}

void printlist(list *l)
{
    printf("\n");
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
        } while (p != NULL);
    }
}

int main()
{
    list *l1 = initlist();
    insertnodebeginning(l1, 5);
    insertnodebeginning(l1, 6);
    insertnodebeginning(l1, 7);
    printlist(l1);
    insertnodelast(l1, 8);
    printlist(l1);
    insertatindex(l1, 9, 2);
    printlist(l1);
    deletefirstnode(l1);
    printlist(l1);
    deletelastnode(l1);
    printlist(l1);
    deleteatindex(l1, 2);
    printlist(l1);
    return 0;
}