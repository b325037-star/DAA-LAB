
#include <stdio.h>

int main()
{
    int n, m, i, j, temp;
    int x;

    printf("Enter size of Set A: ");
    scanf("%d", &n);

    printf("Enter size of Set B: ");
    scanf("%d", &m);

    int A[n], B[m];

    printf("Enter elements of Set A:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Enter elements of Set B:\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &B[i]);
    }

    printf("Enter target x: ");
    scanf("%d", &x);

    
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (A[i] > A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }

    
    for (i = 0; i < m - 1; i++)
    {
        for (j = i + 1; j < m; j++)
        {
            if (B[i] > B[j])
            {
                temp = B[i];
                B[i] = B[j];
                B[j] = temp;
            }
        }
    }


    i = 0;
    j = m - 1;

    while (i < n && j >= 0)
    {
        int sum = A[i] + B[j];

        if (sum == x)
        {
            printf("YES\n");
            printf("Pair = (%d, %d)\n", A[i], B[j]);
            return 0;
        }
        else if (sum < x)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    printf("NO\n");

    return 0;
}