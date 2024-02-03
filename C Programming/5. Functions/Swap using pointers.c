#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
int temp;
temp=*a;
*a=*b;
*b=temp;
}
int main()
{
int a,b;
printf("Enter number A : ");
scanf("%d", &a);
printf("Enter number B : ");
scanf("%d", &b);
swap(&a,&b);
printf("After swapping the value for A is %d & the value for B is %d\n",a,b);
system("pause");
}
