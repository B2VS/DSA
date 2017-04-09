#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100];
    gets(str);
    int i = 0, j = 0;
    int counter[256] = {};
    for (i = 0; i < strlen(str); ++i)
    {
        if (counter[str[i]] > 0)
            continue;
        counter[str[i]] = 1;
        str[j++] = str[i];
    }
    str[j] = '\0';
    puts(str);
}
