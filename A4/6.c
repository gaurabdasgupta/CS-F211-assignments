#include<stdio.h>
#include<stdlib.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d\n", x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)

int cmp(const void* l, const void* r)
{
    return (*(int*)l - *(int*)r);
}

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
    f2(i,1,n)
        s(a[i]);
    int d;
    s(d);

    qsort(a+1,n,sizeof(int),cmp);

    f2(i,1,n)
    {
        int ans = binSearch(n,a,i+1,n,d+a[i]);
        if(ans!=-1)
        {
            p(a[i]+a[ans]);
            return 0;
        }
    }

    p(-1);
}