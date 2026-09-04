
#include <stdio.h>

int cost = 0;

// Reverse array from l to r
void reverseArray(int a[], int l, int r)
{
    cost += (r - l + 1);

    while (l < r)
    {
        int temp = a[l];
        a[l] = a[r];
        a[r] = temp;

        l++;
        r--;
    }
}

// Sort using reversal
void sortArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int pos = i;

        // Find correct element
        for (int j = i; j < n; j++)
        {
            if (a[j] == i + 1)
            {
                pos = j;
                break;
            }
        }

        // Bring it to position i using reversal
        if (pos != i)
        {
            reverseArray(a, i, pos);
        }
    }
}

// Display array
void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main()
{
    int a[100];
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter permutation: ");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sortArray(a, n);

    printf("Sorted permutation: ");
    display(a, n);

    printf("Total reversal cost = %d\n", cost);

    return 0;
}