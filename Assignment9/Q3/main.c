#include <stdio.h>
#include <stdlib.h>

int main()
{
    char sudoku[11][11];
    int i, j, row, col, k, count[11] = {}, result = 1;
    for (i = 1; i < 10; ++i)
        for (j = 1; j < 10; ++j)
            scanf(" %c", &sudoku[i][j]);
    for (i = 1; i < 10; ++i)
    {
        for (j = 1; j < 10; ++j)
            count[j] = 0;
        for (j = 1; j < 10; ++j)
        {
            if (count[sudoku[i][j] - '0'] == 1)
                printf("NO at row calculation %d %d\n", i, j);
            count[sudoku[i][j] - '0'] += 1;
        }
    }
    for (i = 1; i < 10; ++i)
    {
        for (j = 1; j < 10; ++j)
            count[j] = 0;
        for (j = 1; j < 10; ++j)
        {
            if (count[sudoku[j][i] - '0'] == 1)
                printf("NO at col calculation %d\n", i);
            count[sudoku[j][i] - '0'] += 1;
        }
    }
    for (row = 0; row < 3; ++row)
    {
        for (col = 0; col < 3; ++col)
        {
            for (j = 1; j < 10; ++j)
                count[j] = 0;
            for (i = 1; i <= 3; ++i)
            {
                for (j = 1; j <= 3; ++j)
                {
                    if (count[sudoku[3*row + i][3*col + j] - '0'] == 1)
                        printf("NO at box calculation %d %d\n", row, col);
                    count[sudoku[3*row + i][3*col + j] - '0'] += 1;
                }
            }
        }
    }
    if (result) printf("YES");
    else printf("NO");
}
