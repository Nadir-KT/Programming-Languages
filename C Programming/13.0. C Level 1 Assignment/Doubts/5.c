/* Program to find whether a number is even or odd*/
#include<stdio.h>
int main(void)
{
	int num;
	int mask=0x1; \\  0x81 = 0b10000001
	printf("Enter a number : ");
	scanf("%d",&num);
	if((num&mask)==0)
		printf("Number is even\n");
	else
		printf("Number is odd\n");
	return 0;
}
