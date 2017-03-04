#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    int *arr = (int *) malloc (n * sizeof(int));
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    int loc = -1, lcount = 0, rcount = 0, max = 0, maxl, uno = 0;
    if (arr[0] == 0) loc = 0, uno = 1;
    else rcount = 1;
    for (i = 1; i < n; ++i)
    {
        if (arr[i] == 1) ++rcount;
        else
        {
            if (lcount + rcount + uno > max)
            {
                max = lcount + rcount + uno;
                maxl = loc;
            }
            if (arr[i - 1] == 0)
                uno = lcount = rcount = 0;
            else
            {
                lcount = rcount;
                rcount = 0;
                uno = 1;
                loc = i;
            }
        }
    }
    if (lcount + rcount + uno > max)
    {
        max = lcount + rcount + uno;
        maxl = loc;
    }
    printf("%d %d\n", max, maxl);
}
