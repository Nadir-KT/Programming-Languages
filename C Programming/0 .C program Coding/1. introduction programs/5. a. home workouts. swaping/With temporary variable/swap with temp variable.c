#include<stdio.h>
#include<conio.h>
main()
{
int a,b,c;
printf("\n Enter two no ");
scanf("%d%d",&a,&b);

printf("\n Before Swaping value of a and b %d %d",a,b);

c=a;
a=b;
b=c;

printf("\n After Swaping value of a and b %d %d",a,b);

getch();
} 
