#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *left, *right;
} node;

int find(char *str, int size, char ch)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        if (ch == str[i])
            return i;
    }
}

node *MakeTree(char *infix, char *postfix, int size)
{
    node *root = (node *) malloc(sizeof(node));
    root->left = root->right = NULL;
    int infmark = find(infix, size, postfix[size - 1]);
    root->data = postfix[size - 1];
    if (infmark > 0)
        root->left = MakeTree(infix, postfix, infmark);
    if (size - infmark - 1 > 0)
        root->right = MakeTree(infix + infmark + 1, postfix + infmark, size - infmark - 1);
    return root;
}

void Preorder(node *root)
{
    printf("%c", root->data);
    if (root->left != NULL) Preorder(root->left);
    if (root->right != NULL) Preorder(root->right);
}

int main()
{
    char infix[100], postfix[100];
    gets(infix);
    gets(postfix);
    node *root = MakeTree(infix, postfix, strlen(infix));
    Preorder(root);
}
