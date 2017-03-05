#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void print(node **list)
{
    node *x = *list;
    while (x != NULL)
        printf("%d ", x->data),
        x = x->next;
    printf("\n");
}

void InsertAtBeg(node **list, int x)
{
    node *nn = (node *) malloc (sizeof(node));
    nn->next = *list;
    nn->data = x;
    *list = nn;
}

void InsertAtEnd(node **list, int data)
{
    node *nn = (node *) malloc (sizeof(node));
    nn->data = data;
    nn->next = NULL;
    if (*list == NULL)
    {
        *list = nn;
        return;
    }
    node *x = *list;
    while (x->next != NULL)
        x = x->next;
    x->next = nn;
}

void Insert(node **list, int data, int ref)
{
    if (*list == NULL)
    {
        printf("Empty list bro\n");
        return;
    }
    node *nn = (node *) malloc (sizeof(node));
    nn->data = data;
    node *x = *list;
    if (x->data == ref)
    {
        nn->next = *list;
        *list = nn;
        return;
    }
    while (x->next != NULL && x->next->data != ref)
        x = x->next;
    if (x->next == NULL)
    {
        printf("Element not found!!\n");
        free(nn);
        return 0;
    }
    nn->next = x->next;
    x->next = nn;
}

int main()
{
    node *x = NULL;
    node **list = &x;
    char ch;
    int var, ref;
    start:
    printf("\nCurrently the array is: ");
    print(list);
    printf("Menu\n");
    printf(" a. Insert at beginning of the list\n");
    printf(" b. Insert at the end of the list\n");
    printf(" c. Insert just before a number in the list\n");
    printf(" d. Exit\n");
    printf("Enter your option: ");
    scanf(" %c", &ch);
    printf("\nEnter the number to be inserted: ");
    scanf("%d", &var);
    switch (ch)
    {
        case 'a': InsertAtBeg(list, var);
                  break;
        case 'b': InsertAtEnd(list, var);
                  break;
        case 'c': printf("\nBefore what number should this one be placed?: ");
                  scanf("%d", &ref);
                  Insert(list, var, ref);
                  break;
        case 'd': return 0;
        default : printf("Invalid option!!!");
                  break;
    }
    goto start;
}
