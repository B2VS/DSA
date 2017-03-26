#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Parent(i)
{
    return i / 2;
}

int LeftChild(i)
{
    return 2*i;
}

int RightChild(i)
{
    return 2*i + 1;
}

void MaxHeapify(int *a, int i, int size)
{
    int l = LeftChild(i);
    int r = RightChild(i);
    int max;
    if (l <= size && a[l] > a[i])
        max = l;
    else
        max = i;
    if (r <= size && a[r] > a[max])
        max = r;
    if (max != i)
    {
        swap(a + i, a + max);
        MaxHeapify(a, max, size);
    }
}

void MaxHeap(int *a, int size)
{
    int i;
    for (i = size / 2; i > 0; --i)
        MaxHeapify(a, i, size);
}

void Insert(int *a, int *size, int data)
{
    ++*size;
    a[*size] = data;
    int i = *size;
    while (i > 1)
    {
        if (a[Parent(i)] < a[i])
            swap(a + Parent(i), a + i);
        i = Parent(i);
    }
}

void DeleteMax(int *a, int *size)
{
    a[1] = a[*size];
    *size -= 1;
    if (*size == 0) return;
    MaxHeapify(a, 1, *size);
}

int main()
{
    int a[100], size = 0, var;
    char ch;
    start:
    printf("Menu\n");
    printf(" 1. Insert a number\n");
    printf(" 2. Delete maximum\n");
    printf(" 3. Find maximum\n");
    printf(" Press any other key to exit\n");
    printf("Enter your decision: ");
    scanf(" %c", &ch);
    switch(ch)
    {
        case '1': printf("Enter the data: ");
                  scanf("%d", &var);
                  Insert(a, &size, var);
                  printf("Value inserted!\n");
                  break;
        case '2': if (size == 0)
                      printf("heap is empty!\n");
                  else
                      DeleteMax(a, &size);
                  printf("Maximum deleted!\n");
                  break;
        case '3': printf("Max = %d", a[1]);
                  break;
        default:  return 0;
    }
    printf("the heap is now: ");
    for (var = 1; var <= size; ++var)
        printf("%d ", a[var]);
    printf("\n*************************************\n");
    goto start;
}
