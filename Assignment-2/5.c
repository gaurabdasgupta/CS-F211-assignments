#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define d(x) printf("%d",x);
#define f(i,x,y) for(int i=x;i<y;i++)
#define null NULL

int g[1000][1000], vis[1000], componentV[1000],n;

void dfs(int x)
{
    vis[x]=1;
    componentV[x]=1;
    // printf("%d ",x);
    for(int i=0;i<n;i++)
    {
        if(!vis[i]&&g[x][i])
            dfs(i);
    }
}

// void addEdge(int x, int y)
// {
//     g[x][y]=1;
//     g[y][x]=1;
// }

int main()
{
    int setV[1000];
    memset(setV,-1,sizeof(setV));
    int delta;
    // n=5;
    // addEdge(1, 0);
    // addEdge(2, 3);
    // addEdge(3, 4);
    scanf("%d %d", &n, &delta);
    f(i,0,n)
    {
        int v,f;
        scanf("%d %d", &v, &f);
        setV[v] = f;
    }

    f(i,0,n)
        f(j,0,n)
            if(setV[i]!=-1&&setV[j]!=-1&&abs(setV[i]-setV[j]>=delta))
            {
                g[i][j]=1;
                g[j][i]=1;  
            }
    f(i,0,n){ f(j,0,n) printf("%d ",g[i][j]); printf("\n");}
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            int compMat[1000][1000];
            memset(compMat,0,sizeof(compMat));
            f(i,0,n) f(j,0,n) compMat[i][j]= g[i][j];

            for(int i=0;i<n;i++)
            {
                if(componentV[i]==0)
                {
                    for(int j=0;j<n;j++)
                        compMat[i][j]=-1;
                    for(int j=0;j<n;j++)
                        compMat[j][i]=-1;
                }
            }

            // f(i,0,n){ f(j,0,n) printf("%d ",compMat[i][j]); printf("\n");}
            f(i,0,n)
            {
                f(j,0,n)
                {
                    if(compMat[i][j]!=-1)
                        printf("%d ", compMat[i][j]);
                }
                printf("\n");
            }

            memset(componentV,0,sizeof(componentV));
            printf("-----\n");
        }
    }


}