#include<stdio.h>
#include<stdlib.h>
//void swap(int a,int b)
//{
//int temp;
//temp=a;
//a=b;
//b=temp;
//printf("After swapping the value for A is %d & the value for B is %d\n",a,b);
//}
void swap(int,int);
int main()
{
int a,b;
printf("Enter the value of A & B\n");
scanf("%d%d",&a,&b);
swap(a,b);
system("pause");
}
void swap(int a,int b)
{
int temp;
temp=a;
a=b;
b=temp;
printf("After swapping the value for A is %d & the value for B is %d\n",a,b);
}
