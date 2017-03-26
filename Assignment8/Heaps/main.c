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
        MaxHeap(a, max, size);
    }
}

void MaxHeap(int *a, int size)
{
    int i;
    for (i = size / 2; i >= 0; --i)
        MaxHeapify(a, i, size);
}

void Insert(int *a, int *size, int data)
{
    a[*size] = data;
    int i = *size;
    while (i > 0)
    {
        if (a[Parent(i)] == a[i])
            swap(a + Parent(i), a + i);
        i = Parent(i);
    }
    ++*size;
}

void DeleteMax(int *a, int *size)
{
    a[1] = a[--*size];
    MaxHeapify(a, 1, *size);
}

int main()
{

}
