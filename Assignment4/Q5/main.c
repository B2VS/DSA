#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int bin_search(int *arr, int size, int ele)
{
    int start = 0, mid, end = size - 1;
    while(start <= end)
    {
        mid = (start + end) / 2;
        if (ele == arr[mid])
            return mid;
        if (ele > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main()
{
    int n, k, i;
    scanf("%d", &n);
    int *arr = (int *) malloc((n + 2) * sizeof(int));
    for (i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);
    scanf("%d", &k);
    arr[n + 1] = INT_MAX;
    arr[0] = INT_MIN;
    int begin = 1, mid;
    int end = n;
    while(begin <= end)
    {
        mid = (begin + end) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            break;
        if (arr[mid] > arr[n])
            begin = mid + 1;
        else
            end = mid - 1;
    }
    int index;
    if (k <= arr[n]) index = mid + bin_search(arr + mid + 1, n - mid, k);
    else index = bin_search(arr + 1, mid + 1, k);
    printf("%d", index);
}
