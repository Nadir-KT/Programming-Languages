#include<stdio.h>
int main()
{
int max,a=10,b=20,c=30;
max = a>b?a>c?a:c:b>c?b:c;
printf("max = %d\n",max);
}
