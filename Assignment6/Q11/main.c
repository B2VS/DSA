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

void input(node **list)
{
    char ch;
    int var;
    start:
    printf("\nThe list currently is: ");
    print(list);
    printf("Menu\n");
    printf(" a. Insert from the beginning of the list\n");
    printf(" b. Done!\n");
    printf("Enter your option: ");
    scanf(" %c", &ch);
    switch (ch)
    {
        case 'a': printf("Enter the number to be inserted: ");
                  scanf("%d", &var);
                  InsertAtBeg(list, var);
                  break;
        case 'b': return 0;
        default : printf("Invalid option!!!\n");
                  break;
    }
    goto start;
}

node *reverse(node **list)
{
    node *curr = *list, *prev;
    if (curr->next == NULL)
        return curr;
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    curr->next = reverse(list);
    *list = curr;
    return curr;
}


int main()
{
    node *head = NULL;
    node **list = &head;
    input(list);
    printf("\nOriginal string: ");
    print(list);
    reverse(list);
    printf("Reversed string is: ");
    print(list);
}
