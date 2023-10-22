#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void swap(node *prev, node *a, node *b)
{
    if (prev == NULL)
    {
        a->next = b->next;
        b->next = a;
    }
    else
    {
        prev->next = b;
        a->next = b->next;
        b->next = a;
    }
}

void bubbleSort(list *l)
{
    int c = countListElements(l);
    int k = c - 1;
    bool swapped = false;
    if (c == 0 || c == 1)
    {
        return;
    }
    else
    {
        for (int i = 1; i < c; i++)
        {
            node *prev = NULL;
            printf("prev =  %d\n", (prev) ? prev->val : 0);
            node *a = l->head;
            printf("a =  %d\n", a->val);
            node *b = l->head->next;
            printf("b =  %d\n", b->val);
            for (int j = 0; j < k; j++)
            {
                if ((a->val > b->val) && (j == 0))
                {
                    l->head = b;
                    swap(prev, a, b);
                    swapped = true;
                }
                else if ((a->val > b->val) && (j != 0))
                {
                    swap(prev, a, b);
                    swapped = true;
                }
                else
                {
                    swapped = false;
                }
                if (swapped)
                {
                    prev = b;
                    b = a->next;
                }
                else
                {
                    prev = a;
                    a = a->next;
                    b = b->next;
                }
            }
            k--;
        }
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
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = n;
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

void deletenode(list *l)
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

int main()
{
    list *l1 = initlist();

    insertnode(l1, 7);
    insertnode(l1, 3);
    insertnode(l1, 6);
    // insertnode(l1, 5);
    // insertnode(l1, 4);
    printLinkedlist(l1);
    bubbleSort(l1);
    printLinkedlist(l1);
    // insertAfterIndex(l1, 10, 2);
    // printLinkedlist(l1);
    // deleteIndex(l1, 3);
    // printLinkedlist(l1);
}
