#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p,n,i,*temp;
    printf("\n Enter How many elements : ");
    scanf("%d",&n);
    p = (int *) malloc (n*sizeof(int)); // Enforsing void * to int *
    if(p==NULL)
    {
        printf("\n Fail to allocate memory\n");
        exit(1);
    }
    printf("\n Memory Allocated at : %p ",p);
    for(i=0;i<n;i++)
        p[i] = i+1;
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d",p[i]);
    printf("\n");
    temp = realloc(p,(n*sizeof(int))+5);
    if(p==temp)
        printf("\n old memory is extended\n");
        else
        printf("\n new memory is allocated\n");
    n=n+5;
    for(i=0;i<n;i++)
        printf("%d",p[i]);
    printf("\n");
}
