#include <stdio.h>

int main()
{
    enum day
    {
        mon,
        tue,
        wed
    };
    enum day d;
    d = tue;
    printf("%d\n", d);

    enum months
    {
        jan = 2,
        feb,
        mar,
        apr = 10,
        may,
        jun,
        jul = 11,
        aug
    };
    enum months month2 = feb;
    enum months month3 = may;
    enum months month4 = jun;
    enum months month5 = jul;
    enum months month6 = aug;
    printf("%d %d %d %d %d\n", month2, month3, month4, month5, month6);
    //3 11 12 11 12

    return 0;
}