#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void deleter(node *n)
{
    node *x = n->next;
    n->next = x->next;
    free(x);
}

node *initialize(node **l, int n)
{
    int i;
    node *first = (node *) malloc (sizeof(node)), *prev = first, *nn;
    first->data = 1;
    for (i = 2; i <= n; ++i)
    {
        nn = (node *) malloc (sizeof(node));
        nn->data = i;
        prev->next = nn;
        prev = nn;
    }
    nn->next = first;
    *l = first;
    return nn;
}

int main()
{
    int n, k, i;
    node *curr;
    scanf("%d %d", &n, &k);
    node **l = (node **) malloc (sizeof(node *));
    curr = initialize(l, n);
    while (curr->next != curr)
    {
        for (i = 0; i < k - 1; ++i)
            curr = curr->next;
        deleter(curr);
    }
    printf("%d", curr->data);
}
