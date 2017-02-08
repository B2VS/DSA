#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, m, prod = 1;
    scanf("%d %d %d", &a, &b, &m);
    while(b--)
    {
        prod = (prod * a) % m;
    }
    printf("%d", prod);
}
