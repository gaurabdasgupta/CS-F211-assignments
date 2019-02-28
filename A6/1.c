#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d ", x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)

typedef struct n{
    int val;
    int idx;
}ii;

int main()
{
    int n;
    s(n);
    ii v[n];
    f1(i,0,n)
    {
        int x;
        s(x);
        ii t;
        t.val = x;
        t.idx = i;
    }

    int a[n][n];

    f1(i,0,n)
        f1(j,0,n)
            s(a[i][j]);

    qsort(v, n, sizeof(ii), cmp);

    f1(i,0,n)
    {
        if(v[i].idx==i)
            continue;
        else
        {
            swap(&v[i].val, &v[v[i].idx].val);
            swap(&v[i].idx, &v[v[i].idx].idx);
        }
        ans++;
    }
}

