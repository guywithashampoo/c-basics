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

list *initlist()
{
    list *l = (list *)malloc(sizeof(list));
    l->head = NULL;
    return l;
}

node *newnode(int val)
{
    node *n = (node *)malloc(sizeof(node));
    n->val = val;
    n->next = NULL;
    return n;
}

void insertNodeEnd(list *l, int val)
{
    node *n = newnode(val);
    if (l->head == NULL)
    {
        l->head = n;
    }
    else
    {
        node *p = l->head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = n;
    }
}

void insertNodeStart(list *l, int val)
{
    node *n = newnode(val);
    if (l->head == NULL)
    {
        l->head = n;
    }
    else
    {
        n->next = l->head;
        l->head = n;
    }
}

void insertAfterIndex(list *l, int val, int i)
{
    node *n = newnode(val);
    node *p = l->head;
    if (i == 0)
    {
        n->next = l->head;
        l->head = n;
    }
    else
    {

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
        n->next = p->next;
        p->next = n;
    }
}

void deleteNodeEnd(list *l)
{
    if (l->head == NULL)
    {
        printf("list empty\n");
    }
    else if (l->head->next == NULL)
    {
        printf("deleted %d\n", l->head->val);
        free(l->head);
        l->head = NULL;
    }
    else
    {
        node *p = l->head;
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        printf("deleted %d\n", p->next->val);
        free(p->next);
        p->next = NULL;
    }
}

void deleteNodeStart(list *l)
{
    if (l->head == NULL)
    {
        printf("list empty\n");
    }
    else if (l->head->next == NULL)
    {
        printf("deleted %d\n", l->head->val);
        free(l->head);
        l->head = NULL;
    }
    else
    {
        node *p = l->head->next;
        free(l->head);
        l->head = p;
    }
}

void deleteIndex(list *l, int i)
{
    node *p = l->head;
    node *tmp;
    if (i == 1)
    {
        printf("deleted %d\n", l->head->val);
        tmp = p->next;
        free(l->head);
        l->head = tmp;
    }
    else
    {
        for (int j = 1; j < i - 1; j++)
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
        tmp = p->next->next;
        free(p->next);
        p->next = tmp;
    }
}

void printLinkedlist(list *l)
{
    printf("\n");
    if (l->head == NULL)
    {
        printf("list empty\n");
    }
    else
    {
        node *n = l->head;
        do
        {
            printf("%d\n", n->val);
            n = n->next;
        } while (n != NULL);
    }
}

int countListElements(list *l)
{
    int count = 0;
    node *n = l->head;
    while (n != NULL)
    {
        n = n->next;
        count++;
    }
    return count;
}

void frontBackSplit(list *l, list *l1, list *l2)
{
    int count = countListElements(l);
    int mid = (count % 2 == 0) ? count / 2 : (count / 2) + 1;
    node *n = l->head;
    while (mid != 0)
    {
        insertNodeEnd(l1, n->val);
        n = n->next;
        mid--;
    }
    while (n != NULL)
    {
        insertNodeEnd(l2, n->val);
        n = n->next;
    }
}

int main()
{
    list *l1 = initlist();

    insertNodeEnd(l1, 3);
    insertNodeEnd(l1, 4);
    insertNodeEnd(l1, 5);
    insertNodeEnd(l1, 6);
    insertNodeEnd(l1, 7);
    printLinkedlist(l1);
    insertAfterIndex(l1, 10, 2);
    printLinkedlist(l1);
    deleteIndex(l1, 3);
    printLinkedlist(l1);
    // deleteNodeEnd(l1);
    // printLinkedlist(l1);
    // deleteNodeStart(l1);
    // printLinkedlist(l1);

    list *l2 = initlist();
    list *l3 = initlist();

    frontBackSplit(l1, l2, l3);
    printLinkedlist(l2);
    printLinkedlist(l3);
}
