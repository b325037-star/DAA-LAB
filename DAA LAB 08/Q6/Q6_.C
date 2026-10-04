#include <stdio.h>
#include <string.h>

int min(int a, int b)
{
    if(a < b)
        return a;
    else
        return b;
}

int main()
{
    char A[50], B[50];
    int i, j;

    printf("Enter first string: ");
    scanf("%s", A);

    printf("Enter second string: ");
    scanf("%s", B);

    int m = strlen(A);
    int n = strlen(B);

    int dp[m + 1][n + 1];

    for(i = 0; i <= m; i++)
        dp[i][0] = i;

    for(j = 0; j <= n; j++)
        dp[0][j] = j;

    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            else
            {
                dp[i][j] = 1 + min(
                    dp[i - 1][j],
                    min(dp[i][j - 1],
                        dp[i - 1][j - 1])
                );
            }
        }
    }

    printf("Edit Distance = %d", dp[m][n]);

    return 0;
}