
#include <stdio.h>

#define INF 999999

int main()
{
    int n, m, s, C;
    int a[100][100], w[100][100];
    int d[100][2], q[10000], p[10000];

    printf("Enter n, m: ");
    scanf("%d%d", &n, &m);

    printf("Enter source and penalty: ");
    scanf("%d%d", &s, &C);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=0;

    printf("Enter edges (u v weight):\n");

    for(int i=0;i<m;i++)
    {
        int u,v,x;
        scanf("%d%d%d",&u,&v,&x);
        a[u][v]=1;
        w[u][v]=x;
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<2;j++)
            d[i][j]=INF;

    int front=5000,rear=5000;

    d[s][0]=0;
    q[rear]=s;
    p[rear++]=0;

    while(front<rear)
    {
        int u=q[front];
        int par=p[front++];

        for(int v=0;v<n;v++)
        {
            if(a[u][v])
            {
                int x=w[u][v];
                int np=par^x;
                int nd=d[u][par]+x;

                if(nd<d[v][np])
                {
                    d[v][np]=nd;

                    if(x==0)
                    {
                        q[--front]=v;
                        p[front]=np;
                    }
                    else
                    {
                        q[rear]=v;
                        p[rear++]=np;
                    }
                }
            }
        }
    }

    printf("\nMinimum Cost:\n");

    for(int i=0;i<n;i++)
    {
        int x=d[i][0];
        int y=d[i][1];

        if(y!=INF)
            y=y+C;

        if(x==INF && y==INF)
            printf("%d Unreachable\n",i);
        else
            printf("%d %d\n",i,x<y?x:y);
    }

    return 0;
}
