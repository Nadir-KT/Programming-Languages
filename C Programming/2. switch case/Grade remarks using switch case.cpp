#include<stdio.h>
#include<stdlib.h>
int main(){char grade;
printf("Enter your grade\n");
scanf("%c",&grade);
switch(grade){case'A': printf("Excellent!\n" ); break;
    case 'B' : printf("Good!\n" ); break;
    case 'C' : printf("Well try\n" ); break;
    case 'D' : printf("You passed\n" ); break;
    case 'E' : printf("Better try again\n" ); break;
    default : printf("Invalid grade\n" );}
printf("Your grade is %c\n", grade );
system("pause");}
