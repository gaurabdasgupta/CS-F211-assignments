#include<stdio.h>
#define min(a,b) ((a)<(b)?(a):(b))

int i,n,k,s,t,l=1,r=1e9+5,mid,d,cost=INT_MAX,g[200005],v[200005],c[200005];

bool can(int x)
{
	long sum=0;
	for(i=1;i<=k;i++)
    {
		d=g[i]-g[i-1];
		if (d>x)
			return false;
		sum=sum+d+max(2*d-x,0);
	}
	return sum<=t;
}

int main()
{
	scanf("%d %d %d %d", &n, &k, &s, &t);
	for(i=1;i<=n;i++)
		scanf("%d%d",c+i,v+i);
	for(i=1;i<=k;i++)
		scanf("%d",g+i);
	g[0]=0;
	g[++k]=s;
	sort(g,g+k+1);
	while(l<r)
    {
		mid=(l+r)/2;
		if(can(mid))
			r=mid;
		else
            l=mid+1;
	}
	if (!can(l))
		return printf("-1"),0;
	else
    {
        for(i=1;i<=n;i++)
			if(v[i]>=l)
				cost=min(cost,c[i]);
		if (cost==INT_MAX)
			cost=-1;
		printf("%d", cost);
	}
}