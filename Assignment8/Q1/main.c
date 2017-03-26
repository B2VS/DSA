#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *front, *behind;
} node;

void enqueue(node **fstack, node **bstack, int data)
{
    node *last = *bstack;
    node *nn = (node *) malloc(sizeof(node));
    nn->data = data;
    if (last != NULL) last->behind = nn;
    else *fstack = nn;
    nn->front = last;
    nn->behind = NULL;
    *bstack = nn;
}

void dequeue(node **fstack, node **bstack)
{
    node *first = *fstack;
    *fstack = first->behind;
    free(first);
    if (*fstack != NULL) (*fstack)->front = NULL;
    else *bstack = NULL;
}

void Printer(node **fstack, node **bstack)
{
    if (*fstack == NULL)
    {
        printf("Both stacks are empty!!");
        return;
    }
    printf("stack1 (front stack): ");
    node *curr = *fstack;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->behind;
    }
    printf("\nstack2 (back stack): ");
    curr = *bstack;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->front;
    }
    printf("\n");
}

int main()
{
    node **fstack = (node **) malloc(sizeof(node *));
    node **bstack = (node **) malloc(sizeof(node *));
    *fstack = *bstack = NULL;
    char ch;
    int var;
    start:
    printf("Menu\n");
    printf(" a. Insert an element\n");
    printf(" b. Delete an element\n");
    printf(" c. Print elements of the stacks\n");
    printf(" d. Exit\n");
    printf("Enter your decision: ");
    scanf(" %c", &ch);
    switch(ch)
    {
        case 'a': printf("Enter the element: ");
                  scanf("%d", &var);
                  enqueue(fstack, bstack, var);
                  break;
        case 'b': if (*fstack == NULL)
                      printf("Queue is already empty\n");
                  else
                      dequeue(fstack, bstack);
                  break;
        case 'c': Printer(fstack, bstack);
                  break;
        case 'd': return 0;
    }
    printf("\n************************************\n");
    goto start;
}
