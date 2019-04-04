#include<stdio.h>

int main()
{
    int n,m,x;
    scanf("%d %d %d", &n,&m,&x);
    int a[n], b[m];

    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    
    for(int i=0;i<m;i++)
        scanf("%d", &b[i]);

    int sum = 0, count = 0,i=0,j=0;

    while(i<n && sum+a[i]<=x)
        sum+=a[i++];

    count = i;
    while(j<m && i>=0)
    {
        sum+=b[j++];
        while(sum>x && i>0)
        {
            i--;
            sum-=a[i];
        }

        if(sum<=x && i+j>count)
            count = i+j;
    }
   
    printf("%d", count);

}