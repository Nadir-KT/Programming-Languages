/*

This example explains how to use continue statement 
This example asks the user to enter any 10 integets & find sum of all elements, if any -ve value isthe continue statement bypasses the Arithmetic Expression

*/

#include<stdio.h>
int main()
{
	int i,sum=0,num;
	printf("\n Enter any 10 +ve integers \n");
	for(i=0;i<=10;i++)
	{
	  scanf("%d",&num);
	  if(num<0)
		continue;
	  sum+=num;
	}
	printf("\n Sum of all +ve values entered : %d\n",sum);
}

