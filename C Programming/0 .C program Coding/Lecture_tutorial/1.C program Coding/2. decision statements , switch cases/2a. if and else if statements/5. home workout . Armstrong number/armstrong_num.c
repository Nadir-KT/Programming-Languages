#include<stdio.h>
#include<conio.h>
main()
{
      int a,b,c,d,e,i,j,k,z;
      printf("enter a 3 digit number");
      scanf("%d",&a);
      b=a%10;
      c=a/10;
      d=c%10;
      e=c/10;
     
      i=e*e*e;
      j=d*d*d;
      k=b*b*b;
      z=i+j+k;
      if(a==z)
      printf("%d is an armstrong number",a);
      else
      printf("%d is not an armstrong number",a);
      getch();
      }         
