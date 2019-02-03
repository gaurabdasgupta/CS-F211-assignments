#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

int main()
{
    char s[1000];
    scanf("%s", s);

    int m;
    scanf("%d", &m);
    while(m--)
    {
        int f,r,k;
        scanf("%d %d %d", &f, &r, &k);

        int st = f-1, en = r-1;
        while(k--)
        {
            char tmp = s[en];
            for(int i=en;i>=st+1;i--)
                s[i]=s[i-1];
            s[st] = tmp;
        }
    }
    printf("%s", s);
    
}