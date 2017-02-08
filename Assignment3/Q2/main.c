#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert(char str[], int len)
{
    int i, j = 1;
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] = str[0] + 'A' - 'a';
    for (i = 1; i < len; ++i)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] + 'A' - 'a';
        switch(str[i])
        {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            case 'H':
            case 'W':
            case 'Y': str[i] = '0'; break;
            case 'B':
            case 'F':
            case 'P':
            case 'V': str[i] = '1'; break;
            case 'C':
            case 'G':
            case 'J':
            case 'K':
            case 'Q':
            case 'S':
            case 'X':
            case 'Z': str[i] = '2'; break;
            case 'D':
            case 'T': str[i] = '3'; break;
            case 'L': str[i] = '4'; break;
            case 'M':
            case 'N': str[i] = '5'; break;
            case 'R': str[i] = '6'; break;
        }
    }
    if (len == 1)
        return (str[0] - 'A' + 1) * 1000;
    char prev = '-', str2[100];
    str2[0] = str[0];
    for (i = 1; i < len; ++i)
    {
        if (str[i] == prev) continue;
        if (str[i] != '0') str2[j++] = str[i];
        prev = str[i];
    }
    //printf("val of j: %d\n", j);
    while(j < 4) str2[j++] = '0';
    str2[j] = '\0';
    //printf("in func: ");
    //puts(str2);
    int x = str2[0] - 'A' + 1;
    //printf("x = %d\n", x);
    x = 1000 * x + 100 * (str2[1] - '0') + 10 * (str2[2] - '0') + (str2[3] - '0');
    return x;
}

int main()
{
    FILE *f;
    f = fopen("text.txt", "r");
    if (f == NULL) return 0;
    char str[1000], str2[1000], word[100];
    //printf("c1\n");
    gets(word);
    int i;
    int wn = convert(word, strlen(word));
    //printf("Word code: %d\n", wn);
    //printf("Entering loop\n");
    while(fgets(str, 1000, f) != NULL)
    {
        //puts(str);
        strcpy(str2, str);
        int start = 0;
        int len = strlen(str);
        for (i = 0; i < len; ++i)
        {
            if (!isalpha(str[i]))
            {
                int stc = convert(str + start, i - start);
                //printf("string code: %d\n", stc);
                if (wn == stc)
                {
                    puts(str2);
                    i = len;
                }
                start = i + 1;
            }
        }
    }
}
