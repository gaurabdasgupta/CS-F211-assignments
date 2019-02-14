#include<stdio.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d\n", x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)

int binSearch(int n, int a[n], int l, int r, int key)
{
    while(l<=r)
    {
        int m = (r+l)/2;
        if(key==a[m])
            return m;
        if(a[m]>a[m+1]&&key==a[m+1])
            return m+1;
        if(a[m]<a[m-1]&&key==a[m-1])
            return m-1;
        
        if(key>a[m])
            l=m+1;
        else
            r=m-1;
    }

    return -1;
}

int main()
{
    int n, pre, post;
    s(n);
    int a[n];
    f2(i,1,n)
        s(a[i]);
    
    int key;
    s(key);
    int ans = binSearch(n,a,1,n,key);

    p(ans);
}