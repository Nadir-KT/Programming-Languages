#include<stdio.h>
#include<stdlib.h>
void main()
{
    int *p,n,i;
    printf("\n how many elements you are going to enter::");
    scanf("%d",&n);
    p=(int *)malloc(n*sizeof(int));
    printf("\n enter elements::");
    for(i=0;i<n;i++)
    {
        scanf("%d",(p+i));
    }
    printf("\n entered elements are follows::\n");
    for(i=0;i<n;i++)
        printf("%d\t",*(p+i));
    printf("\n");
}
