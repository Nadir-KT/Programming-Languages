#include<stdio.h>
#include<conio.h>
 main()
 {
 int a,b,c;
 printf("\nEnter the two numbers : ");
 scanf("%d %d",&a,&b);
  c = sum(&a,&b);

 printf("\nAddition of two number is  :%d ",c);
 getch();
 }

 int sum ( int *num1,int *num2)
 {
 int num3;
 num3 = (*num1) + (*num2);
 return(num3);
 }
