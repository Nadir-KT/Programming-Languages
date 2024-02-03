#include <stdio.h>
main()
{
    int a[20],i;
    int *p=&a[0],size;
    printf("\n how many elements you are going to enter::");
    scanf("%d",&size);
    printf("\n enter array elements::\n");
    for(i=0;i<size;i++)
        scanf("%d",(p+i)); //&a[i]
        printf("\n displaying array elements by using the pointer::\n");
    for(i=0;i<size;i++)
        printf("%d\t",*(p+i)); //a[i]
        printf("\n");
}
