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
    struct Node* 
}node;

node* createNode(int x)
{
    node* t = (node*)malloc(sizeof(node));
    t->id = x;
    t->next = null;
    t->prev = null;
    return t;
}

int main()
{
    int 
}