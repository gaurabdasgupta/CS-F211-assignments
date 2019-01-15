#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define d(x) printf("%d", x);
#define f(i,x,y) for(int i=x;i<y;i++)

int main()
{
    int n;
    scanf("%d", &n);

    int a[n][n];
    f(i,0,n)
    {        
        f(j,0,n)
            scanf("%d", &a[i][j]);
    }
    // f(i,0,n)
    // {    
    //     f(j,0,n)
    //         printf("%d ", a[i][j]);
    //     printf("\n");
    // }

    f(i,0,n)
    {
        int minRowVal = a[i][0], col = 0;
        int j, res;
        for(j=1;j<n;j++)
        {
            if(minRowVal>a[i][j])
            {
                minRowVal = a[i][j];
                col = j;
            }
        }
    
        int k;
        for(k=0;k<n;k++)
            if(minRowVal<a[k][col])
                break;

        if(k==n)
            res = minRowVal;


        f(l,0,n)
            if(a[i][l]==res)
                    printf("%d,%d|%d\n",i,l,res);
    }

}