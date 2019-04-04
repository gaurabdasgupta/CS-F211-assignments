#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

typedef struct pair{
    int cnt;
    char c;
}ii;

ii heap[100];
int heapSize;

int cmp(const void* l, const void* r)
{
    ii* a = (ii*)l;
    ii* b = (ii*)r;
    return b->cnt - b->cnt;
}

void insert(ii t)
{
    heap[heapSize++] = t;
    qsort(heap, sizeof(heap), sizeof(ii), cmp);
}

ii getMax()
{
    return heap[0];
}

void pop()
{
    for(int i=0;i<=heapSize-2;i++)
        heap[i]=heap[i+1];
    heapSize--;
}

int main()
{
    heapSize = 0;
    char str[100];
    scanf("%s", str);
    int n = strlen(str);
    char done[100];
    for(int i=0;i<100;i++)
        done[i] = '#';
    int idx = 0;
    for(int i=0;i<n;i++)
    {
        char ch= str[i];
        int cnt=0;
        int f=1;
        for(int m=0;m<100;m++)
            if(done[m]==ch)
                f=0;
        printf("%c %d\n",ch, f);
        if(f)
        {
            for(int j=0;j<n;j++)
                if(str[j]==ch)
                    cnt++;
            ii t;
            t.c = ch;
            t.cnt = cnt;
            insert(t);
        }

        done[idx++] =ch;

    }

    printf("%d\n", heapSize);

    char nstr[n];
    ii prev;
    prev.cnt = -1;
    prev.c = '#';
    // int f = 1;
    int i=0;
    while(heapSize>0 && i<n)
    {
        ii t = getMax();
        pop();
        printf("ch:%c", t.c);
        nstr[i++] = t.c;

        if(prev.cnt>0)
            insert(prev);
        
        t.cnt--;
        prev = t;
    }

    printf("%s\n", nstr);

    if(strlen(nstr)==n)
        printf("possible");
    else
        printf("impossible");

}