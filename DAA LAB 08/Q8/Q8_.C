
#include <stdio.h>

#define MAX 20
#define INF 999999

int main()
{
    int n, i, j, k, r;
    double p[MAX], q[MAX];
    double cost[MAX][MAX];
    double weight[MAX][MAX];

    printf("Enter number of keys: ");
    scanf("%d", &n);

    printf("Enter p values:\n");

    for(i = 1; i <= n; i++)
        scanf("%lf", &p[i]);

    printf("Enter q values:\n");

    for(i = 0; i <= n; i++)
        scanf("%lf", &q[i]);

    for(i = 1; i <= n + 1; i++)
    {
        cost[i][i - 1] = q[i - 1];
        weight[i][i - 1] = q[i - 1];
    }

    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n - k + 1; i++)
        {
            j = i + k - 1;

            cost[i][j] = INF;

            weight[i][j] =
                weight[i][j - 1] + p[j] + q[j];

            for(r = i; r <= j; r++)
            {
                double x = cost[i][r - 1]
                         + cost[r + 1][j]
                         + weight[i][j];

                if(x < cost[i][j])
                    cost[i][j] = x;
            }
        }
    }

    printf("Minimum Cost = %.2lf", cost[1][n]);

    return 0;
}