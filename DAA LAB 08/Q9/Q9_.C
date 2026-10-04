
#include <stdio.h>

void collatz(long long n)
{
    printf("%lld ", n);

    while(n != 1)
    {
        if(n % 2 == 0)
            n = n / 2;
        else
            n = 3 * n + 1;

        printf("%lld ", n);
    }
}

int main()
{
    long long n;

    printf("Enter n: ");
    scanf("%lld", &n);

    printf("Collatz Sequence:\n");

    collatz(n);

    return 0;
}