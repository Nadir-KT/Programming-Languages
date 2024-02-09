#include<stdio.h>
main()
{
      int a,b;
      printf("enter the values\n");
      scanf("%d %d",&a,&b);
      printf("You have entered a= %d\nb=%d\n",a,b);
      a=a+b;
      b=a-b;
      a=a-b;
      printf("After swapping the value are:\na=%d\nb= %d ",a,b);
      getch();
      }
      
