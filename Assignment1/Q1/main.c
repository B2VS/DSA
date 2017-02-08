#include <stdio.h>
#include <stdlib.h>

int strlen(char *str)
{
    int i;
    for(i = 0; str[i] != '\0'; ++i);
    return i;
}

char *strcpy(char *dest, char *src)
{
    int i = 0;
    for(i = 0; str[i] != '\0'; ++i)
        dest[i] = src[i];
    return dest;
}

char *strcat(char *dest, char *src)
{
    int len = 0, i, flen;
    for(i = 0; dest[i] != '\0'; ++len, ++i);
    flen = i;
    for(i = 0; src[i] != '\0'; ++len, ++i);
    char cat[len];
    for(i = 0; dest[i] != '\0'; ++i)
        cat[i] = dest[i];
    for(i = 0; src[i] != '\0'; ++i)
        cat[flen + i] = src[i];
    return cat;
}

int strend(char *s, char *t)
{
    int lens, lent, match = 1;
    for(lens = 0; s[lens] != '\0'; ++lens);
    for(lent = 0; t[lent] != '\0'; ++lent);
    int i;
    for(i = 0; i < lent; ++i)
    {
        if(t[lent - 1 - i] != s[lens - 1 - i])
            match = 0;
    }
    return match;
}

int checkPalindrome(char *s)
{
    int len, palindrome = 1;
    for(len = 0; str[len] != '\0'; ++len);
    for(int i = 0; i < len; ++i)
    {
        if(s[i] != s[len - 1 - i])
            palindrome = 0;
    }
    return palindrome;
}

char *reverse(char *original)
{
    int len;
    for(len = 0; str[len] != '\0'; ++len);
    char rev[len];
    int i;
    for(i = 0; i < len; ++i)
        rev[len - 1 - i] = original[i];
    return rev;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
