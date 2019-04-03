#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
  char c;
  struct node* next;
}nd;

nd* head;
int size;

nd* createNode(char x)
{
  nd* n = (nd*)malloc(sizeof(nd));
  n->c = x;
  n->next = NULL;
  return n;
}

void push(int x)
{
  nd* tmp = createNode(x);
  tmp->next = head;
  head = tmp;
  size++;
}

void pop()
{
  head = head->next;
  size--;
}

char top()
{
  return head->c;
}

char findClosing(char c)
{
  if(c=='(')
    return ')';
  else if(c=='{')
    return '}';
  else
    return ']';
}

int main()
{
  size = 0;
  char str[100];
  scanf("%s", str);
  head = createNode(str[0]);
  size++;

  for(int i=1;i<strlen(str);i++)
  {
    if(size>0 && str[i] == findClosing(top()))
      pop();
    else
      push(str[i]);
  }

  printf("%d\n",size );

  if(size==0)
    printf("valid\n");
  else
    printf("invalid\n");
}
