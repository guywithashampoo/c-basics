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
    return q;
}

void enqueue(queue *q, int val)
{
    node *n = newnode(val);
    if (q->head == NULL)
    {
        q->head = n;
        n->next = n;
    }
    else
    {
        node *p = q->head;
        while (p->next != q->head)
        {
            p = p->next;
        }
        p->next = n;
        n->next = q->head;
    }
}

void dequeue(queue *q)
{
    if (q->head == NULL)
    {
        printf("empty queue\n");
    }
    else if (q->head->next == q->head)
    {
        free(q->head);
        q->head = NULL;
    }
    else
    {
        node *p = q->head;
        while (p->next != q->head)
        {
            p = p->next;
        }
        p->next = q->head->next;
        free(q->head);
        q->head = p->next;
    }
}

void printQueue(queue *q)
{
    printf("\n");
    if (q->head == NULL)
    {
        printf("empty queue\n");
    }
    else
    {
        node *p = q->head;
        do
        {
            printf("%d\n", p->val);
            p = p->next;
        } while (p != q->head);
    }
}

int main()
{
    queue *q1 = initqueue();
    enqueue(q1, 3);
    enqueue(q1, 4);
    enqueue(q1, 5);
    printQueue(q1);
    dequeue(q1);
    printQueue(q1);
    return 0;
}