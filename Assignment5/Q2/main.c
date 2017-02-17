#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(long *a, long *b)
{
    long temp = *a;
    *a = *b;
    *b = temp;
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

void Bubble(long *arr, int size)
{
    int i, sorted = 0;
    while (sorted == 0)
    {
        sorted = 1;
        for (i = 0; i < size - 1; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr + i, arr + i + 1);
                sorted = 0;
            }
        }
    }
}

void Comb(long *arr, int size)
{
    float k = 1.3;
    int gap = size / k, i;
    while (gap > 1)
    {
        for (i = 0; i + gap < size; ++i)
        {
            if (arr[i] > arr[i + gap])
                swap(arr + i, arr + i + gap);
        }
        gap /= k;
    }
    //printf("Combo done\n");
    Bubble(arr, size);
}

void Merge(long *arr, int size)
{
    if (size <= 1) return;
    if (size == 2)
    {
        if (arr[0] > arr[1])
            swap(arr, arr + 1);
        return;
    }
    int half = size / 2, c1, c2, i;
    long *b = (long *) malloc(size * sizeof(long));
    allocate(b, arr, size);
    Merge(b, half);
    Merge(b + half, size - half);
    for (i = 0, c1 = 0, c2 = half; c1 < half && c2 < size;)
    {
        if (b[c1] < b[c2])
            arr[i++] = b[c1++];
        else
            arr[i++] = b[c2++];
    }
    while (c1 < half)
        arr[i++] = b[c1++];
    while (c2 < size)
        arr[i++] = b[c2++];
    free(b);
}

void Quick(long *arr, int size)
{
    if (size <= 1) return;
    if (size == 2)
    {
        if (arr[0] > arr[1])
            swap(arr, arr + 1);
        return;
    }
    int i = -1, j;
    for (j = 0; j < size; ++j)
    {
        if (arr[j] <= arr[size - 1])
            swap(arr + ++i, arr + j);
    }

    Quick(arr, i);
    Quick(arr + i + 1, size - i - 1);
}

int main()
{
    int size[5] = {10, 10000, 50000, 100000, 500000};
    int i, k;
    clock_t start, end;
    long *arr, *m;
    for (k = 0; k < 5; ++k)
    {
        //printf("c1 %d\n", k);
        printf("Case %d, input size: %d\n", k + 1, size[k]);
        arr = (long *) malloc(size[k] * sizeof(long));
        m = (long *) malloc(size[k] * sizeof(long));
        //printf("c2 %d\n", k);
        srand(time(NULL));
        randomize(m, size[k]);
        if (k == 0)
        {
            printf("Original array: ");
            for (i = 0; i < size[k]; ++i)
                printf("%ld ", m[i]);
            printf("\n");
        }
        //printf("c3 %d\n", k);
        allocate(arr, m, size[k]);
        //printf("c4 %d\n", k);
        start = clock();
        Comb(arr, size[k]);
        end = clock();
        //printf("c5 %d\n", k);
        printf("Comb sort done, clocks taken: %ld\n", end - start);
        if (k == 0)
        {
            printf("Comb sorted array: ");
            for (i = 0; i < size[k]; ++i)
                printf("%ld ", arr[i]);
            printf("\n");
        }
        allocate(arr, m, size[k]);
        start = clock();
        Merge(arr, size[k]);
        end = clock();
        printf("Merge sort done, clocks taken: %ld\n", end - start);
        if (k == 0)
        {
            printf("Merge sorted array: ");
            for (i = 0; i < size[k]; ++i)
                printf("%ld ", arr[i]);
            printf("\n");
        }
        allocate(arr, m, size[k]);
        start = clock();
        Quick(arr, size[k]);
        end = clock();
        printf("Quick sort done, clocks taken: %ld\n", end - start);
        if (k == 0)
        {
            printf("Quick sorted array: ");
            for (i = 0; i < size[k]; ++i)
                printf("%ld ", arr[i]);
            printf("\n");
        }
        free(arr);
        free(m);
        printf("\n");
    }

}
