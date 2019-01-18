#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define d(x) printf("%d",x);
#define f(i,x,y) for(int i=x;i<y;i++)
#define null NULL

int nodeNum, edgeNum;

bool isCyclicUtil(int g[nodeNum][nodeNum],int pos, bool visited[nodeNum], bool stack[nodeNum])
{
    if(visited[pos]==false)
    {    
        visited[pos] = true;
        stack[pos] = true;

        f(i,0,nodeNum)
        {
            if(g[pos][i])
            {
                d(i)
                if(!visited[i] && isCyclicUtil(g,i, visited, stack))
                    return true;
                else if(stack[i])
                    return true;
            }
        }

    }

    stack[pos] = false;
    return false;
}

bool isCycle(int g[nodeNum][nodeNum], int nodeNum)
{

    bool visited[nodeNum], stack[nodeNum];
    f(i,0,nodeNum)
    {
        visited[i] = false;
        stack[i] = false;
    }

    f(i,0,nodeNum)
        if(isCyclicUtil(g,i, visited, stack))
            return true;
    
    return false;
}

int main()
{
    scanf("%d", &nodeNum);
    int g[nodeNum][nodeNum];
    memset(g,0,sizeof(g));
    f(i,0,nodeNum)
        f(j,0,nodeNum)
            scanf("%d",&g[i][j]);
    f(i,0,nodeNum){ f(j,0,nodeNum) printf("%d ",g[i][j]); printf("\n");}
    isCycle(g, nodeNum) ? printf("Yes") : printf("No");
    
}