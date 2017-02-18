#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}

int min(int a, int b)
{
    if (a < b) return a;
    else return b;
}

int cmp(char *a, char *b)
{
    int i, len = min(strlen(a), strlen(b));
    for (i = 0; i < len; ++i)
    {
        if (a[i] < b[i]) return -1;
        if (a[i] > b[i]) return 1;
    }
    return 0;
}

char *Longest_Prefix(char *word, char **dict, int size)
{
    if (cmp(word, dict[size - 1]) == 0) return size - 1;
    int start = 0, end = size - 2, mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        int x = cmp(word, dict[mid]);
        int y = cmp(word, dict[mid + 1]);
        if (x == 0 && y < 0)
            return dict[mid];
        if (x < 0)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return NULL;
}

int main()
{
    int n, i;
    scanf("%d", &n);
    char k[100];
    gets(k);
    char **dict = (char **) malloc(n * sizeof(char *));
    for (i = 0; i < n; ++i)
    {
        dict[i] = (char *) malloc(100 * sizeof(char));
        gets(dict[i]);
    }
    qsort(dict, n, sizeof(char *), cmpfunc);
    printf("Dictionary made\n");
    gets(k);
    puts(Longest_Prefix(k, dict, n));
}
