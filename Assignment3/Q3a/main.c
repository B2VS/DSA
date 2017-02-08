#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, count = 1;
    scanf("%d", &n);
    int **arr = (int **) malloc(n * sizeof(int *));
    for (i = 0; i < n; ++i)
        arr[i] = (int *) malloc(n * sizeof(int));
    int direction = 0; //0 right, 1 down, 2 left, 3 up;
    int lb = 0, rb = n - 1, ub = 1, db = n - 1;
    for (i = 0, j = 0; count <= n * n; ++count)
    {
        arr[i][j] = count;
        switch(direction)
        {
            case 0: ++j;
                    if (j > rb)
                    {
                        --j; ++i;
                        direction = 1;
                        --rb;
                    }
                    break;
            case 1: ++i;
                    if (i > db)
                    {
                        --i; --j;
                        direction = 2;
                        --db;
                    }
                    break;
            case 2: --j;
                    if (j < lb)
                    {
                        ++j; --i;
                        direction = 3;
                        ++lb;
                    }
                    break;
            case 3: --i;
                    if (i < ub)
                    {
                        ++i; ++j;
                        direction = 0;
                        ++ub;
                        //count = n*n + 1;
                    }
                    break;
        }
    }
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}
