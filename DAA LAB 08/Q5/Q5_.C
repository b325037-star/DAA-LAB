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
    int n, i, j, ans;

    printf("Enter size: ");
    scanf("%d", &n);

    int A[n], dp[n];

    printf("Enter elements: ");

    for(i = 0; i < n; i++)
        scanf("%d", &A[i]);

    for(i = 0; i < n; i++)
        dp[i] = A[i];

    for(i = 1; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(A[j] < A[i])
                dp[i] = max(dp[i], dp[j] + A[i]);
        }
    }

    ans = dp[0];

    for(i = 1; i < n; i++)
    {
        if(dp[i] > ans)
            ans = dp[i];
    }

    printf("Maximum Sum = %d", ans);

    return 0;
}