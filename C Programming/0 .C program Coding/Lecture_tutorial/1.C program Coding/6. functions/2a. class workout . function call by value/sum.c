#include <stdio.h>
#include <conio.h>

int sum(int x,int y);
main()
{
     int x,y,s;
     printf("enter value of x & y\n");
     scanf("%d%d",&x,&y);
     s=sum(x,y);
     printf("sum is %d",s);
     getch();
     }
     int sum(int x,int y)
     {
         int z;
         z=x+y;
         return z ;
         
         }
