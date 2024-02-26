#include <stdio.h>
//pointers must be handled with care, since it is possible to overwrite other data stored in memory.
int main() {
  int myAge = 43;		// An int variable
  printf("%d\n", myAge);  // Outputs the value of myAge
  printf("%p\n", &myAge); // Outputs the memory address of myAge // To print pointer values, we use the %p format specifier.
  //The memory address is in hexadecimal form (0x..).
  int* ptr = &myAge;	// A pointer variable //&myAge gives address of myAge, and ptr points to address of myAge
  // A pointer is a derived data type that keeps track of another data type's memory address. When a pointer is declared, the data type it refers to is stated first, and then the variable name is preceded by an asterisk (*).
  printf("%p\n", ptr);// Reference: Output the memory address of myAge with the pointer
  //Referencing means taking the address of an existing variable (using &) to set a pointer variable
  //A pointer is a variable that stores the memory address of another variable as its value.
  //A pointer variable points to a data type (like int) of the same type
  printf("%d\n", *ptr);// Dereference: Accessing the value from a certain memory location against which that pointer is pointing.
  int **ptr_to_ptr = &ptr;
  printf("%p\n", ptr_to_ptr);// Pointer to Pointer: pointer contains the address of another pointer
  int myNumbers[4] = {25, 50, 75, 100};
  printf("%p\n", myNumbers); // Get the memory address of the myNumbers array
  // The name of an array, is actually a pointer to the first element of the array.
  printf("%p\n", &myNumbers[0]); // Get the memory address of the first array element
  // Get the memory address of each array element
  for (int i = 0; i < 4; i++) {
	printf("%p\n", &myNumbers[i]);
  }
  // Get the size of the myNumbers array
  printf("%ld\n", sizeof(myNumbers));
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
  int *ptr2 = &myNumbers;	// A pointer variable//Same as int *ptr2 = myNumbers
  for (int i = 0; i < 4; i++) {
    printf("%d\n", *(ptr2 + i));
  }
  int *ptr3 = NULL;    // ptr is a NULL pointer
  printf("\n\n The value of ptr is: %ls ", ptr3);
  void* dataPtr; // Any address can be stored in a pointer of type void*, making it a universal pointer. void* can be used to build generic pointers, void itself cannot be declared as a variable type.
  void* dataPtr1 = &myAge;  
  printf("\nValue of number: %d\n", *(int*)dataPtr1);  
  return 0;
}