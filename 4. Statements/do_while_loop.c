/*

This program explains about do while looping constructor.
This example will find whether the given numbers are palindrome or not

Usage   :
          do 
          {
             statement 1;
             statement 2;
             statement 3;
          }while(exp);
        Arguments
        ---------
        statement
            A null statement, simple statement, or compound statement.
  	exp   
  	Any expression.

Version : 1.0

#include<stdio.h>
int main()
{
	int i=0,sum=0;
	do
	{
		sum=sum+i;
		i++;
	}
	while(i<=5);
	printf("%d\n",sum);
	return0;
}

*/

#include<stdio.h>
int main()
{
	int num,dig,rev=0,temp;
	char choice;
	do
	{
          num=0;
          printf("\n Enter any Number : ");
	    scanf("%d",&num);
	   temp=num;
	   rev=0;
	   while(num>0)
	   {
	      dig=num%10;
	      rev=rev*10+dig;
	      num/=10;	
	   }
	   
	   if(temp==rev)
	      printf("\n %d is a palindrome\n",temp);
	   else	
	      printf("\n %d is not palindrome\n",temp);
	   printf("\n\n Again (y/n) : ");
	   gets(stdin);
	   choice = getchar();	
	}while(choice=='y' || choice=='Y');
	return 0;
}
