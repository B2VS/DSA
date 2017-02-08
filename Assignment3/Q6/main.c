#include <stdio.h>
#include <stdlib.h>

char board[8][8];

int span(int r, int c) //1 for collision
{
    int i, j;
    //horizontal
    for (j = c + 1; j < 8; ++j)
        if (board[r][j] == 1) return 1;
    for (j = c - 1; j >= 0; --j)
        if (board[r][j] == 1) return 1;
    //vertical
    for (i = r + 1; i < 8; ++i)
        if (board[i][c] == 1) return 1;
    for (i = r - 1; i >= 0; --i)
        if (board[i][c] == 1) return 1;
    // '/' diagonal
    for (i = r - 1, j = c + 1; i >= 0 && j < 8; --i, ++j)
        if (board[i][j] == 1) return 1;
    for (i = r + 1, j = c - 1; i < 8 && j >= 0; ++i, --j)
        if (board[i][j] == 1) return 1;
    // '\' diagonal
    for (i = r - 1, j = c - 1; i >= 0 && j >= 0; --i, --j)
        if (board[i][j] == 1) return 1;
    for (i = r + 1, j = c + 1; i < 8 && j < 8; ++i, ++j)
        if (board[i][j] == 1) return 1;
    return 0;
}

int main()
{
    int i, j;
    for (i = 0; i < 8; ++i)
        for (j = 0; j < 8; ++j)
            scanf("%d", &board[i][j]);
    for (i = 0; i < 8; ++i)
    {
        for (j = 0; j < 8; ++j)
        {
            if (board[i][j] == 1 && span(i, j) == 1)
            {
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
}
