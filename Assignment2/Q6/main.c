#include <stdio.h>
#include <stdlib.h>

long long power(int val, int n)
{
    long long p = 1;
    while(n--)
        p *= val;
    return p;
}

long long count = 0;

int length(long long n)
{
    long long n2 = n;
    int digits = 0, i;
    while(n2 > 0)
    {
        n2 /= 10;
        ++digits;
    }
    return digits;
}

void counter(long long n, int valid)
{
    int digits = length(n);
    if (digits == 0) return;
    long long curr = 0;
    int i;
    if (valid == 0)
    {
        for (i = 1; i <= digits; ++i)
            curr += power(3, i);
        count += 4 * curr;
        return;
    }
    for (i = 1; i < digits; ++i)
        curr += power(3, i);
    long long x = power(10, digits - 1);
    printf("n/x = %d, n = %lld, x = %lld\n", (int)(n/x), n, x);
    switch ((int)(n / x))
    {
        case 1: counter(n - x, 1); break;
        case 2: counter(n - 2 * x, 0); break;
        case 3: counter(n - 3 * x, 0); break;
        case 4: counter(n - 4 * x, 0); break;
        case 5: counter(n - 5 * x, 0); break;
        case 6: counter(n - 6 * x, 0); break;
        case 7: curr *= 2;
                counter(n - 7 * x, 1);
                break;
        case 8: curr *= 2;
                counter(n - 8 * x, 0);
                break;
        case 9: curr *= 3;
                counter(n - 9 * x, 1);
                break;
    }
    count += curr;
    printf("curr = %lld\n", curr);
}

int main()
{
    long long n;
    scanf("%lld", &n);
    long long n2 = n;
    counter(n, 1);
    if (n % 10 >= 1) count += 1;
    if (n % 10 >= 7) count += 1;
    if (n % 10 >= 9) count += 1;

    printf("%lld", count);
}
