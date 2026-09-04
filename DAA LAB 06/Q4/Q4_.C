

#include <stdio.h>
#include <limits.h>

int main()
{
    int N, i, j, k, len;

    printf("Enter N: ");
    scanf("%d", &N);

    int arr[N];

    printf("Enter dimensions: ");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    long long dp[N][N];

    /* Initialize diagonal */
    for (i = 0; i < N; i++)
    {
        dp[i][i] = 0;
    }

    /* Calculate minimum multiplication cost */
    for (len = 2; len <= N - 1; len++)
    {
        for (i = 1; i <= N - len; i++)
        {
            j = i + len - 1;

            dp[i][j] = LLONG_MAX;

            for (k = i; k < j; k++)
            {
                long long cost = dp[i][k]
                               + dp[k + 1][j]
                               + (long long)arr[i - 1]
                               * arr[k]
                               * arr[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }
printf("Minimum number of scalar multiplications = %lld\n",
           dp[1][N - 1]);

    return 0;
}