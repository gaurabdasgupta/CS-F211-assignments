#include<stdio.h>
#include<stdlib.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d\n", x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)

int f;

int binSearch(int n, int a[n], int l, int r, int key)
{
    int m;
    while(l<=r)
    {
        m = (r+l)/2;

        if(a[m]==key)
        {
            f=1;
            return m;
        }
        else if(a[m]<key)
            l = m+1;
        else
            r = m-1;
    }

    return l;
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

    int ans = binSearch(n,a,1,n,d);
    if(f)
        printf("Naruto %d", ans);
    else
        printf("Sasuke %d", ans);
}