#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define d(x) printf("%d",x)
#define f(i,x,y) for(int i=x;i<y;i++)
#define null NULL

int nodesNum;

bool colorGraph(int g[nodesNum][nodesNum],int pos,int color[nodesNum],int c)
{
    // to check if toBeAssignedColor == currentColor, if violated means that it fails for the node for which it was assigned to be c.
    if(color[pos]!=-1&&color[pos]!=c)
        return false;

    color[pos] = c;
    bool ans = true;

    f(i,0,nodesNum)
    {
        if(g[pos][i])
        {
            // to check if adjacent node has same color or not
            if(color[i]!=-1 && color[i]==c)
                return false;
            // assign opposite color
            if(color[i]==-1)
            {   
                ans &= colorGraph(g,i,color,1-c);
                if(!ans)
                    return false;
            }
                
        }
    }

    return true;
}

bool isBipartite(int g[nodesNum][nodesNum])
{
    int color[nodesNum];
    memset(color,-1,sizeof(color));
    return colorGraph(g, 0, color, 1);
}


int main()
{
    scanf("%d", &nodesNum);
    int g[nodesNum][nodesNum];
    memset(g,0,sizeof(g));
    f(i,0,nodesNum)
        f(j,0,nodesNum)
        {
            int val;
            scanf("%d",&val);
            g[i][j] = val;
            g[j][i] = val;
        }

    f(i,0,nodesNum){ f(j,0,nodesNum) printf("%d ",g[i][j]); printf("\n");}

    isBipartite(g) ? printf("Yes") : printf("No");


}