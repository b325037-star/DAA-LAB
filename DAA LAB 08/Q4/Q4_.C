
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
    int n, i, j, ans = 1;

    printf("Enter size: ");
    scanf("%d", &n);

    int A[n], dp[n];

    printf("Enter elements: ");

    for(i = 0; i < n; i++)
        scanf("%d", &A[i]);

    for(i = 0; i < n; i++)
        dp[i] = 1;

    for(i = 1; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(A[j] < A[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    for(i = 0; i < n; i++)
    {
        if(dp[i] > ans)
            ans = dp[i];
    }

    printf("LIS Length = %d", ans);

    return 0;
}