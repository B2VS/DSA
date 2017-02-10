#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIV 1

int bin_search(int *arr, int size, int ele)
{
    int begin = 0, mid;
    int end = size - 1;
    while (begin <= end)
    {
        mid = (begin + end) / 2;
        if (ele == arr[mid])
            return mid;
        if (ele > arr[mid])
            begin = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int ter_search(int *arr, int size, int ele)
{
    int begin = 0, mid1, mid2;
    int end = size - 1;
    while (begin <= end)
    {
        mid1 = (end - begin) / 3 + begin;
        mid2 = 2 * (end - begin) / 3 + begin;
        if (ele == arr[mid1])
            return mid1;
        if (ele == arr[mid2])
            return mid2;
        if (ele < arr[mid1])
            end = mid1 - 1;
        else if (ele > arr[mid2])
            begin = mid2 + 1;
        else
        {
            begin = mid1 + 1;
            end = mid2 - 1;
        }
    }
    return -1;
}

int cmpfun(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int n, k, i;
    scanf("%d %d", &n, &k);
    int *arr = (int *) malloc(n * sizeof(int));
    srand(time(NULL));
    for (i = 0; i < n; ++i)
        arr[i] = rand() / (RAND_MAX / (DIV * n));
    qsort(arr, n, sizeof(int), cmpfun);
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    clock_t begin = clock();
    int bin = bin_search(arr, n, k);
    clock_t mid = clock();
    int ter = ter_search(arr, n, k);
    clock_t end = clock();
    double bin_time = (double)(mid - begin) * 1000.0;
    double ter_time = (double)(end - mid) * 1000.0;
    printf("\nbinary search returned %d, time: %f\n", bin, bin_time);
    printf("ternary search returned %d, time: %f", ter, ter_time);
}
