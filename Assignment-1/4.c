#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define d(x) printf("%d", x);
#define f(i,x,y) for(int i=x;i<y;i++)
#define null NULL

typedef struct slNode{
    struct slNode* next;
    int val;
}slnode;

typedef struct dlNode{
    struct dlNode* next;
    struct dlNode* prev;
    int val;
}dlnode;

slnode* head;
dlnode* headDL;
dlnode* tailDL;

void printList(dlnode* head)
{
    while(head!=null)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

slnode* createSLNode(int x)
{
    slnode* nd = (slnode*)malloc(sizeof(slnode));
    nd->val = x;
    nd->next = null;
    return nd;
}

dlnode* createDLNode(int x)
{
    dlnode* nd = (dlnode*)malloc(sizeof(dlnode));
    nd->val = x;
    nd->prev = null;
    nd->next = null;
}

void pushSL(slnode* head, int x)
{
    while(head->next!=null)
        head=head->next;
    head->next = createSLNode(x);
}

void pushDL(int x)
{
    dlnode* trv = headDL;
    while(trv->next!=null)
        trv=trv->next;
    dlnode* newn = createDLNode(x);
    trv->next = newn;
    newn->prev = trv;
    tailDL = newn;

}

void findKthSL(int k)
{
    slnode* f;
    slnode* s;
    f = head;
    s = head;
    f(i,0,k)
    s=s->next;

    while(s!=null)
    {
        f=f->next;
        s=s->next;
    }

    printf("%d\n", f->val);
}

void findKthDL(int k)
{
    dlnode* trv = tailDL;
    while(trv!=null&&k--)
        trv=trv->prev;
    printf("%d\n", trv->val);
}


int main()
{
    int n,k;
    scanf("%d %d", &n, &k);
    int t;
    scanf("%d", &t);
    // head = createSLNode(t);
    headDL = createDLNode(t);
    f(i,0,n-1)
    {
        int x;
        scanf("%d", &x);
        pushDL(x);
    }
    findKthDL(k);
    printList(headDL);
    
}