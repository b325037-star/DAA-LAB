#include <stdio.h>

int main() {
    int n, a[100], total = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    while (n > 1) {
        int x = 0, y = 1;

        if (a[x] > a[y]) {
            int t = a[x]; a[x] = a[y]; a[y] = t;
        }

        for (int i = 2; i < n; i++) {
            if (a[i] < a[x]) {
                y = x;
                x = i;
            } else if (a[i] < a[y]) {
                y = i;
            }
        }

        int sum = a[x] + a[y];
        total += sum;

        if (x > y) {
            int t = x; x = y; y = t;
        }

        a[x] = sum;
        a[y] = a[n - 1];
        n--;
    }

    printf("Minimum cost = %d\n", total);
    return 0;
}