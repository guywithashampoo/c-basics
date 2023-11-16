#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} node;

typedef struct stack
{
    node *top;
} stack;

node *newnode(int val)
{
    node *n = (node *)malloc(sizeof(node));
    n->next = NULL;
    n->val = val;
}

stack *initstack()
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = NULL;
}

void push(stack *s, int val)
{
    node *n = newnode(val);
    if (s->top == NULL)
    {
        s->top = n;
    }
    else
    {
        n->next = s->top;
        s->top = n;
    }
}

void pop(stack *s)
{
    if (s->top == NULL)
    {
        printf("empty stack\n");
    }
    else
    {
        printf("popped element %d\n", s->top->val);
        node *tmp = s->top->next;
        free(s->top);
        s->top = tmp;
    }
}

int main()
{
    stack *s = initstack();
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    pop(s);
    pop(s);
    pop(s);
    return 0;
}