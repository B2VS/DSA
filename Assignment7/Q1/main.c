#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void input(node **l)
{
    int n, i;
    node *newnode = (node *)malloc(sizeof(node));
    node *prev = newnode;
    *l = newnode;
    printf("The following input of the linked list is insert at end...\n");
    printf("How many numbers? :");
    scanf("%d", &n);
    printf("Enter the data\n");
    printf("Enter number 1: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    for (i = 1; i < n; ++i)
    {
        node *newnode = (node *)malloc(sizeof(node));
        prev->next = newnode;
        printf("Enter number %d: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        prev = newnode;
    }
    printf("\n");
}

void printer(node **l)
{
    node *n = *l;
    if (n == NULL) return;
    printf("%d", n->data);
    for (n = n->next; n != NULL; n = n->next)
        printf("->%d", n->data);
}

void evod(node **l)
{
    node *last[2] = {NULL, NULL}, *first[2] = {NULL, NULL}, *curr = *l;
    while(curr != NULL)
    {
        int index = curr->data % 2;
        if (first[index] == NULL)
            first[index] = curr;
        else
            last[index]->next = curr;
        last[index] = curr;
        curr = curr->next;
    }
    if (first[0] != NULL)
    {
        *l = first[0];
        last[0]->next = first[1];
    }
    else
        *l = first[1];
    if (first[1] != NULL)
        last[1]->next = NULL;
}

void swap(node **l)
{
    node *n1, *n2, *curr = *l, *prev = NULL;
    if (curr->next != NULL)
        *l = curr->next;
    while(curr->next != NULL)
    {
        n1 = curr;
        n2 = curr->next;
        curr = n2->next;
        n1->next = curr;
        n2->next = n1;
        if (prev != NULL)
            prev->next = n2;
        prev = n1;
        if (curr == NULL) return;
    }
}

int main()
{
    char ch;
    int i;
    node *head;
    node **linked_list = &head;
    input(linked_list);
    printf("Menu ");
    printer(linked_list);
    printf("\n");
    printf(" a. Modify such that all even numbers come before odd numbers\n");
    printf(" b. Swap elements pairwise\n");
    printf("Enter your decision: ");
    scanf(" %c", &ch);
    if (ch == 'a') evod(linked_list);
    if (ch == 'b') swap(linked_list);
    printer(linked_list);
}
