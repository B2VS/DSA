#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(long *a, long *b)
{
    long temp = *a;
    *a = *b;
    *b = temp;
}

int pass(long *arr, int size, int dir)
{
    int i, check = 0;
    if (dir == 0)
    {
        for (i = 0; i < size - 1; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr + i, arr + i + 1);
                check = 1;
            }
        }
        return check;
    }
    for (i = size - 1; i > 0; --i)
    {
        if (arr[i] < arr[i - 1])
        {
            swap(arr + i, arr + i - 1);
            check = 1;
        }
    }
    return check;
}


void BBS(long int *arr, int n)
{
    int check = 1, i, j;
    for (i = 0; check; ++i)
        check = pass(arr + (int)(i / 2), n - i, i % 2);
}

void Bubble(long *arr, int n)
{
    int check = 1, i;
    for (i = 0; check; ++i)
        check = pass(arr, n - i, 0);
}

void Insertion(long *arr, int n)
{
    int pos, i;
    long temp;
    for (i = 1; i < n; ++i)
    {
        temp = arr[i];
        for (pos = i; pos > 0 && arr[pos - 1] > temp; --pos)
            arr[pos] = arr[pos - 1];
        arr[pos] = temp;
    }
}

void randomize(long *arr, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        arr[i] = rand();
}

void allocate(long *arr2, long *arr, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        arr2[i] = arr[i];
}

int main()
{
    int size[4] = {10, 10000, 25000, 50000};
    int i, j;
    long *arr, *arr2;
    clock_t start, end;
    for (i = 0; i < 4; ++i)
    {
        printf("Case %d, size = %d\n", i + 1, size[i]);
        arr = (long *) malloc(size[i] * sizeof(long));
        arr2 = (long *) malloc(size[i] * sizeof(long));
        srand(time(NULL));
        randomize(arr, size[i]);
        allocate(arr2, arr, size[i]);
        if (i == 0)
        {
            printf("Original array: ");
            for (j = 0; j < size[i]; ++j)
                printf("%ld ", arr[j]);
            printf("\n");
        }
        start = clock();
        Bubble(arr, size[i]);
        end = clock();
        printf("Bubble sort done, clocks taken: %ld\n", end - start);
        if (i == 0)
        {
            printf("Bubble sort array: ");
            for (j = 0; j < size[i]; ++j)
                printf("%ld ", arr[j]);
            printf("\n");
        }
        allocate(arr, arr2, size[i]);
        start = clock();
        BBS(arr, size[i]);
        end = clock();
        printf("Bidirectional Bubble sort done, clocks taken: %ld\n", end - start);
        if (i == 0)
        {
            printf("Bidirectional Bubble sort array: ");
            for (j = 0; j < size[i]; ++j)
                printf("%ld ", arr[j]);
            printf("\n");
        }
        allocate(arr, arr2, size[i]);
        start = clock();
        Insertion(arr, size[i]);
        end = clock();
        printf("Insertion sort done, clocks taken: %ld\n", end - start);
        if (i == 0)
        {
            printf("Insertion sort array: ");
            for (j = 0; j < size[i]; ++j)
                printf("%ld ", arr[j]);
            printf("\n");
        }
        printf("\n");
        free(arr);
        free(arr2);
    }
}
