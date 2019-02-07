#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
#include<stdbool.h>

#define null NULL
#define f(i,x,y) for(int i=x;i<y;i++)

int g[100][100], n;
int vis[100];
int posX, posY, x, y, foundX;


void dfs(int v, int k, int pos)
{
    vis[v] = 1;
    if(v==x)
    {
        posX = pos;
        foundX = 1;
    }

    if(v==y)
        posY = pos;

    if(v==k)
        return;

    for(int i=1;i<=n;i++)
        if(g[v][i]&&!vis[i])
            dfs(i, k, pos+1);
}

int main()
{
    scanf("%d %d %d", &n, &x, &y);
    int cnt = 0;
    f(i,0,n-1)
    {
        int x, y;
        scanf("%d %d", &x, &y); 
        g[x][y] = 1;
        g[y][x] = 1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            {
               
                dfs(i,j,0);

                if(posX>=posY||(!foundX))
                    cnt++;

                memset(vis,0,sizeof(vis));
                posX = 0;
                posY = 0;
                foundX = 0;
            }
        }
    }

    printf("%d", cnt);

}