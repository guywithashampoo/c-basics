#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct car
{
    int year;
    char name[30];
    char brand[30];
    char variant[30];
    double price;
} car;

void swap(car *xp, car *yp)
{
    car temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(car arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0)
                swap(&arr[j], &arr[j + 1]);
            swapped = true;
        }
    }

    // If no two elements were swapped by inner loop,
    // then break
    if (swapped == false)
        return;
}

void search(car arr[], int N, char brand[])
{
    for (int i = 0; i < N; i++)
        if (arr[i].brand == brand)
        {
            // return i;
            printf("found %s\n", brand);
            return;
        }
    printf("%s not found\n", brand);
}

void binarySearch(car arr[], int l, int r, char name[])
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m].name == name)
        {
            printf("found %s\n", name);
            return;
        }

        // If x greater, ignore left half
        if (strcmp(arr[m].name, name) < 0)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // If we reach here, then element was not present
    printf("%s not found\n", name);
}

// Function to print an array
void printArray(car arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i].name);
}

// Driver program to test above functions
int main()
{

    car arr[] = {
        // {.year = 1940, .brand = "ferrari", .name = "f40", .price = 1000000.0, .variant = "manual"},
        // {.year = 1940, .brand = "lamborghini", .name = "countach", .price = 1000000.0, .variant = "auto"},
        // {.year = 1940, .brand = "jaguar", .name = "xjc", .price = 1000000.0, .variant = "manual"},
        // {.year = 1940, .brand = "ford", .name = "boss429", .price = 1000000.0, .variant = "auto"},
        // {.year = 1940, .brand = "pagani", .name = "huayra", .price = 1000000.0, .variant = "manual"},
        // {.year = 1940, .brand = "mercedes", .name = "300sl", .price = 1000000.0, .variant = "auto"},
        // {.year = 1940, .brand = "porche", .name = "gt3rs", .price = 1000000.0, .variant = "manual"},
        // {.year = 1940, .brand = "bentley", .name = "continental", .price = 1000000.0, .variant = "auto"},
        // {.year = 1940, .brand = "ford", .name = "gt", .price = 1000000.0, .variant = "manual"},
        // {.year = 1940, .brand = "ferrari", .name = "sf90", .price = 1000000.0, .variant = "auto"}};

        {1940, "ferrari", "f40", "manual", 1000000.0},
        {1940, "lamborghini", "countach", "auto", 1000000.0},
        {1940, "jaguar", "xjc", "manual", 1000000.0},
        {1940, "ford", "boss429", "auto", 1000000.0},
        {1940, "pagani", "huayra", "manual", 1000000.0},
        {1940, "mercedes", "300sl", "auto", 1000000.0},
        {1940, "porche", "gt3rs", "manual", 1000000.0},
        {1940, "bentley", "continental", "auto", 1000000.0},
        {1940, "ford", "gt", "manual", 1000000.0},
        {1940, "ferrari", "sf90", "auto", 1000000.0}};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    search(arr, n, "jaguar");
    binarySearch(arr, 0, n - 1, "jaguar");

    return 0;
}