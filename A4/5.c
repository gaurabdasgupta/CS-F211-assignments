#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d\n", x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)

int calcItems(int n, int a[n], int time)
{
    int ans = 0;
    f1(i,0,n)
        ans+=(time/a[i]);
    
    return ans;
}

int binSearch(int n, int a[n], int m, int r)
{
    int l = 1;

    while(l<r)
    {
        int mid = (r+l)/2;
        int items = calcItems(n,a,mid);
        // printf("l: %d r:%d m:%d items:%d\n", l, r, mid, items);
        if(items<m)
            l = mid+1;
        else
            r = mid;
    }

    return r;
}

int main()
{
    int n, m;
    s(n); s(m);

    int a[n];

    f1(i,0,n)
        s(a[i]);
    
    int mx=INT_MIN;
    f1(i,0,n)
        if(a[i]>mx)
            mx = a[i];
    
    p(binSearch(n,a,m,m*mx));

}