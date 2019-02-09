#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d\n", x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)

int check(int v, int k)
{
    int cnt=0;
    int d = 1;
    while(1)
    {
        if(v/d<=0)
            break;
        cnt+=v/d;
        d*=k;
    }

    return cnt;
}

int binSearch(int l, int r, int k)
{
    // int m;
    int n=r;
    while(l<r)
    {
        int m = (r+l)/2;

        int probsSolved = check(m,k);
        printf("l:%d m:%d r:%d solved:%d\n", l, m, r, probsSolved);

        if(probsSolved>n)
            r = m;
        else if(probsSolved<n)
            l = m+1;
        else 
        {
            p(11);
            return m;
        }

    }
}

int main()
{
    int n, k;
    s(n); s(k);

    p(binSearch(1,n,k));                                                         
}

/* testcases:

9 2 (nearest possible)
20 2 (same)
56 6
40 7
9 3
*/