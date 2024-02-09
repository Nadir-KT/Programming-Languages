#include<stdio.h>
#include<conio.h>
main()
{
int d,e;
d=25;
e=naturaln(d);
printf("\nThe sum of the first %d digits is %d",d,e);
getch();
}

naturaln(int x)
{
int a;
if(x==1)
return(1);
else
{
a=x+naturaln(x-1);
return(a);
}
} 
