#include<stdio.h>
int max(int ,int );
int main()
{
int a=10,b=4,c=9,d;
printf("maximum num: %d\n",max(a,max(b,c)));
return 0;
}
int max (int a, int b)
{
return a>b? a:b;
}
