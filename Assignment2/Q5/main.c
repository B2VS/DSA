#include <stdio.h>
#include <stdlib.h>

int main()
{
    long n, i;
    scanf("%ld", &n);
    int count = 0;
    for (i = 2; n > 1; ++i)
    {
        while (n % i == 0)
        {
            ++count;
            n /= i;
        }
    }
    printf("%d", count);
}
