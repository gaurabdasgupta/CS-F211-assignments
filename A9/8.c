#include<stdio.h>
int main(){
int k,w,n;
scanf("%d %d %d",&k,&w,&n);
int p[n];
int c[n];
int i,j;
int profit;
int best;
for(i=0;i<n;i++)
scanf("%d",&p[i]);
for(i=0;i<n;i++)
scanf("%d",&c[i]);
for(i=0;i<k;i++)
{
	best=-1;
	profit=0;
	for(j=0;j<n;j++){
		if(w>=c[j] && p[j]>profit){
			best=j;
			profit=p[j];
		}
	}
	if(profit==0)
	break;
	w+=profit;
	p[best]=-10000;
}
printf("%d",w);
}