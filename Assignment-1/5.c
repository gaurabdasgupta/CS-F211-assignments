#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define d(x) printf("%d", x);
#define f(i,x,y) for(int i=x;i<y;i++)
#define null NULL

typedef struct Node{
    struct Node* next;
    int val;
}node;

node* head;

void printList(node* head)
{
    while(head!=null)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

node* createNode(int x)
{
    node* nd = (node*)malloc(sizeof(node));
    nd->val = x;
    nd->next = null;
    return nd;
}

void push(node* head, int x)
{
    while(head->next!=null)
        head=head->next;
    head->next = createNode(x);
}

void search(int x)
{
    int i=1;
    node* trv = head;
    while(trv!=null)
    {
        if(trv->val==x)
            printf("Found at: %d node\n",i);
        trv=trv->next;
        i++;
    }
}

void delete(int x)
{
    bool found = false;
    node* trv = head;
    while(trv!=null)
    {
        if(trv->next->val==x)
        {
            if(!found)
                found = true;
            else
            {
                trv->next = trv->next->next; 
            }
        }
        trv=trv->next;

    }
}

void swap(int x)
{
    node* prev = head;
    node* curr = head->next;
    while(curr!=null&&curr->next!=null)
    {
        if(curr->val==x)
        {
            node* tmp = curr->next;
            curr->next = prev;
            prev->next = tmp;
            head = curr;
            return;
        }
        if(curr->next->val==x)
        {
            node* tmp = curr->next->next;
            prev->next = curr->next;
            curr->next->next = curr;
            curr->next = tmp;
            return;
        }
        prev = prev->next;
        curr = curr->next;
    }
}



int main()
{
    int n;
    scanf("%d", &n);
    int t;
    scanf("%d", &t);
    head = createNode(t);

    f(i,0,n-1)
    {
        int x;
        scanf("%d", &x);
        push(head, x);
    }
    
    delete(3);
    printList(head);
    swap(3);
    printList(head);
}