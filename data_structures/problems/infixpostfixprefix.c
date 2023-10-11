#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    char ch;
    struct node *next;
} node;

typedef struct stack
{
    node *top;
} stack;

node *newnode(char ch)
{
    node *n = (node *)malloc(sizeof(node));
    n->ch = ch;
    n->next = NULL;
    return n;
}

stack *initstack()
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = NULL;
    return s;
}

void push(stack *s, char ch)
{
    node *n = newnode(ch);
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
        return;
    }
    else
    {
        node *p = s->top;
        s->top = s->top->next;
        free(p);
        p = NULL;
    }
}

int precedence(char c)
{
    if (c == '^')
    {
        return 5;
    }
    else if (c == '/' || c == '*' || c == '%')
    {
        return 4;
    }
    else if (c == '+' || c == '-')
    {
        return 3;
        ;
    }
    else if (c == ')')
    {
        return 2;
    }
    else if (c == '(')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool shuoldPop(stack *s, char c)
{
    if (s->top == NULL)
    {
        return false;
    }
    else if (s->top->ch == '(' && c == ')')
    {
        pop(s);
        return true;
    }
    else if (precedence(s->top->ch) > precedence(c))
    {
        printf("%c", s->top->ch);
        pop(s);
        return true;
    }
    else
    {
        return false;
    }
}

bool isChar(char c)
{
    if (((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)))
        return true;
    else
        return false;
}

void infixToPostfix(stack *s, char exp[])
{
    for (int i = 0; i < sizeof(exp) / sizeof(char); i++)
    {
        if (isChar(exp[i]))
        {
            printf("%c", exp[i]);
        }
        else
        {
            bool flag = shuoldPop(s, exp[i]);
            while (flag)
            {
                flag = shuoldPop(s, exp[i]);
            }
            if (exp[i] != ')')
            {
                push(s, exp[i]);
            }
        }
        while (s->top != NULL)
        {
            pop(s);
        }
    }
}

char *reverseString(char exp[])
{
    char rev[] = exp;
    for (int i = 0; i < sizeof(exp) / sizeof(char); i++)
    {
        if (exp[i] != '(' || exp[i] != ')')
        {
            rev[sizeof(exp) / sizeof(char) - i] = exp[i];
        }
    }
    return rev;
}

void infixToPrefix(stack *s, char exp[])
{
    char revexp[] = reverseString(exp);
}

int main()
{

    return 0;
}