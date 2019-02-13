#include<stdio.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d\n", x)
#define f(i,x,y) for(int i=x;i<y;i++)

int main()
{
 int n;
    s(n);

    f(i,0,n)
        s(a[i]);
    
    // O(logn) approach
    
    int l = 0, r = n-1, ans=0;
    int m;
    while(l<=r)
    {
        m = (r+l)/2;

        if(m%2==0)
        {
            if(a[m]==a[m+1])
                l = m+1;
            else if(a[m]==a[m-1])
                r = m-1;
            else
                break;
        }
        else
        {
            if(a[m]==a[m+1])
                r = m-1;
            else if(a[m]==a[m-1])
                l = m+1;
            else
                break;   
        }        
    }

    p(a[m]);


}