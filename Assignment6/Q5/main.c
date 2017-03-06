#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpstr(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}

int cmpalpha(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}

int main()
{
    int n, i, j;
    char **str = (char **) malloc (100 * sizeof(char *));
    char **sorted = (char **) malloc (100 * sizeof(char *));
    for (i = 0; ; ++i)
    {
        str[i] = (char *) malloc (sizeof(char));
        sorted[i] = (char *) malloc (sizeof(char));
        if (gets(str[i]) == NULL) break;
        for (j = 0; isalpha(str[i][j]); ++j);
        str[i][j] = '\0';
    }
    n = i;
    qsort(str, n, sizeof(char *), cmpstr);
    for (i = 0; i < n; ++i)
    {
        for (j = 0; isalpha(str[i][j]); ++j)
            sorted[i][j] = str[i][j];
        sorted[i][j] = '\0';
    }
    for (i = 0; i < n; ++i)
        qsort(sorted[i], strlen(sorted[i]), sizeof(char), cmpalpha);
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < strlen(str[i]); ++j)
            printf("%c", sorted[i][j]);
        printf(" ");
        for (j = 0; j < strlen(str[i]); ++j)
            printf("%c", str[i][j]);
        printf("\n");
    }
}
