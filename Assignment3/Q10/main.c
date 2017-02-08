#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    f = fopen("file.txt", "r");
    char *str[100]; //100 is max # of lines
    str[0] = (char *) malloc(1000 * sizeof(char));
    int i;
    for (i = 0; fgets(str[i], 1000, f) != NULL; ++i)
    {
        str[i + 1] = (char *) malloc(1000 * sizeof(char));
    }
    int lines = i;
    fclose(f);
    f = fopen("file.txt", "w");
    for (i = 1; i < lines;)
    {
        fputs(str[i], f);
        if (i % 2) --i;
        else i += 3;
    }
    if (lines % 2) fputs(str[lines - 1], f);
}
