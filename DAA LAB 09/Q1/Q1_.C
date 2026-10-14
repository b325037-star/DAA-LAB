

#include <stdio.h>

int main()
{
    int n, i, j, best;
    float v[100], w[100], lambda[100];
    float density[100], fraction[100];
    float W, remaining, time = 0, total = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter knapsack capacity: ");
    scanf("%f", &W);

    for (i = 0; i < n; i++)
    {
        printf("Enter value, weight and decay rate of item %d: ", i + 1);
        scanf("%f %f %f", &v[i], &w[i], &lambda[i]);

        density[i] = v[i] / w[i];
        fraction[i] = 0;
    }

    remaining = W;

    for (i = 0; i < n && remaining > 0; i++)
    {
        best = -1;

        for (j = 0; j < n; j++)
        {
            if (fraction[j] == 0)
            {
                float current = density[j] - lambda[j] * time;

                if (current > 0 &&
                    (best == -1 ||
                     current > density[best] - lambda[best] * time))
                {
                    best = j;
                }
            }
        }

        if (best == -1)
            break;

        if (w[best] <= remaining)
        {
            fraction[best] = 1;

            total += w[best] *
                     (density[best] - lambda[best] * time);

            remaining -= w[best];
        }
        else
        {
            fraction[best] = remaining / w[best];

            total += remaining *
                     (density[best] - lambda[best] * time);

            remaining = 0;
        }

        printf("Item %d: Fraction taken = %.2f\n",
               best + 1, fraction[best]);

        time++;
    }

    printf("\nTotal effective value = %.2f\n", total);
    printf("Unused capacity = %.2f\n", remaining);

    return 0;
}