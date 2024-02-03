#include<stdio.h>

int main()
{
	int i,r,c;
	printf("\n Enter the number of rows & columns which you want tables : ");
	 scanf("%d%d",&r,&c);
	for(;i<=c;i++)
	   printf("%d*%d=%d\n",r,i,r*i);
}
