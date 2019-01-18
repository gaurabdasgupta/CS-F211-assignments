#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define d(x) printf("%d", x);
#define f(i,x,y) for(int i=x;i<y;i++)
#define null NULL

void swapNodes(int* x, int* y)
{
    int tmp = *y;
    *y = *x;
    *x = tmp;
}

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
    node* trv = head;
    while(trv->next!=null)
    {
        if(trv->val==x)
        {
            swapNodes(&trv->val,&trv->next->val);
            return;
        }
        trv = trv->next;
    }
    printf("Swapping Not Possible\n");

}

int main()
{
    int t, len=0;
    scanf("%d", &t);
    head = createNode(t);
    for(int i=0;;i++)
    {        
        int x;char c;
        scanf("%d%c", &x, &c);
        push(head, x);
        if(c=='\n')
            break;
        else
            len++;
    }
    // delete(3);
    // printList(head);
    swap(5);
    printList(head);
}