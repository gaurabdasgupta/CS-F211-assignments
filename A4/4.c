#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d\n", x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)

int findCost(int n, int height[n], int cost[n], int targetHeight)
{
    int c = 0;
    f1(i,0,n)
        c+=abs(height[i]-targetHeight)*cost[i];
    return c;
}

int binSearch(int n, int mx, int height[n], int cost[n])
{
    int l = 0;
    int r = mx+1;
    int ans = INT_MAX;
    while(l<r)
    {
        int m = (r+l)/2;

        // TODO: mLess, mGreat needed?
        int mLess = (m>0)?findCost(n,height,cost,m-1):INT_MAX;
        int mCost = findCost(n,height,cost,m);
        int mGreat = findCost(n,height,cost,m+1);

        printf("m:%d cost:%d\n", m, mCost);

        if (ans == mCost)
            break;

        if(ans>mCost)
            ans = mCost;
        if (mLess <= mCost) 
            r = m;
        else if (mGreat <= mCost) 
            l = m + 1; 
    }

    return ans;

}

int main()
{
    int n;
    s(n);

    int height[n], cost[n];
    f1(i,0,n)
        s(height[i]);
    f1(i,0,n)
        s(cost[i]);
    
    int mxHeight = INT_MIN;
    f1(i,0,n)
        if(height[i]>mxHeight)
            mxHeight = height[i];
    p(mxHeight);

    p(binSearch(n,mxHeight,height,cost));
}

/* testcases:

    5 2 3

*/