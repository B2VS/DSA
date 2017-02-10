#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    char str[100];
    scanf("%d", &t);
    gets(str);
    while(t--)
    {
        gets(str);
        int len = strlen(str), i, j;
        for (i = len - 2; i >= 0 && str[i] >= str[i + 1]; --i);
        if (i < 0)
        {
            printf("game terminated\n");
            continue;
        }
        for (j = len - 1; str[j] <= str[i]; --j);
        int temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        ++i; j = len - 1;
        while(i < j)
        {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            ++i; --j;
        }
        puts(str);
    }
}
