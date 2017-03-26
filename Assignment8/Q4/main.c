#include <stdio.h>
#include <stdlib.h>

int findmin(int *arr, int k)
{
    int min = arr[0], i;
    for (i = 0; i < k; ++i)
        if (arr[i] < min)
            min = arr[i];
    return min;
}

int findmax(int *arr, int k)
{
    int max = arr[0], i;
    for (i = 0; i < k; ++i)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int main()
{
    int n, k, sum = 0;
    printf("n = ");
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    printf("arr[] = ");
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    printf("k = ");
    scanf("%d", &k);
    int min = findmin(arr, k), max = findmax(arr, k);
    sum = min + max;
    for (i = 0; i < n - k - 1; ++i)
    {

    }
}
