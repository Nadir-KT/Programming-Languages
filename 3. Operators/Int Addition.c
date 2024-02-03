#include<stdio.h>
main( )
{
        int a, b, c, d;
        printf("Enter the value of A & B\n");
        scanf("%d%d",&a,&b);
        c=a+b;
        d=c+a;
        printf("%d\n%d",c,d);
        getch();
}
