#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} node;

typedef struct queue
{
    node *head;
    node *tail;
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
    l->tail = NULL;
    return l;
}

void enqueue(list *l, int val)
{
    node *n = newnode(val);
    if (l->head == NULL)
    {
        l->head = n;
        l->tail = n;
    }
    else
    {
        node *p = l->head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = n;
        l->tail = n;
    }
}

void dequeue(list *l)
{
    if (l->head == NULL)
    {
        printf("queue empty\n");
    }
    else if (l->head == l->tail)
    {
        printf("dequeued %d\n", l->head->val);
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
    }
    else
    {
        printf("dequeued %d\n", l->head->val);
        node *p = l->head->next;
        free(l->head);
        l->head = p;
    }
}

void printqueue(list *l)
{
    if (l->head == NULL)
    {
        printf("queue empty\n");
    }
    else
    {
        node *p = l->head;
        printf("%d\n", p->val);
        while (p->next != NULL)
        {
            p = p->next;
            printf("%d\n", p->val);
        }
    }
}

int main()
{
    list *l1 = initlist();
    enqueue(l1, 5);
    enqueue(l1, 6);
    enqueue(l1, 7);
    enqueue(l1, 8);
    enqueue(l1, 9);
    dequeue(l1);
    printqueue(l1);
    return 0;
}