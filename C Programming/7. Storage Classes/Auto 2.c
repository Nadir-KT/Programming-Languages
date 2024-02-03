#include<stdio.h>
void count();
int main()
{
	count();
	count();
	count();
	count();
}
void count()
{
	auto int c=1;
	printf("\n Function called %d time\n",c++);
	printf("\n Function called %d time\n",&c);
}
