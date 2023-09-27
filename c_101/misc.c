#include <stdio.h>

int main()
{
    // int x = 5;
    // int y = 4;
    // float c = (float)x / y;
    // printf("%f\n", c);
    // c = (float)x / (float)y;
    // printf("%f\n", c);

    // float a = 5.0;
    // float b = 4.0;
    // int n = (int)a / b;
    // printf("%d\n", n);

    int p1 = 150, p2;
    float f1 = 100.0, f2;
    f2 = p1 / f1; // int / float = float
    printf("%f\n", f2);
    p1 = 100;
    f1 = 150.0;
    p2 = f1 / p1; // float / int = int
    printf("%d\n", p2);

    // if (1 < 2)
    //     printf("1<2\n");
    // if (2 > 3)
    //     printf("2>3\n");
    // else // goes with the most recent if(2>3)
    //     printf("2<3\n");

    return 0;
}