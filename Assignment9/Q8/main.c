#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *left, *right;
} node;

int Operator(char ch)
{
    if (ch == '+') return 1;
    if (ch == '-') return 1;
    if (ch == '*') return 2;
    if (ch == '/') return 2;
    return 0;

}

node *MakeTree(char *infix, int size)
{
    node *root = (node *) malloc(sizeof(node));
    root->left = root->right = NULL;
    if (size == 1)
    {
        root->data = infix[0];
        return root;
    }
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
    root->data = infix[pos];
    if (infix[0] == '(')
    {
        root->left = MakeTree(infix + 1, pos - 1);
        root->right = MakeTree(infix + pos + 1, size - pos - 2);
    }
    else
    {
        root->left = MakeTree(infix, pos);
        root->right = MakeTree(infix + pos + 1, size - pos - 1);
    }
    return root;
}

void Postorder(node *root)
{
    if (root->left != NULL) Postorder(root->left);
    if (root->right != NULL) Postorder(root->right);
    printf("%c", root->data);
}

void Preorder(node *root)
{
    printf("%c", root->data);
    if (root->left != NULL) Preorder(root->left);
    if (root->right != NULL) Preorder(root->right);
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
    scanf(" %c", &ch);
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
    printf("\n******************************\n");
    goto start;
}
