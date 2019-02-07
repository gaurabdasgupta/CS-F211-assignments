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

bool isPalindrome(char* str, int s, int e)
{
    if(s==e)
        return true;
    
    if(str[s]!=str[e])
        return false;
    
    if(s<e+1)
        return isPalindrome(str, s+1, e-1);
    
    return true;
}

void generatePermutation(char* s, int l, int r)
{
    if(l==r)
    {
        if(isPalindrome(s,0,strlen(s)-1))
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