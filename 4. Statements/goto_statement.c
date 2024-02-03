/*

This Program implements goto & Lable statements in c

*/

#include<stdio.h>
int main()
{
	int a=10;
	if(a>1)
	{
	  if(a>2)	
	    if(a>3)	
	      if(a>4)	
	        if(a==10)	
		{
		   printf("\n control is being jumped to specified lable")		;
		   goto flag;
		}
	  printf("\n Exiting normally from if & also executes statements in lable\n");
	}
	flag:
		printf("\n executing from lable\n");
	
}

