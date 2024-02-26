#include<stdio.h>
#include<stdlib.h>
int sum(int n);
int main()
{
int f,l;
printf("Input a 5 digit number\n");
scanf("%d",&f);
l=sum(f);
printf("The sum of the digits = %d\n",l);
system("pause");
}
int sum(int n)
{
if(n==0)
return 0;
else
return(n%10+sum(n/10));
}
