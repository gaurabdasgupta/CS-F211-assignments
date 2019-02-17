#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define s(x) scanf("%d", &x)
#define p(msg, x) printf("%s: %d\n", msg, x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)

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

    int left = 2;
    int right=left+1;
    for(int i=left;i>=0;i--)
    {
        while(a[right]<=2*a[i]&&right<n-1)
        {
            printf("%d %d", i, right);
            right++;
        }
        printf("\n");
    }

    p("l",left);
    p("r", right);
}