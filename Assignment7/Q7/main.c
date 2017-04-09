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

void MaxHeapify(int *a, int *b, int *c, int i, int size)
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
        swap(b + i, b + max);
        swap(c + i, c + max);
        MaxHeapify(a, b, c, max, size);
    }
}

void MaxHeap(int *a, int *b, int *c, int size)
{
    int i;
    for (i = size / 2; i > 0; --i)
        MaxHeapify(a, b, c, i, size);
}

void Insert(int *a, int *b, int *c, int *size, int data, int row, int col)
{
    ++*size;
    a[*size] = data;
    b[*size] = row;
    c[*size] = col;
    int i = *size;
    while (i > 1)
    {
        if (a[Parent(i)] < a[i])
        {
            swap(a + Parent(i), a + i);
            swap(b + Parent(i), b + i);
            swap(c + Parent(i), c + i);
        }
        i = Parent(i);
    }
}

void DeleteMax(int *a, int *b, int *c, int *size)
{
    a[1] = a[*size];
    b[1] = b[*size];
    c[1] = c[*size];
    *size -= 1;
    if (*size == 0) return;
    MaxHeapify(a, b, c, 1, *size);
}

int main()
{
    int n, m, i, j, count = 0, size;
    scanf("%d %d", &n, &m);
    int **arr;
    arr = (int **) malloc(sizeof(int *) * n);
    for (i = 0; i < n; ++i)
        arr[i] = (int *) malloc(sizeof(int) * m);
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            scanf("%d", &arr[i][j]);
    int *heap = (int *) malloc(sizeof(int) * n);
    int *row = (int *) malloc(sizeof(int) * n);
    int *col = (int *) malloc(sizeof(int) * n);
    for (i = 0; i < n; ++i)
    {
        heap[i] = arr[i][0];
        row[i] = i;
        col[i] = 0;
    }
    MaxHeap(heap - 1, row - 1, col - 1, n);
    size = n;
    while(count < n)
    {
        printf("%d %d %d\n", heap[0], row[0], col[0]);
        int tr = row[0];
        int tc = col[0];
        DeleteMax(heap - 1, row - 1, col - 1, &size);
        if (tc + 1 < m)
            Insert(heap - 1, row - 1, col - 1, &size, arr[tr][tc + 1], tr, tc + 1);
        else
            ++count;
    }
}
