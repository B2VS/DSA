#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void InsertBeg(node **l, int var)
{
    node *curr = *l;
    node *nn = (node *) malloc (sizeof(node));
    nn->data = var;
    *l = nn;
    nn->next = curr;
}

void InsertEnd(node **l, int var)
{
    node *curr = *l;
    node *nn = (node *) malloc (sizeof(node));
    nn->data = var;
    nn->next = NULL;
    if (curr == NULL)
    {
        *l = nn;
        return;
    }
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = nn;
}

/*node *Pali(node *curr, node *cmp, node *lim)
{
    if (curr->next == lim) return cmp;
    curr = curr->next;
    cmp = Pali(curr, cmp, lim);
    if (cmp == NULL) return NULL;
    if (curr->data != cmp->data) return NULL;
    return cmp->next;
}

int Palindrome(node **l)
{
    int size, i;
    node *curr = *l, *cmp;
    for (size = 0; curr != NULL; ++size)
        curr = curr->next;
    curr = *l;
    for (i = 0; i < size / 2; ++i)
        curr = curr->next;
    printf("size is %d\n", size);
    printf("marking at %d\n", curr->data);
    if (size % 2) cmp->next = curr;
    else cmp = curr->next;
    if (Pali(*l, cmp, curr) != NULL) return 1;
    else return 0;
}*/

int Palindrome(node **l)
{
    node **rev = (node **) malloc (sizeof(node *));
    node *curr = *l, *n, *prev = NULL;
    while(curr != NULL)
    {
        n = (node **) malloc (sizeof(node *));
        n->data = curr->data;
        n->next = prev;
        prev = n;
        curr = curr->next;
        *rev = n;
    }
    curr = *l;
    n = *rev;
    while(curr != NULL)
    {
        if (curr->data != n->data)
            return 0;
        curr = curr->next;
        n = n->next;
    }
    return 1;
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
    printf(" c. Check if palindrome\n");
    printf(" d. Print the elements in the list\n");
    printf(" e. Exit\n");
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
        case 'c': if (Palindrome(l))
                      printf("Yes, the string is a palindrome\n");
                  else
                      printf("No, the string is not a palindrome\n");
                  break;
        case 'd': Printer(l); break;
        case 'e': return 0;
    }
    printf("\n************************************\n");
    goto start;
}
