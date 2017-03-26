#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void InsertBeg(node **l, int data)
{
    node *nn = (node *) malloc(sizeof(node));
    nn->next = *l;
    nn->data = data;
    *l = nn;
}

void InsertEnd(node **l, int data)
{
    node *nn = (node *) malloc(sizeof(node));
    node *curr = *l;
    nn->next = NULL;
    nn->data = data;
    if (curr == NULL)
    {
        *l = nn;
        return;
    }
    while(curr->next != NULL)
        curr = curr->next;
    curr->next = nn;
}

void Reverse(node **l)
{
    if ((*l)->next == NULL) return;
    node *curr = (*l)->next, *prev = *l, *next = curr->next;
    prev->next = NULL;
    while (next != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
    }
    curr->next = prev;
    *l = curr;
}

void Reverser(node **l)
{
    int M, L, i, size;
    node *curr = *l, *temp, *prev, *nh, **nl = &nh;
    printf("Enter the number of elements to be reversed: ");
    scanf("%d", &M);
    printf("Enter the location of the first element: ");
    scanf("%d", &L);
    for (size = 0; curr != NULL; ++size)
        curr = curr->next;
    if (size == 0)
    {
        printf("ERROR: the list is empty bro\n");
        return;
    }
    if (L + M > size || L < 0 || M < 0)
    {
        printf("ERROR: reversed array bounds are not in given array!\n");
        return;
    }
    if (M == 0)
    {
        printf("ERROR: cannot reverse an array of size zero!\n");
        return;
    }
    curr = *l;
    for (i = 0; i < L - 1; ++i)     //finding previous element
        curr = curr->next;
    prev = curr;
    if (L) curr = curr->next;
    *nl = curr;
    for (i = 0; i < M - 1; ++i)     //storing the after element
        curr = curr->next;
    temp = curr->next;
    curr->next = NULL;              //allocating last element of the list
    Reverse(nl);                    //reversing
    if (L) prev->next = *nl;        //substitute first element
    else *l = *nl;
    curr = *nl;                    //substitute last element
    while(curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
}

void Printer(node **l)
{
    node *curr = *l;
    if (curr == NULL)
        printf("The list is empty!!!");
    else
        printf("The list is: ");
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    char ch;
    int var;
    node *head = NULL;
    node **l = &head;
    start:
    printf("Menu\n");
    printf(" a. Insert an element at the beginning\n");
    printf(" b. Insert an element at the end\n");
    printf(" c. Reverse subpart of the list\n");
    printf(" d. Print the elements of the list\n");
    printf(" e. Exit\n");
    printf("Enter your decision: ");
    scanf(" %c", &ch);
    switch(ch)
    {
        case 'a': printf("Enter the data: ");
                  scanf("%d", &var);
                  InsertBeg(l, var); break;
        case 'b': printf("Enter the data: ");
                  scanf("%d", &var);
                  InsertEnd(l, var); break;
        case 'c': Reverser(l); break;
        case 'd': Printer(l); break;
        case 'e': return 0;
    }
    printf("\n************************************\n");
    goto start;
}
