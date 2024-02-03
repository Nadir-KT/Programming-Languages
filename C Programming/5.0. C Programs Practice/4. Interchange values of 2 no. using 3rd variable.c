#include<stdio.h>
void main()
{
    int a,b,c;
    printf("Enter the value of A & B :\n");
    scanf("%d%d",&a,&b);
    c=a,a=b,b=c;
    printf("After swapping the values are : A = %d B = %d\n",a,b);
}
