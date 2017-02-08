#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100];
    int counter = 0, i;
    char ch;
    gets(str);
    for (i = 0; str[i] != '\0'; ++i)
    {
        switch (counter)
        {
            case 0: ch = 'g'; break;
            case 1: ch = 'o'; break;
            case 2: ch = 'o'; break;
            case 3: ch = 'd'; break;
            case 4: ch = 'b'; break;
            case 5: ch = 'y'; break;
            case 6: ch = 'e'; break;
            default: break;
        }
        if (str[i] == ch)
            counter++;
    }
    if (counter > 6) printf("Yes");
    else printf("No");
}
