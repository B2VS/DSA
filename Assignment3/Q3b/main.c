#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int line, start;
    FILE *f;
    char str[1000];
    f = fopen(argv[argc - 1], "r");
    for (line = 1; fgets(str, 1000, f) != NULL; ++line)
    {
        start = 0;
        for (i = 0; i < strlen(str); ++i)
        {
            if (!isalpha(str[i]))
            {
                char ch = str[i];
                str[i] = '\0';
                if (!strcmp(argv[argc - 2], str + start))
                {
                    if (argc == 4) i = strlen(str);
                    else
                }
            }
        }
    }
    return 0;
}
