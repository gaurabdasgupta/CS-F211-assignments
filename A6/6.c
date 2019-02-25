#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<stdbool.h>

#define s(x) scanf("%d", &x)
#define p(x) printf("%d ", x)
#define f1(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i<=y;i++)

bool check(char str[])
{
    int n = strlen(str)/2;
    f1(i,1,n)
        if(str[i]<str[i-1])
            return false;
    return true;
}

bool isPalin(char str[], int s, int e)
{
    if (s == e) 
    return true; 

    if (str[s] != str[e]) 
    return false; 

    if (s < e + 1) 
    return isPalin(str, s + 1, e - 1); 
  
    return true; 
}

int main()
{
    char str[100];
    scanf("%s", str);
    int n = strlen(str);

    for (int len = 1; len <= n; len++)  
    {     

        for (int i = 0; i <= n - len; i++)  
        {  
            int j = i + len - 1;
            char substr[j];
            int idx = 0;            
            for (int k = i; k <= j; k++)
            {
                substr[idx++] = str[k];
                printf("%s", substr);
                //  if(isPalin(substr,0,strlen(substr)-1)&&check(substr))
                // {
                //     if(strcmp(substr,ans)<0)
                //         strcpy(ans,substr);
                // }
                
            } 
            printf("\n");
        } 
    } 

    // printf("%s", ans);

}