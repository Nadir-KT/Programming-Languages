#include<stdio.h>
void show(int[],int);
main()
{
    int a[20],i,n;
    printf("\n enter array size::");
    scanf("%d",&n);
    printf("\n enter array elementes::");
    for(i=0;i<n;i++)
	scanf("%d",&a[i]);
    show(a,n);
    printf("\n");
}
void show(int a[],int n)
{
    int i;
    printf("\n array elements are as follows::\n");
    for(i=0;i<n;i++)
	printf("%d\t",a+i);
}
