#include <stdio.h>
#include <stdlib.h>

int getCode(char ch)
{
    if (ch == ' ') return 0;
    if (ch <= 'c') return 2;
    if (ch <= 'f') return 3;
    if (ch <= 'i') return 4;
    if (ch <= 'l') return 5;
    if (ch <= 'o') return 6;
    if (ch <= 's') return 7;
    if (ch <= 'v') return 8;
    if (ch <= 'z') return 9;
}

void mark(char ch)
{
    switch(ch)
    {
        case 'z':
        case 's': printf("%d", getCode(ch));

        case 'c':
        case 'f':
        case 'i':
        case 'l':
        case 'o':
        case 'r':
        case 'v':
        case 'y': printf("%d", getCode(ch));

        case 'b':
        case 'e':
        case 'h':
        case 'k':
        case 'n':
        case 'q':
        case 'u':
        case 'x': printf("%d", getCode(ch));

        case 'a':
        case 'd':
        case 'g':
        case 'j':
        case 'm':
        case 'p':
        case 't':
        case 'w':
        case ' ': printf("%d", getCode(ch));
    }
}

int main()
{
    char str[100];
    int i;
    gets(str);
    mark(str[0]);
    for (i = 1; str[i] != '\0'; ++i)
    {
        if (getCode(str[i]) == getCode(str[i - 1]))
            printf(" ");
        mark(str[i]);
    }
}
