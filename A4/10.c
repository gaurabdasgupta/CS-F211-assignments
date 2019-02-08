#include<stdio.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d\n", x)
#define f(i,x,y) for(int i=x;i<y;i++)
// code O(logn) approach
int main()
{
    int n;
    s(n);
    int a[n], res=0;

    f(i,0,n)
    {
        int x;
        s(x);
        res^=x;
    }

    p(res);
}