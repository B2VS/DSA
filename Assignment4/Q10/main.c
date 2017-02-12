#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int search(int *arr, int size, int ele)
{
    int start = 1, end = size - 1, mid;
    while(start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] >= ele && arr[mid - 1] < ele)
            return mid;
        if (arr[mid] < ele)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, i, c, diff;
        scanf("%d %d", &n, &c);
        int *arr = (int *) malloc(n * sizeof(int));
        for (i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        qsort(arr, n, sizeof(int), cmpfunc);
        int count, loc;
        for (diff = (arr[n - 1] - arr[0]) / (c - 1); diff > 0; --diff)
        {
            count = 1;
            loc = 0;
            while(count < c)
            {
                loc = search(arr, n, arr[loc] + diff);
                if (loc >= 0)
                    count++;
                else
                    break;
            }
            if (count == c) break;
        }
        loc = 0;
        printf("The numbers are: ");
        while(loc >= 0)
        {
            printf("%d ", arr[loc]);
            loc = search(arr, n, arr[loc] + diff);
        }
        printf("\nThe difference is %d", diff);
    }
}
