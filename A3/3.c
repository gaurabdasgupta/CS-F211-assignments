#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>

#define null NULL
#define f(i,x,y) for(int i=x;i<y;i++)

typedef struct Node{
    int val;
    struct Node* next;
}node;

node* createNode(int x)
{
    node* t = (node*)malloc(sizeof(node));
    t->val = x;
    t->next = null;
    return t;
}

void insert(node** head, int x)
{
    node* trv = *head;
    while(trv->next!=null)
        trv=trv->next;
    trv->next = createNode(x);
}

node* reverseList(node** head)
{
    node* prev = null;
    node* curr = *head;
    while(curr!=null)
    {
        node* t = curr->next;
        curr->next = prev;
        prev = curr;
        curr = t;
    }
    
    return prev;
}

void printList(node** head)
{
    node* trv = *head;
    while(trv!=null)
    {       
        printf("%d ", trv->val);
        trv = trv->next;
    }
}

int main()
{
    int k;
    scanf("%d", &k);

    node* head;
    node* newHead;

    int t;
    scanf("%d ", &t);
    head = createNode(t);

    int i=2;
    while(1)
    {        
        int v;
        char c;
        scanf("%d%c", &v, &c);
        if(i==k)
            newHead = createNode(v);
        else if(i%k==0)
            insert(&newHead, v);
        else
            insert(&head, v);
        i++;
        if(c=='\n')
            break;
    }

    node* tmp = newHead;
    while(tmp->next!=null)
        tmp = tmp->next;
    tmp->next = reverseList(&head);

    printList(&newHead);
}