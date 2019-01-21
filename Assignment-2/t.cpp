#include <bits/stdc++.h>
using namespace std;
const int maxn=4010;
int dp[maxn];
int main()
{
	int n,a,b,c;
	int num[4];
	scanf("%d%d%d%d",&n,&num[1],&num[2],&num[3]);
	int ans=0;
	for(int i=0;i<maxn;i++) dp[i]=-10000;
	dp[0]=0;
	for(int i=1;i<=3;i++){
		for(int j=num[i];j<=n;j++){
			dp[j]=max(dp[j],dp[j-num[i]]+1);
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}