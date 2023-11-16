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
} queue;

node *newnode(int val)
{
    node *n = (node *)malloc(sizeof(node));
    n->val = val;
    n->next = NULL;
    return n;
}

queue *initqueue()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enqueue(queue *q, int val)
{
    node *n = newnode(val);
    if (q->head == NULL)
    {
        q->head = n;
        q->tail = n;
    }
    else
    {
        q->tail->next = n;
        q->tail = n;
    }
}

void dequeue(queue *q)
{
    if (q->head == NULL)
    {
        printf("queue empty\n");
    }
    else
    {
        printf("dequeued %d\n", q->head->val);
        node *p = q->head->next;
        free(q->head);
        q->head = p;
    }
}

void printqueue(queue *q)
{
    if (q->head == NULL)
    {
        printf("queue empty\n");
    }
    else
    {
        node *p = q->head;
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
    queue *q1 = initqueue();
    enqueue(q1, 5);
    dequeue(q1);
    printqueue(q1);
    enqueue(q1, 6);
    enqueue(q1, 7);
    enqueue(q1, 8);
    enqueue(q1, 9);
    printqueue(q1);
    return 0;
}