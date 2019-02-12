#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d\n", x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)

int a2[106], mMx;

int cmp(const void* l, const void* r)
{
    int lIndex = a2[*(int*)l];
    int rIndex = a2[*(int*)r];
    if(rIndex==INT_MAX&&lIndex==INT_MAX)
        return (*(int*)l - *(int*)r);

    return (lIndex-rIndex);
}

int main()
{
    int n, m;
    s(n); s(m);

    int a1[n];

    mMx = INT_MIN;
    f1(i,0,n)
    {
        int x;
        s(x);
        if(x>mMx)
            mMx = x;
        a1[i] = x;
    }

    f1(i,0,106)
        a2[i]=INT_MAX;
    
    f1(i,0,m)
    {
        int x;
        s(x);
        a2[x]=i;
    }

    qsort(a1, n, sizeof(int), cmp);

    f1(i,0,n)
        printf("%d ", a1[i]);
}