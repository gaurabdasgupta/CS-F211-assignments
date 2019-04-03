#include<stdio.h>
#include<stdlib.h>

int harr[100], idx;

int cmp(const void* l, const void* r)
{
  return *(int*)l - *(int*)r;
}

void insert(int x)
{
  harr[idx++] = x;
  qsort(harr, idx, sizeof(int), cmp);
}

int getMin()
{
  return harr[0];
}

void pop()
{
  for(int i=0;i<idx;i++)
    harr[i] = harr[i+1];
  idx--;
}

int main()
{
  idx = 0;
  // insert(1);
  // insert(3);
  // insert(2);
  // printf("%d\n", getMin());
  // insert(5);
  // insert(0);
  // pop();
  // pop();
  // printf("%d\n", getMin());
  // for(int i=0;i<idx;i++)
  //   printf("%d", harr[i]);
  int n;
  scanf("%d", &n);
  int a[n];
  for(int i=0;i<n;i++)
    scanf("%d", &a[i]);

  int sum = 0;
  int diff;
  for (int i = 0; i < n; i++) 
  {
    if (idx>0 && getMin() < a[i]) 
    {
      diff = a[i] - getMin();
      sum += diff;
      pop();
      // insert(a[i]);
    }
    insert(a[i]);
  }

    printf("%d\n",sum);
}
