#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter the credit card number: ");
    char arr[14];
    int sum = 0, i;
    for (i = 0; i < 14; ++i)
        scanf("%c", &arr[i]);
    for (i = 0; i < 13; ++i)
    {
        if (i % 2)
            sum += arr[i] - '0';
        else if (arr[i] - '0' < 5)
            sum += 2 * (arr[i] - '0');
        else
            sum += (2 * (arr[i] - '0')) % 10 + 1;
    }
    if ((sum + arr[13] - '0') % 10)
        printf("Credit card is invalid!!");
    else
        printf("Credit card is valid!!");

}
