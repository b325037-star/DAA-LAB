#include <stdio.h>

#define MAX 1000

int parent[MAX], sz[MAX];
int weight[MAX], sum[MAX];

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return;

    if (sz[a] < sz[b])
    {
        int t = a;
        a = b;
        b = t;
    }

    parent[b] = a;
    sz[a] += sz[b];
    sum[a] += sum[b];
}

int main()
{
    int n, m, K, i, u, v, r;
    int maximum;

    printf("Enter vertices, edges and K: ");
    scanf("%d%d%d", &n, &m, &K);

    for (i = 0; i < n; i++)
    {
        printf("Weight of vertex %d: ", i);
        scanf("%d", &weight[i]);

        parent[i] = i;
        sz[i] = 1;
        sum[i] = weight[i];
    }

    for (i = 0; i < m; i++)
    {
        printf("Enter edge (u v): ");
        scanf("%d%d", &u, &v);

        unite(u, v);

        maximum = -1;

        for (r = 0; r < n; r++)
        {
            if (parent[r] == r && sz[r] <= K)
            {
                if (sum[r] > maximum)
                    maximum = sum[r];
            }
        }

        if (maximum == -1)
            printf("No eligible component\n");
        else
            printf("Maximum weight = %d\n", maximum);
    }

    return 0;
}