#include <stdio.h>
#include <stdlib.h>

#define X 5
#define Y 6

const int a = 5;
const int b = 6;

typedef struct in
{
    int k;
} in;

typedef struct out
{
    struct in *x;
    struct in y;
} out;

int main()
{
    // Dynamic allocation in stack
    in i = {5};
    in j = {6};
    out s = {&i, j};
    out *r = &s;

    printf("%d\n", s.x->k);
    printf("%d\n", s.y.k);
    printf("%d\n", r->x->k);
    printf("%d\n", r->y.k);

    // static allocation in heap, use stdlib for calloc, malloc
    in *l = (in *)malloc(sizeof(in));
    l->k = 20;
    out *m = (out *)malloc(sizeof(out));
    m->x = l;
    m->y = j;

    printf("%d\n", m->x->k);
    printf("%d\n", m->y.k);

    return 0;
}