#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define d(x) printf("%d", x);
#define f(i,x,y) for(int i=x;i<y;i++)

bool isColMax(int n, int a[n][n], int minRowVal, int col)
{

    for(int k=0;k<n;k++)
        if(minRowVal<a[k][col])
            return false;
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);

    int a[n][n];
    int notFound = 1;
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
            if(minRowVal>a[i][j])
                minRowVal = a[i][j];

        for(int col=0;col<n;col++)
        {
            if(a[i][col]==minRowVal)
                if(isColMax(n, a, minRowVal, col))
                {
                    notFound = 0;
                    printf("%d,%d|%d\n",i,col,minRowVal);
                }
                    
        }
    }

    if(notFound)
        printf("Saddle Point not found");
    
    return 0;
}