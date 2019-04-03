#include<stdio.h>
#include<stdlib.h>

int cmp(const void* l, const void* r)
{
  return (*(int*)l - *(int*)r);
}

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  int a[n];
  for(int i=0;i<n;i++)
    scanf("%d", &a[i]);
  int res = 0, cnt=0;
  while(res<k)
  {
    qsort(a, n, sizeof(int), cmp);
    int swt = a[0]+2*a[1];
    int i;
    for(i=0;i<n-2;i++)
      a[i]=a[i+2];
    a[i++] = swt;
    res+=swt;
    cnt++;
  }
  printf("%d\n",cnt);
}
