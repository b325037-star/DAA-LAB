#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    long long w[50], dp[50][50], sum[50][50];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%lld", &w[i]);

    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
        sum[i][i] = w[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            int j = i + len - 1;

            sum[i][j] = sum[i][j - 1] + w[j];
            dp[i][j] = LLONG_MAX;

            for (int k = i; k < j; k++) {
                long long cost = dp[i][k]
                               + dp[k + 1][j]
                               + sum[i][j];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    printf("Minimum cost = %lld\n", dp[0][n - 1]);
    return 0;
}