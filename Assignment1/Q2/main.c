#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100], l[100];
    gets(s);
    gets(l);
    int i, count = 0;
    int lens, lenl;
    for (lens = 0; s[lens] != '\0'; ++lens);
    for (lenl = 0; l[lenl] != '\0'; ++lenl);
    for (i = 0; i < lenl; ++i)
    {
        int j = i;
        while(i < lenl && i - j < lens && l[i] == s[i - j])
            ++i;
        if (i - j == lens) ++count;
    }
    printf("%d", count);
}
