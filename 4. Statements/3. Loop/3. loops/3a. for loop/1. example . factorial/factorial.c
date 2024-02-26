#include<stdio.h>
#include<conio.h>
 main()
{
      unsigned int a,i,fact=1;
      printf("enter the number");
      scanf("%d",&a);
      for(i=1;i<=a;i++)//while(a>0)
      {
               fact=i*fact;
               }
                       printf("the factorial is %d",fact);
                       getch();
                       }
