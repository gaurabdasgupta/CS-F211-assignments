#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>

#define f(i,x,y) for(int i=x;i<y;i++)

int g[1000][1000], n, vis[1000], f;
bool ans;

void isReachable(int v, int k)
{
    vis[v] = 1;
    if(v==k)
    {
        f=1;
        return;
    }
    for(int i=0;i<n;i++)
        if(g[v][i]&&!vis[i])
            isReachable(i, k);
}   

int main()
{
    int m;
    scanf("%d %d", &n, &m);

    while(m--)
    {
        int x,y;
        scanf("%d %d", &x, &y);
        g[x][y]=1;
    }

    int t;
    scanf("%d", &t);
    while(t--)
    {
        f=0;
        int x,y;
        scanf("%d %d", &x, &y);
        isReachable(x,y);
        if(f)
            printf("Yes\n");
        else
            printf("No\n");
        memset(vis,0,sizeof(vis));
    }
}