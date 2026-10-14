#include <stdio.h>

int main() {
    int n, a[100], max, min, best;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);

        if (a[i] % 2 != 0)
            a[i] *= 2;
    }

    best = 1000000000;

    while (1) {
        max = min = a[0];

        for (int i = 1; i < n; i++) {
            if (a[i] > max) max = a[i];
            if (a[i] < min) min = a[i];
        }

        if (max - min < best)
            best = max - min;

        if (max % 2 != 0)
            break;

        for (int i = 0; i < n; i++) {
            if (a[i] == max) {
                a[i] = max / 2;
                break;
            }
        }
    }

    printf("Minimum deviation = %d\n", best);
    return 0;
}