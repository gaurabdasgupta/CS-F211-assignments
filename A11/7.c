#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct item{
    char v[100];
    int cnt;
}si;

si list[100];

int cmp(const void* l, const void* r)
{
    si* a = (si*)l;
    si* b = (si*)r;
    return b->cnt - a->cnt;
}

int found(char str[100])
{
    for(int i=0;i<100;i++)
        if(strcmp(list[i].v, str)==0)
            return i;
    return -1;
}

int main()
{
    int n;
    int k;
    scanf("%d", &n);
    scanf("%d", &k);

    int idx = 0;
    for(int i=0;i<n;i++)
    {
        char temp[100];
        scanf("%s", temp);
        si t;

        strcpy(t.v, temp);
        t.cnt = 1;
        int res = found(temp);
        if(res==-1)
            list[idx++] =  t;
        else
            list[res].cnt++;
    }

    qsort(list, idx, sizeof(si), cmp);

    for(int i=0;i<k;i++)
        printf("%s ", list[i].v);
}