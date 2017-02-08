#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, size = 1, Ccarry, Ncarry = 0, digit;
    char str[500];
    str[0] = '1';
    str[1] = '\0';
    scanf("%d", &n);
    for (i = 2; i <= n; ++i)
    {
        for (j = 0; j < size; ++j)
        {
            Ccarry = Ncarry;
            digit = ((str[j] - '0') * i + Ccarry) % 10;
            Ncarry = ((str[j] - '0') * i + Ccarry) / 10;
            str[j] = digit + '0';
        }
        while (Ncarry)
        {
            str[size] = Ncarry % 10 + '0';
            Ncarry = Ncarry / 10;
            ++size;
        }
    }
    for (i = size - 1; i >= 0; --i)
        printf("%c", str[i]);

}
