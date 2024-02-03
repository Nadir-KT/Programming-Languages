/*
 
Program to demonstrate the 'switch/case' structure.
Prog looks at the number of command line parameters passed and tells the user how many its got.

Usage	:  
	  switch ( exp )
	  {
	    	case const_exp : 
		       [statement]...
		[case const_exp : 
		       [statement]...]
		[default : 
		       [statement]...]
	  }
 
	  Arguments 
	  exp   
		The integer expression that the switch statement evaluates and then compares to the values in all the cases.
  	  const_exp   
 		An integer expression to which exp is compared. If const_exp matches exp, the accompanying statement is executed.
 	 statement   
	        Zero or more simple statements. (If there is more than one simple statement, you do not need to enclose the statements in braces.)

Version	: 1.0 
*/

#include<stdio.h>

int main()
{
	int cho,a=1;
	printf("\n 1. New Game");
	printf("\n 2. Game Loded");
	printf("\n 3. Game Saved");
	printf("\n 4. Exiting Game\n");
	printf("\n Enter Your Choice : ");
	 scanf("%d",&cho);
	switch(cho)
	{
	    default:	
		printf("\n Error: Bad input\n");
		break;
	    case 1:
		printf("\n New Game is Selected\n");
	    break;
     	case 2:
		printf("\n Loding saved Game\n");
		break;
	    case 3:
		printf("\n Saving the Game\n");
		break;
	    case 4:
		printf("\n Quit Game\n");
		break;
	}
//	printf("\n Statement Related to case 2 case 4");
	
	printf("\n Out of switch body\n");
}
	


