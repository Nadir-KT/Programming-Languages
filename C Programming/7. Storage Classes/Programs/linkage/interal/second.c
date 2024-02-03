#include<stdio.h>
static int result;		// Making External linkage to internal linkage
//int result;
void  show();
int sub(int x,int y)
{
	result = x-y;
	return result;
}

void show()
{
	printf("\n I am Static function in second with internal Linkage \n : %d",result);
}
