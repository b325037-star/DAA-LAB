
#include <stdio.h>

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main()
{
    int n, i, j;

    printf("Enter rod length: ");
    scanf("%d", &n);

    int price[n + 1];
    int dp[n + 1];
    int cut[n + 1];

    printf("Enter prices:\n");

    for(i = 1; i <= n; i++)
        scanf("%d", &price[i]);

    dp[0] = 0;

    for(i = 1; i <= n; i++)
    {
        dp[i] = price[i];
        cut[i] = i;

        for(j = 1; j < i; j++)
        {
            if(price[j] + dp[i - j] > dp[i])
            {
                dp[i] = price[j] + dp[i - j];
                cut[i] = j;
            }
        }
    }

    printf("Maximum Revenue = %d\n", dp[n]);

    printf("Pieces: ");

    i = n;

    while(i > 0)
    {
        printf("%d ", cut[i]);
        i = i - cut[i];
    }

    return 0;
}