#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<limits.h>

#define d(x) printf("%d",x);
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)
#define null NULL

int g[100][100], uni[100], vis[100], dist[100], parent[100], n,diameter, result[100];

typedef struct Node{
    int val;
    struct Node* next;
}node;

typedef struct Queue{
    node* front;
    node* rear;
    int size;   
}q;

node* createNode(int x)
{
    node* t = (node*)malloc(sizeof(node));
    t->val = x;
    t->next = NULL;
    return t;
}

q* createQ()
{
    q* t = (q*)malloc(sizeof(q));
    t->rear = null;
    t->front = null;
    return t;
}

void enq(q* qu, int x)
{
    node* t = createNode(x);
    if(qu->rear == null)
    {
        // d(121212)
        qu->front = qu->rear = t;
        return;
    }
    qu->rear->next = t;
    qu->rear = t;
}

node* deq(q* q)
{
    if(q->front == null)
        return null;
    
    node* t = q->front;
    q->front = q->front->next;

    if(q->front==null)
        q->rear = null;
    return t;
}

bool isEmpty(q* q)
{
    // d(222)
    if(q->rear==null)
        return true;
    return false;
}

void addEdge(int u, int v)
{
    g[u][v] = 1;
    g[v][u] = 1;
}

bool bfs(q* q, int s, int dest)
{
    // init
    memset(vis,0,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    f1(i,0,n)
        dist[i]=INT_MAX;
    
    vis[s] = 1;
    dist[s] = 0;
    enq(q,s);

    while(!isEmpty(q))
    {
        s = deq(q)->val;
        f1(i,0,n)
        {
            if(g[s][i])
            {
                if(!vis[i])
                {
                    vis[i] = 1;
                    dist[i] = dist[s]+1;
                    parent[i] = s;
                    enq(q, i);
                    if(i == dest)
                        return true;
                }
            }
        }
    }

    return false;
}

void printShortestDistance(int u, int v)
{
    q* w = createQ();
    printf("Shortest Path for %d and %d:\n", u, v);
    if(!bfs(w,u,v))
    {
        printf("Self Loop\n");
        return;
    }

    int crawl = v;
    int path[n];
    memset(path,-1,sizeof(path));
    int i=0;
    // path[i++] = crawl;
    while(parent[crawl]!=-1)
    {
        path[i++] = crawl;
        crawl = parent[crawl];
    }

    printf("%d ",u);
    for(int j=i-1;j>=0;j--)
        printf("%d ", path[j]);
    
    printf("\n");

    if(dist[v]>diameter)
        diameter = dist[v];
}

int main()
{
    diameter=INT_MIN;
    scanf("%d", &n);
    memset(g,0,sizeof(g));
    memset(result,0,sizeof(result));

    // f2(i,1,n)
    // {
    //     int u,v;
    //     scanf("%d %d",&u,&v);
    //     g[u][v] = 1;
    //     g[v][u] = 1;
    // }
    // scanf("%d",&t);

    addEdge( 0, 1); 
    addEdge( 0, 3); 
    addEdge( 1, 2); 
    addEdge( 3, 4); 
    addEdge( 3, 7); 
    addEdge( 4, 5); 
    addEdge( 4, 6); 
    addEdge( 4, 7); 
    addEdge( 5, 6); 
    addEdge( 6, 7);

    f1(i,0,n)  
    {
        f1(j,0,n)
        {
            if(i>=j)
                printShortestDistance(i,j);
        }    
    } 
    printf("Diameter of the given graph: %d", diameter);
}