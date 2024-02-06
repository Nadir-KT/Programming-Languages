#include <stdio.h>

int main() {
  int myAge = 43;		// An int variable
  int* ptr = &myAge;	// A pointer variable
  printf("%d\n", myAge);  // Outputs the value of myAge
  printf("%p\n", &myAge); // Outputs the memory address of myAge // To print pointer values, we use the %p format specifier.
  //The memory address is in hexadecimal form (0x..).
  //A pointer is a variable that stores the memory address of another variable as its value.
  //A pointer variable points to a data type (like int) of the same type
  printf("%p\n", ptr);// Reference: Output the memory address of myAge with the pointer
  printf("%d\n", *ptr);// Dereference: Output the value of myAge with the pointer
  int myNumbers[4] = {25, 50, 75, 100};
  // Get the memory address of the myNumbers array
  printf("%p\n", myNumbers);
  // Get the memory address of the first array element
  printf("%p\n", &myNumbers[0]);
  // Get the value of the first element in myNumbers
  printf("%d", *myNumbers);
  // Get the value of the second element in myNumbers
  printf("%d\n", *(myNumbers + 1));
  // Change the value of the first element to 13
  *myNumbers = 13;
  // Change the value of the second element to 17
  *(myNumbers +1) = 17;
  // Get the value of the first element
  printf("%d\n", *myNumbers);
  // Get the value of the second element
  printf("%d\n", *(myNumbers + 1));
  int *ptr2 = &myNumbers;	// A pointer variable
  for (int i = 0; i < 4; i++) {
    printf("%d\n", *(ptr2 + i));
  }
  return 0;
}