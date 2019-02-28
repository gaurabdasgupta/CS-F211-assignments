#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>


#define min(a, b) (a< b?a:b)
#define p(x) printf("%d\n", x);
#define p2(x, y) printf("%d %d\n", x, y);
#define s(x) scanf("%d", &x);

int n, arr[10], visited[10];

void combo(int data[], int start, int end, int index, int k){
	if(index == k){
		for(int j = 0; j<k; j++){
			printf("%d ",  data[j]);
		}
		printf("\n");
		return;
	}

	for(int i = start; i <= end && end-i+1>=k-index; i++){
		data[index] = arr[i];
		combo(data, i+1, end, index+1, k);
	}

}

int main(){
	int n, m, flag, x;
	s(n)
	s(m)
	s(flag)
	for (int i = 1; i <= n*m; ++i)
	{
		s(x)
	}
	int data[2];
	for (int i = 0; i < m; ++i)
	{
		arr[i] = i+1;
	}
	combo(data, 0, m-1, 0, 2);
}