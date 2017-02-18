#include <stdio.h>
#include <stdlib.h>

typedef struct xint
{
    int val;
    int count;
    int index;
} xint;

int cmp_index(const void *a, const void *b)
{
    return ((*((xint **)a))->index) - ((*((xint **)b))->index);
}

void allocate(xint *a, xint *b)
{
    a->val = b->val;
    a->count = b->count;
    a->index = b->index;
}

void swap(xint **a, xint **b)
{
    xint *temp = *a;
    *a = *b;
    *b = temp;
}

void MergeSort_Wierd(xint **arr, int size)
{
    if (size <= 1) return;
    if (size == 2)
    {
        if (arr[0]->val > arr[1]->val)
        {
            arr[0]->count += 1;
            swap(arr, arr + 1);
        }
        return;
    }
    int c1, c2, i, half = size / 2, tcount = 0;
    MergeSort_Wierd(arr, half);
    MergeSort_Wierd(arr + half, size - half);
    xint **b = (xint **) malloc(size * sizeof(xint *));
    for (i = 0; i < size; ++i)
    {
        b[i] = (xint *) malloc(sizeof(xint));
        allocate(b[i], arr[i]);
    }
    for (c1 = 0, c2 = half, i = 0; c1 < half && c2 < size; ++i)
    {
        if (b[c1]->val <= b[c2]->val)
        {
            allocate(arr[i], b[c1++]);
            arr[i]->count += tcount;
        }
        else
        {
            allocate(arr[i], b[c2++]);
            tcount++;
        }
    }
    while (c1 < half)
    {
        allocate(arr[i], b[c1++]);
        arr[i++]->count += tcount;
    }
    while (c2 < size)
        allocate(arr[i], b[c2++]);
    for (i = 0; i < size; ++i)
        free(b[i]);
    free(b);
}

int main()
{
    int n, i;
    scanf("%d", &n);
    xint **arr = (xint **) malloc(n * sizeof(xint *));
    for (i = 0; i < n; ++i)
    {
        arr[i] = (xint *) malloc(sizeof(xint));
        scanf("%d", &arr[i]->val);
        arr[i]->count = 0;
        arr[i]->index = i;
    }
    MergeSort_Wierd(arr, n);
    qsort(arr, n, sizeof(xint *), cmp_index);
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]->count);
}
