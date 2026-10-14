

#include <stdio.h>

int main()
{
    int n, i, j, a, b, total;
    int f[100];

    printf("Enter number of symbols: ");
    scanf("%d", &n);

    printf("Enter frequencies:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &f[i]);

    total = n;

    while (total > 1)
    {
        a = -1;
        b = -1;

        for (i = 0; i < total; i++)
        {
            if (f[i] != -1)
            {
                if (a == -1 || f[i] < f[a])
                {
                    b = a;
                    a = i;
                }
                else if (b == -1 || f[i] < f[b])
                    b = i;
            }
        }

        printf("Combine %d and %d\n", f[a], f[b]);

        f[a] = f[a] + f[b];
        f[b] = -1;
        total--;
    }

    printf("Huffman merging completed.\n");

    return 0;
}