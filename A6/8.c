#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<stdbool.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d ", x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)

int rowN, colN;
bool f;
int rowNum[] = {-1, 0, 0, 1}; 
int colNum[] = {0, -1, 1, 0}; 

bool isvalid(int row, int col) 
{ 
	return (row >= 0) && (row < rowN) && 
		(col >= 0) && (col < colN); 
}

void DFS(char mat[][colN], int row, int col, char* word, 
		int index, int n) 
{ 
	if (index > n || mat[row][col] != word[index])
        return;

	if (index == n) 
	{
        f = true;
		return;
	}

	for (int k = 0; k < 4; ++k) 
		if (isvalid(row + rowNum[k], col + colNum[k]))
			DFS(mat, row + rowNum[k], col + colNum[k], 
				word, index+1, n); 
} 

void findWords(char mat[][colN], char* word, int n) 
{ 
	for (int i = 0; i < rowN; ++i) 
		for (int j = 0; j < colN; ++j) 
			if (mat[i][j] == word[0]) 
				DFS(mat, i, j, word, 0, n); 
} 

int main() 
{ 
    s(rowN); s(colN);
    char mat[rowN][colN];
    f1(i,0,rowN)
        f1(j,0,colN)
            scanf(" %c", &mat[i][j]);
    // f1(i,0,rowN)
    //     f1(j,0,colN)
    //         printf("%c ", mat[i][j]);
    int t;
    s(t);
    f1(i,0,t)
    {
        char word[100];
        scanf("%s", word);
        f = false;
        findWords(mat, word, strlen(word) - 1);
        if(f)
            printf("YES\n");
        else
            printf("NO\n");
    }

	return 0; 
} 
