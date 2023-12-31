#include <stdio.h>
#include <string.h>

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, to_rod, from_rod, aux_rod);
}

int isPalindrome(char s[], int x, int y)
{
    if (x >= y)
    {
        return 1;
    }
    else
    {
        if (s[x] == s[y])
        {
            return isPalindrome(s, x + 1, y - 1);
        }
        else
        {
            return 0;
        }
    }
}
int main()
{

    // binary search
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array") : printf("Element is present at index %d", result);

    // tower of hanoi
    int N = 3;
    towerOfHanoi(N, 'A', 'C', 'B');

    // is palindrome
    char c[] = "abccba";
    int isPal = isPalindrome(c, 0, strlen(c) - 1);
    printf("%d\n", isPal);

    return 0;
}
