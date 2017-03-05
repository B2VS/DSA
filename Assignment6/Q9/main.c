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

node **mergeSortedList(node **list1, node**list2)
{
    node *curr[2] = {*list1, *list2}, *prev = NULL;
    int loc = 2;
    if (curr[0]->data < curr[1]->data) loc = 1;
    while(curr[0] != NULL && curr[1] != NULL)
    {
        int index = 1;
        if (curr[0]->data < curr[1]->data) index = 0;
        if (prev != NULL) prev->next = curr[index];
        prev = curr[index];
        curr[index] = curr[index]->next;
        prev->next = curr[1-index];
        prev = curr[1-index];
        curr[1-index] = curr[1-index]->next;
    }
    if (curr[0] != NULL)
        prev->next = curr[0];
    else
        prev->next = curr[1];
    if (loc == 1) return list1;
    else return list2;
}

int main()
{
    node *head1 = NULL, *head2 = NULL, *head = NULL;
    node **list1 = &head1, **list2 = &head2, **list = &head;
    input(list1);
    input(list2);
    list = mergeSortedList(list1, list2);
    print(list);
}
