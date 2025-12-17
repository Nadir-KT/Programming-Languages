/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

// Define a union named MyUnion
union MyUnion {
    int intValue;
    float floatValue;
    char charValue;
};

int main() {
    union MyUnion myUnion; // Declare a variable of type MyUnion
    
    // Assigning values to the union members
    myUnion.intValue = 65;
    printf("Integer value: %d\n", myUnion.intValue);
    printf("Float value: %f\n", myUnion.floatValue); // Accessing floatValue after intValue assignment
    
    myUnion.floatValue = 3.14;
    printf("Float value: %f\n", myUnion.floatValue);
    printf("Integer value: %d\n", myUnion.intValue); // Accessing intValue after floatValue assignment
    
    myUnion.charValue = 'A';
    printf("Character value: %c\n", myUnion.charValue);
    printf("Integer value: %d\n", myUnion.intValue); // Accessing intValue after charValue assignment
    
    return 0;
}
