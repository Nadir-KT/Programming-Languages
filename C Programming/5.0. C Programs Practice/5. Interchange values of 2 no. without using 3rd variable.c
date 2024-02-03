#include<stdio.h>
void main()
{
    int a,b;
    printf("Enter the value of A & B :\n");
    scanf("%d%d",&a,&b);
    a=a+b,b=a-b,a=a-b;
    printf("After swapping the values are : A = %d B = %d\n",a,b);
}
