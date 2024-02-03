/*

This Program Explains About if conditional branching statement in C 
This program will print "A is Big" message if a is greater than b
	
Useage	:  if (exp) 	     [Format 1]
    	   	statement; 
	   An exp can be any integer expression
	   A Statement can be any null statement, simple statement, or compound statement. 
	   A statement can itself be another if statement.
	   Remember, a statement ends with a semicolon.
Version :  1.0

*/

#include<stdio.h>
main()
{
	int a=10,b=2;
	
	if(a>b)
	{
		printf("\n A is Big \n");
	}
}

