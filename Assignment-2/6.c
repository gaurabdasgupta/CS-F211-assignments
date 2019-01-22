#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<limits.h>

#define d(x) printf("%d",x);
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)
#define null NULL

int g[1000][1000], vis[1000]={0};
int n, npr;

void addEdge(int g[n][n], int i, int j)
{
    g[i][j]=1;
    g[j][i]=1;
}

void dfs(int gpr[npr][npr], int x)
{
	vis[x]=1;
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
			printf("break points: %d\n",i );		
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
    // npr = n;
    //     int gpr[npr][npr];
    // memset(gpr,0,sizeof(gpr));
    // f1(i,0,p)
    // {
    //     int x,y;
    //     scanf("%d %d", &x, &y);
    //     addEdge(gpr, x,y);
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

    int mem[npr];
    memset(mem,0,sizeof(mem));

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
			printf("answer: %d\n",i);

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

