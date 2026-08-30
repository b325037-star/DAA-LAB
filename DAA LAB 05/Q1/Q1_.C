
#include <stdio.h>

int main()
{
    int a[100], n, i, j;
    int count;
    int mid1, mid2;
    int x = 0, y = 0;
    float median;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (n % 2 != 0)
    {
        mid1 = n / 2;

        for (i = 0; i < n; i++)
        {
            count = 0;

            for (j = 0; j < n; j++)
            {
                if (a[j] < a[i])
                    count++;
            }

            if (count == mid1)
            {
                median = a[i];
                break;
            }
        }
    }
    else
    {
        mid1 = n / 2 - 1;
        mid2 = n / 2;

        for (i = 0; i < n; i++)
        {
            count = 0;

            for (j = 0; j < n; j++)
            {
                if (a[j] < a[i])
                    count++;
            }

            if (count == mid1)
                x = a[i];

            if (count == mid2)
                y = a[i];
        }

        median = (x + y) / 2.0;
    }

    printf("Median = %.2f\n", median);

    return 0;
}