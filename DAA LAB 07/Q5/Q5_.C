
#include <stdio.h>

int main()
{
    int n, i;

    printf("Enter number of hiding spots: ");
    scanf("%d", &n);

    if (n <= 1)
    {
        printf("Invalid input");
        return 0;
    }

    printf("Shooting sequence: ");

    if (n % 2 != 0)       // n is odd
    {
        for (i = 2; i <= n - 1; i++)
            printf("%d ", i);

        for (i = 2; i <= n - 1; i++)
            printf("%d ", i);
    }
    else                  // n is even
    {
        for (i = 2; i <= n - 1; i++)
            printf("%d ", i);

        for (i = n - 1; i >= 2; i--)
            printf("%d ", i);
    }

    return 0;
}