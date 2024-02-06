#include<stdio.h>
#include<conio.h>
main()
{
      int i;
      printf("enter the option number");
      scanf("%d",&i);
      int p,c,a,fact=1,secVal,s,m,h,min,y,value;
      //char positive,negative;
      switch(i)
      {
       case 1:

           printf("enter seconds");
           scanf("%d",&secVal);
           s=secVal%60;
           m=secVal/60;
           h=m/60;
           min=m%60;
           printf("hour=%d\tminutes=%d\tseconds=%d",h,m,secVal);

           break;
       case 2:

            printf("enter the number");
            scanf("%d",&y);
            //y=(value>0?1:0);
            if(y==1)
            printf("positive");
            else if(y==0)
            printf("negative");
            else
            printf("zero");
            break;

      default:
            printf("default");
            break;
            }
getch();
}
