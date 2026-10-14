#include <stdio.h>
#include <string.h>

int main() {
    char s[100], ans[100];
    int f[256] = {0}, next[256] = {0};
    int k, n;

    scanf("%99s", s);
    scanf("%d", &k);

    if (k < 0) return 1;

    n = strlen(s);

    for (int i = 0; i < n; i++)
        f[(unsigned char)s[i]]++;

    for (int pos = 0; pos < n; pos++) {
        int best = -1;

        for (int j = 0; j < 256; j++) {
            if (f[j] > 0 && next[j] <= pos) {
                if (best == -1 || f[j] > f[best])
                    best = j;
            }
        }

        if (best == -1) {
            printf("Not possible\n");
            return 0;
        }

        ans[pos] = best;
        f[best]--;
        next[best] = pos + k;
    }

    ans[n] = '\0';
    printf("Result = %s\n", ans);

    return 0;
}
