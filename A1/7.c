#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define d(x) printf("%d", x);
#define f(i,x,y) for(int i=x;i<y;i++)
#define MAX 30

char* reverseString(char* s)
{
    char* buffer = (char*)malloc(strlen(s)*sizeof(char));
    int j=0;
    for(int i=strlen(s)-1;i>=0;i--)
    {
        *(buffer+j)=s[i];
        j++;
    }
    return buffer;
}

char *encode(char* str)
{
    int len = strlen(str);
    for(int i=0;i<len;)
    {
        if(str[i]==' ')
            i++;
        else
        {
            str[i]+=3;
            if(str[i+1]==' ')
                i+=3;
            else
                i+=2;
        }
    }

    char* buffer = (char*)malloc(strlen(str)*sizeof(char));
    char* token = strtok(str, " ");

    while(token != NULL)
    {
        strcat(buffer,reverseString(token));
        strcat(buffer, " ");
        token = strtok(NULL, " "); 
    }

    return buffer;
}

char* decode(char* str)
{
    char* buffer = (char*)malloc(strlen(str)*sizeof(char));
    char* token = strtok(str, " ");

    while(token != NULL)
    {
        strcat(buffer,reverseString(token));
        strcat(buffer, " ");
        token = strtok(NULL, " "); 
    }
    
    str = buffer;
    int len = strlen(str);
    for(int i=0;i<len;)
    {
        if(str[i]==' ')
            i++;
        else
        {
            str[i]-=3;
            if(str[i+1]==' ')
                i+=3;
            else
                i+=2;
        }
    }

    return buffer;
}

int main()
{
    char* str = (char*)malloc(MAX*sizeof(char));
    scanf("%[^\n]%*c", str);
    char* f = encode(str);
    printf("%s", f);
}