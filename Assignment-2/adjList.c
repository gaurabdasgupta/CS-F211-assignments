#include<stdio.h>
#include<stdlib.h>

#define d(x) printf("%d",x)
#define f(i,x,y) for(int i=x;i<y;i++)
#define null NULL

typedef struct Node{
    int val;
    struct Node* next;
}node;

typedef struct Graph{
    int nodes;
    node** arr;
}graph;

node* createNode(int x)
{
    node* tmp = (node*)malloc(sizeof(node));
    tmp->val = x;
    tmp->next = null;
    return tmp;
}

graph* createGraph(int numNodes)
{
    graph* tmp = (graph*)malloc(sizeof(graph));
    tmp->nodes = numNodes;
    tmp->arr = (node**)malloc(numNodes*sizeof(node*));
    f(i,0,numNodes)
        tmp->arr[i] = null;
    return tmp;
}

void addEdge(graph* g, int src, int dst)
{
    node* tmp = createNode(dst);
    tmp->next = g->arr[src];
    g->arr[src] = tmp;

    tmp = createNode(src);
    tmp->next = g->arr[dst];
    g->arr[dst] = tmp;
}

void printGraph(graph* g)
{
    f(i,0,g->nodes)
    {
        node* d = g->arr[i];
        printf("AdjList of %d: ",i);
        while(d!=null)
        {
            printf("%d ", d->val);
            d=d->next;
        }
        printf("\n");
    }
}

int main()
{
    graph* g = createGraph(6);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 1, 4);
    addEdge(g, 1, 3);
    addEdge(g, 2, 4);
    addEdge(g, 3, 4);
    addEdge(g, 4, 6);
    addEdge(g, 5, 1);
    addEdge(g, 5, 6);

    printGraph(g);
}

