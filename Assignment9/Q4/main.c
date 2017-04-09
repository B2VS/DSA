#include <stdio.h>
#include <stdlib.h>

int cmp(char *word, char *str)
{
    int wordlen = strlen(word);
    int strl = strlen(str);
    if (strl < wordlen) return 0;
    int i;
    for (i = 0; i < wordlen; ++i)
        if (str[i] != word[i]) return 0;
    return 1;
}

void printer(char *word)
{
    int i;
    for (i = 0; i < strlen(word); ++i)
        printf("%c", word[i]);
}

int main()
{
    char str[100];
    char **word;
    int n, *dict, p = 0, i, j, k, stind, edind;
    scanf("%d", &n);
    gets(str);
    gets(str);
    int len = strlen(str);
    int *count = (int *) malloc(sizeof(int) * n);
    word = (char **) malloc(n * sizeof(char *));
    dict = (int *) malloc(len * sizeof(int));
    for (i = 0; i < n; ++i)
    {
        word[i] = (char *) malloc(100 * sizeof(char));
        gets(word[i]);
    }
    for (i = 0; i < len; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (cmp(word[j], str + i) == 1)
            {
                dict[p++] = j;
                i += strlen(word[j]) - 1;
                break;
            }
        }
        if (j == n) dict[p++] = -1;
    }
    int maxlen = 0, start = 0;
    for (i = 0; i < p; ++i)
    {
        if (dict[i] == -1)
        {
            if (i - start > maxlen)
                maxlen = i - start;
            start = i + 1;
            continue;
        }
    }
    if (i - start > maxlen)
        maxlen = i - start;
    for (i = n; i <= maxlen; ++i)
    {
        stind = 0;
        for (j = 0; j < p - i + 1; ++j)
        {
            for (k = 0; k < n; ++k)
                count[k] = 0;
            for (k = 0; k < i; ++k)
            {
                if (dict[k + j] == -1) break;
                count[dict[k + j]] += 1;
            }
            for (k = 0; k < n; ++k)
                if (count[k] == 0) break;
            if (k == n)
            {
                maxlen = i;
                edind = stind - 1;
                for (k = 0; k < i; ++k)
                {
                    printer(word[dict[j + k]]);
                    edind += strlen(word[dict[j + k]]);
                }
                printf(", starting: %d, ending: %d\n", stind, edind);
            }
            if (dict[j] != -1)
                stind += strlen(word[dict[j]]);
            else
                stind += 1;
        }
    }
}
