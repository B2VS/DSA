#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void push(node **stack, char ch)
{
    node *nn = (node *) malloc(sizeof(node));
    nn->data = ch;
    nn->next = *stack;
    *stack = nn;
}

char pop(node **stack)
{
    node *nn = *stack;
    char ch = nn->data;
    *stack = nn->next;
    free(nn);
    return ch;
}

int Operator(char ch)
{
    switch(ch)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
    }
    return 0;
}

int Empty(node **stack)
{
    if (*stack == NULL) return 1;
    return 0;
}

int Top(node **stack)
{
    return (*stack)->data;
}

int main()
{
    char infix[100], postfix[100], loc = 0;
    node **stack = (node **) malloc(sizeof(node *));
    *stack = NULL;
    gets(infix);
    int len = strlen(infix), i;
    for (i = 0; i < len; ++i)
    {
        if (Operator(infix[i]))
        {
            while(Empty(stack) == 0 && Top(stack) != '(' && Operator(Top(stack)) >= Operator(infix[i]))
                postfix[loc++] = pop(stack);
            push(stack, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while(Empty(stack) == 0 && Top(stack) != '(')
                postfix[loc++] = pop(stack);
            pop(stack);
        }
        else if (isalpha(infix[i]))
            postfix[loc++] = infix[i];
        else
            push(stack, infix[i]);
    }
    while(Empty(stack) == 0)
        postfix[loc++] = pop(stack);
    postfix[loc] = '\0';
    puts(postfix);
}
