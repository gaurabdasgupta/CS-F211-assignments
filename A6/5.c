#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d ", x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)

typedef struct n{
    int val;
    struct n* next;
}node;

node* createNode(int x)
{
    node* tmp = (node*)malloc(sizeof(node));
    tmp->val = x;
    tmp->next = NULL;
    return tmp;
}

void insert(node* head, int x)
{
    node* trv = head;
    while(trv->next!=NULL)
    {
        trv=trv->next;
    }
    trv->next = createNode(x);
}

void printList(node* head)
{
    while(head!=NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void merge(node* h1, node* h2)
{
    node* head;
    node* trv1;
    node* trv2;
    if(h1->data<*h2->data)
    {
        head = h1;
        trv1 = h1->next;
        trv2 = h2;
    }
    else
    {
        head = h2;
        trv2 = h2->next;
        trv1 = h1;
    }

    while()

}

int main()
{
    int n1, n2;
    s(n1);
    int h;
    s(h);
    node* h1 = createNode(h);
    f1(i,0,n1-1)
    {
        int t;
        s(t);
        insert(h1, t);
    }
    s(n2);
    s(h);
    node* h2 = createNode(h);
    f1(i,0,n2-1)
    {
        int t;
        s(t);
        insert(h2, t);
    }

    // printList(h1);
    // printList(h2);

    // merge(&h1, &h2);

}