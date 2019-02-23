#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d ", x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)

int adj[100][100], cats[100], vis[100], n, ans;

void dfs(int x, int consec, int m)
{
    printf("p: %d %d\n",x,consec);
    if(cats[x])
        consec++;
    else
        consec = 0;
    if(consec==m)
        return;
    
    vis[x] = 1;
    int leaf = 1;
    for(int i=1;i<=n;i++)
    {
        if(adj[x][i]&&!vis[i])
        {
            leaf = 0;
            dfs(i,consec, m);
        }
    }

    if(leaf)
        ans++;
}

int main()
{
    int m;
    s(n); s(m);
    f2(i,1,n)
        s(cats[i]);

    f1(i,0,n-1)
    {
        int x,y;
        s(x); s(y);
        adj[x][y] = 1;
        // adj[y][x] = 1;
    }

    ans = 0;
    dfs(1,0,m+1); // todo: m or m+1/ to consider root or not?
    p(ans);
}