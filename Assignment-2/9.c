#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<limits.h>

#define d(x) printf("%d",x);
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)
#define null NULL
#define max(a,b) ((a>b)?a:b)

int maxSumSub(int N, int mat[][N], int k) 
{ 

    if (k > N) 
        return 0; 

    int stripSum[N][N]; 
  
    for (int j=0; j<N; j++) 
    { 

        int sum = 0; 
        for (int i=0; i<k; i++) 
            sum += mat[i][j]; 
        stripSum[0][j] = sum; 

        for (int i=1; i<N-k+1; i++) 
        { 
            sum += (mat[i+k-1][j] - mat[i-1][j]); 
            stripSum[i][j] = sum; 
        } 
    } 
  
    int max_sum = INT_MIN, *pos = NULL; 
  
    for (int i=0; i<N-k+1; i++) 
    { 

        int sum = 0; 
        for (int j = 0; j<k; j++) 
            sum += stripSum[i][j]; 

        if (sum > max_sum) 
        { 
            max_sum = sum; 
            pos = &(mat[i][0]); 
        } 

        for (int j=1; j<N-k+1; j++) 
        { 
            sum += (stripSum[i][j+k-1] - stripSum[i][j-1]); 
            if (sum > max_sum) 
            { 
                max_sum = sum; 
                pos = &(mat[i][j]); 
            } 
        } 
    } 

    // printf("%d", max_sum);
    return max_sum;
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n][n];

    f1(i,0,n) f1(j,0,n) scanf("%d", &a[i][j]);

    int ans = INT_MIN;
    f2(i,1,n)
    {   
        ans = max(ans,maxSumSub(n,a,i));
    }

    d(ans);
}