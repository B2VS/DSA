#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int check(int *arr, int size)
{
    int i = 0, j = size - 1, count = 0;
    while(i < j)
    {
        if (arr[i] + arr[j] == arr[size])
        {
            ++i; --j;
            count++;
        }
        else if (arr[i] + arr[j] > arr[size])
            --j;
        else
            ++i;
    }
    return count;
}

int main()
{
    int n, i, j, k, count = 0;
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmpfunc);
    for (i = 2; i < n; ++i)
    {
        count += check(arr, i);
    }
    printf("%d", count);
}
