#include <stdio.h>

int T(int n)
{
    int k, moves, minimum;
    int power;

    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    /* First value */
    k = 1;
    power = 1;

    for (int i = 1; i <= n - k; i++)
        power = power * 2;

    minimum = 2 * T(k) + power - 1;

    /* Check remaining values */
    for (k = 2; k < n; k++)
    {
        power = 1;

        for (int i = 1; i <= n - k; i++)
            power = power * 2;

        moves = 2 * T(k) + power - 1;

        if (moves < minimum)
            minimum = moves;
    }

    return minimum;
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("Minimum number of moves = %d\n", T(n));

    return 0;
}