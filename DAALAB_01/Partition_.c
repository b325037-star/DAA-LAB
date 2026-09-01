
#include <stdio.h>

int findPartition(int a[], int n) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int main() {
    int n, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements (0's followed by 1's):\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int partition = findPartition(a, n);

    if (partition == n)
        printf(" There is No 1 found in the array.\n");
    else
        printf("Partition point is at index %d\n", partition);

    return 0;
}