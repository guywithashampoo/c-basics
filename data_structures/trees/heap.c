#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int heap[MAX];
int top = -1;

// Arr[(i-1)/2]	Returns the parent node
// Arr[(2*i)+1]	Returns the left child node
// Arr[(2*i)+2]	Returns the right child node

void swap(int x, int y)
{
    int temp = heap[x];
    heap[x] = heap[y];
    heap[y] = temp;
}

void insertMinHeap(int val)
{
    heap[++top] = val;
    int x = top;
    while (top != 0 || heap[x] < heap[(x - 1) / 2])
    {
        swap(x, ((x - 1) / 2));
        x = (x - 1) / 2;
    }
}

int deleteMinHeap()
{
    if (top == -1)
    {
        return NULL;
    }
    int val = heap[0];
    swap(0, top--);
    int x = 0;
    while ((x * 2 + 1) < top && (heap[x] > heap[(2 * x) + 1] || heap[x] > heap[(2 * x) + 2]))
    {
        if (heap[(2 * x) + 2] > heap[(2 * x) + 1])
        {
            swap(x, (2 * x) + 1);
        }
        else
        {
            swap(x, (2 * x) + 2);
        }
    }
    return val;
}

// void insertMaxHeap(int val)
// {
// }

// int deleteMaxHeap()
// {
// }

// heapify()
// {
// }

void printHeap()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d\t", i);
    }
    printf("\n");
}

int main()
{
    insertMinHeap(10);
    printHeap();
    insertMinHeap(9);
    printHeap();
    insertMinHeap(8);
    printHeap();
    insertMinHeap(7);
    printHeap();
    return 0;
}