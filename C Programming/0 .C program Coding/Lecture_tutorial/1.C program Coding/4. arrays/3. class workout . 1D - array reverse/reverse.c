
#include<stdio.h>
main()
{
      int a[10],b[10],i,sum=0;
      printf("enter the values of array");
      for(i=0;i<5;i++)
      {
                       scanf("%d",&a[i]);
                       }
                     for(i=0;i<5;i++)
      {
                       printf("a[%d]=%d\n",i,a[i]);
                       }
                        for(i=0;i<5;i++)
      {
                       sum=a[i]+sum;
                       }
                       printf("sum of the array is : %d\n",sum);
                       
                     for(i=4;i>=0;i--)
                     {
                     printf("b[%d]=%d\n",i,a[i]);
                     }
                       getch();
                       }

