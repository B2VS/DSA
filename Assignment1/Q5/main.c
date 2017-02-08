#include <stdio.h>
#include <stdlib.h>

char str[100];
int size = 1;

void multiplier()
{
    int i, Ccarry = 0, Ncarry = 0, digit;
    for (i = 0; i < size; ++i)
    {
        Ccarry = Ncarry;
        digit = ((str[i] - '0') * 2) % 10;
        Ncarry = ((str[i] - '0') * 2) / 10;
        str[i] = digit + Ccarry + '0';
    }
    if (Ncarry == 1 && size < 10)
    {
        str[size] = '1';
        str[size + 1] = '\0';
        ++size;
    }
}

int main()
{
    str[0] = '1';
    str[1] = '\0';
    int n, i;
    scanf("%d", &n);
    while (n--)
    {
        multiplier();
    }

    for (i = size - 1; i >= 0; --i)
        printf("%c", str[i]);
}
