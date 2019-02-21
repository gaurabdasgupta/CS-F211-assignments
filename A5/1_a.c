#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>


#define max(a, b) (a>b?a:b);
#define p(x) printf("%d\n", x);
#define p2(x, y) printf("%d %d\n", x, y);
#define s(x) scanf("%d", &x);

int n, arr[20], count=0;
typedef struct pair{
	int l;
	int r;
} pair;


int compare(const void *a, const void *b){
	pair *temp1 = (pair*)a, *temp2 = (pair*)b;
	return temp1->l-temp2->l;
}

int main(){
	int t;
	s(t)
	while(t--){
		s(n);
		pair p[n];
		for (int i = 0; i < n; ++i)
		{
			int a, b;
			s(a)
			s(b)
			p[i].l = a, p[i].r = b;
			/* code */
		}
		qsort(p, n, sizeof(pair), compare);
		int ans[n], overlap[n];
		memset(ans, 0, sizeof(ans));
		memset(overlap, 0, sizeof(overlap));

		for (int i = 0; i < n; ++i)
		{
			if(overlap[i]==0){
				// p2(100, i)
				for (int j = i+1; j < n; ++j)
				{
					if((p[i].r<p[j].l)){
						ans[i] = 1-ans[i];
					}
					else{
						// p2(200, j)
						overlap[j] = 1;

					}
					/* code */
				}
			}
			/* code */
		}
		for (int i = 0; i < n; ++i)
		{
			if(ans[i]==0)
				printf("CA ");
			else
				printf("IM ");
			/* code */
		}
		printf("\n");
	}
}

/*
1
3
2 3 5 5 3 4
CA IM CA
*/