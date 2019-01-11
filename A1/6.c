#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define d(x) printf("%d", x);
#define f(i,x,y) for(int i=x;i<y;i++)
#define null NULL

void sieve(int a, int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for(int i=2;i*i<=n;i++)
        if(prime[i]==true)
            for(int j=i*i;j<=n;j+=i)
                prime[j] = false;
    for(int i=2;i<=n;i++)
        if(prime[i]&&i>=a)
            printf("%d ", i);
}

int main()
{
    int a,b;
    scanf("%d %d", &a, &b);
    sieve(a, b);
}