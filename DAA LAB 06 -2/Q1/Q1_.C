
#include <stdio.h>
#include <math.h>

// (i) Finding Maximum
int findMax(int a[], int n)
{
    int max = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }

    return max;
}

// (ii) Finding First and Second Largest
void findLargestTwo(int a[], int n)
{
    int first = a[0], second = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > first)
        {
            second = first;
            first = a[i];
        }
        else if (a[i] > second && a[i] != first)
        {
            second = a[i];
        }
    }

    printf("First Largest = %d\n", first);
    printf("Second Largest = %d\n", second);
}

// (iii) Finding Mean
float findMean(int a[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    return (float)sum / n;
}

// Function for sorting
void sort(int a[], int n)
{
    int temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
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

// (iv) Finding Median
float findMedian(int a[], int n)
{
    sort(a, n);

    if (n % 2 == 1)
        return a[n / 2];
    else
        return (a[n / 2 - 1] + a[n / 2]) / 2.0;
}

// (v) Finding Standard Deviation
float findSD(int a[], int n)
{
    float mean = findMean(a, n);
    float sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += (a[i] - mean) * (a[i] - mean);
    }

    return sqrt(sum / n);
}

// (vi) Finding Mode
int findMode(int a[], int n)
{
    int mode = a[0];
    int maxCount = 0;

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
                count++;
        }

        if (count > maxCount)
        {
            maxCount = count;
            mode = a[i];
        }
    }

    return mode;
}

// (vii) Removing Duplicates
int removeDuplicates(int a[], int n)
{
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        int found = 0;

        for (int j = 0; j < k; j++)
        {
            if (a[i] == a[j])
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            a[k] = a[i];
            k++;
        }
    }

    return k;
}

// (viii) Reversing Array
void reverseArray(int a[], int n)
{
    int temp;

    for (int i = 0; i < n / 2; i++)
    {
        temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
}

// (ix) Partitioning with Pivot
void partitionArray(int a[], int n, int pivot)
{
    int i = 0, j = n - 1;
    int temp;

    while (i <= j)
    {
        while (i <= j && a[i] >= pivot)
            i++;

        while (i <= j && a[j] < pivot)
            j--;

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;

            i++;
            j--;
        }
    }
}

// Display Array
void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

// Main Function
int main()
{
    int n, a[100], b[100];
    int pivot, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // (i)
    printf("\n1. Maximum = %d\n", findMax(a, n));

    // (ii)
    printf("\n2. First and Second Largest:\n");
    findLargestTwo(a, n);

    // (iii)
    printf("\n3. Mean = %.2f\n", findMean(a, n));

    // (iv)
    printf("\n4. Median = %.2f\n", findMedian(a, n));

    // (v)
    printf("\n5. Standard Deviation = %.2f\n", findSD(a, n));

    // (vi)
    printf("\n6. Mode = %d\n", findMode(a, n));

    // (vii)
    for (int i = 0; i < n; i++)
        b[i] = a[i];

    k = removeDuplicates(b, n);

    printf("\n7. After Removing Duplicates:\n");
    display(b, k);

    // (viii)
    for (int i = 0; i < n; i++)
        b[i] = a[i];

    reverseArray(b, n);

    printf("\n8. Reversed Array:\n");
    display(b, n);

    // (ix)
    for (int i = 0; i < n; i++)
        b[i] = a[i];

    printf("\nEnter pivot: ");
    scanf("%d", &pivot);

    partitionArray(b, n, pivot);

    printf("9. Partitioned Array:\n");
    display(b, n);

    return 0;
}