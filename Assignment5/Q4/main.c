#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//all the crap in this function is because of printing the pairs... otherwise it's just merge sort
int MergeSort_count(int *arr, int low, int high, int *index)
{
    if (high - low <= 0) return 0;
    if (high - low == 1)
    {
        if (arr[low] > arr[high])
        {
            printf("(%d, %d)\n", index[low], index[high]);
            swap(arr + low, arr + high);
            swap(index + low, index + high);
            return 1;
        }
        return 0;
    }
    int countL, countR, count = 0, half = (high - low + 1) / 2;
    countL = MergeSort_count(arr, low, low + half - 1, index);
    countR = MergeSort_count(arr, low + half, high, index);
    int c1, c2, i, j;
    int *b = (int *) malloc((high - low + 1) * sizeof(int));
    for (i = low; i <= high; ++i)
        b[i - low] = arr[i];
    int *ind = (int *) malloc((high - low + 1) * sizeof(int));
    for (i = low; i <= high; ++i)
        ind[i - low] = index[i];
    for (c1 = 0, c2 = half, i = low; c1 < half && c2 <= high - low; ++i)
    {
        if (b[c1] < b[c2])
        {
            index[i] = ind[c1];
            arr[i] = b[c1++];
        }
        else
        {
            index[i] = ind[c2];
            arr[i] = b[c2++];
            count += half - c1;
            for (j = c1; j < half; ++j)
                printf("(%d, %d)\n", ind[j], ind[c2 - 1]);
        }
    }
    while (c1 < half)
    {
        index[i] = ind[c1];
        arr[i++] = b[c1++];
    }
    while (c2 <= high - low)
    {
        index[i] = ind[c2];
        arr[i++] = b[c2++];
    }
    free(b);
    free(ind);
    return countL + countR + count;
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    int *index = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    for (i = 0; i < n; ++i)
        index[i] = i;
    printf("%d\n", MergeSort_count(arr, 0, n - 1, index));
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}
