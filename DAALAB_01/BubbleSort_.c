
#include <stdio.h>

void optimizedBubbleSort(int a[], int n) {
    int i, j, temp;
    int swapped, comparisons = 0;

    for(i = 0; i < n - 1; i++) {
        swapped = 0;

        for(j = 0; j < n - i - 1; j++) {
            comparisons++;

            if(a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }

        if(swapped == 0)
            break;
    }

    printf("\nOptimized Bubble Sort\n");
    printf("Sorted Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nComparisons = %d\n", comparisons);
}

void normalBubbleSort(int a[], int n) {
    int i, j, temp;
    int comparisons = 0;

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            comparisons++;

            if(a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("\nNormal Bubble Sort\n");
    printf("Sorted Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nComparisons = %d\n", comparisons);
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n], b[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];   // Copy array for second version
    }

    optimizedBubbleSort(a, n);
    normalBubbleSort(b, n);

    return 0;
}