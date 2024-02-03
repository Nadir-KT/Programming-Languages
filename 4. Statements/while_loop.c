/*

This program explains about while looping constructor.
This example will prints a Fahrenheit-in-Celsius

Usage	:
	  while(exp)
	  {
             statement 1;
             statement 2;
             statement 3;
	  }
	Arguments 
	---------
	exp   
 		Any expression.
  	statement   
  		This statement is executed when the while (exp) is true.

Version	: 1.0

*/

#include<stdio.h>
main()
{
    float a;
    a = 0;
    while (a <= 100)
    {
	        printf("%6.2f degrees F = %6.2f degrees C\n",a, (a - 32.0) * 5.0 / 9.0);
        a = a + 10;
    }
    
}
