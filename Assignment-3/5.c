#include<stdio.h>
#include<string.h>
#include<limits.h>

#define f(i,x,y) for(int i=x;i<y;i++)

int n, vis[1000][1000], m[1000][1000];

int calcArea(int i, int j)
{
    if(i<0||i>=n||j<0||j>=n||vis[i][j]||m[i][j]==0)
        return 0;

    vis[i][j]=1;
    return (1+calcArea(i-1,j) + calcArea(i+1,j) + calcArea(i,j-1) + calcArea(i,j+1));
}

int main()
{
    int ans=0;
    scanf("%d", &n);

    f(i,0,n)
        f(j,0,n)
            scanf("%d",&m[i][j]);

    f(i,0,n)
    
        f(j,0,n)
        {
            int t = calcArea(i,j);
            if(t>ans)
                ans = t;
        }
    
    printf("%d", ans);
}