#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n, i, j;
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    int loc = 0;
    for (i = 0; i < 10; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (arr[j] % 10 == i)
                swap(arr + j, arr + loc++);
        }
    }
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}
