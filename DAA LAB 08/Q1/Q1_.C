
#include <stdio.h>

int min(int a, int b)
{
    if(a < b)
        return a;
    else
        return b;
}

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

    dp[0] = 0;

    for(i = 1; i <= V; i++)
        dp[i] = 9999;

    for(i = 1; i <= V; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(coin[j] <= i)
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
        }
    }

    if(dp[V] == 9999)
        printf("Not possible");
    else
        printf("Minimum coins = %d", dp[V]);

    return 0;
}