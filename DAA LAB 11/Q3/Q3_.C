
#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char word[100][20],A[20],B[20];

    int a[100][100]={0};
    int d1[100],d2[100];
    int q1[100],q2[100];

    printf("Enter number of words: ");
    scanf("%d",&n);

    printf("Enter words:\n");

    for(int i=0;i<n;i++)
        scanf("%19s",word[i]);

    printf("Enter start and target: ");
    scanf("%19s%19s",A,B);

    int s=-1,t=-1;

    for(int i=0;i<n;i++)
    {
        if(strcmp(word[i],A)==0) s=i;
        if(strcmp(word[i],B)==0) t=i;
    }

    if(s==-1 || t==-1)
    {
        printf("No valid path");
        return 0;
    }

    for(int i=0;i<n;i++)
    {
        d1[i]=-1;
        d2[i]=-1;

        for(int j=0;j<n;j++)
        {
            int count=0;

            if(strlen(word[i])==strlen(word[j]))
            {
                for(int k=0;word[i][k]!='\0';k++)
                    if(word[i][k]!=word[j][k])
                        count++;

                if(count==1)
                    a[i][j]=1;
            }
        }
    }

    int f1=0,r1=0,f2=0,r2=0;

    q1[r1++]=s;
    q2[r2++]=t;

    d1[s]=0;
    d2[t]=0;

    if(s==t)
    {
        printf("Minimum mutations = 0");
        return 0;
    }

    while(f1<r1 && f2<r2)
    {
        int u=q1[f1++];

        for(int v=0;v<n;v++)
        {
            if(a[u][v] && d1[v]==-1)
            {
                d1[v]=d1[u]+1;

                if(d2[v]!=-1)
                {
                    printf("Minimum mutations = %d",
                           d1[v]+d2[v]);
                    return 0;
                }

                q1[r1++]=v;
            }
        }

        u=q2[f2++];

        for(int v=0;v<n;v++)
        {
            if(a[u][v] && d2[v]==-1)
            {
                d2[v]=d2[u]+1;

                if(d1[v]!=-1)
                {
                    printf("Minimum mutations = %d",
                           d1[v]+d2[v]);
                    return 0;
                }

                q2[r2++]=v;
            }
        }
    }

    printf("No valid path");

    return 0;
}
