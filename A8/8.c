#include<stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int a[N][N];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d", &a[i][j]);

	int S[N+1][N+1];

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (i == 0 || j == 0)
				S[i][j] = 0;
			else
				S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] +
						a[i-1][j-1];
		}
	}

    int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			for (int m = 0; m < N; m++)
			{
				for (int n = m; n < N; n++)
				{
					int submatrix_sum = S[j+1][n+1] - S[j+1][m] -
									S[i][n+1] + S[i][m];

					if (submatrix_sum == 1)
                        cnt++;
				}
			}
		}
	}

    printf("%d", cnt);

}