#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

typedef struct list
{
    node *head;
    int size;
} list;

void Insert(list *l, int var, int index)
{
    int i;
    l->size += 1;
    node *nn = (node *) malloc (sizeof(node));
    nn->data = var;
    if (l->size == 1)
    {
        l->head = nn;
        nn->next = nn;
        nn->prev = nn;
        return;
    }
    node *prev = l->head->prev;
    if (index == -1) l->head = nn;
    for (i = 0; i <= index; ++i)
        prev = prev->next;
    node *curr = prev->next;
    nn->next = curr;
    curr->prev = nn;
    nn->prev = prev;
    prev->next = nn;
}

void Printer(list *l)
{
    if (l->head == NULL)
        printf("ERROR: list is empty!");
    else
        printf("The list is: ");
    node *curr = l->head;
    int i;
    for (i = 0; i < l->size; ++i)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    list *l = (list *) malloc (sizeof(list));;
    l->head = NULL;
    l->size = 0;
    char ch;
    int var, loc;
    start:
    printf("Menu\n");
    printf(" a. Insert an element at the beginning\n");
    printf(" b. Insert an element at the end\n");
    printf(" c. Insert an element after an index\n");
    printf(" d. Print the elements in the list\n");
    printf(" e. Exit\n");
    printf("Enter you decision: ");
    scanf(" %c", &ch);
    switch(ch)
    {
        case 'a': printf("Enter the element to be inserted: ");
                  scanf("%d", &var);
                  Insert(l, var, -1);
                  break;
        case 'b': printf("Enter the element to be inserted: ");
                  scanf("%d", &var);
                  Insert(l, var, -2);
                  break;
        case 'c': printf("Enter the element to be inserted: ");
                  scanf("%d", &var);
                  printf("Enter after what index: ");
                  scanf("%d", &loc);
                  if (loc >= l->size || loc < 0)
                      printf("ERROR: index out of bound!\n");
                  else
                      Insert(l, var, loc);
                  break;
        case 'd': Printer(l); break;
        case 'e': return 0;
    }
    printf("\n************************************\n");
    goto start;
}
