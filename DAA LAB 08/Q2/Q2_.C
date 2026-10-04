
#include <stdio.h>

int main()
{
    int n, V, i, j;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    int coin[n];

    printf("Enter coins: ");
    for(i = 0; i < n; i++)
        scanf("%d", &coin[i]);

    printf("Enter amount: ");
    scanf("%d", &V);

    int dp[V + 1];

    for(i = 0; i <= V; i++)
        dp[i] = 0;

    dp[0] = 1;

    for(i = 0; i < n; i++)
    {
        for(j = coin[i]; j <= V; j++)
        {
            dp[j] = dp[j] + dp[j - coin[i]];
        }
    }

    printf("Number of ways = %d", dp[V]);

    return 0;
}