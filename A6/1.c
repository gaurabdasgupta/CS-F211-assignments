#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);
#define p2(x, y) printf("%d %d\n", x, y);

int swap(int *a, int *b){
	 int temp = *a;
	 *a = *b;
	 *b = temp;
}

int g[10][10];

int main(){
	int n;
	s(n);
	int arr[n], g[n][n];
	for (int i = 0; i < n; ++i)
	{
		s(arr[i])
		/* code */
	}
	
	for (int i = 0; i < n; ++i)
	{
		for(int j = 0; j< n; j++){
			s(g[i][j])
			// p(g[i][j])
		}
		/* code */
	}
	for (int i = 0; i < n; ++i)
	{
		for(int j = 0; j< n; j++){
			if(g[i][j]==1 && (arr[j]<arr[i] && j>i))
				swap(&arr[i], &arr[j]);
							
		}
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
		/* code */
	}
}

/*
7
5 2 4 3 6 7 1
0 0 0 1 0 0 1
0 0 0 0 0 0 0
0 0 0 1 0 1 0 
1 0 1 0 0 0 1
0 0 0 0 0 0 0
0 0 1 0 0 0 0
1 0 0 1 0 0 0
*/