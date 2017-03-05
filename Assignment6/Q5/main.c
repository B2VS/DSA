#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpstr(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}

int main()
{
    int n = 0, i, j;
    FILE *f;
    f = fopen("anagrams.txt", "r");
    char **str = (char **) malloc (100 * sizeof(char *));
    char **sorted = (char **) malloc (100 * sizeof(char *));
    for (n = 0; !feof(f); ++n)
    {
        str[n] = (char *) malloc (sizeof(char));
        sorted[n] = (char *) malloc (sizeof(char));
        fgets(str[n], 100, f);
        for (j = 0; isalpha(str[n][j]); ++j);
        str[n][j] = '\0';
    }
    for (i = 0; i < n; ++i)
        puts(sorted[i]);
    printf("\n");
    qsort(sorted, n, sizeof(char *), cmpstr);

    for (j = 0; isalpha(str[n][j]); ++j)
        sorted[n][j] = str[n][j];
    sorted[n][j] = '\0';

    for (i = 0; i < n; ++i)
        puts(sorted[i]);
    printf("\n");

}
