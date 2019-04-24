#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int* l, int* r)
{
    int t = *r;
    *r = *l;
    *l = t;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int l[m], r[m], c[m], pos[n];
        for(int i=0;i<n;i++)
            pos[i] = 0;
        int p, q, s;
        scanf("%d %d %d %d %d %d", &l[0], &r[0], &c[0], &p, &q, &s);
        for(int i=1;i<m;i++)
        {
            l[i] = (l[i-1]*p + r[i-1])%n + 1;
            r[i] = (r[i-1]*q + l[i-1])%n + 1;
            if(l[i]>r[i])
                swap(&l[i], &r[i]);

            c[i] = (c[i-1]*s)%1000000 + 1;
        }

        for(int i=0;i<m;i++)
            for(int j=l[i];j<=r[i];j++)
                pos[j]+=c[i];
                
        int res = 0;
        int idx = 0;
        for(int i=0;i<n;i++)
        {
            // printf("%d ", pos[i]);
            if(pos[i]>res)
            {
                res = pos[i];
                idx = i;
            }
        }

        printf("%d %d", idx, res);
    }
}