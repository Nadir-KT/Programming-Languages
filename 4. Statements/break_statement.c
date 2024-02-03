/*

This example explains how to use break statement 
This example asks the user to enter any 10 integets & if any -ve value is entered loop will be treminated

*/

#include<stdio.h>

int main()
{
	int i,sum=0,num;
	printf("\n Enter any 10 +ve integers \n");
	for(i=0;i<10;i++)
	{
	  scanf("%d",&num);
	  if(num<0)
		break;
	  sum+=num;
	}
	printf("\n Sum of all +ve values entered : %d\n",sum);
}

