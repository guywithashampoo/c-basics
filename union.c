#include <stdio.h>

union x
{
    int y;
    char z;
    float f;
} x1;

int main()
{
    x1.y = 5;
    printf("%d\n", x1.y);
    printf("%c\n", x1.z); // garbage value
    printf("%f\n", x1.f); // default value = 0
    x1.z = 'b';
    printf("%d\n", x1.y); // char equivalent
    printf("%c\n", x1.z);
    printf("%f\n", x1.f); // default value = 0
    x1.f = 6.0;
    printf("%d\n", x1.y); // garbage value
    printf("%c\n", x1.z); // indeterminate value
    printf("%f\n", x1.f);

    printf("\n%d\n", sizeof(x1)); // largest data type
    return 0;
}

/*
5
♣
0.000000
98
b
0.000000
1086324736

6.000000

4
*/