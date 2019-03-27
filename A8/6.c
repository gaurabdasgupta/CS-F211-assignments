#include<stdio.h>
#include<stdlib.h>

#define min(a,b) ((a)<(b)?(a):(b))

typedef struct node{
  int val;
  int m;
  struct node* next;
}nd;

nd* head;

nd* createnode(int x, int mn)
{
  nd* t = (nd*)malloc(sizeof(nd));
  t->val = x;
  t->m = mn;
  t->next = NULL;
  return t;
}

void push(int x)
{
  nd* n = createnode(x, min(x,head->m));
  n->next = head;
  head = n;
}

void pop()
{
  head = head->next;
}

int top()
{
  return head->val;
}

int getMin()
{
  return head->m;
}

int main()
{
  int n;
  scanf("%d", &n);
  int v;
  scanf("%d", &v);
  head = createnode(v,v);
  for(int i=0;i<n-1;i++)
  {
    int v;
    scanf("%d", &v);
    push(v);
  }
  printf("%d\n", getMin());
  printf("%d\n", top());
  pop();
  printf("%d\n", getMin());
}
