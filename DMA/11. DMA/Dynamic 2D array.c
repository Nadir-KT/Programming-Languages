#include<stdio.h>
#include<stdlib.h>
void main()
{
    int *p,m,n,val,i,j;
    printf("\n enter 2D array size::");
    scanf("%d%d",&m,&n);
    p=(int *)malloc(m*n*sizeof(int));
    printf("\n enter elements::");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
    {
        scanf("%d",(p+i*n+j));
    }
    printf("\n entered elements are follows::\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        printf("%d\t%p\n",*(p+i*n+j),(p+i*n+j));
        printf("\n");
    }
    printf("\n");
}
