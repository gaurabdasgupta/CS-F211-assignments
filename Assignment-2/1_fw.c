#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<limits.h>

#define d(x) printf("%d",x);
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)
#define null NULL
#define inf 99999
#define min(a,b) (a<b?a:b) 

int n;

void printPath(int paths[n][n], int v, int u)
{
    if(paths[v][u]==v)
    {
        printf("%d", paths[v][u]);
        return;
    }
    
    printPath(paths, v, paths[v][u]);
    printf("%d", paths[v][u]);
}

void findMinCycle(int g[n][n])
{
    int dist[n][n];
    int paths[n][n];
    f1(i,0,n)
    {
        f1(j,0,n) 
        {
            dist[i][j]=g[i][j];
            if(g[i][j]!=inf && i!=j)
                paths[i][j]=i;
            else
                paths[i][j]=-1;
        }
    } 

    f1(k,0,n)
        f1(i,0,n)
            f1(j,0,n)
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    paths[i][j] = paths[k][j];
                    // printf("%d ",k);
                }
    
    int ans = INT_MAX;
    int ansNode=0;
    f1(i,0,n)
    {
        if(dist[i][i]<ans)
        {
            ans = dist[i][i];
            ansNode = i;
        }
    }
    
    printf("%d\n", ans);

    f1(i,0,n)
    {
        f1(j,0,n)
            printf("%d ",paths[i][j]);
        printf("\n");
    }

    printPath(paths,ansNode,ansNode);
}

int main()
{
    scanf("%d", &n);

    int g[n][n];

    f1(i,0,n)
    {
        f1(j,0,n)
        {
            int x;
            scanf("%d", &x);
            if(x!=0)
                g[i][j]=x;
            else
                g[i][j]=inf;

        }
    }

    findMinCycle(g);
    // f1(i,0,n)
    // {
    //     f1(j,0,n)
    //         printf("%d ", g[i][j]);
    //     printf("\n");
    // }
}