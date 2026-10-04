
#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    if(a > b)
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
    {
        for(j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;

            else if(A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else
                dp[i][j] = max(dp[i - 1][j],
               dp[i][j - 1]);
        }
    }

    printf("LCS Length = %d\n", dp[m][n]);

    printf("LCS = ");

    i = m;
    j = n;

    char lcs[50];
    int k = dp[m][n];

    lcs[k] = '\0';

    while(i > 0 && j > 0)
    {
        if(A[i - 1] == B[j - 1])
        {
            lcs[k - 1] = A[i - 1];
            k--;
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    printf("%s", lcs);

    return 0;
}