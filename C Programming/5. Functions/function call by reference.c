#include<stdio.h>
#include<stdlib.h>
int sum(int *num1,int *num2);
int main()
{
    int a,b,s;
    printf("Enter the two numbers\n");
    scanf("%d%d",&a,&b);
    s=sum(&a,&b);
    printf("Addition of entered numbers = %d\n",s);
    system("pause");
    }
 int sum(int *num1,int *num2)
 {
 int num3;
 num3=(*num1)+(*num2);
 return(num3);
 }
