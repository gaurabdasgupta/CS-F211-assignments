#include<stdio.h>
#include<string.h>

typedef struct str{
    char data[100];
}string;

string lib[100];

int main()
{
    int n, q;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        char t[100];
        scanf("%s", t);
        strcpy(lib[i].data, t);
    }

    scanf("%d", &q);
    for(int i=0;i<q;i++)
    {
        
    }
}