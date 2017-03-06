#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(char *str)
{
    int i;
    for (i = 0; isalpha(str[i]); ++i)
        printf("%c", &str[i]);
    printf(" ");
}

int main()
{
    int n, i, j;
    scanf("%d ", &n);
    char *str = (char *) malloc (100 * sizeof(char));
    char *prev = (char *) malloc (100 * sizeof(char));
    char *curr = (char *) malloc (100 * sizeof(char));
    gets(prev);
    gets(str);
    print(str);
    for (i = 1; ; ++i)
    {
        if (gets(curr) == NULL) break;
        if (strcmp(curr, prev)) printf("\n");
        gets(str);
        print(str);
    }
}
