#include<stdio.h>
#include <conio.h> 
int main () 
{ 
char grade; 
scanf("%c",&grade);
switch(grade)
 { 
 case'A':
 printf("Excellent!\n" );
  break; 
  case 'B' :
  printf("Good!\n" );	
   case 'C' : 
   printf("Well try\n" );
    break;
	 case 'D' : 
	 printf("You passed\n" );
	  break; 
	  case 'E' : 
	  printf("Better try again\n" );
	   break;
	    default : 
		printf("Invalid grade\n" );
		 } 
		 printf("Your grade is %c\n", grade ); 
		 return 0; 
		 }
