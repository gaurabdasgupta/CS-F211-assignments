#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d\n", x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)

int cmp(const void* l, const void* r)
{
    return (*(int*)l - *(int*)r);
}

int main()
{
    int p,x,any;
    scanf("%d %d %d", &p, &x, &any);
    int m;
    s(m);

    int xb[m],ps[m];
    int k=0,l=0;

    f1(i,0,m)
    {
        int v;
        char str[5];
        s(v);
        scanf("%s", str);
        if(strcmp(str,"PS4")==0)
            xb[k++]=v;
        else
            ps[l++]=v;
    }

    qsort(xb,k,sizeof(int),cmp);
    qsort(ps,l,sizeof(int),cmp);

    int num=0,cost=0;
    int xbPtr=0, psPtr=0;

    while(p-- && psPtr<k)
    {
        cost+=ps[psPtr++];
        num++;
    }

    while(x-- && xbPtr<l)
    {
        cost+=xb[xbPtr++];
        num++;
    }

    while(any-- && (psPtr<k||xbPtr<l))
    {
        if(xb[xbPtr]<ps[psPtr])
            cost+=xb[xbPtr++];
        else
            cost+=ps[psPtr++];

        num++;
    }

    printf("%d %d", num, cost);
}

/* testcases:
2 3 2
8
2 PS4
9 PS4
7 PS4
5 PS4
3 XBOX
6 XBOX
1 XBOX
8 XBOX
o/p: 7 32

2 3 2
8
2 PS4
5 PS4
7 PS4
6 PS4
1 XBOX
3 XBOX
6 XBOX
8 XBOX
o/p: 7 30

*/