#include <stdio.h>
#include <stdlib.h>

int counter(char *str, int size, int loc, int len)
{
    int count = 0, i, j;
    for (i = 0; i <= size - len; ++i)
    {
        for (j = 0; j < len; ++j)
        {
            if (str[loc + j] != str[i + j])
                break;
        }
        if (j == len) count++;
    }
    return count;
}

int main()
{
    char str[100];
    gets(str);
    int len, i, j, size = strlen(str), count;
    for (len = size - 1; len > 0; --len)
    {
        for (i = 0; i <= size - len; ++i)
        {
            count = counter(str, size, i, len);
            if (count > 1) goto done;
        }
    }
    done:
    if (len == 0) printf("No substring found");
    for (j = 0; j < len; ++j)
        printf("%c", str[j + i]);
}
