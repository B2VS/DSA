#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    gets(str);
    strrev(str);
    int i, j, start = 0;
    for (i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == ' ')
        {
            for (j = start; j < i - j + start - 1; ++j)
            {
                int temp = str[j];
                str[j] = str[i - j + start - 1];
                str[i - j + start - 1] = temp;
            }
            start = i + 1;
        }
    }
    for (j = start; j < i - j + start - 1; ++j)
    {
        int temp = str[j];
        str[j] = str[i - j + start - 1];
        str[i - j + start - 1] = temp;
    }
    puts(str);
}
