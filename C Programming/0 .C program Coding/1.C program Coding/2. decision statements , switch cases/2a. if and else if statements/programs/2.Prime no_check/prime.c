
#include<stdio.h>
main()
{
int a,b,no;
printf("enter the no.");
scanf("%d",&no);
for(a=2;a<no;a++)
{
if(no%a==0)
{
b=1;
break;
}}
if(b==1)
{
printf("\n given no is a prime no.");
}
else
{
printf("\n given  is not a prime no.");
}
getch();
}
