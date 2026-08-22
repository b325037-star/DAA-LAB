
#include <stdio.h>

int findSum(int a[], int n, int k, int target, int start)
{
    int i;
    
    if (k == 0)
{
    if (target == 0)
        return 1;
    else
        return 0;
}
    if (k == 1)
    {
        for (i = start; i < n; i++)
        {
            if (a[i] == target)
                return 1;
        }

        return 0;
    }

    
    for (i = start; i < n; i++)
    {
        if (findSum(a, n, k - 1, target - a[i], i + 1))
            return 1;
    }

    return 0;
}

int main()
{
    int a[100];
    int n, k, T;
    int i;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Enter target T: ");
    scanf("%d", &T);

    if (findSum(a, n, k, T, 0))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}