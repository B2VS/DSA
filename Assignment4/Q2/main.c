#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int *a = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmpfunc);
    int max = 1, temp = a[0], count = 1, winner = a[0];
    for (i = 1; i < n; ++i)
    {
        if (temp == a[i])
            ++count;
        else
        {
            if (max < count)
            {
                winner = a[i - 1];
                max = count;
            }
            count = 1;
            temp = a[i];
        }
    }
    if (max < count)
        winner = a[i - 1];
    printf("%d", winner);
    return 0;
}
