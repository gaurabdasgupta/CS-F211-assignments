#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define s(x) scanf("%d", &x)
#define p(msg, x) printf("%s: %d\n", msg, x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)
#define min(a,b) ((a)<(b)?(a):(b))

int cmp(const void* l, const void* r)
{
    return (*(int*)l - *(int*)r);
}

int main()
{
    int n;
    s(n);
    int a[n];

    f1(i,0,n)
        s(a[i]);
    
    qsort(a,n,sizeof(int),cmp);

    int ans=INT_MAX;
    int i;
    f1(i,0,n)
    {
        if(a[i]==a[i+1])
            i++;
        int res=i;
        f1(j,i+1,n)
        {
            if(a[j]<=2*a[i]&&a[j-1]!=a[j])
                res++;
            else
                break;
        }
        
        ans = min(ans,n-(res-i)-1);
    }

    p("result", ans);
}

/* testcases:

4
1 1 9 9

4
2 2 2 3

4
2 3 3 3

*/