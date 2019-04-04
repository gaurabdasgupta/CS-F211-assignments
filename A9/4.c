#include<stdio.h>
#include<stdlib.h>

int f(int n, int* diff){
  for (int i = 0; i < n; i++) {
    int sum = 0;
    int j = 0;
    int start = i;
    while (sum >= 0 && j < n) {
      sum += diff[start];
      start = (start + 1)%n;
      j++;
    }
    if (j == n) return i;
  }
  return -1;
}

int main(){
  int n;
  scanf("%d", &n);
  int *gas = (int*)malloc(n*sizeof(int));
  int *dist = (int*)malloc(n*sizeof(int));
  int *diff = (int*)malloc(n*sizeof(int));
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &gas[i], &dist[i]);
    diff[i] = gas[i] - dist[i];
  }
  printf("%d\n", f(n, diff));
  return 0;
}