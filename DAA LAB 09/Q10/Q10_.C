
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[20][200];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%199s", s[i]);

    while (n > 1) {
        int bi = 0, bj = 1, best = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int a = strlen(s[i]);
                int b = strlen(s[j]);
                int ov = 0;

                for (int k = 1; k <= a && k <= b; k++) {
                    if (strncmp(s[i] + a - k, s[j], k) == 0)
                        ov = k;
                }

                if (ov > best) {
                    best = ov;
                    bi = i;
                    bj = j;
                }
            }
        }

        strcat(s[bi], s[bj] + best);

        for (int i = bj; i < n - 1; i++)
            strcpy(s[i], s[i + 1]);

        n--;
    }

    printf("Superstring = %s\n", s[0]);
    return 0;
}