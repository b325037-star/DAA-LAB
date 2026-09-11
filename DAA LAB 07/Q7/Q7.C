
#include <stdio.h>

int m[10][10], s[10][10];

void order(int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
        return;
    }

    printf("(");
    order(i, s[i][j]);
    printf(" x ");
    order(s[i][j] + 1, j);
    printf(")");
}

int main()
{
    int p[10], n, i, j, k, l, cost;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions: ");
    for (i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    for (i = 1; i <= n; i++)
        m[i][i] = 0;

    for (l = 2; l <= n; l++)
    {
        for (i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;

            m[i][j] = m[i][i] + m[i + 1][j]
                    + p[i - 1] * p[i] * p[j];

            s[i][j] = i;

            for (k = i + 1; k < j; k++)
            {
                cost = m[i][k] + m[k + 1][j]
                     + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("\nMinimum scalar multiplications = %d", m[1][n]);

    printf("\nOptimal ordering = ");
    order(1, n);

    return 0;
}