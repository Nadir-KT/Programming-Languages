#include<stdio.h>
extern int myNum; // Declare a variable using name (Identifier)
#define LENGTH 10 // Defining Constant using #define preprocessor.
#define WIDTH  5
#define NEWLINE '\n'
int main()
{
	int myNum; // variable definition
    myNum = 15;	// Initialization: Assign a value to the variable
    float myFloatNum = 5.99; // Floating point number
    char myLetter = 'D'; // Character
	const int  LENGTH2 = 10; // Defining Constant using const keyword.
	const int  WIDTH2 = 5;
	const char NEWLINE2 = '\n';
	int area2;  
	int _ab;  // Valid variable name
    // Print variables using format specifiers
    printf("%d\n", myNum);
    printf("%f\n", myFloatNum);
    printf("%c\n", myLetter);
	
	int area = LENGTH * WIDTH;
	printf("value of area : %d", area);
	printf("%c", NEWLINE);
	
	area2 = LENGTH2 * WIDTH2;
	printf("value of 2nd area : %d", area2);
	printf("%c", NEWLINE2);
	
	return 0;
}