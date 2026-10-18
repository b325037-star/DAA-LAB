#include <stdio.h>

#define MAX 1000

int parent[MAX], a[MAX];
int graph[MAX][MAX], visited[MAX];
int index[MAX], values[MAX];

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

    if (a != b)
        parent[b] = a;
}

int main()
{
    int n, m, i, j, u, v, root;
    int count, t;

    printf("Enter n and m: ");
    scanf("%d%d", &n, &m);

    printf("Enter permutation: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        parent[i] = i;
    }

    for (i = 0; i < m; i++)
    {
        printf("Enter edge (u v): ");
        scanf("%d%d", &u, &v);
        unite(u, v);
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    for (i = 0; i < n; i++)
    {
        if (visited[i])
            continue;

        root = find(i);
        count = 0;

        for (j = 0; j < n; j++)
        {
            if (find(j) == root)
            {
                index[count] = j;
                values[count] = a[j];
                count++;
                visited[j] = 1;
            }
        }

        for (j = 0; j < count; j++)
        {
            int k;
            for (k = j + 1; k < count; k++)
            {
                if (index[j] > index[k])
                {
                    t = index[j];
                    index[j] = index[k];
                    index[k] = t;
                }

                if (values[j] > values[k])
                {
                    t = values[j];
                    values[j] = values[k];
                    values[k] = t;
                }
            }
        }

        for (j = 0; j < count; j++)
            a[index[j]] = values[j];
    }

    printf("Smallest permutation: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
    return 0;
}