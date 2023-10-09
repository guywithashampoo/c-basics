#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coef;
    int exp;
    struct node *next;
} node;

typedef struct poly
{
    node *head;
} poly;

node *newnode(int coef, int exp)
{
    node *n = (node *)malloc(sizeof(node));
    n->coef = coef;
    n->exp = exp;
    n->next = NULL;
    return n;
}

poly *initpoly()
{
    poly *p = (poly *)malloc(sizeof(poly));
    p->head = NULL;
    return p;
}

void addcoef(poly *p, int coef, int exp)
{
    if (coef == 0)
    {
        return;
    }
    node *n = newnode(coef, exp);
    if (p->head == NULL)
    {
        p->head = n;
    }
    else
    {
        node *k = p->head;
        while (k->next != NULL)
        {
            k = k->next;
        }
        k->next = n;
    }
}

poly *addpoly(poly *p1, poly *p2)
{
    node *x = p1->head;
    node *y = p2->head;
    poly *p = initpoly();
    if (x != NULL && y != NULL)
    {
        while (x != NULL && y != NULL)
        {
            if (x->exp == y->exp)
            {
                addcoef(p, x->coef + y->coef, x->exp);
                x = x->next;
                y = y->next;
            }
            else if (x->exp > y->exp)
            {
                addcoef(p, x->coef, x->exp);
                x = x->next;
            }
            else
            {
                addcoef(p, y->coef, y->exp);
                y = y->next;
            }
        }
    }
    if (x == NULL && y != NULL)
    {
        while (y != NULL)
        {
            addcoef(p, y->coef, y->exp);
            y = y->next;
        }
    }
    else if (y == NULL && x != NULL)
    {
        while (x != NULL)
        {
            addcoef(p, x->coef, x->exp);
            x = x->next;
        }
    }
    return p;
}

void printpoly(poly *p)
{
    node *k = p->head;
    char c = '+';
    if (k == NULL)
    {
        return;
    }
    else
    {
        printf("%dx^%d", k->coef, k->exp);
        k = k->next;
        while (k != NULL)
        {
            c = (k->coef >= 0) ? '+' : '-';
            printf("%c%dx^%d", c, abs(k->coef), k->exp);
            k = k->next;
        }
    }
    printf("\n");
}

void inputpoly(poly *p)
{
    int c = 0, e = 0;
    char ch = '+';
    char tmp;
    printf("enter polynomail\n");
    scanf("%d%c^%d%c", &c, &tmp, &e, &ch);
    addcoef(p, c, e);
    while (ch != 10)
    {
        if (ch == '-')
        {
            scanf("%d%c^%d%c", &c, &tmp, &e, &ch);
            addcoef(p, -c, e);
        }
        else
        {
            scanf("%d%c^%d%c", &c, &tmp, &e, &ch);
            addcoef(p, c, e);
        }
    }
}

int main()
{
    poly *p1 = initpoly();
    inputpoly(p1);
    poly *p2 = initpoly();
    inputpoly(p2);
    poly *p3 = addpoly(p1, p2);
    printpoly(p3);
    return 0;
}