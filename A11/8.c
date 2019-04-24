#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,k,t;
    scanf("%d %d %d", &n, &k, &t);

    int pow[n];
    for(int i=0;i<n;i++)
        scanf("%d", &pow[i]);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(abs(pow[i]-pow[j])<=t && abs(i-j)<=k && i!=j)
            {
                printf("Hogwarts Win");
                return 0; c
            }
        }
    }

    printf("Voldemort Wins");
}