#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Book
{
    //char name[100];
    //char author[100];
    //int edition;
    //int ISBN;
    float price;
    //char publication[100];
    int year;
} Book;

void print(Book **b, int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        printf("%d. Price: %f, Year: %d\n", i + 1, b[i]->price, b[i]->year);
    }
}

void copy(Book *b1, Book *b2)
{
    b1->price = b2->price;
    b1->year = b2->year;
}

void Ins_sort(Book **b, char ch, int n)
{
    int i, pos;
    Book *c = (Book *) malloc(sizeof(Book));
    for (i = 1; i < n; ++i)
    {
        copy(c, b[i]);
        pos = i;
        while (pos > 0)
        {
            if (ch == 'p' && b[pos - 1]->price <= c->price) break;
            if (ch == 'y' && b[pos - 1]->year <= c->year) break;
            copy(b[pos], b[pos - 1]);
            pos--;
        }
        copy(b[pos], c);
    }
}

int main()
{
    int n, i;
    scanf("%d", &n);
    Book **b = (Book **) malloc(n * sizeof(Book *));
    for (i = 0; i < n; ++i)
        b[i] = (Book *) malloc(sizeof(Book));
    FILE *f;
    f = fopen("file.txt", "w");
    srand(time(NULL));
    for (i = 0; i < n; ++i)
    {
        b[i]->price = 100 * (float)((float)rand() / RAND_MAX);
        b[i]->year = 1960 + rand() % 55;
    }
    //storing
    fprintf(f, "%d\n", n);
    for (i = 0; i < n; ++i)
    {
        fprintf(f, "%f ", b[i]->price);
        fprintf(f, "%d\n", b[i]->year);
    }
    //storing
    fclose(f);
    //////////////////////////////////////////////////////////////////////////////////////
    f = fopen("file.txt", "r");
    fscanf(f, "%d", &n);
    for (i = 0; i < n; ++i)
    {
        fscanf(f, "%f", &b[i]->price);
        fscanf(f, "%d", &b[i]->year);
    }
    printf("IN main before sorting\n");
    //print(b, n);
    Ins_sort(b, 'p', n);
    printf("\nSorted by price...\n");
    //print(b, n);
    Ins_sort(b, 'y', n);
    printf("\nSorted by year...\n");
    //print(b, n);
    fclose(f);
}
