
#include <stdio.h>

void sort(int a[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, i;
    int left[100], right[100];

    int count = 0;
    int maxCount = 0;
    int maxPoint = 0;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    printf("Enter intervals:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &left[i], &right[i]);
    }

    sort(left, n);
    sort(right, n);

    int l = 0, r = 0;

    while (l < n)
    {
       
        if (left[l] <= right[r])
        {
            count++;

            if (count > maxCount)
            {
                maxCount = count;
                maxPoint = left[l];
            }

            l++;
        }
        else
        {
            count--;
            r++;
        }
    }

    printf("\nPoint = %d", maxPoint);
    printf("\nMaximum number of intervals = %d\n", maxCount);

    return 0;
}