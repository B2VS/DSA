#include <stdio.h>
#include <stdlib.h>

int checkpalindrome(char *str, int size)
{
    int first = 0, last = size - 1;
    for(; first < last; ++first, --last)
    {
        if (str[first] != str[last])
            return 0;
    }
    return 1;
}

void print(char *str, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        printf("%c", str[i]);
    printf(" ");
}

int findpalindrome(char *str, int size)
{
    int i = size;
    for (; i > 0; --i)
    {
        if (checkpalindrome(str, i) == 1)
        {
            print(str, i);
            return i;
        }
    }
}

int main()
{
    char str[100];
    gets(str);
    int len = strlen(str), pos = 0, count = 0;
    while(pos < len)
    {
        pos += findpalindrome(str + pos, len - pos);
        count += 1;
    }
    printf(", count = %d", count);
    //traverse twice if you want to print count first
    //...or store the substrings
}
