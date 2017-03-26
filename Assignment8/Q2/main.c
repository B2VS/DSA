#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void enqueue(node **queue, int data)
{
    node *nn = (node *) malloc(sizeof(node));
    nn->next = NULL;
    nn->data = data;
    node *curr = *queue;
    if (curr == NULL)
    {
        *queue = nn;
        return;
    }
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = nn;
}

int dequeue(node **queue)
{
    if (*queue == NULL) return INT_MIN;
    node *first = *queue;
    *queue = first->next;
    int data
}

void push(node **l, int data)
{
    node *nn = (node *) malloc(sizeof(node));
    node **nl = (node **) malloc(sizeof(node *));
    node *curr = *l, *prev = NULL;
    *nl = curr;
    while (curr != NULL)
    {
        if (prev != NULL) prev->next = curr;

    }
    if (prev != NULL) prev->next = curr;
}

void pop(node **topq, node **bottomq)
{

}

void Printer(node **topq, node **bottomq)
{
    if (*topq == NULL)
    {
        printf("Both stacks are empty!!");
        return;
    }
    printf("queue1 (top to bottom): ");
    node *curr = *topq;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->below;
    }
    printf("\nqueue2 (bottom to top): ");
    curr = *bottomq;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->above;
    }
    printf("\n");
}

int main()
{
    node **topq = (node **) malloc(sizeof(node *));
    node **bottomq = (node **) malloc(sizeof(node *));
    *topq = *bottomq = NULL;
    char ch;
    int var;
    start:
    printf("Menu\n");
    printf(" a. Push an element\n");
    printf(" b. Pop an element\n");
    printf(" c. Print elements of the queues\n");
    printf(" d. Exit\n");
    printf("Enter your decision: ");
    scanf(" %c", &ch);
    switch(ch)
    {
        case 'a': printf("Enter the element: ");
                  scanf("%d", &var);
                  push(topq, bottomq, var);
                  break;
        case 'b': if (*topq == NULL)
                      printf("Stack is already empty\n");
                  else
                      pop(topq, bottomq);
                  break;
        case 'c': Printer(topq, bottomq);
                  break;
        case 'd': return 0;
    }
    printf("\n************************************\n");
    goto start;
}
