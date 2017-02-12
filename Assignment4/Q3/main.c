#include <stdio.h>
#include <stdlib.h>

int peak(int *arr, int size)
{
    if (size == 1) return 0;
    if (arr[0] >= arr[1]) return 0;
    if (arr[size - 1] >= arr[size - 2]) return size - 1;
    int start = 1, end = size-2, mid;
    while(start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
            return mid;
        if (arr[mid] <= arr[mid - 1])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    printf("%d", peak(arr, n));
}
