
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);

    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    int p;

    if (low < high)
    {
        p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main()
{
    int a[100], n, i;
    FILE *fp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    srand(time(NULL));

    fp = fopen("random.txt", "w");

    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    printf("Generated elements:\n");

    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        fprintf(fp, "%d ", a[i]);
        printf("%d ", a[i]);
    }

    fclose(fp);

    fp = fopen("random.txt", "r");

    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
        fscanf(fp, "%d", &a[i]);

    fclose(fp);

    quickSort(a, 0, n - 1);

    printf("\n\nSorted elements:\n");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}