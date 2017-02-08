#include <stdio.h>
#include <stdlib.h>

int max1darray(int *arr, int n, int size)
{
    int temp = 0, i, max;
    for (i = 0; i < size; ++i)
        temp += arr[i];
    max = temp;
    for (i = 1; i <= n - size; ++i)
    {
        temp += arr[i + size - 1] - arr[i - 1];
        if (max < temp)
            max = temp;
    }
    printf("n = %d, size = %d, max = %d\n", n, size, max);
    return max;
}

int main()
{
    int n, arr[100][100], line[100];
    int i, j, matrix_max, line_max, k;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            scanf("%d", &arr[i][j]);
    matrix_max = arr[0][0];
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j) line[j] = 0;
        for (j = i; j < n; ++j)
        {
            for (k = 0; k < n; ++k)
                line[k] += arr[k][j];
            line_max = max1darray(line, n, j - i + 1);
            if (line_max > matrix_max)
                matrix_max = line_max;
        }
    }
    printf("%d", matrix_max);
}
