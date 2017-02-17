#include <stdio.h>
#include <stdlib.h>

int *cmpfunc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int n, k, i;
    scanf("%d %d", &n, &k);
    int *arr = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmpfunc);
    int start = 0, end = n - 1;
    while (start < end)
    {
        if (arr[start] + arr[end] == k)
            break;
        if (arr[start] + arr[end] < k)
            start++;
        else
            end--;
    }
    if (start < end) printf("Yes");
    else printf("No");
    return 0;
}
