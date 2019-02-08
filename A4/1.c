#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d\n", x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)

int cost;

int cmp(const void* l, const void* r)
{
    return (*(int*)l - *(int*)r);
}

int calcCost(int n, int a[n], int numItems)
{
    int cost = 0;
    f2(i,1,numItems)
        cost += (a[i]+i*numItems);
    
    return cost;
}

int maxItems(int n, int a[n], int budget)
{
    int l = 0;
    int r = n;
    int m;

    while(l<r)
    {
        m = (l+r)/2;

        // int costL = calcCost(n,a,m-1);
        cost = calcCost(n,a,m);
        // int costG = calcCost(n,a,m+1);
        // p(cost);
        // printf("l:%d m:%d r:%d cost:%d", l, m, r, cost);

        if(cost>budget)
            r = m;
        else if(cost<=budget)
            l = m+1;
    }
    // p(cost);
    return m;
}

int main()
{
    int n, budget;
    s(n); s(budget);

    int a[n];
    f2(i,1,n)
        s(a[i]);
    
    qsort(a+1,n,sizeof(int),cmp);

    p(maxItems(n,a,budget));
    p(cost);
}
/* testcase

5 25
5 4 1 2 6
ans : 3 25

*/`
