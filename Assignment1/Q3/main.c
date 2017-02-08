#include <stdio.h>
#include <stdlib.h>

char str[100];
int count[100], len = 0;

int finder(char c)
{
    int i;
    for (i = 0; i < len; ++i)
    {
        if (str[i] == c)
            return i;
    }
    return -1;
}

int main()
{
    int i, size;
    char s[100];
    gets(s);
    for (size = 0; s[size] != '\0'; ++size);
    for (i = 0; i < size; ++i)
    {
        char ch = s[i];
        int loc = finder(ch);
        if (loc == -1)
        {
            str[len] = ch;
            count[len] = 1;
            ++len;
        }
        else
            count[loc]++;
    }
    for (i = 0; i < len; ++i)
    {
        printf("%c %d\n", str[i], count[i]);
    }
}
