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
}

list *initlist()
{
    list *l = (list *)malloc(sizeof(list));
    l->head = NULL;
    l->tail = NULL;
}

void insertnodelast(list *l, int val)
{
    node *n = newnode(val);
    if (l->head == NULL)
    {
        l->head = n;
        l->tail = n;
    }
    else if (l->head == l->tail)
    {
        l->head->next = n;
        n->prev = l->head;
    }
    else
    {
        node *p = l->head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = n;
        n->prev = p;
    }
}

void deletenode(list *l)
{
    if (l->head = NULL)
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
        node *p = l->head;
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        free(p->next);
        p->next = NULL;
    }
}

void insertatindex(list *l, int val, int i)
{
    node *n = newnode(val);
    if (i == 0)
    {
        l->head->prev = n;
        n->next = l->head;
        l->head = n;
    }
    else
    {
        node *p = l->head;
        for (int j = 1; j < i; j++)
        {
            if (p != NULL)
            {
                p = p->next;
            }
            else
            {
                printf("invalid index\n");
                return;
            }
        }
        if (p->next)
        {
            n->next = p->next;
            p->next->prev = n;
        }
        n->prev = p;
        p->next = n;
    }
}

void deleteatindex(list *l, int i)
{
    if (i == 0)
    {
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
    }
    else
    {
        node *p = l->head;
        for (int j = 1; j < i; j++)
        {
            if (p->next == NULL)
            {
                printf("invalid index\n");
                return;
            }
        }
    }
}

int main()
{
    return 0;
}