#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} node;

int Operator(char ch)
{
    if (ch == '+') return 1;

}

node *MakeTree(char *infix, int size)
{
    int maxbrac = -100, i, brac = 0, pos, pres;
    for (i = size - 1; i >= 0; --i)
    {
        int op = Operator(infix[i]);
        if (infix[i] == '(') brac += 1;
        else if (infix[i] == ')') brac -= 1;
        else if (op > 0)
        {
            if (brac > maxbrac || (brac == maxbrac && pres == 2 && op == 1))
            {
                pos = i;
                maxbrac = brac;
                pres = op;
            }
        }
    }
    printf("%c", infix[pos]);
}

void Postorder(node *root)
{

}

void Preorder(node *root)
{

}

int main()
{
    char ch, str[100];
    node *root;
    start:
    printf("Menu\n");
    printf(" a. Create an expression tree\n");
    printf(" b. Print postfix expression\n");
    printf(" c. Print prefix expression\n");
    printf(" d. Exit\n");
    printf("Enter your decision: ");
    scanf("%c", &ch);
    switch(ch)
    {
        case 'a': gets(str); gets(str);
                  root = MakeTree(str, strlen(str));
                  break;
        case 'b': Postorder(root);
                  break;
        case 'c': Preorder(root);
                  break;
        case 'd': return 0;
    }
    printf("******************************\n");
    goto start;
}
