#include<stdio.h>
int fun(int);
int main()
{
int x=10;
x=fun(x);
printf("%d\n",x);
return 0;
}
int fun(int x)
{
return x++,x++;
}
