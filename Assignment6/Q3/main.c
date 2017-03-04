#include <stdio.h>
#include <stdlib.h>

int gNo(void *a)
{
    int i, sum = 0;
    for (i = 0; *(*(char **)a + i) != '\0'; ++i)
        sum += (int) *(*(char **)a + i);
    return __builtin_popcount(sum);
}

void copyfunc(void *a, void *b)
{
    int i;
    for (i = 0; *(*(char **)b + i) != '\0'; ++i)
        *(*(char **)a + i) = *(*(char **)b + i);
    *(*(char **)a + i) = '\0';
}

void CountSort(void *arr, void *sorted, int n, int size, int groups, int (*gNo)(void *), void (*copyfunc)(void *, void *))
{
    int *count = (int *) malloc (groups * sizeof(int));
    int i;
    for (i = 0; i < groups; ++i)
        count[i] = 0;
    for (i = 0; i < n; ++i)
        count[gNo(arr + size * i)]++;
    for (i = 1; i < groups; ++i)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; --i)
    {
        copyfunc(sorted + size * (count[gNo(arr + size * i)] - 1), arr + size * i);
        count[gNo(arr + size * i)]--;
    }
}

int main()
{
    int i, n;
    scanf("%d", &n);
    char **name = (char **) malloc (n * sizeof(char *));
    char **sorted = (char **) malloc (n * sizeof(char *));
    for (i = 0; i < n; ++i)
    {
        name[i] = (char *) malloc (100 * sizeof(char));
        sorted[i] = (char *) malloc (100 * sizeof(char));
        if (i == 0) gets(name[i]);
        gets(name[i]);
    }
    CountSort(name, sorted, n, sizeof(char *), 20, gNo, copyfunc);
    printf("\n");
    for (i = 0; i < n; ++i)
    {
        printf("%d - ", gNo((void *)(sorted + i)));
        puts(sorted[i]);
    }
    return 0;
}
