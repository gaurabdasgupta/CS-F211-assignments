#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define d(x) printf("%d",x);
#define f(i,x,y) for(int i=x;i<y;i++)
#define null NULL

int nodeNum, edgeNum;
int g[100][100];
int cycleNum = 0;

void dfs(int node, int par, int col[nodeNum], int mark[nodeNum], int parent[nodeNum])
{  
    if(col[node]==2)
    {   
        d(122)
        return;
    }
    
    if(col[node]==1)
    {
        cycleNum++;
        d(cycleNum)
        printf("assd");
        int curr = par;
        mark[curr] = cycleNum;
        while(curr!=node)
        {
            curr = parent[curr];
            mark[curr] = cycleNum;
        }
        return;
    }

    d(122)
    parent[node] = par;
    col[node] = 1;

    f(i,0,nodeNum)
    {
        if(g[node][i])
        {
            if(i == parent[node])
                continue;
            dfs(i,node,col,mark,parent);
        }
    }
    col[node] = 2;
    // d(cycleNum)
}

void calcMinWeight(int mark[nodeNum])
{
    f(i,0,cycleNum)
    {
        f(j,0,nodeNum)
        {
            if(mark[j]==i)
                printf("%d ", j);
        }
        printf("\n");
    }
}

void addEdge(int x, int y)      
{
    g[x-1][y-1] = 1;
    // g[y-1][x-1] = 1;
}

int main()
{
    // scanf("%d", &nodeNum);
    nodeNum = 13;
    memset(g,0,sizeof(g));
    // f(i,0,nodeNum)
    //     f(j,0,nodeNum)
    //         scanf("%d",&g[i][j]);
    addEdge(1, 2); 
    addEdge(2, 3); 
    addEdge(3, 4); 
    addEdge(4, 6); 
    addEdge(4, 7); 
    addEdge(5, 6); 
    addEdge(3, 5); 
    addEdge(7, 8); 
    addEdge(6, 10); 
    addEdge(5, 9); 
    addEdge(10, 11); 
    addEdge(11, 12); 
    addEdge(11, 13); 
    addEdge(12, 13);
    
    f(i,0,nodeNum){ f(j,0,nodeNum) printf("%d ",g[i][j]); printf("\n");}
    // isCycle(g, nodeNum) ? printf("Yes") : printf("No");
    // int cycleNum = 0;
    int col[nodeNum], mark[nodeNum], parent[nodeNum];
    f(i,0,nodeNum)
    {
        col[i] = 0;
        mark[i] = 0;
        parent[i] = 0;
    }

    dfs(1,0,col,mark,parent);
    d(cycleNum)
    // calcMinWeight(mark);
}