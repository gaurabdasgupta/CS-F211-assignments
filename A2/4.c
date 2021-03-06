#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define d(x) printf("%d",x);
#define f(i,x,y) for(int i=x;i<y;i++)
#define null NULL

typedef struct Node{
    int id;
    struct Node* next;
    struct Node* prev;
    int c;
    int col;
}node;

node* head;

int idNum = 0;
bool visited[1000];

node* createNode(int x)
{
    node* t = (node*)malloc(sizeof(node));
    t->id = x;
    t->next = null;
    t->prev = null;
    t->c = idNum++;
    return t;
}

node* getNode(int x)
{
    node* trv = head;
    while(trv->next!=null)
    {
        if(trv->id==x)
            return trv;
        else
            trv = trv->next;
    }

    return null;
}

void insert(int id, int prv, int nxt)
{
    node* newn = createNode(id);
    node *temp = head;
    if(temp==NULL || prv==0){
        head = newn;
        return;
    }
  
    while(temp->next!=NULL && temp->next->id!=nxt){
        temp = temp->next;
    }

    temp->next = newn;
    temp = head;

    while(temp->id!=prv){
        temp = temp->next;
    }
    newn->prev = temp;
    return;
}

void printList(node* head)
{
    while(head!=null)
    {
        printf("%d ", head->id);
        head = head->next;
    }
    printf("\n");
}

void printListColor(node* head)
{
    while(head!=null)
    {
        printf("%d ", head->col);
        head = head->next;
    }
    printf("\n");
}

void printCycle(node* start)
{
    node* nd = start;
    bool f = false;
    while(1)
    {
        if(nd->prev->id==start->id&&abs(nd->c - nd->prev->c)!=1&&f&&visited[nd->id]==0)
        {
            printf("%d %d",nd->id, start->id);
            break;
        }
        else
            printf("%d ", nd->id);
        
        nd=nd->next;
        f = true;
    }
}

void detectCycle(node* start)
{
    node* nd = start;
    while(nd!=null)
    {   
        d(nd->id);
        printf("\n");
        if(visited[nd->id]==0&&visited[nd->prev->id]==1&&abs(nd->c - nd->prev->c)!=1){
            visited[nd->id]=1;
            f(i,0,10)
                printf("%d", visited[i]);
            printf("\n");
            printCycle(nd->prev);
            nd = start; // resetd
            continue;
        }
        else{
            visited[nd->id]=1;
            nd=nd->next;
        }

    }
}

void colorList(node* head)
{
    node* nd = head;
    int available[100];
    nd->col = 1;
    available[1]=0;
    nd = nd->next;
    int prevCol = 1;
    while(nd!=null)
    {  
        for(int i=0;i<100;i++)
            available[i]=1;

        available[prevCol] = 0;
        available[nd->prev->col] = 0;

        int currCol;
        for(int i=1;i<100;i++)
        {
            if(available[i]==1)
            {
                currCol = i;
                break;
            }
        }

        nd->col = currCol;
        prevCol = nd->col;
        nd=nd->next;
    }

    printListColor(head);
}

int main()
{
    int x,y,z;
    memset(visited,0,sizeof(visited));
    while(1)
    {
        char c;
        scanf("%d %d %d%c",&x,&y,&z,&c);
        // d(x)d(y)d(z)
        insert(x,y,z);
        if(c=='q')
            break;
    }

    printList(head);
    detectCycle(head->next);
    colorList(head);

}

/*
testcases:

1 0 2
2 1 3
3 2 4
4 2 5
5 4 0q

1 0 2
2 1 3
3 1 4
4 2 5
5 3 6
6 5 7
7 3 0q

*/


