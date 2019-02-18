#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d\n", x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)

typedef struct node{
    int idx;
    int dist;
    int vis;
}v;

int cmp(const void* l, const void* r)
{
    v* t1 = (v*)l;
    v* t2 = (v*)r;
    int d1 = t1->dist;
    int d2 = t2->dist;
    // p(d1-d2);
    return (d1-d2);
}

int main()
{
    int n;
    s(n);
    v d[1000];
    int cnt[1000];
    memset(cnt,0,sizeof(cnt));
    f1(i,0,n)
    {
        v x;
        int tmp;
        s(tmp);
        x.idx = i;
        x.dist = tmp;
        d[i] = x;
        cnt[tmp]++;
        // p(11);
    }
    // f1(i,0,n)
    //     p(d[i].dist);

    qsort(d,n,sizeof(v),cmp);

    f1(i,0,n)
        p(d[i].idx);
    int f=0;
    f1(i,0,n)
    {
        f1(j,i+1,n)
        {
            // printf("%d %d\n",d[i].idx,d[j].idx);
            if(abs(d[i].dist - d[j].dist)==1&&cnt[d[j].dist]>0)
            {
                printf("fnd: %d %d\n",d[i].idx,d[j].idx);
                cnt[d[j].dist]--;
            }   
        }
    }
}