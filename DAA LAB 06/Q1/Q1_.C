//Fibonacci series using dynamic programming

#include <stdio.h>
int main()
{
    int n, i;
    long long f[100];

    printf("Enter n: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Invalid input");
        return 0;
    }

    f[0] = 0;

    if (n >= 1)
        f[1] = 1;

    for (i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    printf("Fibonacci number at position %d = %lld\n", n, f[n]);
  return 0;
}