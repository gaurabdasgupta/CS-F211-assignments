#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

int main()
{
    char s[101];
    scanf("%s", s);
    for(int i=0;i<strlen(s);i++)
    {
        int t = ((s[i]+3)%123);
        if(t<100)
            t+=97;
        s[i]=t;
    }
    printf("%s", s);
}