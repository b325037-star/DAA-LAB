
#include <stdio.h>

#define INF 999999

int main()
{
    int n,m,k,R;
    int a[100][100],d[100],owner[100];
    int q[100];

    printf("Enter vertices and edges: ");
    scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=0;

    printf("Enter edges:\n");

    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        a[u][v]=1;
        a[v][u]=1;
    }

    printf("Enter number of hubs and radius: ");
    scanf("%d%d",&k,&R);

    for(int i=0;i<n;i++)
    {
        d[i]=INF;
        owner[i]=-1;
    }

    int front=0,rear=0;

    printf("Enter hubs:\n");

    for(int i=1;i<=k;i++)
    {
        int h;
        scanf("%d",&h);

        d[h]=0;
        owner[h]=i;
        q[rear++]=h;
    }

    while(front<rear)
    {
        int u=q[front++];

        for(int v=0;v<n;v++)
        {
            if(a[u][v] && d[v]==INF)
            {
                d[v]=d[u]+1;
                owner[v]=owner[u];
                q[rear++]=v;
            }
        }
    }

    printf("\nVertex Owner Distance\n");

    for(int i=0;i<n;i++)
    {
        if(d[i]>R)
            owner[i]=-1;

        printf("%d\t%d\t",i,owner[i]);

        if(d[i]==INF)
            printf("Unreachable\n");
        else
            printf("%d\n",d[i]);
    }

    return 0;
}
