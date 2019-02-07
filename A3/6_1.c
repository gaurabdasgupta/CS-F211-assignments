#include<stdio.h>
#include<string.h>

int hash[27];

int main()
{
    char str[11];
    scanf("%s", str);
    for(int i=0;i<strlen(str);i++)
        hash[str[i]-97]++;

    int even = 0, odd = 0;

    for(int i=0;i<26;i++)
    {
        if(hash[i]!=0)
        {
            if(hash[i]%2!=0&&hash[i]!=0)
                odd++;
        }

    }
    // printf("%d %d\n", even, odd);
    if(odd>1)
        printf("No");
    else
        printf("Yes");
}