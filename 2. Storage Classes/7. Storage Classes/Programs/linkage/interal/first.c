#include<stdio.h>
static int result;		// Making External linkage to internal linkage
int add(int x,int y)
{
	result = x+y;
	return result;
}

void disp()
{
	printf("\n Result in first file : %d\n",result);
}
