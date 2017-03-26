#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

void InsertBeg(node **l, int var)
{
    node *curr = *l;
    node *nn = (node *) malloc (sizeof(node));
    nn->data = var;
    nn->prev = NULL;
    *l = nn;
    nn->next = curr;
    if (curr != NULL) curr->prev = nn;
}

void InsertEnd(node **l, int var)
{
    node *curr = *l;
    node *nn = (node *) malloc (sizeof(node));
    nn->data = var;
    nn->next = NULL;
    if (curr == NULL)
    {
        nn->prev = NULL;
        *l = nn;
        return;
    }
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = nn;
    nn->prev = curr;
}

void RevIterative(node **l)
{
    node *prev = *l, *curr = prev->next, *next = curr->next;
    prev->next = NULL;
    while(next != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
    }
    curr->next = prev;
    *l = curr;
}

node *RevRecursive(node **l)
{
    node *curr = *l;
    if (curr->next == NULL) return curr;
    node **nl = (node **) malloc (sizeof(node *));
    *nl = curr->next;
    curr->next = NULL;
    RevRecursive(nl)->next = curr;
    *l = *nl;
    free(nl);
    return curr;
}

void Printer(node **l)
{
    if (*l == NULL)
        printf("ERROR: list is empty!");
    else
        printf("The list is: ");
    node *curr = *l;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    node **l = (node **) malloc (sizeof(node *));
    *l = NULL;
    char ch;
    int var;
    start:
    printf("Menu\n");
    printf(" a. Insert an element at the beginning\n");
    printf(" b. Insert an element at the end\n");
    printf(" c. Reverse using Iterative method\n");
    printf(" d. Reverse using Recursive method\n");
    printf(" e. Print the elements in the list\n");
    printf(" f. Exit\n");
    printf("Enter you decision: ");
    scanf(" %c", &ch);
    switch(ch)
    {
        case 'a': printf("Enter the element to be inserted: ");
                  scanf("%d", &var);
                  InsertBeg(l, var);
                  break;
        case 'b': printf("Enter the element to be inserted: ");
                  scanf("%d", &var);
                  InsertEnd(l, var);
                  break;
        case 'c': if (*l == NULL)
                  {
                      printf("ERROR: string is empty!!!\n");
                      return 0;
                  }
                  RevIterative(l); break;
        case 'd': if (*l == NULL)
                  {
                      printf("ERROR: string is empty!!!\n");
                      return 0;
                  }
                  RevRecursive(l); break;
        case 'e': Printer(l); break;
        case 'f': return 0;
    }
    printf("\n************************************\n");
    goto start;
}
