#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    int y;
    int dir;
    struct node *next;
} node;

void push(node **stack, int x, int y, int dir)
{
    node *nn = (node *) malloc(sizeof(node));
    nn->x = x;
    nn->y = y;
    nn->dir = dir;
    nn->next = *stack;
    *stack = nn;
}

node *top(node **stack)
{
    return *stack;
}

int pop(node **stack)
{
    node *n = *stack;
    *stack = n->next;
    free(n);
    if (*stack == NULL) return -1;
    return (*stack)->dir;
}

int empty(node **stack)
{
    if (*stack == NULL) return 1;
    return 0;
}

int Dir(int x, int y, int maze[10][10], int dir, int output[10][10])
{
    if (dir == 0)
    {
        if (y == 9) return 0;
        if (output[x][y + 1] != 0) return 0;
        return maze[x][y + 1];
    }
    if (dir == 1)
    {
        if (x == 9) return 0;
        if (output[x + 1][y] != 0) return 0;
        return maze[x + 1][y];
    }
    if (dir == 2)
    {
        if (y == 0) return 0;
        if (output[x][y - 1] != 0) return 0;
        return maze[x][y - 1];
    }
    if (dir == 3)
    {
        if (x == 0) return 0;
        if (output[x - 1][y] != 0) return 0;
        return maze[x - 1][y];
    }
}

void Print(int maze[10][10])
{
    int i, j;
    for (i = 0; i < 10; ++i)
    {
        for (j = 0; j < 10; ++j)
            printf("%d ", maze[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int maze[10][10];
    int i, j;
    for (i = 0; i < 10; ++i)
        for (j = 0; j < 10; ++j)
            scanf("%d", &maze[i][j]);
    int output[10][10];
    printf("\n");
    for (i = 0; i < 10; ++i)
        for (j = 0; j < 10; ++j)
            output[i][j] = 0;
    int direction = 0; //0 right, 1 down, 2 left, 3 up;
    node **stack = (node **) malloc(sizeof(node *));
    *stack = NULL;
    int x = 0, y = 0, loop = 1, backtrack = 0;
    push(stack, 0, 0, 0);
    output[0][0] = 1;
    while(loop)
    {
        if (backtrack == 1)
        {
            x = top(stack)->x;
            y = top(stack)->y;
            output[x][y] += 1;
            direction = top(stack)->dir;
            backtrack = 0;
        }
        if (backtrack == 0 && Dir(x, y, maze, direction, output) == 0)
        {
            direction = direction + 1;
            if (direction < 4) continue;
            else
            {
                backtrack = 1;
                if (pop(stack) == -1)
                {
                    Print(output);
                    printf("no solution");
                    return 0;
                }
                continue;
            }
        }
        switch(direction)
        {
            case 0: y += 1; break;
            case 1: x += 1; break;
            case 2: y -= 1; break;
            case 3: x -= 1; break;
        }
        output[x][y] += 1;
        if (x == 9 && y == 9)
            loop = 0;
        push(stack, x, y, direction);
        direction = 0;
    }
    Print(output);
}
