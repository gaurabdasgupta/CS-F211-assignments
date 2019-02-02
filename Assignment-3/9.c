#include<stdio.h>
#include<string.h>
#include<limits.h>

#define f(i,x,y) for(int i=x;i<y;i++)
#define inf 9999

int g[1000][1000], n;

void fw()
{
    int dist[n][n];

    f(i,0,n) f(j,0,n) dist[i][j] = g[i][j];

    f(k,0,n)
        f(i,0,n)
            f(j,0,n)
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    
    f(i,0,n)
        f(j,0,n)
            if(dist[i][j]<=1)
            {
                f=1;
                seen[i]=1;
                if(!seen[i])
                printf("%d,",i);
            }
    if(!f)
        printf("No");
}

int main()
{
    int m;
    scanf("%d %d", &n, &m);
    f(i,0,n) 
        f(j,0,n)
        {
            if(i==j)
                g[i][j]=0;
            else
                g[i][j] = inf;
        } 
    
    while(m--)
    {
        int x,y;
        scanf("%d %d", &x, &y);
        g[x][y]=1;
    }

    fw();
}