#include<stdio.h>  
#include<stdlib.h>
#include<string.h>

#define MAX 256 
 
#define MAX_WORD_LEN 500 

typedef struct trieNode 
{ 
	struct trieNode *child[MAX]; 
	int freq;
}tn; 

typedef struct s{
	char data[100];
}string;

tn* newTrieNode(void) 
{ 
	tn* newNode = (tn*)malloc(sizeof(tn)); 
	newNode->freq = 1;
	for (int i = 0; i<MAX; i++) 
		newNode->child[i] = NULL; 
	return newNode; 
} 
 
void insert(tn* root, string str) 
{ 
	int len = strlen(str.data); 
	tn* pCrawl = root; 

	for (int level = 0; level<len; level++) 
	{  
		int index = str.data[level]; 

		if (!pCrawl->child[index]) 
			pCrawl->child[index] = newTrieNode(); 
		else
			(pCrawl->child[index]->freq)++; 

		pCrawl = pCrawl->child[index]; 
	} 
} 

void findPrefixesUtil(tn* root, char prefix[], int ind) 
{ 
	if (root == NULL) 
		return; 
 
	if (root->freq == 1) 
	{ 
		prefix[ind] = '\0'; 
		printf("%s ", prefix); 
		return; 
	} 

	for (int i=0; i<MAX; i++) 
	{ 
		if (root->child[i] != NULL) 
		{ 
			prefix[ind] = i; 
			findPrefixesUtil(root->child[i], prefix, ind+1); 
		} 
	} 
} 

void findPrefixes(string arr[], int n) 
{  
	tn* root = newTrieNode(); 
	root->freq = 0; 
	for (int i = 0; i<n; i++) 
		insert(root, arr[i]); 

	char prefix[MAX_WORD_LEN]; 

	findPrefixesUtil(root, prefix, 0); 
} 

int main() 
{ 
	int n;
	scanf("%d", &n);

	string arr[n];
	for(int i=0;i<n;i++)
		scanf("%s", arr[i].data);

	findPrefixes(arr, n); 

	return 0; 
} 
