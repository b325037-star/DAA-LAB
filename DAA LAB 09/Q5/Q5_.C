
#include <stdio.h>

int main() {
    int n, r[100], c[100], sum = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &r[i]);
        c[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (r[i] > r[i - 1])
            c[i] = c[i - 1] + 1;
    }

    for (int i = n - 2; i >= 0; i--) {
        if (r[i] > r[i + 1] && c[i] <= c[i + 1])
            c[i] = c[i + 1] + 1;
    }

    for (int i = 0; i < n; i++)
        sum += c[i];

    printf("Minimum candies = %d\n", sum);
    return 0;
}