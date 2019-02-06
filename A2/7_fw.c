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
int g[1000][1000], uni[1000];

void printPath(int paths[n][n], int v, int u)
{
    if(paths[v][u]==v)
    {
        printf("%d ", paths[v][u]);
        return;
    }
    
    printPath(paths, v, paths[v][u]);
    printf("%d ", paths[v][u]);
}

int findNearestLib()
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
    int ans = INT_MAX;
    f1(k,0,n)
        f1(i,0,n)
            f1(j,0,n)
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    // if(dist[i][j]>ans)
                    //     ans = dist[i][j];
                    paths[i][j] = paths[k][j];
                }
    int city=-1;
    f1(i,1,n)
    {
        if(dist[0][i]==ans&&uni[i])
        {
            if(city>i)
                city = i;
        }
        if(dist[0][i]<ans&&uni[i])
        {
            ans = dist[0][i];
            city = i;
        }   

    }

    return city;
}

void addEdge(int x, int y)
{
    g[x][y]=1;
    g[y][x]=1;
}

int main()
{
    n=8;
    addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(1, 3); 
    addEdge(1, 4); 
    addEdge(4, 99); 
    addEdge(4, 6);
    addEdge(0, 7); 
    addEdge(7, 8);
    f1(i,0,n)
    {
        f1(j,0,n)
        {
            if(g[i][j]==0)
            {
                if(i!=j)
                    g[i][j]=inf;
                else
                    g[i][j]=0;
            }
        }
    }
    int m;
    scanf("%d ",&m);
    f1(i,0,m)
    {
        int d;
        scanf("%d",&d);
        uni[d]=1;
    }

    printf("%d",findNearestLib());
}