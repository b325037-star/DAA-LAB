
#include <stdio.h>

#define MAX 10000

int parent[MAX], size[MAX], land[MAX];

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

int unite(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return 0;

    if (size[a] < size[b])
    {
        int t = a;
        a = b;
        b = t;
    }

    parent[b] = a;
    size[a] += size[b];
    return 1;
}

int main()
{
    int R, C, k, r, c, i, j;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    int count = 0, id, nr, nc, nid;

    printf("Enter rows, columns and operations: ");
    scanf("%d%d%d", &R, &C, &k);

    for (i = 0; i < R * C; i++)
    {
        parent[i] = i;
        size[i] = 1;
        land[i] = 0;
    }

    for (i = 0; i < k; i++)
    {
        printf("Enter row and column: ");
        scanf("%d%d", &r, &c);

        id = r * C + c;

        if (!land[id])
        {
            land[id] = 1;
            count++;

            for (j = 0; j < 4; j++)
            {
                nr = r + dr[j];
                nc = c + dc[j];

                if (nr >= 0 && nr < R &&
                    nc >= 0 && nc < C)
                {
                    nid = nr * C + nc;

                    if (land[nid] && unite(id, nid))
                        count--;
                }
            }
        }

        printf("%d ", count);
    }

    return 0;
}