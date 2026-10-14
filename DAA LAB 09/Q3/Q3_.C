
#include <stdio.h>

int main() {
    int n, F, D;
    int d[100], f[100];
    int reach, stops = 0, i = 0;

    printf("Enter n, initial fuel and target: ");
    scanf("%d %d %d", &n, &F, &D);

    for (int j = 0; j < n; j++)
        scanf("%d %d", &d[j], &f[j]);

    /* Sort stations by distance */
    for (int j = 0; j < n - 1; j++) {
        for (int k = j + 1; k < n; k++) {
            if (d[j] > d[k]) {
                int t = d[j]; d[j] = d[k]; d[k] = t;
                t = f[j]; f[j] = f[k]; f[k] = t;
            }
        }
    }

    reach = F;

    while (reach < D) {
        int best = -1, maxFuel = -1;

        while (i < n && d[i] <= reach) {
            if (f[i] > maxFuel) {
                maxFuel = f[i];
                best = i;
            }
            i++;
        }

        if (best == -1) {
            printf("Destination not possible\n");
            return 0;
        }

        reach += f[best];
        f[best] = 0;
        stops++;
    }

    printf("Minimum stops = %d\n", stops);
    return 0;
}