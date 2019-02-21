#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d\n", x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)

#define MAX_SIZE 10 

void sortArrayUsingCounts(int arr[], int n) 
{ 
	int count[MAX_SIZE] = {0}; 
	for (int i = 0; i < n; i++) 
		count[arr[i]]++; 

	int index = 0; 
	for (int i = 0; i < MAX_SIZE; i++) 
		while (count[i] > 0) 
			arr[index++] = i, count[i]--; 
} 

bool removeAndPrintResult(int arr[], int n, int ind1, int ind2) 
{ 
	for (int i = n-1; i >=0; i--) 
		if (i != ind1 && i != ind2) 
			cout << arr[i] ; 
} 

bool largest3Multiple(int arr[], int n) 
{ 
    int sum=0;
    f1(i,0,n)
        sum+=arr[i];

	if (sum%3 == 0) 
		return true ; 

	sortArrayUsingCounts(arr, n); 
    
	int remainder = sum % 3; 

	if (remainder == 1) 
	{ 
		int rem_2[2]; 
		rem_2[0] = -1, rem_2[1] = -1; 
		for (int i = 0 ; i < n ; i++) 
		{ 
			if (arr[i]%3 == 1) 
			{ 
				removeAndPrintResult(arr, n, i); 
				return true; 
			} 

			if (arr[i]%3 == 2) 
			{ 
				if (rem_2[0] == -1) 
					rem_2[0] = i; 
				else if (rem_2[1] == -1) 
					rem_2[1] = i; 
			} 
		} 

		if (rem_2[0] != -1 && rem_2[1] != -1) 
		{ 
			removeAndPrintResult(arr, n, rem_2[0], rem_2[1]); 
			return true; 
		} 
	} 

	else if (remainder == 2) 
	{ 
		int rem_1[2]; 
		rem_1[0] = -1, rem_1[1] = -1; 

		for (int i = 0; i < n; i++) 
		{ 
			if (arr[i]%3 == 2) 
			{ 
				removeAndPrintResult(arr, n, i); 
				return true; 
			} 

			if (arr[i]%3 == 1) 
			{ 
				if (rem_1[0] == -1) 
					rem_1[0] = i; 
				else if (rem_1[1] == -1) 
					rem_1[1] = i; 
			} 
		} 

		if (rem_1[0] != -1 && rem_1[1] != -1) 
		{ 
			removeAndPrintResult(arr, n, rem_1[0], rem_1[1]);
			return true; 
		} 
	} 

	printf("Not Possible");
	return false; 
} 

int main() 
{ 
	int arr[] = {4 , 4 , 1 , 1 , 1 , 3} ; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	largest3Multiple(arr, n); 
	return 0; 
} 
