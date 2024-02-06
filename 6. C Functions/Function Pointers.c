
#include <stdio.h>

// Define two functions with the same signature
int add(int a, int b) {
 return a + b;
}

int subtract(int a, int b) {
 return a - b;
}

int main() {
 // Declare a function pointer with the same signature as the functions
 int (*operation)(int, int);

 // Initialize the function pointer with the address of the add function
 operation = add;

 // Use the function pointer to call the add function
 int result = operation(10, 5);
 printf("Result of addition: %d\n", result);

 // Reassign the function pointer to the subtract function
 operation = subtract;

 // Use the function pointer to call the subtract function
 result = operation(10, 5);
 printf("Result of subtraction: %d\n", result);

 return 0;
}
 