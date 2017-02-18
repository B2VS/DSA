#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int cmpfunc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int n1, n2, i, j;
    scanf("%d", &n1);
    int *arr1 = (int *) malloc(n1 * sizeof(int));
    for (i = 0; i < n1; ++i)
        scanf("%d", &arr1[i]);
    scanf("%d", &n2);
    int *arr2 = (int *) malloc(n2 * sizeof(int));
    for (i = 0; i < n2; ++i)
        scanf("%d", &arr2[i]);
    int loc = 0;
    for (i = 0; i < n2 && loc < n1; ++i)
    {
        for (j = loc; j < n1; ++j)
        {
            if (arr1[j] == arr2[i])
                swap(arr1 + j, arr1 + loc++);
        }
    }
    if (loc < n1) qsort(arr1 + loc, n1 - loc, sizeof(int), cmpfunc);
    for (i = 0; i < n1; ++i)
        printf("%d ", arr1[i]);
}
