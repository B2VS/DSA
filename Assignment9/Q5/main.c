#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arrow[10000] = {}, count = 0;
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int ai, wi;
        scanf("%d %d", &ai, &wi);
        arrow[ai] += 1;
        if (arrow[wi] > 0)
            arrow[wi] -= 1;
        else
            ++count;
    }
    printf("%d", count);
}
