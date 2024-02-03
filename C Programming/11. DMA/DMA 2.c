#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p,n,i;
    printf("\n Enter How many elements : ");
    scanf("%d",&n);
    p = (int *) malloc (n*sizeof(int)); // Enforsing void * to int *
    if(p==NULL)
    {
        printf("\n Fail to allocate memory\n");
        return 0;
    }
    printf("\n Memory Allocated at : %p ",p);
    printf("\n Initial Value \n");
    for(i=0;i<n;i++)
        printf("%p",p[i]);
    for(i=0;i<n;i++)
        p[i]=i+1;
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d",p[i]);
    printf("\n");
}
