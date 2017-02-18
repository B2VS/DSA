#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, loc = 0, count = 1, i;
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    for (i = 1; i < n; ++i)
    {
        if (arr[i] != arr[loc])
            count--;
        else
            count++;
        if (count == 0)
            count = 1, loc = i;
    }
    count = 0;
    for (i = 1; i < n; ++i)
        if (arr[i] == arr[loc])
            count++;
    if (count > n / 2)
        printf("%d\n", arr[loc]);
    else
        printf("NONE\n");
}
