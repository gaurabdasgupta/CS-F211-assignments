#include<stdio.h>
#include<stdlib.h>

typedef struct i{
    int pf;
    int cp;
}pr;

int cmp(const void* l, const void* r)
{
    pr* a = (pr*)l;
    pr* b = (pr*)r;
    return a->pf - b->pf;
}

int main()
{
    int k,w,n;
    scanf("%d %d %d", &k, &w, &n);
    int rtn = w;
    int profit[n], capital[n];
    for(int i=0;i<n;i++)
        scanf("%d", &profit[i]);
    
    for(int i=0;i<n;i++)
        scanf("%d", &capital[i]);
    
    pr arr[n];
    for(int i=0;i<n;i++)
    {
        pr t;
        t.pf = profit[i];
        t.cp = capital[i];
        arr[i] = t;
    }

    qsort(arr, n, sizeof(pr), cmp);

    for(int i=0;i<k;i++)
    {
        for(int p = n-1;p>=0;p--)
        {
            if(rtn>=arr[p].cp)
            {
                rtn += arr[p].pf;
                arr[p].pf = 0;
                qsort(arr, n, sizeof(pr), cmp);
                break;
            }
        }
    }

    printf("%d\n", rtn);
}