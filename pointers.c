#include <stdio.h>

void format_specifier()
{
    int x = 10;
    int *p = &x;
    printf("%p\n", p);
    printf("%p\n", x);
    printf("%p\n", &x);
    /*
    0061FF18
    0000000A
    0061FF18
    */
}

void pointer_array()
{
    int arr[5] = {1, 2, 3, 4, 5};

    int(*ptr)[5]; // Pointer to an array of 5 integers
    int *p;       // Pointer to an integer

    p = arr;    // Points to 0th element of the arr.
    ptr = &arr; // Points to the whole array arr.

    printf("p = %p, ptr = %p\n", p, ptr);
    p++;   // +4
    ptr++; // +20
    printf("p = %p, ptr = %p\n", p, ptr);
    printf("*p = %d, *ptr = %p\n", *p, *ptr);

    printf("sizeof(p) = %lu, sizeof(*p) = %lu\n", sizeof(p), sizeof(*p));
    printf("sizeof(ptr) = %lu, sizeof(*ptr) = %lu\n", sizeof(ptr), sizeof(*ptr));

    /*
    p = 0061FF04, ptr = 0061FF04
    p = 0061FF08, ptr = 0061FF18
    *p = 2, *ptr = 0061FF18
    sizeof(p) = 4, sizeof(*p) = 4
    sizeof(ptr) = 4, sizeof(*ptr) = 20
    */
}

void multid_pointer()
{
    // arr[i][j] =>  *(*(arr + i) + j)
    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int i = 1, j = 0;
    printf("%d\n", *(*(arr + i) + j)); // 5
    printf("%d\n", (*(arr + i) + j));  // pointer to 5
    printf("%d\n", *(arr + i));        // pointer to 5
    printf("%d\n", (arr + i));         // pointer to 5

    int arr2[3][4] = {
        {10, 11, 12, 13},
        {20, 21, 22, 23},
        {30, 31, 32, 33}};
    int(*ptr)[4];
    ptr = arr2;
    printf("%p %p %p\n", ptr, ptr + 1, ptr + 2);
    printf("%p %p %p\n", *ptr, *(ptr + 1), *(ptr + 2));
    printf("%d %d %d\n", **ptr, *(*(ptr + 1) + 2), *(*(ptr + 2) + 3));
    printf("%d %d %d\n", ptr[0][0], ptr[1][2], ptr[2][3]);

    int *p = arr2;
    printf("%p %p %p\n", p, p + 1, p + 2);
    printf("%p %p %p\n", *p, *(p + 1), *(p + 2));
    // printf("%d %d %d\n", **p, *(*(p + 1) + 2), *(*(p + 2) + 3));
    // printf("%d %d %d\n", p[0][0], p[1][2], p[2][3]);
}

int main()
{
    // format_specifier();
    // pointer_array();
    // multid_pointer();

    return 0;
}