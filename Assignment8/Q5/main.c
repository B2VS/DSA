#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void push(node **l, int data)
{
    node *nn = (node *) malloc(sizeof(node));
    nn->data = data;
    nn->next = *l;
    *l = nn;
}

void pop(node **l)
{
    node *top = *l;
    *l = top->next;
    free(top);
}

int empty(node **l)
{
    if (*l == NULL) return 1;
    else return 0;
}

int top(node **s)
{
    return (*s)->data;
}

int max(int a, int b)
{
    return a > b? a: b;
}


int findMaxLen(char *str, int n)
{

    // Create a stack and push -1 as initial index to it.
    node **stk = (node **) malloc (sizeof(node *));
    push(stk, -1);

    // Initialize result
    int result = 0;

    // Traverse all characters of given string
    for (int i=0; i<n; i++)
    {
        // If opening bracket, push index of it
        if (str[i] == '(')
          push(stk, i);

        else // If closing bracket, i.e.,str[i] = ')'
        {
            // Pop the previous opening bracket's index
            pop(stk);

            // Check if this length formed with base of
            // current valid substring is more than max
            // so far
            if (!empty(stk))
                result = max(result, i - top(stk));

            // If stack is empty. push current index as
            // base for next valid substring (if any)
            else push(stk, i);
        }
    }

    return result;
}

// Driver program
int main()
{

    char str[] = "()(()))))";
     printf("%d", findMaxLen(str, 9));

    return 0;
}
