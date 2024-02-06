#include<stdio.h>
	extern int result;	// Declaration
	void sub(int,int);
	void sub(int x,int y)
	{
		result = x-y;
	}
