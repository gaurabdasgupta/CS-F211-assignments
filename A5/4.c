#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d\n", x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)
#define min(a,b) ((a)<(b)?(a):(b))

typedef struct pair{
    int val;
    int idx;
}ii;

int cmp(const void* l, const void* r)
{
    ii* tmp1 = (ii*)l;
    ii* tmp2 = (ii*)r;
    int t = tmp1->val;
    int q = tmp2->val;

    return (t-q);
}

int cmp1(const void* l, const void* r)
{
    ii* tmp1 = (ii*)l;
    ii* tmp2 = (ii*)r;
    int t = tmp1->val;
    int q = tmp2->val;

    return (q-t);
}

void swap(int* a, int* b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

int main()
{
    int n, ans=0;
    s(n);

    ii v[n];
    memset(v,0,sizeof(v));
    int k=0;
    f1(i,0,n)
    {
        int x;
        s(x);
        ii t;
        t.val = x;
        t.idx = i;
        v[k++]=t;
    }

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

    int ans2=0;
    qsort(v,n,sizeof(ii),cmp1);

    f1(i,0,n)
    {
        if(v[i].idx==i)
            continue;
        else
        {
            swap(&v[i].val, &v[v[i].idx].val);
            swap(&v[i].idx, &v[v[i].idx].idx);
        }

        ans2++;
    }
    
    p(ans);
    p(ans2);
    p(min(ans,ans2));
}
