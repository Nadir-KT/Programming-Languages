/*

This Program explains about nested if control statements in C
Usage   :
	   if(exp1)
	   	if(exp2)
	   		statement;
	   exp   
		  Any expression.
	   statement   
  		Any null statement, simple statement, or compound statement. 
		A statement can itself be another if statement. 
		Remember, a statement ends with a semicolon.
Version : 1.0

*/

#include<stdio.h>

main()
{
	int age;
	char gender;
	
	printf("\n Enter Your Gender : ");
	gender=getchar();
	printf("\n Enter Your Age : ");
	scanf("%d",&age);
	if(gender=='m' || gender=='M')
		if(age>=13 && age<=19)
				printf("\n You are in Teens\n"); 
	//printf statement is executed if both if statements are true
}	






