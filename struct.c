#include <stdio.h>

// structure variable
struct v
{
    int t;
    char x[3];
    int y;
    float p;
} v1 = {5, {1, 2, 3}, 55, 5.5}, v2 = {5, 5.5};

// tagged structure
struct t
{
    int x;
    int y;
    float z
};

struct t t1 = {1, 2.0, 3.0};
struct t t2 = {1, 2.0};

// type defined structure
typedef struct
{
    int x[3];
    int y;
    float p;
} s;

int main()
{
    printf("%d \t%d %d %d \t%d \t%f\n", v1.t, v1.x[0], v1.x[1], v1.x[2], v1.y, v1.p);
    printf("%d \t%d %d %d \t%d \t%f\n", v2.t, v2.x[0], v2.x[1], v2.x[2], v2.y, v2.p);
    printf("%d \t%f \t%d\n", t1.x, t1.y, t1.z);
    printf("%d \t%f \t%d\n", t2.x, t2.y, t2.z);

    s s1 = {{}, 0, 0.0};
    s *s1p = &s1;
    s1p->x[0] = 7;
    s1p->y = 3;
    s1p->p = 3.3;

    printf("%d \t%d \t%f \t%d\n", s1p->x[0], s1p->y, s1p->p);

    // &s1p.x == &(s1p.x)
    // s1p.x++ == (s1p.x)++
    // *(s1p).x == s1p->x

    return 0;
}