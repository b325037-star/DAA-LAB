#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a > *(int *)b)
         - (*(int *)a < *(int *)b);
}

int main() {
    int n, s[100], e[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d %d", &s[i], &e[i]);

    qsort(s, n, sizeof(int), cmp);
    qsort(e, n, sizeof(int), cmp);

    int i = 0, j = 0, rooms = 0, maxRooms = 0;

    while (i < n) {
        if (s[i] < e[j]) {
            rooms++;
            if (rooms > maxRooms)
                maxRooms = rooms;
            i++;
        } else {
            rooms--;
            j++;
        }
    }

    printf("Minimum rooms = %d\n", maxRooms);
    return 0;
}