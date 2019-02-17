#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d\n", x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)

int main()
{
    int n;
    int a[n];

    f1(i,0,n)
        s(&a[i]);
    
    int dp[n+1];
    memset(dp,-1,sizeof(dp));

    if(a[0]%3==0)
        dp[0]=1;
    else
        dp[0]=0;

    f1(i,1,n)
    {
        
    }
}