// C code for function with arguments and return value
#include <stdio.h>

int function(int, int, char); // function declaration
//int value;

void main()
{
	int value = function(1, 2, 'c'); // function call
	printf ("\nThe function return value is %d", value);
}

int function(int a, int b, char c) // function definition
{
	printf("The function arguments values are %d, %d, %c", a,b,c);
	return a;
}


