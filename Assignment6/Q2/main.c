#include <stdio.h>
#include <stdlib.h>

int cmpfunc(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

int simplify(long **ptr, int *size, int m)
{
    int i, k; long x;
    long *arr = *ptr;
    x = arr[0];
    for (i = 1; i < m; ++i)
        arr[*size - i] -= x;
    arr[0] = 0;
    qsort(arr, *size, sizeof(long), cmpfunc);
    for (i = 0; i < *size; ++i)
        if (arr[i] != 0)
            break;
    *size -= i;
    *ptr = *ptr + i;
    return x;
}

int main()
{
    int n, m, i;
    scanf("%d %d", &n, &m);
    long *arr = (long *) malloc (n * sizeof(long));
    long **ptr = &arr;
    for (i = 0; i < n; ++i)
        scanf("%ld", &arr[i]);
    int len = n, count = 0;
    qsort(arr, n, sizeof(long), cmpfunc);
    while (len >= m)
        count += simplify(ptr, &len, m);
    printf("%d", count);
}
