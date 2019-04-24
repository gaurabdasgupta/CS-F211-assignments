#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct i{
    char s[100];
}ii;

ii list[100];
int main()
{
    int n,k;
    scanf("%d %d", &n, &k);

    // ii list[n];
    for(int i=0;i<n;i++)
    {
        ii t;
        char temp[100];
        scanf("%s", temp);
        strcpy(t.s, temp);
        list[i] = t;
    }
    

    for(int i=0;i<k;i++)
    {
        char sfn[100];
        scanf("%s", sfn);
        int f = 0;
        for(int j=0;j<n;j++)
            if(strcmp(list[j].s,sfn) == 0)
            {
                f = 1;
                break;
            }
        if(f)
            continue;
        else
        {
            printf("No");
            return 0;
        }
    }

    printf("Yes");

}