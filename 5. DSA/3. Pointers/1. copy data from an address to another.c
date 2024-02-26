#include <stdio.h>

int main() {
    int value = 10; // Value to be stored
    int *ptr1 = &value; // Pointer to the original memory location
    int copy; // Variable to store the copied value
    int *ptr2 = &copy; // Pointer to the new memory location
	//int *ptr2 = (int*)0x7ffe744eb358; // Pointer to the new memory

    // Copying the value
    *ptr2 = *ptr1;// Dereference: Accessing the value from a certain memory location against which that pointer is pointing.
	//copy = *ptr1;
    printf("Original value: %d\n", *ptr1);
    printf("Copied value: %d\n", *ptr2);

    return 0;
}