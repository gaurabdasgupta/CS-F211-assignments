#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d ", x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)
#define max(a,b) ((a)>(b)?(a):(b))

int main()
{
    int n;
    s(n);
    if(n>75)
        p(-1);
    int dp[76];
    for(int i=1;i<=6;i++)
        dp[i] = i;  
    
    for(int i=7;i<=n;i++)
    {
        dp[i] = 0;
        for(int j=i-3;j>=1;j--)
            dp[i] = max(dp[i],(i-j-1)*dp[j]);
            
    }
    p(dp[n]);
}