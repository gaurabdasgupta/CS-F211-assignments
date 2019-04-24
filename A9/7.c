#include<stdio.h>
#include<limits.h>

int vis[100];
int g[100][100];
int n, m;
int ans;

void dfs(int s, int d, int k, int cost)
{
    if(s == d)
    {
        ans = cost;
        return;
    }

    if(k == 0)
        return;
        
    vis[s] = 1;
    for(int i=0;i<n;i++)
    {
        if(vis[i] == 0 && g[s][i]!=0)
        {
            if(cost + g[s][i] > ans)
                continue;
            
            dfs(i, d, k-1, cost+g[s][i]);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    for(int i=0;i<m;i++)
    {
        int s,d,p;
        scanf("%d %d %d", &s, &d, &p);
        g[s][d] = p;
    }

    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
        int s,d,k;
        scanf("%d %d %d", &s, &d, &k);
        ans = INT_MAX;
        dfs(s, d, k+1, 0);
        printf("%d\n", ans);
    }

}

