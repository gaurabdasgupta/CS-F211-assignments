#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

void swap(char *x, char *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
}

bool isPalindrome(char* s)
{
    int i=0, j = strlen(s)-1;
    int f=0;
    while(1)
    {
        if(i==j)
            return true;
        else if((j-i)==1&&s[i]==s[j])
            return true;
        else if((j-i)==1&&s[i]!=s[j])
            break;
        
        if(s[i]==s[j])
        {
            i++;
            j--;
        }
        else
            break;


    }

    return false;
}

void generatePermutation(char* s, int l, int r)
{
    if(l==r)
    {
        if(isPalindrome(s))
        {
            printf("%s\n", s);
            printf("Yes");
            exit(0);
        }
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap((s+l), (s+i));
            generatePermutation(s,l+1,r);
            swap((s+l), (s+i));
        }
    }
}

int main()
{
    char str[11];
    scanf("%s", str);
    generatePermutation(str,0,strlen(str)-1);
    printf("No");
}