#include <stdio.h>
// union union-name { variable_declarations } obj;
// union helps to store various data types in the same memory address. all variables inside union will have same value
// When you need to represent many data types interchangeably.
union data { 
int age; 
char value; 
} d; 

// Driver code
int main() { 
d.age = 15; // A union's members can be accessed by using the dot (.) operator.
d.value = 56;
// Declare a variable of type union unionA
    union data data1;
// Assign a value to the union  
    data1.age = 42;
    data1.value = 49; 
printf("age = %d", d.age);
printf("\nvalue = %d", d.value); 
printf("\nage = %d", data1.age); 
printf("\nvalue = %d", data1.value); 
}
