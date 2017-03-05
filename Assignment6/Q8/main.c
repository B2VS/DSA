#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

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

void DeleteAtBeg(node **list)
{
    if (*list == NULL)
    {
        printf("Underflow error!!!\n");
        return 0;
    }
    node *nn = *list;
    *list = (*list)->next;
    free(nn);
}

void DeleteAtEnd(node **list)
{
    if (*list == NULL)
    {
        printf("Underflow error!!!\n");
        return 0;
    }
    node *x = *list;
    if (x->next == NULL)
    {
        *list = NULL;
        return;
    }
    while(x->next->next != NULL)
        x = x->next;
    node *nn = x->next;
    x->next = NULL;
    free(nn);
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
    printf(" a. Insert from the beginning of the list\n");
    printf(" b. Delete from the beginning of the list\n");
    printf(" c. Delete from the end of the list\n");
    printf(" d. Exit\n");
    printf("Enter your option: ");
    scanf(" %c", &ch);
    switch (ch)
    {
        case 'a': printf("Enter the number to be inserted: ");
                  scanf("%d", &var);
                  InsertAtBeg(list, var);
                  break;
        case 'b': DeleteAtBeg(list);
                  break;
        case 'c': DeleteAtEnd(list);
                  break;
        case 'd': return 0;
        default : printf("Invalid option!!!\n");
                  break;
    }
    goto start;
}
