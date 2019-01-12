#include<stdio.h>
#define d(x) printf("%d", x);
#define f(i,x,y) for(int i=x;i<y;i++)

int dir(char d, int* q, int* j)
{
    if(d=='u')
        *q-=1;
    else if(d=='d')
        *q+=1;
    else if(d=='l')
        *j-=1;
    else
        *j+=1;
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n][n];

    int mid = n/2, k = 1;
    int i=mid, j=mid;
    int rc=1,uc=1,lc=2,dc=2;   
    int f = 0;

    a[i][j]=k++;

    while(1)
    {
        f(l,0,rc)
        {
            dir('r',&i,&j);
            a[i][j] = k++;
            if(k>n*n)
            {
                f=1;
                break;
            }
        }
        if(f)
            break;

        f(l,0,uc)
        {
            dir('u',&i,&j);
            a[i][j] = k++;
            if(k>n*n)
            {
                f=1;
                break;
            }
        }
        if(f)
            break;

        f(l,0,lc)
        {
            dir('l',&i,&j);
            a[i][j] = k++;
            if(k>n*n)
            {
                f=1;
                break;
            }
        }
        if(f)
            break;

        f(l,0,dc)
        {
            dir('d',&i,&j);
            a[i][j] = k++;
            if(k>n*n)
            {
                f=1;
                break;
            }
        }
        if(f)
            break;

        rc+=2;
        uc+=2;
        lc+=2;
        dc+=2;
    }

    for(int k=0;k<n;k++)
    {
        for(int l=0;l<n;l++)
        {
            if(a[k][l]<=9)
                printf("%d  ", a[k][l]);
            else
                printf("%d ", a[k][l]);
        }
           
        printf("\n");
    }

    return 0;
}