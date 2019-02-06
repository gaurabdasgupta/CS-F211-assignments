#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<limits.h>

#define d(x) printf("%d",x);
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)
#define null NULL

int g[1000][1000], vis[1000]={0}, componentV[1000];
int n, npr;

// void addEdge(int g[n][n], int i, int j)
// {
//     g[i][j]=1;
//     g[j][i]=1;
// }

void dfs(int gpr[npr][npr], int x)
{
	vis[x]=1;
    componentV[x]=1;
	for(int i=0;i<npr;i++)
		if(gpr[x][i]==1&&vis[i]!=1)
			dfs(gpr, i);
}

bool isArticulationPoint(int gpr[npr][npr], int u)
{
	int components=0;
	for(int i=0;i<npr;i++)
	{
		if(vis[i]==0)
		{
			dfs(gpr, i);
            components++;
            if(components>1)
            {
                int compMat[1000][1000];
                memset(compMat,0,sizeof(compMat));
                f1(i,0,npr) f1(j,0,npr) compMat[i][j]= gpr[i][j];

                for(int i=0;i<npr;i++)
                {
                    if(componentV[i]==0) //whichever nodes are not set, uska rows and columns are set to -1
                    {
                        for(int j=0;j<npr;j++)
                        {                        
                            compMat[i][j]=-1; 
                            compMat[j][i]=-1; 
                        }
                    }
                }

                // f(i,0,n){ f(j,0,n) printf("%d ",compMat[i][j]); printf("\n");}
                f1(i,0,npr)
                {
                    f1(j,0,npr)
                    {
                        if(compMat[i][j]!=-1)
                            printf("%d ", compMat[i][j]);
                    }
                    printf("\n");
                }
                memset(componentV,0,sizeof(componentV));
                printf("------\n");	
            }
            
				
		}
	}

	for(int i=0;i<npr;i++)
		vis[i]=0;
	if(u==0)
		components-=1;
	if(components > 1){
		printf("#components: %d\n",components);
		return true;
	}
	return false;
}

void addEdge(int g[npr][npr], int x, int y)
{
    g[x][y]=1;
    g[y][x]=1;
}

int main()
{
    // n = 7;
    // scanf("%d", &n);
    // int k = 0;
    // f1(i,0,n) 
    //     f1(j,0,n)
    //     { 
    //         int x;
    //         scanf("%d", &x);
    //         if(j>i)
    //         {
    //             if(x==1)
    //             {
    //                 npr++;
    //                 g[i][j] = k++;
    //             }
    //             else
    //                 g[i][j] = -1;
    //         }
    //         else if(i==j)
    //             g[i][j]=-1;
    //         else
    //             g[i][j]= g[j][i];

    //     }

    // npr=k;
    npr = 7;
    int gpr[npr][npr];
    memset(gpr,0,sizeof(gpr));
    // f1(i,0,p)
    // {
    //     int x,y;
    //     scanf("%d %d", &x, &y);
    //     addEdge(gpr, x,y);
    // }

    // f1(i,0,n)
    //     f1(j,0,n)
    //         if(g[i][j]!=-1)
    //             f1(k,j+1,n)
    //                 if(j!=k&&g[i][k]!=-1)
    //                 {
    //                     gpr[g[i][j]][g[i][k]] =1;
    //                     gpr[g[i][k]][g[i][j]] =1;
    //                 }

    addEdge(gpr, 0,1);
    addEdge(gpr, 0,3);
    addEdge(gpr, 0,4);
    addEdge(gpr, 3,4);
    addEdge(gpr, 1,2);
    addEdge(gpr, 2,5);
    addEdge(gpr, 2,6);
    addEdge(gpr, 5,6);

    int mem[npr];
    memset(mem,0,sizeof(mem));

    f1(i,0,npr){ f1(j,0,npr) printf("%d ", gpr[i][j]); printf("\n");}
    printf("\n");

    for(int i=0;i<npr;i++)
	{
		for(int j=0;j<npr;j++)
		{
			if(gpr[i][j]==1)
			{
				mem[j]=1;
				gpr[i][j]=0;
			}
		}

		if(isArticulationPoint(gpr, i))
			break;

		for(int k=0;k<npr;k++)
		{
			if(mem[k]==1)
			{
				gpr[i][k]=1;
				mem[k]=0;
			}
		}

	}

}

