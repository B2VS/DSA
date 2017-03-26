#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void push(node **l, int data)
{
    node *nn = (node *) malloc(sizeof(node));
    nn->data = data;
    nn->next = *l;
    *l = nn;
}

void pop(node **l)
{
    node *top = *l;
    *l = top->next;
    free(top);
}

int empty(node **l)
{
    if (*l == NULL) return 1;
    else return 0;
}

int top(node **s)
{
    return (*s)->data;
}

int getMaxArea(int hist[], int n)
{
    // Create an empty stack. The stack holds indexes of hist[] array
    // The bars stored in stack are always in increasing order of their
    // heights.
    node **s = (node **) malloc(sizeof(node *));
    *s = NULL;

    int max_area = 0; // Initalize max area
    int tp;  // To store top of stack
    int area_with_top; // To store area with top bar as the smallest bar

    // Run through all bars of given histogram
    int i = 0;
    while (i < n)
    {
        // If this bar is higher than the bar on top stack, push it to stack
        if (empty(s) || hist[top(s)] <= hist[i])
            push(s, i++);

        // If this bar is lower than top of stack, then calculate area of rectangle
        // with stack top as the smallest (or minimum height) bar. 'i' is
        // 'right index' for the top and element before top in stack is 'left index'
        else
        {
            tp = top(s);  // store the top index
            pop(s);  // pop the top

            // Calculate the area with hist[tp] stack as smallest bar
            area_with_top = hist[tp] * (empty(s) ? i : i - top(s) - 1);

            // update max area, if needed
            if (max_area < area_with_top)
                max_area = area_with_top;
            printf("hist[tp] = %d, %d\n", hist[tp], area_with_top);
        }
    }

    // Now pop the remaining bars from stack and calculate area with every
    // popped bar as the smallest bar
    while (empty(s) == 0)
    {
        tp = top(s);
        pop(s);
        area_with_top = hist[tp] * (empty(s) ? i : i - top(s) - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
        printf("%d\n", area_with_top);
    }

    return max_area;
}

int main()
{
    int hist[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(hist)/sizeof(hist[0]);
    printf("%d", getMaxArea(hist, n));
    return 0;
}
