#include <stdio.h>

#define MAX 100

int graph[MAX][MAX], color[MAX], queue[MAX];
int n;

int isBipartite()
{
    int i, u, v, front, rear;

    for (i = 0; i < n; i++)
        color[i] = -1;

    for (i = 0; i < n; i++)
    {
        if (color[i] != -1)
            continue;

        front = rear = 0;
        queue[rear++] = i;
        color[i] = 0;

        while (front < rear)
        {
            u = queue[front++];

            for (v = 0; v < n; v++)
            {
                if (graph[u][v])
                {
                    if (color[v] == -1)
                    {
                        color[v] = 1 - color[u];
                        queue[rear++] = v;
                    }
                    else if (color[v] == color[u])
                        return 0;
                }
            }
        }
    }
    return 1;
}

int main()
{
    int m, u, v, i;

    printf("Enter vertices and edges: ");
    scanf("%d%d", &n, &m);

    for (i = 0; i < m; i++)
    {
        printf("Enter edge (u v): ");
        scanf("%d%d", &u, &v);

        graph[u][v] = graph[v][u] = 1;

        if (isBipartite())
            printf("Edge accepted\n");
        else
        {
            graph[u][v] = graph[v][u] = 0;
            printf("Edge rejected\n");
        }
    }
    return 0;
}