#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100];
    gets(str);
    int count = 0, i;
    int len = strlen(str);
    for (i = 0; i < len; ++i)
        count += 2 * (str[i] - '(') - 1;
    if (count >= 0)
    {

    }
}
