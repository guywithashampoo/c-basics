#include <stdio.h>
#include <stdlib.h>

void table()
{
    printf("DATA TYPE\t\tFORM.SP.\tSIZE\t\tDEFAULT VALUE\n");
    short int a;
    printf("short int\t\thd\t\t%d\t\t%hd\n", sizeof(a), a);
    unsigned short int b;
    printf("unsigned short int\thu\t\t%d\t\t%hu\n", sizeof(b), b);
    unsigned int c;
    printf("unsigned int\t\tu\t\t%d\t\t%u\n", sizeof(c), c);
    int d;
    printf("int\t\t\td\t\t%d\t\t%d\n", sizeof(d), d);
    long int e;
    printf("long int\t\tld\t\t%d\t\t%ld\n", sizeof(e), e);
    unsigned long int f;
    printf("unsigned long int\tlu\t\t%d\t\t%lu\n", sizeof(c), c);
    long long int g;
    printf("long long int\t\tlld\t\t%d\t\t%lld\n", sizeof(g), g);
    unsigned long long int h;
    printf("unsigned long long int\tllu\t\t%d\t\t%llu\n", sizeof(h), h);
    signed char i;
    printf("signed char\t\tc\t\t%d\t\t%c\n", sizeof(i), i);
    unsigned char j;
    printf("unsigned char\t\tc\t\t%d\t\t%c\n", sizeof(j), j);
    char ch;
    printf("char\t\t\tc\t\t%d\t\t%c\n", sizeof(ch), ch);
    float k;
    printf("float\t\t\tf\t\t%d\t\t%f\n", sizeof(k), k);
    double l;
    printf("double\t\t\tlf\t\t%d\t\t%lf\n", sizeof(l), l);
    long double m;
    printf("long double\t\tLf\t\t%d\t\t%Lf\n", sizeof(m), m);
    struct n
    {
        int o;
    } n1;
    printf("int in struct\t\td\t\t%d\t\t%d\n", sizeof(n1.o), n1.o);
    int *p;
    printf("pointer\t\t\tp\t\t%d\t\t%p\n", sizeof(p), p);
    int q[2];
    printf("int in array\t\td\t\t%d\t\t%d\n", sizeof(q[0]), q[0]);
    enum r
    {
        el1,
        el2,
        el3
    };
    enum r t1;
    printf("enum\t\t\tf\t\t%d\t\t%d\n", sizeof(t1), t1);

    /*
        DATA TYPE               FORM.SP.        SIZE            DEFAULT VALUE
        short int               hd              2               64
        unsigned short int      hu              2               128
        unsigned int            u               4               2510848
        int                     d               4               0
        long int                ld              4               4201280
        unsigned long int       lu              4               2510848
        long long int           lld             8               18044751049785168
        unsigned long long int  llu             8               18044362185207597
        signed char             c               1               [indeterminate]
        unsigned char           c               1               [indeterminate]a
        char                    c               1               [indeterminate]
        float                   f               4               [0.0]-1.#QNAN0
        double                  lf              8               [0]-6442649977230984800000000000000000000000000000000000000000000000000.000000
        long double             Lf              12              0.000000
        int in struct           d               4               4199136
        pointer                 p               4               00401B40
        int in array            d               4               -1142167633
        enum                    f               4               0
    */
}

void lim_form_sp()
{
    int x = 123456;
    int *p = &x;
    printf("%d\n", x);
    printf("%.8d\n", x); // atleast 8
    printf("%8d\n", x);  // atleast 8

    char s[] = "abcdefg";
    printf("%.*s\n", 4, s); // first 4
    printf("%.4s\n", s);    // first 4
    printf("%.10s\n", x);   // unidentified
    /*
        123456
        00123456
        123456
        abcd
        abcd

    */
}

int main()
{
    // table();
    lim_form_sp();
    return 0;
}