#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5, n2 = 4;
    int *ptr1 = (int *)malloc(n * sizeof(int));
    // malloc() function creates a single block of memory of a specific size.
    // malloc() is faster.
    // The memory block allocated by malloc() has a garbage value.
    // malloc() indicates memory allocation.

    int *ptr2 = (int *)calloc(n, sizeof(int));
    // calloc() function assigns multiple blocks of memory to a single variable.
    // calloc() is slower.
    // The memory block allocated by calloc() is initialized by zero.
    // calloc() indicates contiguous allocation.

    ptr2 = realloc(ptr2, n2 * sizeof(int));
    free(ptr1);
    ptr1 = NULL; // prevents dangling pointers
    free(ptr2);
    ptr2 = NULL; // prevents dangling pointers
    // pointer still exists and points to same location, but now points to garbage value
    // after free, clear pointer by setting it to NULL

    return 0;
}