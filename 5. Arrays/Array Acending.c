#include<stdio.h>
main()
{
    int i,j,t,a[10];
    for(i=0;i<=5;i++)
    {
        scanf("%d",&a[i]);
    }
            for(i=0;i<=5;i++)
            {
                for(j=0;j<=5;j++)
                {
                   if(a[i]<a[j])
                   {
                      t=a[i];
                      a[i]=a[j];
                      a[j]=t;
                   }
                }
            }
                         for(j=0;j<=5;j++)

                         {
                             printf("%d\n",a[j]);
                         }
    getch();
}
















