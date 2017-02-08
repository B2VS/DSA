#include <stdio.h>
#include <stdlib.h>

void print_digit(int n)
{
    switch(n)
    {
        case 1: printf("One "); break;
        case 2: printf("Two "); break;
        case 3: printf("Three "); break;
        case 4: printf("Four "); break;
        case 5: printf("Five "); break;
        case 6: printf("Six "); break;
        case 7: printf("Seven "); break;
        case 8: printf("Eight "); break;
        case 9: printf("Nine "); break;
    }
}

void printer(int f, int d)
{
    print_digit(f);
    if (f) printf("Hundred ");
    if (f && d) printf("and ");
    if (d / 10 == 1)
    {
        switch(d % 10)
        {
            case 0: printf("Ten "); break;
            case 1: printf("Eleven "); break;
            case 2: printf("Twelve "); break;
            case 3: printf("Thirteen "); break;
            case 4: printf("Fourteen "); break;
            case 5: printf("Fifteen "); break;
            case 6: printf("Sixteen "); break;
            case 7: printf("Seventeen "); break;
            case 8: printf("Eighteen "); break;
            case 9: printf("Nineteen "); break;
        }
    }
    else
    {
        switch(d / 10)
        {
            case 2: printf("Twenty "); break;
            case 3: printf("Thirty "); break;
            case 4: printf("Forty "); break;
            case 5: printf("Fifty "); break;
            case 6: printf("Sixty "); break;
            case 7: printf("Seventy "); break;
            case 8: printf("Eighty "); break;
            case 9: printf("Ninety "); break;
        }
        print_digit(d % 10);
    }
}

int main()
{
    long n;
    scanf("%ld", &n);
    if (n == 0) printf("Zero");
    if (n / 1000) printer(n / 100000, (n / 1000) % 100);
    if (n / 1000) printf("Thousand ");
    n = n % 1000;
    if (n) printer(n / 100, n % 100);
}
