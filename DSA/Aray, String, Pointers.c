#include <stdio.h>

void main()
{
    int a = 12;
	printf("%p\n", &a);
	char b = 'c';
	printf("%c\n", b);
	char greetings[] = "Hello World!";
	printf("%s\n", greetings);
	int myAge = 43;     // Variable declaration
	// & and * operators are used to perform memory-related operations. The & operator is used to get the address of a variable and the * operator is the complement of the & operator and is used to get the value of the object for located at a memory address.
	//	* represents a pointer to an object.
	//	m = &x (will return the memory address of the variable x)
	//	*m will return the value stored at the memory address m.
	int* ptr = &myAge;  // Pointer declaration
	printf("%p\n", ptr);
	printf("%d\n", *ptr);
}