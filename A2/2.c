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
int g[1000][1000];

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

void findMaxDiameter()
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
    int ans = INT_MIN;
    f1(k,0,n)
        f1(i,0,n)
            f1(j,0,n)
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    if(dist[i][j]>ans)
                        ans = dist[i][j];
                    paths[i][j] = paths[k][j];
                }

    printf("%d\n", ans);

    f1(i,0,n)
    {
        f1(j,0,n)
        {
            if(dist[i][j]==ans)
            {
                printf("%d %d\n", i, j);
                printPath(paths,i,j);
                printf("%d",j);
                printf("\n");
            }       
        }
    }
}

void add_edge(int x, int y)
{
    g[x][y]=1;
    g[y][x]=1;
}

int main()
{
    // scanf("%d", &n);
    n=8;
    add_edge( 0, 1); 
    add_edge( 0, 3); 
    add_edge( 1, 2); 
    add_edge( 3, 4); 
    add_edge( 3, 7); 
    add_edge( 4, 5); 
    add_edge( 4, 6); 
    add_edge( 4, 7); 
    add_edge( 5, 6); 
    add_edge( 6, 7); 
    f1(i,0,n)
    {
        f1(j,0,n)
        {
            if(g[i][j]==0)
            {
                // if(i!=j)
                    g[i][j]=inf;
                // else
                //     g[i][j]=0;
            }
        }
    }

    // f1(i,0,n)
    // { 
    //     f1(j,0,n) 
    //         printf("%d ", g[i][j]); 
    //     printf("\n");
    // }

    findMaxDiameter();
}