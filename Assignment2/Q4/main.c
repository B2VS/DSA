#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100], s[100];
    printf("Enter the string to encrypt: ");
    gets(str);
    printf("Enter the key: ");
    int key, size, i, j;
    scanf("%d", &key);
    for (size = 0; str[size] != '\0'; ++size);
    for (i = 0, j = 0; i <= size; ++i)
    {
        if (str[i] != ' ') s[j++] = str[i];
    }
    size = j - 1;
    for (i = 0; i < key; ++i)
    {
        for (j = i; j < size; j += key)
            printf("%c", s[j]);
    }

}
