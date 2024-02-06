#include<stdio.h>
void add(int,int);
void main()
{
	int a=10,b=20;
	add(a,b);
}
void add(int x,int y)
{
	int sum;
	sum = x+y;
	printf("%d\n",sum);
}