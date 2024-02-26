#include<stdio.h>
#include<conio.h>
 main()
{
int a1,a2,a3,s;
printf("Enter 3 Angles");
scanf("%d%d%d",&a1,&a2,&a3);
s=a1+a2+a3;
if(s==180)
 {
 printf("Valid Triangle");
 }
 else
  {
  printf("Invalid Triangle");
  }
getch();
}
