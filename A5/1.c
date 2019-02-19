#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d ", x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)

typedef struct d{
    int st;
    int en;
    int team;
    int orgPos;
}ivl;

int cmp(const void* l, const void* r)
{
    ivl* t1 = (ivl*)l;
    ivl* t2 = (ivl*)r;
    return (t1->st - t2->st);
}

int cmp2(const void* l, const void* r)
{
    ivl* t1 = (ivl*)l;
    ivl* t2 = (ivl*)r;
    return (t1->orgPos - t2->orgPos);
}

int main()
{
    int t;
    s(t);
    while(t--)
    {
        int n;
        s(n);
        ivl v[n];
        f1(i,0,n)
        {
            int st,en;
            ivl tmp;
            s(st); s(en);
            tmp.st = st;
            tmp.en = en;
            tmp.team = 0;
            tmp.orgPos = i;
            v[i] = tmp;
        }

        qsort(v,n,sizeof(ivl),cmp);

        f1(i,0,n)
        {
            f1(j,0,n)
            {
                int f=0;
                if(i!=j)
                {
                    if(v[i].en<v[j].st||v[i].st>v[j].en)
                    {
                        v[i].team = 1 - v[j].team;
                        printf("%d %d\n", i, j);
                    }
                    else
                    {
                        v[i].team = v[j].team;
                        // printf("else %d %d\n", i, j);
                    }
                }
            }
            // if(v[i].st<=v[i-1].en)
            //     v[i].team = v[i-1].team;
            // else
            //     v[i].team = 1 - v[i-1].team;
        }

        int f = 0;
        f1(i,0,n)
            if(v[i].team==1)
                f = 1;

        qsort(v,n,sizeof(ivl),cmp2);

        if(!f)
            printf("-1\n");
        else
        {
            f1(i,0,n)
            {
                if(v[i].team==0)
                    printf("CA ");
                else
                    printf("IM ");
            }
            printf("\n");
        }
    }
}