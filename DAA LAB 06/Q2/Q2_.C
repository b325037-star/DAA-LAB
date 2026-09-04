//0-1 Knapsack problem using dynamic programming

#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int n, W, i, w;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n + 1];
    int profit[n + 1];

    printf("Enter weights:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &weight[i]);

    printf("Enter profits:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &profit[i]);

    printf("Enter capacity: ");
    scanf("%d", &W);

    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                K[i][w] = 0;
            }
            else if (weight[i] <= w)
            {
                K[i][w] = max(K[i - 1][w],
                               profit[i] +
                               K[i - 1][w - weight[i]]);
            }
            else
            {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    printf("Maximum Profit = %d\n", K[n][W]);

    return 0;
}