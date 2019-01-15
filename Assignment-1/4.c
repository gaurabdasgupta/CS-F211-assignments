#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

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
slnode* headCL;
slnode* tailCL;

void printList(slnode* head)
{
    while(head!=null)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void printListDL(dlnode* head)
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

void pushCL(int x, int i)
{
    slnode* tmp = createSLNode(x);
    if(i==0)
        headCL->next=tmp;
    tailCL->next = tmp;
    tmp->next = headCL;
    tailCL = tmp;
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

void findKthCL(int k)
{

}

int main()
{
    char type[100];
    int k;
    scanf("%s",type);
    scanf("%d", &k);

    if(strcmp(type,"single")==0)
    {
        int t;char l;
        int len=0;
        scanf("%d%c", &t,&l);
        head = createSLNode(t);
        while(1)
        {
            int nd;
            char c;
            scanf("%d%c", &nd, &c);
            pushSL(head, nd);
            if(c=='\n')
                break;
            else
                len++;
        }
        len++;
        if(k>len)
            printf("Value of K has exceeded the limit");
        else
            findKthSL(k);
        printList(head);
    }
    else if(strcmp(type,"double")==0)
    {
        int t;char l;
        int len=0;
        scanf("%d%c", &t,&l);
        headDL = createDLNode(t);
        tailDL = headDL;
        while(1)
        {
            int nd;
            char c;
            scanf("%d%c", &nd, &c);
            pushDL(nd);
            if(c=='\n')
                break;
            else
                len++;
        }
        len++;
        if(k>len)
            printf("Value of K has exceeded the limit");
        else
            findKthSL(k);       
        printListDL(headDL);
    }
    else if(strcmp(type,"circular")==0)
    {
        int t;char l;
        int len=0;
        scanf("%d%c", &t,&l);
        headCL = createSLNode(t);
        tailCL = headCL;
        for(int i=0;;i++)
        {
            int nd;
            char c;
            scanf("%d%c", &nd, &c);
            pushCL(nd,i);
            if(c=='\n')
                break;
            else
                len++;
        }
        len++;
        findKthDL(k); // TODO: circular find kth node
        printListDL(headCL);        
    }
    else
        return 0;
}