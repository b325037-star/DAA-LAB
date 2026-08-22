
#include <stdio.h>
#include <stdlib.h>

struct Interval
{
    int start;
    int end;
};

int compare(const void *a, const void *b)
{
    struct Interval *x = (struct Interval *)a;
    struct Interval *y = (struct Interval *)b;

    return x->start - y->start;
}

void mergeIntervals(struct Interval arr[], int n)
{
    int i;
    int index = 0;

    for (i = 1; i < n; i++)
    {
        if (arr[i].start <= arr[index].end)
        {
            if (arr[i].end > arr[index].end)
            {
                arr[index].end = arr[i].end;
            }
        }
        else
        {
            index++;
            arr[index] = arr[i];
        }
    }

    printf("\nMerged intervals are:\n");

    for (i = 0; i <= index; i++)
    {
        printf("(%d, %d) ", arr[i].start, arr[i].end);
    }
}

int main()
{
    int n, i;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    struct Interval arr[n];

    printf("Enter start and end of each interval:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(struct Interval), compare);

    printf("\nSorted intervals are:\n");

    for (i = 0; i < n; i++)
    {
        printf("(%d, %d) ", arr[i].start, arr[i].end);
    }

    mergeIntervals(arr, n);

    return 0;
}