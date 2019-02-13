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

        if(a[l]<=a[m])
        {
            if(a[l]<=key && key<=a[m])
                r=m-1;
            else
                l=m+1;
        }
        else
        {
            if(a[m]<=key && key<=a[r])
                l=m+1;
            else
                r=m-1;
        }
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
    
    int ans = binSearch(n,a,1,n,key);
    p(ans);

}