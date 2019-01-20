#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<limits.h>

#define d(x) printf("%d",x);
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)
#define null NULL

int g[100][100], uni[100], vis[100], dist[100], parent[100], n, c, result[100];

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

void bfs(q* q, int s)
{
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
                    enq(q, i);
                }
            }
        }
    }
}

void addEdge(int u, int v)
{
    g[u][v] = 1;
    g[v][u] = 1;
}

int main()
{
    c=0;
    q* w = createQ();
    int m;
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
    scanf("%d",&m);
    f1(i,0,m)
    {
        int d;
        scanf("%d",&d);
        uni[d]=1;
    }

    addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(1, 3); 
    addEdge(1, 4); 
    addEdge(4, 5); 
    addEdge(4, 6);
    addEdge(0, 7); 
    addEdge(7, 8);

    bfs(w,0);
    int res = INT_MAX;
    f1(i,0,n)
    {
        if(uni[i])
        {
            if(dist[i]<res)
                res = dist[i];
        }
    }
    f1(i,0,n)
        if(dist[i]==res&&uni[i])
        {
            printf("%d", i);
            return 0;
        }
}