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
    int n, i;
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    int loc = 0;
    for (i = 0; i < n; ++i)
    {
        if (arr[i] % 2 == 0)
            swap(arr + i, arr + loc++);
    }
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);

}
