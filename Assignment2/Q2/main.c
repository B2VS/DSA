#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m[10][3], mt[10][3];
    int matrix[6][6];
    int i, j, size = 0;
    for (i = 0; i < 6; ++i)
        for (j = 0; j < 6; ++j)
            scanf("%d", &matrix[i][j]);
    for (i = 0; i < 6; ++i)
    {
        for (j = 0; j < 6; ++j)
        {
            if (matrix[i][j])
            {
                m[size][0] = i;
                m[size][1] = j;
                m[size][2] = matrix[i][j];
                ++size;
            }
        }
    }
    for (i = 0; i < size; ++i)
    {
        mt[i][0] = m[i][1];
        mt[i][1] = m[i][0];
        mt[i][2] = m[i][2];
    }
    for (i = 0; i < size - 1; ++i)
    {
        int min = mt[i][0];
        int min_supp = mt[i][1];
        int min_loc = i;
        for (j = i + 1; j < size; ++j)
        {
            if (min < mt[j][0]) continue;
            if (min == mt[j][0] && min_supp < mt[j][1])
                continue;
            min = mt[j][0];
            min_supp = mt[j][1];
            min_loc = j;
            printf("switching");
        }
        int temp = mt[i][0];
        mt[i][0] = mt[min_loc][0];
        mt[min_loc][0] = temp;
        temp = mt[i][1];
        mt[i][1] = mt[min_loc][1];
        mt[min_loc][1] = temp;
        temp = mt[i][2];
        mt[i][2] = mt[min_loc][2];
        mt[min_loc][2] = temp;
    }
    printf("\n");
    for (i = 0; i < size; ++i)
    {
        for (j = 0; j < 3; ++j)
            printf("%d ", m[i][j]);
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < size; ++i)
    {
        for (j = 0; j < 3; ++j)
            printf("%d ", mt[i][j]);
        printf("\n");
    }
}
