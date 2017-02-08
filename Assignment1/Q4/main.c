#include <stdio.h>
#include <stdlib.h>

char str[100];

void reverse(int start, int end)
{
    int j;
    char temp[100];
    for (j = start; j <= end; ++j)
        temp[j] = str[j];
    for (j = start; j <= end; ++j)
        str[j] = temp[end + start - j];
}

int main()
{
    gets(str);
    int i, start = 0;
    for (i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == ' ')
        {
            reverse(start, i - 1);
            start = i + 1;
        }
    }
    reverse(start, i - 1);
    for (i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] != ' ')
            str[i] = (str[i] - 'a' + 3) % 26 + 'a';
    }
    puts(str);
}
