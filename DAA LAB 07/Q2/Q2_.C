
#include <stdio.h>

int main()
{
    int E, F;
    int dp[10][101];
    int e, f, k;
    int a, b, worst;

    printf("Enter number of eggs: ");
    scanf("%d", &E);

    printf("Enter number of floors: ");
    scanf("%d", &F);

    //Dynamic programming to find minimum number of droppings in best case
    for (e = 1; e <= E; e++)
    {
        dp[e][0] = 0;
        dp[e][1] = 1;
    }

    for (f = 1; f <= F; f++)
    {
        dp[1][f] = f;
    }

    //DYnamic Programming to find minimum number of droppings in worst case
    for (e = 2; e <= E; e++)
    {
        for (f = 2; f <= F; f++)
        {
            dp[e][f] = F;

            for (k = 1; k <= f; k++)
            {
                a = dp[e - 1][k - 1];  // egg breaks
                b = dp[e][f - k];      // egg does not break

                if (a > b)
                    worst = a;
                else
                    worst = b;

                if (worst + 1 < dp[e][f])
                    dp[e][f] = worst + 1;
            }
        }
    }

    printf("Minimum droppings = %d\n", dp[E][F]);

    return 0;
}