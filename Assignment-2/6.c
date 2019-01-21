#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<limits.h>

#define d(x) printf("%d",x);
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)
#define null NULL

int g[1000][1000];
int n, npr;

int main()
{
    scanf("%d", &n);
    int k = 0;
    f1(i,0,n) 
        f1(j,0,n)
        { 
            int x;
            scanf("%d", &x);
            if(j>i)
            {
                if(x==1)
                {
                    npr++;
                    g[i][j] = k++;
                }
                else
                    g[i][j] = -1;
            }
            else if(i==j)
                g[i][j]=-1;
            else
                g[i][j]= g[j][i];

        }

    npr=k;

    int gpr[npr][npr];
    memset(gpr,0,sizeof(gpr));

    // f1(i,0,n) 
    // {
    //     f1(j,0,n) 
    //         printf("%d ", g[i][j]);
    //     printf("\n");
    // }

    f1(i,0,n)
        f1(j,0,n)
            if(g[i][j]!=-1)
                f1(k,j+1,n)
                    if(j!=k&&g[i][k]!=-1)
                    {
                        gpr[g[i][j]][g[i][k]] =1;
                        gpr[g[i][k]][g[i][j]] =1;
                    }


    // f1(i,0,npr) 
    // {
    //     f1(j,0,npr) 
    //         printf("%d", gpr[i][j]);
    //     printf("\n");
    // }

}