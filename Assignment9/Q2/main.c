#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100];
    gets(str);
    int len = strlen(str);
    int i, j, k, count[26];
    for (i = 26; i > 0; --i) //constant time
    {
        for (j = 0; j < len - i; ++j) //O(n)
        {
            for (k = 0; k < 26; ++k) //constant time
                count[k] = 0;
            for (k = 0; k < i; ++k) //constant time, maximum value of i is 26
            {
                if (count[str[j + k] - 'a'] == 0)
                    count[str[j + k] - 'a'] += 1;
                else break;
            }
            if (k == i)
            {
                printf("%d", i);
                return 0;
            }
        }
    }
}
