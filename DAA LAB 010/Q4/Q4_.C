#include <stdio.h>

#define MAX 1000

int graph[MAX][MAX];
int parent[MAX], active[MAX];
int weight[MAX], sum[MAX], order[MAX];
int n;

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

    parent[b] = a;
    sum[a] += sum[b];
}

int main()
{
    int m, i, u, v, j, x;
    int ans[MAX], maximum;

    printf("Enter vertices and edges: ");
    scanf("%d%d", &n, &m);

    for (i = 0; i < n; i++)
    {
        printf("Weight of vertex %d: ", i);
        scanf("%d", &weight[i]);
        parent[i] = i;
        sum[i] = 0;
    }

    for (i = 0; i < m; i++)
    {
        printf("Enter edge (u v): ");
        scanf("%d%d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    printf("Enter deletion order: ");
    for (i = 0; i < n; i++)
        scanf("%d", &order[i]);

    for (i = 0; i < n; i++)
        active[i] = 0;

    ans[n] = 0;

    for (i = n - 1; i >= 0; i--)
    {
        x = order[i];
        active[x] = 1;
        parent[x] = x;
        sum[x] = weight[x];

        for (j = 0; j < n; j++)
        {
            if (graph[x][j] && active[j])
                unite(x, j);
        }

        maximum = sum[find(x)];

        for (j = 0; j < n; j++)
        {
            if (active[j] && find(j) == j &&
                sum[j] > maximum)
                maximum = sum[j];
        }

        ans[i] = maximum;
    }

    printf("Maximum component sum after each deletion:\n");

    for (i = 1; i <= n; i++)
        printf("%d ", ans[i]);

    printf("\n");
    return 0;
}