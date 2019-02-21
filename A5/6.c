#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define s(x) scanf("%d", &x)
#define p(msg, x) printf("%s: %d\n", msg, x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)

int inv;

void merge(int n, int a[n], int l, int m, int r)
{
    int ln = m-l+1;
    int rn = r-m;

    int la[ln],ra[rn];

    f1(i,0,ln)
        la[i] = a[l+i];
    f1(i,0,rn)
        ra[i] = a[m+1+i];
    
    int lp=0,rp=0,k=l;

    while(lp<ln && rp<rn)
    {
        if(la[lp] <= ra[rp])
            a[k++] = la[lp++];
        else
        {
            a[k++] = ra[rp++];
            inv += m-lp+1;
        }
    }
    
    while(lp<ln)
        a[k++] = la[lp++];

    while(rp<rn)
        a[k++] = ra[rp++];
}

void mergeSortMod(int n, int a[n], int l, int r)
{
    if(l<r)
    {
        int m = (r+l)/2;
        mergeSortMod(n,a,l,m);
        mergeSortMod(n,a,m+1,r);
        merge(n,a,l,m,r);
    }

}

int main()
{
    int n;
    s(n);
    int a[n];
    f1(i,0,n)
        s(a[i]);

    mergeSortMod(n,a,0,n-1);
    p("inv pairs",inv);
}