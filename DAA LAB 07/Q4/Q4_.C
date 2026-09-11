
#include <stdio.h>

long long moves[26];

long long solve(int n)
{
    if (n == 1)
        return 1;

    if (n == 2)
        return 2;

    if (moves[n] != 0)
        return moves[n];

    moves[n] = solve(n - 1) + 2 * solve(n - 2) + 1;

    return moves[n];
}

int main()
{
    int n;

    printf("Enter number of switches: ");
    scanf("%d", &n);

    if (n < 1 || n > 25)
    {
        printf("Enter n between 1 and 25.\n");
        return 0;
    }

    printf("Minimum number of moves = %lld\n", solve(n));

    return 0;
}