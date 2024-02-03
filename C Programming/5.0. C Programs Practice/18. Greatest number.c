#include<stdio.h>
main()
{
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d%d",&a,&b);
    if(a>b)
        printf("Greatest number from entered is %d",a);
    else
        printf("Greatest number from entered is %d",b);
}
