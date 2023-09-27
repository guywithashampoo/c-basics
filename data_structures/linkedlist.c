// Linked list implementation in C

#include <stdio.h>
#include <stdlib.h>

// Creating a node
typedef struct node
{
    int value;
    struct node *next;
} node;

typedef struct list
{
    node *head;
} list;

list *init_list()
{
    // list *l = (list *)malloc(sizeof(list));
    // list *l;
    // l->head = NULL;

    list l;
    l.head = NULL;
    list *l1 = &l;
    return l1;
}

node *newnode(int val)
{
    node *n = (node *)malloc(sizeof(node));
    n->value = val;
    n->next = NULL;
    return n;
}

void printLinkedlist(list *l)
{
    if (l->head == NULL)
    {
        printf("list empty\n");
    }
    else
    {
        node *n = l->head;
        do
        {
            printf("%d\n", n->value);
        } while (n->next != NULL);
    }
}

void insertnode(list *l, int val)
{
    node *n = newnode(val);
    if (l->head == NULL)
    {
        l->head = n;
    }
    else
    {
        node *p = l->head;
        while (l->head->next != NULL)
        {
            p = p->next;
        }
        p->next = n;
    }
}

int deletenode(list *l)
{
    if (l->head == NULL)
    {
        return -1;
    }
    else if (l->head->next == NULL)
    {
        free(l->head);
        l->head == NULL;
    }
    else
    {
        node *p = l->head;
        while (l->head->next->next != NULL)
        {
            p = p->next;
        }
        free(p->next);
        p->next = NULL;
    }
}

int main()
{
    list *l1 = initlist();

    printLinkedlist(l1);
}