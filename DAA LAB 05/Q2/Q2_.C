
#include <stdio.h>

int main()
{
    int a[100], n, k;
    int i, j, count;
    int result = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter K: ");
    scanf("%d", &k);

    if (k < 1 || k > n)
    {
        printf("Invalid value of K\n");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        count = 0;

        for (j = 0; j < n; j++)
        {
            if (a[j] < a[i])
                count++;
        }

        if (count == k - 1)
        {
            result = a[i];
            break;
        }
    }

    printf("%d-th smallest element = %d\n", k, result);

    return 0;
}