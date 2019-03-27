#include<stdio.h>
#include<limits.h>

int main()
{
  int n, res = 0;
  scanf("%d", &n);
  int a[n];
  for(int i=0;i<n;i++)
    scanf("%d", &a[i]);
  for(int i=0;i<n;i++)
  {
    for(int j=i;j<n;j++)
    {
        int mn = INT_MAX;
        for(int k=i;k<=j;k++)
        {

          if(a[k]<mn)
            mn = a[k];
        }
        res+=mn;
    }
  }
  printf("%d\n", res);
}
