#include<stdio.h>
#include<stdlib.h>

double minHeap[100], maxHeap[100];
int minIdx, maxIdx;

// MIN HEAP
int cmp1(const void* l, const void* r)
{
  return *(double*)l - *(double*)r;
}

void insertMin(double x)
{
  minHeap[minIdx++] = x;
  qsort(minHeap, minIdx, sizeof(double), cmp1);
}

double getMin()
{
  return minHeap[0];
}

void popMin()
{
  for(int i=0;i<minIdx;i++)
    minHeap[i] = minHeap[i+1];
  minIdx--;
}

// MAX HEAP
int cmp2(const void* l, const void* r)
{
  return *(double*)r - *(double*)l;
}

void insertMax(double x)
{
  maxHeap[maxIdx++] = x;
  qsort(maxHeap, maxIdx, sizeof(double), cmp2);
}

double getMax()
{
  return maxHeap[0];
}

void popMax()
{
  for(int i=0;i<maxIdx;i++)
   maxHeap[i] =maxHeap[i+1];
  maxIdx--;
}

int main()
{
    int n;
    scanf("%d", &n);
    double stream[n];
    for(int i=0;i<n;i++)
        scanf("%lf", &stream[i]);
    minIdx = 0, maxIdx = 0;
    double med = stream[0];
    insertMax(stream[0]);

    printf("%lf\n", med);

    for(int i=1;i<n;i++)
    {
      double x = stream[i];

      if(maxIdx > minIdx)
      {
        if(x<med)
        {
            insertMin(getMax());
            popMax();
            insertMax(x);
        }
        else
            insertMin(x);
        
        med = (getMax()+getMin())/2.0;
      }
      else if(maxIdx < minIdx)
      {
          if(x<med)
          {
              insertMax(getMin());
              popMin();
              insertMin(x);
          }
          else
              insertMax(x);
          
          med = (getMax()+getMin())/2.0;
      }
      else
      {
          if(x<med)
          {
              insertMax(x);
              med = getMax();
          }
          else
          {
              insertMin(x);
              med = getMin();
          }
      }

      printf("%lf\n", med);
    }
}