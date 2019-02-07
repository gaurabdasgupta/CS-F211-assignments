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

        if(a[m]==key)
            return m;
        else if(a[m]<key)
            l = m+1;
        else
            r = m-1;
    }

    return -1;
}

int main()
{
    int n;
    s(n);
    int a[n];
    a[0] = -1;
    f2(i,1,n)
        s(a[i]);
    int key;
    s(key);
    
    int pivot = 0;

    f2(i,1,n)
        if(a[i]>a[i+1])
            pivot = i;

    int ans = binSearch(n,a,1,pivot,key);
    if(ans == -1)
    {
        ans = binSearch(n,a,pivot+1,n,key);
        if(ans == -1)
            printf("-1");
        else
            p(ans);
    }
    else
        p(ans);

}