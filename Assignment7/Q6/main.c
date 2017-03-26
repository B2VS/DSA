#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
} stack;

void push(stack *s)
{
    s->size += 1;
}

void pop(stack *s)
{
    s->size -=1;
}


int main()
{
    char *str = (char *) malloc (100 * sizeof(char));
    gets(str);
    int i, count = 0;
    stack *s = (stack *) malloc (sizeof(stack));
    s->size = 0;
    for (i = 0; i < strlen(str); ++i)
    {
        if (str[i] == '(') push(s);
        else if (s->size == 0)
        {
            push(s);
            ++count;
        }
        else
            pop(s);
    }
    printf("%d", count + s->size / 2);
}
