#include<stdio.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d\n", x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)

void swap(int* a, int* b)
{
    int t = *b;
    *b = *a;
    *a = t;
}

int binSearch(int n, int a[n], int l, int r, int key)
{
    while(l<=r)
    {
        int m = (r+l)/2;

        if(a[m]==key)
            return m;
        else if(a[m]<key)
            l = m+1;
        else
            r = m-1;
    }

    return -1;
}

int main()
{
    int n, pre, post;
    s(n);
    int a[n];
    f2(i,1,n)
        s(a[i]);
    f2(i,1,n)
        if(a[i]>a[i+1])
        {
            pre = a[i], post = a[i+1];
            swap(&a[i], &a[i+1]);
            break;
        }
    
    int key;
    s(key);
    int ans = binSearch(n,a,1,n,key);
    
    if(key==pre)
        printf("1: %d", ans-1);
    else if(key==post)
        printf("2: %d", ans+1);
    else if(ans!=-1)
        p(ans);
    else
        p(-1);
}