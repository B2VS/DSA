#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    char itemName[20];
    int itemCode;
    float price;
    int QtyInStock;
    int IsHighDemand;
    int SoldToday;
} item;
item *p[100];

void updater(int i)
{
    printf("Enter the name: ");
    gets(p[i]->itemName);
    gets(p[i]->itemName);
    printf("Enter the item code: ");
    scanf("%d", &p[i]->itemCode);
    printf("Enter the price: ");
    scanf("%f", &p[i]->price);
    printf("Enter the quantity in stock: ");
    scanf("%d", &p[i]->QtyInStock);
    printf("Is the demand high? : ");
    scanf("%d", &p[i]->IsHighDemand);
    printf("Enter the quantity sold today: ");
    scanf("%d", &p[i]->SoldToday);
}

int main()
{
    int count = 0;
    start:
    printf("***********************Menu********************\n");
    printf(" 1. Add a new item\n");
    printf(" 2. Update the price of an item\n");
    printf(" 3. Update the stock\n");
    printf(" 4. Show the price list\n");
    printf(" 5. Sell an item\n");
    printf(" 6. Exit\n");
    printf("Select an option: ");
    char choice;
    scanf(" %c", &choice);
    if (choice == '1')
    {
        p[count] = (item *) malloc(sizeof(item));
        updater(count);
        ++count;
    }
    if (choice == '2')
    {
        printf("Enter the item index: ");
        int var;
        scanf("%d", &var);
        printf("The current price of %s is %f\n", p[var]->itemName, p[var]->price);
        printf("Enter new price: ");
        scanf("%f", &p[var]->price);
    }
    if (choice == '3')
    {
        printf("Enter the item index: ");
        int var;
        scanf("%d", &var);
        updater(var);
    }
    if (choice == '4')
    {
        int i;
        for (i = 0; i < count; ++i)
        {
            printf("%s - %f\n", p[i]->itemName, p[i]->price);
        }
    }
    if (choice == '5')
    {
        printf("Enter the item index which you want to sell: ");
        int var, i;
        scanf("%d", &var);
        for (i = var + 1; i < count; ++i)
            p[i - 1] = p[i];
        free(p[count]);
        count--;
    }
    goto start;
}
