#include<stdio.h>
#include<conio.h>
main()
{
      int a,b,c,d,e,f,g,h,i,z;
      printf("enter a 5 digit number");
      scanf("%d",&a);
      b=a%10;
      c=a/10;
      d=c%10;
      e=c/10;
      f=e%10;
      g=e/10;
      h=g%10;
      i=g/10;
      z=i+h+f+d+b;
      printf("the sum of digits is %d",z);
      getch();
      }
