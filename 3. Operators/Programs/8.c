#include<stdio.h>
int main(void)
{
 	int a=8,b=7,temp;
	printf("a=%d, b=%d\n",a,b);
	temp=a,a=b,b=temp;
	printf("a=%d, b=%d\n",a,b);
	return 0;
}
