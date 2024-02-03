#include<stdio.h>
int main()
{
int a=0,b=1;
if(!a)
{
b=a;
if(!b)
a=!b;
}
printf("%d,%d",a,b);
}
